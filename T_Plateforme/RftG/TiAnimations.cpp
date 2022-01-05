#include "TiAnimations.h"

TiAnimations::TiAnimations(QObject *parent) : QObject(parent)
{
    animeNameList = new QList<QString *>;        //paths of the images of the animation
    spriteImage = new QString();
    hitboxImage = new QString();
    hurtboxImage = new QString();
    curFrame = new QPoint(0,0);                        //(n°anime, n°frame)
    dmgList = new QList<QList<int *> *>;
    propultionList = new QList<QList<qreal *> *>;
}
TiAnimations::~TiAnimations()
{

}


void TiAnimations::nextFrame()
{
    curFrame->setX(curFrame->x()+1);
    //this->update(-250,-250,500,500);
}
void TiAnimations::playAnim(int numAnim)
{
    curFrame->setY(numAnim);
    curFrame->setX(0);
}
bool TiAnimations::setSprite(QString sprite, QString box)
{
    if(box == "sprite")
    {*spriteImage = sprite;}
    else if(box == "hitbox")
    {*hitboxImage = sprite;}
    else if(box == "hurtbox")
    {*hurtboxImage = sprite;}

}
bool TiAnimations::setDamages(QList<QList<int>> damages)
{
    dmgList->clear();
    for(int i=0; i < damages.count()-1; i++)
    {
        QList<int *> dmgsAnim;
        for(int j=0; j < damages.at(i).count()-1;j++)
        {
            dmgsAnim.append(new int(damages.at(i).at(j)));
        }
        dmgList->append(&dmgsAnim);
    }
    return dmgList->count() == damages.count();
}
bool TiAnimations::setPropultions(QList<QList<qreal>> propultions)
{
    propultionList->clear();
    for(int i=0; i < propultions.count(); i++)
    {
        QList<qreal *> proplsAnim;
        for(int j=0; j < propultions.at(i).count()-1;j++)
        {
            proplsAnim.append(new qreal(propultions.at(i).at(j)));
        }
        propultionList->append(&proplsAnim);
    }
    return propultionList->count() == propultions.count();
}


QString TiAnimations::getSprite(QString box)
{
    if(box == "sprite")
    {return *spriteImage;}
    else if(box == "hitbox")
    {return *hitboxImage;}
    else if(box == "hurtbox")
    {return *hurtboxImage;}
}
int TiAnimations::getDamage(QPoint idAnimFrame)
{
    if(idAnimFrame==QPoint(0,0)){return *dmgList->at(curFrame->x())->at(curFrame->y());}
    else{return *dmgList->at(idAnimFrame.x())->at(idAnimFrame.y());}
}
qreal TiAnimations::getPropultion(QPoint idAnimFrame)
{
    if(idAnimFrame==QPoint(0,0)){return *propultionList->at(curFrame->x())->at(curFrame->y());}
    else{return *propultionList->at(idAnimFrame.x())->at(idAnimFrame.y());}
}
QPoint TiAnimations::currentFrame()
{
    return *curFrame;
}
QString TiAnimations::currentFrameName()
{
    return *animeNameList->at(curFrame->x());
}
QPoint TiAnimations::animFrameCount()
{
    if(dmgList->count() == propultionList->count())
    {return QPoint(dmgList->count(), dmgList->at(dmgList->count()-1)->count());}
}
