#include "TiBattleField.h"

TiBattleField::TiBattleField(QString *mName, int *mWidth, int *mHeight, QWidget *parent) : QWidget(parent)
{
    name = new QString(*mName);
    size = new QPoint(*mWidth, *mHeight);
    //elements = new TiElement[][]();
}
TiBattleField::TiBattleField(QString *mName, QPoint *mSize, QWidget *parent) : QWidget(parent)
{
    name = new QString(*mName);
    size = new QPoint(*mSize);
    //elements = new TiElement[][]();
}

TiBattleField::TiBattleField(QWidget *parent) : QWidget(parent)
{
    name = new QString("defaultBattlefield");
    size = new QPoint(10, 10);
    //elements = new TiElement[][]();
}
TiBattleField::~TiBattleField()
{

}


QString TiBattleField::getName()
{
    return *name;
}
QPoint TiBattleField::getSize()
{
    return *size;
}
int TiBattleField::getFaith()
{
    int faith(0);
//    for(int i=0; i< *characters->size(); i++)
//    {
//        if(characters->at(i)->getOrientation() == "Religieux")
//        {
//            faith += characters->at(i)->getResources();
//        }
//    }
    return faith;
}
int TiBattleField::getTechnology()
{

}
int TiBattleField::getArcane()
{

}

/**** SETTERS ****/
//void addElement(TiElement *element, QPoint *pos);
//void moveElement(TiElement *element, QPoint *pos);
//void removeElement(TiElement *element);
//void sellElement(TiElement *element);
