#include "TiArena.h"

TiArena::TiArena(QWidget *parent) : QObject(parent)
{
    name = new QString("randowm arena");                                                       //identifient of the arena
    description = new QString("description");
    icon = new QString("../T_Plateforme/SRC/RftG/Arenas/nightCity_ico.png");
    background = new QString("backgroundPath");
    forground = new QString("forGroundPath");
    pos = new QPointF(0.0, 0.0);
    bgPos = new QPointF(0.0, 0.0);
    fgPos = new QPointF(0.0, 0.0);
    size = new QPointF(1000.0, 1000.0);
    bgSize = new QPointF(800.0, 800.0);
    fgSize = new QPointF(500.0, 10.0);
    //destructibleList = new QList<TiDoodad *>;
    destructibleSizeList = new QList<QPointF *>;
    destructiblePosList = new QList<QPointF *>;
}

TiArena::~TiArena()
{

}

void TiArena::setName(QString arenaName)
{
    *name = arenaName;
}
void TiArena::setBackground(QString backgroundPath)
{
    *background = backgroundPath;
    QImageReader reader("../T_Plateforme/SRC/RftG/" + backgroundPath);
    QSize sizeOfImage = reader.size();
    setBackgroundSize(QPointF(sizeOfImage.width(),sizeOfImage.height()));
}
void TiArena::setForground(QString forgroundPath)
{
    *forground = forgroundPath;
    QImageReader reader("../T_Plateforme/SRC/RftG/" + forgroundPath);
    QSize sizeOfImage = reader.size();
    setForgroundSize(QPointF(sizeOfImage.width(),sizeOfImage.height()));
}
void TiArena::setDescription(QString arenaDescription)
{
    *description = arenaDescription;
}
void TiArena::setIcon(QString iconPath)
{
    *icon = iconPath;
}
//void TiArena::addDoodad(TiDoodad newDoodad)
//{
//    TiDoodad *doodad = new TiDoodad;
//    doodad->setName(newDoodad.getName());
//    doodad->setParent(newDoodad.parent());
//    destructibleList->append(doodad);
//}
//void TiArena::setDoodads(QList<TiDoodad *> newDoodadList)
//{
//    for(int i=0; i < newDoodadList.count() - 1; i++)
//    {
//        destructibleList->append(newDoodadList.at(i));
//    }
//}
void TiArena::setPos(QPointF newPos)
{
    *pos = newPos;
}
void TiArena::setBackgroundPos(QPointF newPos)
{
    *bgPos = newPos;
}
void TiArena::setForgroundPos(QPointF newPos)
{
    *fgPos = newPos;
}
void TiArena::setDoodadPos(int id, QPointF newPos)
{
    *destructiblePosList->at(id) = newPos;
}
void TiArena::setSize(QPointF newSize)
{
    *size = newSize;
}
void TiArena::setBackgroundSize(QPointF newSize)
{
    *bgSize = newSize;
}
void TiArena::setForgroundSize(QPointF newSize)
{
    *fgSize = newSize;
}
void TiArena::setDoodadSize(int id, QPointF newSize)
{
    if(destructibleSizeList->count() - 1 < id){destructibleSizeList->append(new QPointF(newSize));}
    else{*destructibleSizeList->at(id) = newSize;}

}


QString TiArena::getName()
{
    return *name;
}
QString TiArena::getDescription()
{
    return *description;
}
QString TiArena::getIcon()
{
    return *icon;
}
QString TiArena::getBackground()
{
    return *background;
}
QString TiArena::getForground()
{
    return *forground;
}
QString TiArena::getDoodad(int id)
{
    //return destructibleList->at(id)->getName();
}
int TiArena::getDoodadsCount()
{
    //return destructibleList->count();
    return destructibleSizeList->count();
}
QPointF TiArena::getPos()
{
    return *pos;
}
QPointF TiArena::getBackgroundPos()
{
    return *bgPos;
}
QPointF TiArena::getForgroundPos()
{
    return *fgPos;
}
QPointF TiArena::getDoodadPos(int id)
{
    return *destructiblePosList->at(id);
}
QPointF TiArena::getSize()
{
    return *size;
}
QPointF TiArena::getBackgroundSize()
{
    return *bgSize;
}
QPointF TiArena::getForgroundSize()
{
    return *fgSize;
}
QPointF TiArena::getDoodadSize(int id)
{
    return *destructibleSizeList->at(id);
}

