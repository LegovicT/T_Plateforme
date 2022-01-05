#include "TiCharacter.h"

TiCharacter::TiCharacter(QObject *parent) : QObject(parent)
{
    name = new QString("name"); //name
    description = new QString("Power:                                05\
                              \rDistance:                            10\
                              \rDamages:                           02\
                              \rSpeed:                                04\
                              \rEndurence:                         08");
    tips = new QString("Spell A:             Fire Shield\
                       \nSpell B:             Fire Flight\
                       \nSpell X:             Fire Jab\
                       \nSpell Y:             Fire Kick\
                       \n-  -  -  -  -  -  -  -  -  -  -  -  -  -\
                       \nUpImpact:        Fire Uppercut\
                       \nDownImpact:   Fire Quake\
                       \nFrontImpact:    Fire Shot\
                       \nBackImpact:     Fire Shade\
                       \n-  -  -  -  -  -  -  -  -  -  -  -  -  -\
                       \n*SPECIAL*:      Fire Shawer");
    pvMax = new int(0);                                                                     //max potential of life points
    staminaMax = new int(0);                                                                //max potential of stamina level
    icon = new QString("null");                                                             //Icon of the character
    weight = new qreal(0.0);
    animPos = new QPoint(0,0);                                                              //weight of the character
    animCount = new QList<int>;
    animationNameList = new QList<QString >;
    spritePath = new QString("null");
    hitboxPath = new QString("null");
    hurtboxPath = new QString("null");
    damageList = new QList<QList<qreal *> *>;
    propulsionList = new QList<QList<qreal *> *>;
    fxFrameAnim = new QList<QPoint>;

    speeds = new QPointF(0.0,0.0);
    comboCounter = new QList<int *>;
    hitCounter = new int(0);                                                                 //count the hits given
    buffer = new int(0);

    stamina = new int(0);                                                                    //current stamina level
    pv = new int(0);                                                                         //current life points
    pos = new QPointF(0.0,0.0);                                                              //Position of the character
    orientation = new bool(false);                                                           //orientation of the character (true==left, false==right)

    effectList = new QList<TiEffects *>;

    for(int i=0;i < 10; i++)
    {
        animationNameList->append("");
        animCount->append(0);
    }
}
TiCharacter::~TiCharacter()
{

}


void TiCharacter::setName(QString charName)
{
    name->clear();
    name->append(charName);
}
void TiCharacter::setSprite(QString sprite, QString box)
{
    if(box == "sprite")
    {
        spritePath->clear();
        spritePath->append(sprite);
    }
    else if(box == "hitbox")
    {
        hitboxPath->clear();
        hitboxPath->append(sprite);
    }
    else if(box == "hurtbox")
    {
        hurtboxPath->clear();
        hurtboxPath->append(sprite);
    }
}
void TiCharacter::setIcon(QString iconPath)
{
    icon->clear();
    icon->append(iconPath);
}
void TiCharacter::setMaxLife(int charLife)
{
    *pvMax = charLife;
}
void TiCharacter::setMaxStamina(int charStamina)
{
    *staminaMax = charStamina;
}
void TiCharacter::setWeight(qreal charWeight)
{
    *weight = charWeight;
}
void TiCharacter::setDescription(QString characterDescription)
{
    description->clear();
    description->append(characterDescription);
}
void TiCharacter::setTips(QString characterTips)
{
    tips->clear();
    tips->append(characterTips);
}
void TiCharacter::setAnimations(QString name, QString path, int box, int idAnim, int idFrame, int xSpriteSheetPos, int ySpriteSheetPos)
{
}
void TiCharacter::setAnimation(QString name, int idAnim, int frameCount)
{
    animCount->replace(idAnim, frameCount);
    animationNameList->replace(idAnim, name);
}
void TiCharacter::setAnimation(QString name, QPoint posAnim)
{
    animCount->replace(posAnim.y(), posAnim.x());
    animationNameList->replace(posAnim.y(), name);
}
void TiCharacter::setDamages(QList<qreal> damages, int idAnim)
{
    while(damageList->count() < idAnim + 1)
    {
        QList<qreal *> *list = new QList<qreal *>;
        list->append(new qreal(0.0));
        damageList->append(list);
    }
    QList<qreal *> *list = new QList<qreal *>;
    for(int i=0;i<damages.size()-1;i++)
    {
        list->append(new qreal(damages.at(i)));
    }
    damageList->replace(idAnim, list);
}
void TiCharacter::setPropulsions(QList<qreal> propulsions, int idAnim)
{
    while(propulsionList->count() < idAnim + 1)
    {
        QList<qreal *> *list = new QList<qreal *>;
        list->append(new qreal(0.0));
        propulsionList->append(list);
    }
    QList<qreal *> *list = new QList<qreal *>;
    for(int i=0;i<propulsions.size()-1;i++)
    {
        list->append(new qreal(propulsions.at(i)));
    }
    propulsionList->replace(idAnim, list);
}
void TiCharacter::setDamages(int noAnim, int noFrame, qreal damage)
{
    while(damageList->count() < noAnim + 1)
    {
        QList<qreal *> *list = new QList<qreal *>;
        list->append(new qreal(0.0));
        damageList->append(list);
    }
    while(damageList->at(noAnim)->count() < noFrame + 1)
    {
        damageList->at(noAnim)->append(new qreal(0.0));
    }
    damageList->at(noAnim)->replace(noFrame, new qreal(damage));
}
void TiCharacter::setDamages(QPoint animFrame, qreal damage)
{
    while(damageList->count() < animFrame.y() + 1)
    {
        QList<qreal *> *list = new QList<qreal *>;
        list->append(new qreal(0.0));
        damageList->append(list);
    }
    while(damageList->at(animFrame.y())->count() < animFrame.x() + 1)
    {
        damageList->at(animFrame.y())->append(new qreal(0.0));
    }
    damageList->at(animFrame.y())->replace(animFrame.x(), new qreal(damage));
}
void TiCharacter::setPropulsions(int noAnim, int noFrame, qreal propulsion)
{
    while(propulsionList->count() < noAnim + 1)
    {
        QList<qreal *> *list = new QList<qreal *>;
        list->append(new qreal(0.0));
        propulsionList->append(list);
    }
    while(propulsionList->at(noAnim)->count() < noFrame + 1)
    {
        propulsionList->at(noAnim)->append(new qreal(0.0));
    }
    propulsionList->at(noAnim)->replace(noFrame, new qreal(propulsion));
}
void TiCharacter::setPropulsions(QPoint animFrame, qreal propulsion)
{
    while(propulsionList->count() < animFrame.y() + 1)
    {
        QList<qreal *> *list = new QList<qreal *>;
        list->append(new qreal(0.0));
        propulsionList->append(list);
    }
    while(propulsionList->at(animFrame.y())->count() < animFrame.x() + 1)
    {
        propulsionList->at(animFrame.y())->append(new qreal(0.0));
    }
    propulsionList->at(animFrame.y())->replace(animFrame.x(), new qreal(propulsion));
}
void TiCharacter::setSpeeds(QPointF speed)
{
    *speeds = speed;
}
void TiCharacter::setSpeeds(qreal speedX, qreal speedY)
{
    *speeds = QPointF(speedX, speedY);
}
void TiCharacter::addEffect(TiEffects *fx, QPoint numFrameAnim)
{
    fxFrameAnim->append(numFrameAnim);
    effectList->append(fx);
}

void TiCharacter::setPos(qreal charPosX, qreal charPosY)
{
    *pos = QPointF(charPosX, charPosY);
}
void TiCharacter::setPos(QPointF charPos)
{
    *pos = charPos;
}
void TiCharacter::setOrientation(bool charOrientation)
{
    *orientation = charOrientation;
}
void TiCharacter::recieveDamage(int damageTaken)
{
    if((damageTaken > 0) && (*pv - damageTaken > 0))
    {*pv = *pv - damageTaken;}
}
void TiCharacter::reduceStamina(int reduceRate)
{
    if((reduceRate > 0) && (*stamina - reduceRate > 0))
    {*stamina = *stamina - reduceRate;}
}
void TiCharacter::gainStamina(int gainRate)
{
    if((gainRate > 0) && (*stamina + gainRate <= *staminaMax))
    {*stamina = *stamina + gainRate;}
}
void TiCharacter::startCombo()
{
    hitCounter = 0;
}
void TiCharacter::finishCombo()
{

}
void TiCharacter::playAnim(int numAnim)
{
    animPos->setX(0);
    animPos->setY(numAnim);
}
void TiCharacter::playAnim(QString nameAnim)
{
    animPos->setX(0);
    animPos->setY(animationNameList->indexOf(nameAnim));
}
void TiCharacter::nextFrame()
{
    if(animPos->x() < animCount->at(animPos->y()) - 1)
    {
        animPos->setX(animPos->x() + 1);
    }
    else
    {
        animPos->setX(0);
    }
}

QString TiCharacter::getName()
{
    return *name;
}
QString TiCharacter::getIcon()
{
    return *icon;
}
int TiCharacter::getMaxLife()
{
    return *pvMax;
}
int TiCharacter::getMaxStamina()
{
    return *staminaMax;
}
QString TiCharacter::getDescription()
{
    return *description;
}
QString TiCharacter::getTips()
{
    return *tips;
}
int TiCharacter::getCurrentLife()
{
    return *pv;
}
int TiCharacter::getCurrentStamina()
{
    return *stamina;
}
QPointF TiCharacter::getPos()
{
    return *pos;
}
bool TiCharacter::getOrientation()
{
    return *orientation;
}
qreal TiCharacter::getWeight()
{
    return *weight;
}
QPointF TiCharacter::getSpeeds()
{
    return *speeds;
}
qreal TiCharacter::currentDamages()
{
    return *damageList->at(currentAnimFrame().y())->at(currentAnimFrame().x());
}
qreal TiCharacter::currentPropulsion()
{
    return *propulsionList->at(currentAnimFrame().y())->at(currentAnimFrame().x());
}
qreal TiCharacter::getDamages(int anim, int frame)
{
    return *damageList->at(anim)->at(frame);
}
qreal TiCharacter::getDamages(QPoint animFrame)
{
    return *damageList->at(animFrame.y())->at(animFrame.x());
}
qreal TiCharacter::getPropulsion(int anim, int frame)
{
    return *propulsionList->at(anim)->at(frame);
}
qreal TiCharacter::getPropulsion(QPoint animFrame)
{
    return *propulsionList->at(animFrame.y())->at(animFrame.x());
}
QString TiCharacter::getSprite(QString box)
{
    if(box == "sprite")
    {
        return *spritePath;
    }
    else if(box == "hitbox")
    {
        return *hitboxPath;
    }
    else if(box == "hurtbox")
    {
        return *hurtboxPath;
    }
}
QPoint TiCharacter::currentAnimFrame()
{
    return *animPos;
}
QString TiCharacter::currentAnimName()
{
    return animationNameList->at(currentAnimFrame().y());
}
QString TiCharacter::getEffect(QPoint numFrameAnim)
{
    return effectList->at(fxFrameAnim->indexOf(numFrameAnim))->getName();
}
QString TiCharacter::getEffect()
{
    return effectList->at(fxFrameAnim->indexOf(currentAnimFrame()))->getName();
}

int TiCharacter::getAnimCount()
{
    return animCount->size();
}
int TiCharacter::getFrameCount(int noAnim)
{
    return animCount->at(noAnim);
}
int TiCharacter::getFrameCount(QString nameAnim)
{
    return animCount->at(animationNameList->indexOf(nameAnim));
}
QString TiCharacter::getAnimName(int noAnim)
{
    return animationNameList->at(noAnim);
}

QPoint TiCharacter::getDetailsCount(int noAnim)
{
    return QPoint(damageList->at(noAnim)->size(), propulsionList->at(noAnim)->size());
}
QPoint TiCharacter::getDetailCount()
{
    return QPoint(damageList->size(), propulsionList->size());
}
