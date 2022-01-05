#ifndef TECHNOMANABSTRACTWHEEL_H
#define TECHNOMANABSTRACTWHEEL_H

#include <QtGui>
#include <QWidget>
#include <QtWidgets>
#include <QTimer>
#include <QList>
#include <QGraphicsItem>

#include <QtOpenGL>
#include <QGLWidget>

#include "AbstractModul.h"
#include "TechnomanCore.h"
#include "TechnomanBody.h"
#include "TechnomanFoot.h"
#include "TechnomanShield.h"
#include "TechnomanAppendage.h"

class TechnomanAbstractWheel : public AbstractModul
{
    Q_OBJECT

public:
    TechnomanAbstractWheel(TechnomanAbstractWheel *abstractWheel);
    TechnomanAbstractWheel
    (
        QString *name,
        TechnomanCore *core=0, TechnomanBody *body=0, TechnomanFoot *foot=0, TechnomanShield *shield=0,
        TechnomanAppendage *appendage1=0, TechnomanAppendage *appendage2=0, TechnomanAppendage *appendage3=0, TechnomanAppendage *appendage4=0,
        TechnomanAppendage *appendage5=0, TechnomanAppendage *appendage6=0, TechnomanAppendage *appendage7=0, TechnomanAppendage *appendage8=0,
        QGraphicsPixmapItem *selectorItem=0, QGraphicsPixmapItem *attachmentItem=0,
        QGraphicsPixmapItem *itemI=0, QGraphicsPixmapItem *itemII=0, QGraphicsPixmapItem *itemIII=0, QGraphicsPixmapItem *itemIV=0,
        double *x=0, double *y=0, double *z=0, double *angle=0,
        double *velocity=0, double *velMax=0, double *acceleration=0, double *rotation=0, double *magnability=0, double *life=0, double *collisionZone=0, double *power=0, double *chocResist=0,
        QWidget *parent=0
    );
    ~TechnomanAbstractWheel();
    QGraphicsPixmapItem *m_wheel;
    QGraphicsPixmapItem *m_selectorItem;
    QGraphicsPixmapItem *m_attachmentItem;
    QGraphicsPixmapItem *m_itemI;
    QGraphicsPixmapItem *m_itemII;
    QGraphicsPixmapItem *m_itemIII;
    QGraphicsPixmapItem *m_itemIV;

    QWidget *m_parent;
    QString *m_name;
    TechnomanCore *m_core;
    TechnomanBody *m_body;
    TechnomanFoot *m_foot;
    TechnomanShield *m_shield;
    TechnomanAppendage *m_appendage1;
    TechnomanAppendage *m_appendage2;
    TechnomanAppendage *m_appendage3;
    TechnomanAppendage *m_appendage4;
    TechnomanAppendage *m_appendage5;
    TechnomanAppendage *m_appendage6;
    TechnomanAppendage *m_appendage7;
    TechnomanAppendage *m_appendage8;
    double *m_x;
    double *m_y;
    double *m_z;
    double *m_angle;
    double *m_velocity;
    double *m_velMax;
    double *m_acceleration;
    double *m_rotation;
    double *m_magnability;
    double *m_life;
    double *m_collisionZone;
    double *m_power;
    double *m_chocResist;
    QList<QList<QPixmap *> *> *m_pixAnimList;
    QList<QString *> *m_nameAnimList;
    QList<double *> *m_animDurationList;

protected:
    //    QWidget *m_parent;
//    QString *m_name;
//    TechnomanCore *m_core;
//    TechnomanBody *m_body;
//    TechnomanFoot *m_foot;
//    TechnomanShield *m_shield;
//    TechnomanAppendage *m_appendage1;
//    TechnomanAppendage *m_appendage2;
//    TechnomanAppendage *m_appendage3;
//    TechnomanAppendage *m_appendage4;
//    TechnomanAppendage *m_appendage5;
//    TechnomanAppendage *m_appendage6;
//    TechnomanAppendage *m_appendage7;
//    TechnomanAppendage *m_appendage8;
//    double *m_x;
//    double *m_y;
//    double *m_z;
//    double *m_angle;
//    double *m_velocity;
//    double *m_velMax;
//    double *m_acceleration;
//    double *m_rotation;
//    double *m_magnability;



public slots:
    void setParent(QWidget *parent);
    void setName(QString *name);
    void setWheel(QGraphicsPixmapItem *item);
    void setSelector(QGraphicsPixmapItem *item);
    void setAttachment(QGraphicsPixmapItem *item);
    void setItemI(QGraphicsPixmapItem *item);
    void setItemII(QGraphicsPixmapItem *item);
    void setItemIII(QGraphicsPixmapItem *item);
    void setItemIV(QGraphicsPixmapItem *item);
    void setX(double *x);
    void setY(double *y);
    void setZ(double *z);
    void setAngle(double *angle);
    void setVelocity(double *velocity);
    void setVelMax(double *velMax);
    void setAcceleration(double *acceleration);
    void setRotation(double *rotation);
    void setMagnability(double *magnability);
    void setLife(double *life);
    void setCollideZone(double *collisionZone);
    void setPower(double *power);
    void setChocResist(double *chocResist);
    void setPixAnimList(QList<QList<QPixmap *> *> *pixAnimList);
    void changePixAnimAt(int id, QList<QPixmap *> *pixAnimList);
    void setNameAnimList(QList<QString *> *nameAnimList);
    void setDurationAnimList(QList<double *> *animDurationList);

    //void parent();
    QString name();
    double x();
    double y();
    double angle();
    double velocity();
    double velMax();
    double acceleration();
    double rotation();
    double magnability();
    double life();
    double collisionZone();
    double power();
    double chocResist();
    void wheel();
    void selector();
    void attachment();
    void itemI();
    void itemII();
    void itemIII();
    void itemIV();
    void playAnim(int *i);

signals:
    void graphicsWheel(QGraphicsPixmapItem *);
    void graphicsSelector(QGraphicsPixmapItem *);
    void graphicsAttachment(QGraphicsPixmapItem *);
    void graphicsItemI(QGraphicsPixmapItem *);
    void graphicsItemII(QGraphicsPixmapItem *);
    void graphicsItemIII(QGraphicsPixmapItem *);
    void graphicsItemIV(QGraphicsPixmapItem *);
    //void widgetParent(QWidget *);
};

#endif // TECHNOMANABSTRACTWHEEL_H
