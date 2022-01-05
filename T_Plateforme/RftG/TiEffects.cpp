#include "TiEffects.h"

TiEffects::TiEffects(QObject *parent) : QObject(parent)
{
    name = new QString;                                              //name of the effect
    pathFx = new QString("../T_Plateforme/SRC/RftG/Effects/fx.xml");                                            //path of the effect xml
    spritePath = new QString("../T_Plateforme/SRC/RftG/Images/fx.png");                                   //path of the sprite png
    hitboxPath = new QString("../T_Plateforme/SRC/RftG/Images/fx.png");                                   //path of the hitbox png
    typeFx = new QString("chanel");                                            //type of effect (chanel, cast, launch)
    move = new QString;                                          //movement of the effect (front, up, back, down, none)
    posFx = new QPointF;
    posFx->setX(0);
    posFx->setY(0);
    frameAnimFx = new QPoint;
    frameAnimFx->setX(0);
    frameAnimFx->setY(0);
    frameCharFx = new QPoint;
    frameCharFx->setX(0);
    frameCharFx->setY(0);
    damageList = new QList<QList<qreal *> *>;
    QList<qreal *> *dmgFrames = new QList<qreal *>;
    dmgFrames->append(new qreal(0.0));
    damageList->append(dmgFrames);
    damageList->append(dmgFrames);
    damageList->append(dmgFrames);
    propulsionList = new QList<QList<qreal *> *>;
    QList<qreal *> *plsFrames = new QList<qreal *>;
    plsFrames->append(new qreal(0.0));
    propulsionList->append(plsFrames);
    propulsionList->append(plsFrames);
    propulsionList->append(plsFrames);
    startFrames = new int;
    loopFrames = new int;
    endFrames = new int;

    soundStart = new QString("../T_Plateforme/SRC/RftG/Effects/fxStart.mp3");                                    //path of the mp3 start effect
    soundLoop = new QString("../T_Plateforme/SRC/RftG/Effects/fxLoop.mp3");
    soundEnd = new QString("../T_Plateforme/SRC/RftG/Effects/fxEnd.mp3");
}
TiEffects::~TiEffects()
{

}


void TiEffects::setName(QString newName)
{
    *name = newName;
}
void TiEffects::setPath(QString newPath)
{
    *pathFx = newPath;
}
void TiEffects::setSprite(QString newPath)
{
    *spritePath = newPath;
}
void TiEffects::setHitbox(QString newPath)
{
    *hitboxPath = newPath;
}
void TiEffects::setType(QString newType)
{
    *typeFx = newType;
}
void TiEffects::setMove(QString newMove)
{
    *move = newMove;
}
void TiEffects::setPos(QPointF newPos)
{
    *posFx = newPos;
}
void TiEffects::setDamages(QPoint frameAnim, qreal dmg)
{
    while(damageList->at(frameAnim.y())->size() < frameAnim.x())
    {
        damageList->at(frameAnim.y())->append(new qreal(0.0));
    }

    *damageList->at(frameAnim.y())->at(frameAnim.x()) = dmg;
}
void TiEffects::setPropulsion(QPoint frameAnim, qreal prpsl)
{
    while(propulsionList->at(frameAnim.y())->size() < frameAnim.x())
    {
        propulsionList->at(frameAnim.y())->append(new qreal(0.0));
    }

    *propulsionList->at(frameAnim.y())->at(frameAnim.x()) = prpsl;
}
void TiEffects::setSound(int idAnim, QString path)
{
    if(idAnim == 0)//Start
    {
        *soundStart = path;
    }
    else if(idAnim == 1)//Loop
    {
        *soundLoop = path;
    }
    else if(idAnim == 2)//End
    {
        *soundEnd = path;
    }
}
void TiEffects::setStartFrames(int noFrames)
{
    *startFrames = noFrames;
}
void TiEffects::setLoopFrames(int noFrames)
{
    *loopFrames = noFrames;
}
void TiEffects::setEndFrames(int noFrames)
{
    *endFrames = noFrames;
}
void TiEffects::setCharacterFrame(QPoint newCharFrm)
{
    *frameCharFx = newCharFrm;
}

void TiEffects::playAnim(int numAnim)
{
    if(numAnim == 0) //start
    {
        if(*startFrames == 0)
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(1);
            emit playSound(soundLoop);
        }
        else
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(0);
            emit playSound(soundStart);
        }
    }
    else if(numAnim == 1) //loop
    {
        if(*loopFrames == 0)
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(2);
            emit playSound(soundEnd);
        }
        else
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(1);
            emit playSound(soundLoop);
        }
    }
    else if(numAnim == 2) //end
    {
        if(*endFrames == 0)
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(0);
            emit endFx();
        }
        else
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(2);
            emit playSound(soundEnd);
        }
    }
}
void TiEffects::nextFrame()
{
    if(currentAnimFrame().y() == 0) //start
    {
        if(*startFrames > frameAnimFx->x())
        {
            frameAnimFx->setX(frameAnimFx->x() + 1);
        }
        else
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(1);
            emit playSound(soundLoop);
        }
    }
    else if(currentAnimFrame().y() == 1) //loop
    {
        if(*loopFrames > frameAnimFx->x())
        {
            frameAnimFx->setX(frameAnimFx->x() + 1);
        }
        else
        {
            frameAnimFx->setX(0);
            if(*typeFx=="chanel" || *typeFx=="cast")
            {
                frameAnimFx->setY(1);
                emit playSound(soundLoop);
            }
            else if(*typeFx=="launch")
            {
                frameAnimFx->setY(2);
                emit playSound(soundEnd);
            }
        }
    }
    else if(currentAnimFrame().y() == 2) //end
    {
        if(*endFrames > frameAnimFx->x())
        {
            frameAnimFx->setX(frameAnimFx->x() + 1);
        }
        else
        {
            frameAnimFx->setX(0);
            frameAnimFx->setY(0);
            emit endFx();
        }
    }
}


QString TiEffects::getName()
{
    return *name;
}
QString TiEffects::getPath(QString box)//box = "sprite" or "hitbox" for png file path or "xml" for xml file path
{
    if(box=="sprite")
    {
        return *spritePath;
    }
    else if(box=="hitbox")
    {
        return *hitboxPath;
    }
    else if(box=="xml")
    {
        return *pathFx;
    }
    else
    {
        return *pathFx;
    }
}
QString TiEffects::getType()
{
    return *typeFx;
}
QPointF TiEffects::getPos()
{
    return *posFx;
}
QString TiEffects::getMove()
{
    return *move;
}
qreal TiEffects::getDamages(QPoint frameAnim)
{
    return *damageList->at(frameAnim.y())->at(frameAnim.x());
}
qreal TiEffects::getPropulsion(QPoint frameAnim)
{
    return *propulsionList->at(frameAnim.y())->at(frameAnim.x());
}
qreal TiEffects::getDamages()
{
    return *damageList->at(frameAnimFx->y())->at(frameAnimFx->x());
}
qreal TiEffects::getPropulsion()
{
    return *propulsionList->at(frameAnimFx->y())->at(frameAnimFx->x());
}
int TiEffects::getFrameCount(int idAnim)
{
    if(idAnim==0)//Start
    {
        return *startFrames;
    }
    else if(idAnim==1)//Loop
    {
        return *loopFrames;
    }
    else if(idAnim==2)//End
    {
        return *endFrames;
    }
    else
    {
        return *startFrames + *loopFrames + *endFrames;
    }
}
int TiEffects::getFrameCount(QString anim)
{
    if(anim=="start")//Start
    {
        return *startFrames;
    }
    else if(anim=="loop")//Loop
    {
        return *loopFrames;
    }
    else if(anim=="end")//End
    {
        return *endFrames;
    }
    else
    {
        return *startFrames + *loopFrames + *endFrames;
    }
}
QPoint TiEffects::getCharacterFrame()
{
    return *frameCharFx;
}

QPoint TiEffects::currentAnimFrame()
{
    return *frameAnimFx;
}
