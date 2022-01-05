#include "TiHBox.h"

TiHBox::TiHBox(QObject *parent) : QObject(parent)
{
    identifient = new QString;                                                           //identifient of the HBox
    x = new qreal;                                                          //Xpos of the HBox
    y = new qreal;                                                          //Ypos of the HBox
    r = new qreal;

    *x = 0;
    *y = 0;
    *r = 0;
}
TiHBox::~TiHBox()
{

}

bool TiHBox::isCollideWith(TiHBox *hBox)
{

}
bool TiHBox::move(int *newX, int *newY)
{

}
qreal TiHBox::X()
{
    return *x;
}
qreal TiHBox::Y()
{
    return *y;
}
qreal TiHBox::R()
{
    return *r;
}

bool TiHBox::setX(qreal val)
{
    *x = val;
}
bool TiHBox::setY(qreal val)
{
    *y = val;
}
bool TiHBox::setR(qreal val)
{
    *r = val;
}
