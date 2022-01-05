#ifndef TICHARACTERMTD_H
#define TICHARACTERMTD_H

#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QWidget>

#include <QtGui>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStandardItemModel>
#include <QPushButton>

#include <QTimer>
#include <QDateTimeEdit>

#include <QKeyEvent>
#include <QMouseEvent>

class TiCharacterMTD : public QWidget
{
    Q_OBJECT

    public:
        TiCharacterMTD(QWidget *parent = nullptr);
        ~TiCharacterMTD();

    public slots:
        /**** GETTERS ****/
        QString getName();
        QPointF getPosition();
        int getResources();
        QString getOrientation();
        bool isAlive();
        QPoint giveDamages();
        bool readyToHit();
        QString getOrder();
        TiCharacterMTD getTarget();


        /**** SETTERS ****/
        void takeDamages(int *dmg, int *fnt);
        void stopStanding();
        void giveOrder(QString *odr);
        void setTarget(TiCharacterMTD *trg);
        //void addElement(TiElement *element, QPoint *pos);
        //void moveElement(TiElement *element, QPoint *pos);
        //void removeElement(TiElement *element);
        //void sellElement(TiElement *element);

    protected :
        QString *name;
        QPointF *position;
        QString *orientation;
        bool *alive;
        int *level;
        int *life;
        int *cost;
        int *resources;
        int *damages;
        int *armor;
        int *range;
        int *move;
        int *affinity;
        int *dexterity;
        QTimer *standHit;
        bool *canHit;
        QString *order;
        TiCharacterMTD *target;
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
};

#endif // TICHARACTERMTD_H
