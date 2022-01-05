#ifndef TIHBOX_H
#define TIHBOX_H

#include <QtGui>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include <QList>
#include <QObject>


class TiHBox : public QObject
{
    Q_OBJECT

public:
    TiHBox(QObject *parent = 0);
    ~TiHBox();

public slots:
    bool isCollideWith(TiHBox *hBox);
    bool move(int *newX, int *newY);                                        //move the character by a distance
    qreal X();                                                                  //return the x value in the list by the id
    qreal Y();                                                                  //return the y value in the list by the id
    qreal R();                                                                  //return the radius value in the list by the id

    bool setX(qreal val);
    bool setY(qreal val);
    bool setR(qreal val);


private:
    QString *identifient;                                                       //identifient of the HBox
    qreal *x;                                                                   //Xpos of the HBox
    qreal *y;                                                                   //Ypos of the HBox
    qreal *r;                                                                   //radius of the HBox

};

#endif // TIHBOX_H
