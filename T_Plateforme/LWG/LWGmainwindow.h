#ifndef LWGMAINWINDOW_H
#define LWGMAINWINDOW_H

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
//#include <QMouseEvent>

//#include <QtNetwork>
//#include <QAbstractSocket>

/***** For 3D ******/
//#include <Qt3DCore>
//#include <Qt3DRender>
//#include <Qt3DInput>
//#include <Qt3DLogic>
//#include <Qt3DExtras>
//#include <Qt3DAnimation>
/*******************/
/******* LWG *******/
#include "TechnomanAbstractWheel.h"
/*******************/
//#include "TLWGWidget.h" //include the implemented openGl widget


class LWGMainWindow : public QWidget
{
    Q_OBJECT

    public:
        LWGMainWindow(QWidget *parent = nullptr);
        ~LWGMainWindow();

    public slots:
        void GameInit();
        void GameLoop();
/*******************INITIALIZATIONS*****************/
        void InitControles();
        void InitScene();
        void InitArena();
        void InitStatsBar();
        void InitSpellBar();
        void InitModuls();
        void InitEffects();
/***********************GETTERS*********************/
/***********************SETTERS*********************/
        void controlChanged(QString cmd, bool valueB);
        void setControl(QString ctrl);
        void controlChanged(int player, QString cmd, int value);
        void shot();
        QString isColliding(QPointF pos1, QPointF pos2, double recoil, double distX, double distY = 0);

protected:
        void keyPressEvent(QKeyEvent *);
        void keyReleaseEvent(QKeyEvent *);

    private:
        QGraphicsTextItem *Tconsole;
/******************Gestion du TEMPS********************/
        QDateTime *m_dateTime;
        QTimer *m_InitTimer;
        QTimer *m_graphicsTimer;
        QTimer *m_dataTimer;
        int *m_ms;
        int *m_s;

/******************Gestion des GRAPHISMES********************/
        QGraphicsView *view;
        QGraphicsScene *scene;
        QList<QGraphicsItem *> *camera;
        QPointF *posO;
        double *modulsScale;
        //Borders
        QGraphicsItem *ItemBorderLeft;
        QGraphicsItem *ItemBorderRight;
        QGraphicsItem *ItemBorderTop;
        QGraphicsItem *ItemBorderBot;
        QGraphicsItem *ItemCornerTopLeft;
        QGraphicsItem *ItemCornerTopRight;
        QGraphicsItem *ItemCornerBotLeft;
        QGraphicsItem *ItemCornerBotRight;

        QGraphicsItem *ItemPlate1;
        QGraphicsItem *ItemPlate2;
        QGraphicsItem *ItemPlate3;
        QGraphicsItem *ItemPlate4;
        QGraphicsItem *ItemPlate5;
        QGraphicsItem *ItemPlate6;
        QGraphicsItem *ItemCorner1;
        QGraphicsItem *ItemCorner2;
        QGraphicsItem *ItemCorner3;
        QGraphicsItem *ItemPad1;
        QGraphicsItem *ItemPad2;
        QGraphicsItem *pointer1;
        QGraphicsItem *pointer2;

/*****************Gestion des ITEMS**********************/
        //Map
//        QGraphicsItem *ItemWallTop;
//        QGraphicsItem *ItemWallBot;
//        QGraphicsItem *ItemWallLeft;
//        QGraphicsItem *ItemWallRight;
//        QGraphicsItem *ItemColide;
//        QGraphicsItem *ItemBole;

        QPixmap *item1;
        double *xItem1;
        double *yItem1;
        double *aItem1;
        double *speedItem1;
        double *movenessItem1;
        double *magnaItem1;
        QPixmap *item2;
        double *xItem2;
        double *yItem2;
        double *aItem2;
        double *speedItem2;
        double *movenessItem2;
        double *magnaItem2;
        QPixmap *item3;
        QPixmap *item4;

        QPointF *posI;
        QPointF *posII;
        QPointF *posIII;
        QPointF *posIV;
        QGraphicsItem *ItemWheelPI;
        QGraphicsItem *ItemSelectorPI;
        double *sizeWheelI;
        double *sizeSelectorI;
        QGraphicsItem *ItemWheelPII;
        QGraphicsItem *ItemSelectorPII;
        double *sizeWheelII;
        double *sizeSelectorII;
        QGraphicsItem *ItemWheelPIII;
        QGraphicsItem *ItemSelectorPIII;
        double *sizeWheelIII;
        double *sizeSelectorIII;
        QGraphicsItem *ItemWheelPIV;
        QGraphicsItem *ItemSelectorPIV;
        double *sizeWheelIV;
        double *sizeSelectorIV;

        /*LWG*/
        TechnomanAbstractWheel *wheelTest;

        //Effects
        double *fxFireCount;
        QGraphicsItem *ItemWheelPIdl1;
        QGraphicsItem *ItemWheelPIdl2;
        QGraphicsItem *ItemWheelPIdl3;
        QGraphicsItem *ItemWheelPIdl4;
        QGraphicsItem *ItemWheelPIdl5;
        QPointF *posIdl1;
        QPointF *posIdl2;
        QPointF *posIdl3;
        QPointF *posIdl4;
        QPointF *posIdl5;
        QPointF *posIdl6;
        QPointF *posIdl7;
        QPointF *posIdl8;
        QPointF *posIdl9;
        QPointF *posIdl10;

/******************Gestion des COMMANDES********************/
        //PI
        bool *upIsPressed;
        bool *downIsPressed;
        bool *leftIsPressed;
        bool *rightIsPressed;
        bool *aIsPressed;
        bool *bIsPressed;
        bool *cIsPressed;
        bool *dIsPressed;
        bool *fiIsPressed;
        bool *fiiIsPressed;
        bool *spaceIsPressed;
        bool *R1Value;
        bool *L1Value;
        double *xLValue;
        double *yLValue;
        double *xRValue;
        double *yRValue;
        double *R2Value;
        double *L2Value;
        //PII
        bool *pIIupIsPressed;
        bool *pIIdownIsPressed;
        bool *pIIleftIsPressed;
        bool *pIIrightIsPressed;
        bool *pIIaIsPressed;
        bool *pIIbIsPressed;
        bool *pIIcIsPressed;
        bool *pIIdIsPressed;
        bool *pIIspaceIsPressed;
};
#endif // LWGMAINWINDOW_H
