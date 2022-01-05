#include "TiDoodad.h"

TiDoodad::TiDoodad(QObject *parent) : QObject(parent)
{
    name = new QString("a doodad");
    pos = new QPointF(0.0, 0.0);
    size = new QPointF(0.0, 0.0);
    origine = new QPointF(0.0, 0.0);
    resize = new QPointF(0.0, 0.0);
    pixmapPath = new QString("doodad");
}
TiDoodad::~TiDoodad()
{

}

QString TiDoodad::getName()
{
    return *name;
}
QPointF TiDoodad::getPos()
{
    return *pos;
}
QPointF TiDoodad::getSize()
{
    return *size;
}
QString TiDoodad::getPixmap()
{
    return *pixmapPath;
}
QPointF TiDoodad::getOrigine()
{
    return *origine;
}

void TiDoodad::setName(QString newName)
{
    *name = newName;
}
void TiDoodad::setPos(qreal newPosX, qreal newPosY)
{
    *pos = QPointF(newPosX, newPosY);
}
void TiDoodad::setPos(QPointF newPos)
{
    *pos = newPos;
}
void TiDoodad::setOrigine(qreal newPosX, qreal newPosY)
{
    *origine = QPointF(newPosX, newPosY);
}
void TiDoodad::setOrigine(QPointF newPos)
{
    *origine = newPos;
}
void TiDoodad::setSize(qreal newSizeX, qreal newSizeY)
{
    *size = QPointF(newSizeX, newSizeY);
}
void TiDoodad::setSize(QPointF newSize)
{
    *size = newSize;
}
void TiDoodad::setPixmap(QString path)
{
    *pixmapPath = path;
}
