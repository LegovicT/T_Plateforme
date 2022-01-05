#include "TiCharacterMTD.h"

TiCharacterMTD::TiCharacterMTD(QWidget *parent)
{
    name = new QString;
    position = new QPointF;
    orientation = new QString();
    alive = new bool(true);
    level = new int;
    life = new int;
    cost = new int;
    resources = new int;
    damages = new int;
    armor = new int;
    range = new int;
    move = new int;
    affinity = new int;
    dexterity = new int;
    standHit = new QTimer;
    canHit = new bool(true);
    order = new QString("Stand");
    target = new TiCharacterMTD();
    //        TiTechnic *tech1;
    //        TiTechnic *tech2;
    //        TiTechnic *tech3;
    //        TiTechnic *tech4;
    //        TiAmelioration *Amelio1;
    //        TiAmelioration *Amelio2;
    //        TiAmelioration *Amelio3;
    //        TiAmelioration *Amelio4;
    //        TiItem *item1;
    //        TiItem *item2;
    //        TiItem *item3;
    //        TiItem *item4;

    /**** CONNECTIONS ****/
    connect(standHit, SIGNAL(timeout()), this, SLOT(stopStanding()));
}
TiCharacterMTD::~TiCharacterMTD()
{

}

QString TiCharacterMTD::getName()
{
    return *name;
}
QPointF TiCharacterMTD::getPosition()
{
    return *position;
}
int TiCharacterMTD::getResources()
{
    return *resources;
}
QString TiCharacterMTD::getOrientation()
{
    return *orientation;
}
bool TiCharacterMTD::isAlive()
{
    return *alive;
}
QPoint TiCharacterMTD::giveDamages()
{
    *canHit = true;
    standHit->setInterval(5 / pow(*dexterity, 0.5));
    standHit->start();
    if(target != NULL && !target->isAlive())
    {
        target = NULL;
        *order = "Stand";
    }
    else
    {
        *order = "Fight";
    }
    return QPoint(*damages, *affinity);
}
bool TiCharacterMTD::readyToHit()
{
    if(target != NULL && target->isAlive())
    {
        *order = "Fight";
    }
    else if(target != NULL && !target->isAlive())
    {
        target = NULL;
        *order = "Stand";
    }
    else
    {
        *order = "Stand";
    }
    return *canHit;
}
QString TiCharacterMTD::getOrder()
{
    return *order;
}
TiCharacterMTD TiCharacterMTD::getTarget()
{
    //return *target;
}

void TiCharacterMTD::takeDamages(int *dmg, int *fnt)
{
    *armor -= *fnt;
    double powarm = pow(*armor, 0.5);
    if(*life <= *dmg / powarm)
    {
        *life = 0;
        *alive = false;
    }
    else
    {
        *life -= *dmg / powarm;
    }
}
void TiCharacterMTD::stopStanding()
{
    *canHit = true;
}
void TiCharacterMTD::giveOrder(QString *odr)
{
    if(*odr == "Stand")
    {
        if(*order == "Stand")
        {
            *order = *odr;
        }
    }
    else if(*odr == "Fight")
    {
        if(*order == "Stand")
        {
            *order = *odr;
        }
    }
}
void TiCharacterMTD::setTarget(TiCharacterMTD *trg)
{
    if(target == NULL)
    {
        target = trg;
    }
}

//void addElement(TiElement *element, QPoint *pos);
//void moveElement(TiElement *element, QPoint *pos);
//void removeElement(TiElement *element);
//void sellElement(TiElement *element);

