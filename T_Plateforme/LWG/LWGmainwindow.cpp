#include "LWGmainwindow.h"

LWGMainWindow::LWGMainWindow(QWidget *parent) : QWidget(parent)
{
    //TLWGWidget lwgWidget;
    //lwgWidget.show();

    setFocus();                                     //get the focus on this widget for KeyEvents
    //setMouseTracking(true);                       //get the focus on this widget for MouseEvents
    setWindowTitle("Light Wheels Game");
                                                    //resize the window throught the desktop window size
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);
    setGeometry(screenGeom);

/****************INITIALIZATIONS****************/
{
    InitControles();                                //initialize game controllers
    InitScene();                                    //initialize graphics scene and vue
    InitArena();                                    //initialize arena moduls
    InitStatsBar();                                 //initialize the statsbar vue
    InitSpellBar();                                 //initialize the spellbar vue
    InitModuls();                                   //initialize players graphics moduls
    InitEffects();                                  //initialize graphics effects and attributes
    view->show();                                   //show the rendering of the graphics view
}

/*********************TIMERS*********************/
{
    m_InitTimer = new QTimer;
    m_graphicsTimer = new QTimer;
    m_dataTimer = new QTimer;
    m_dateTime = new QDateTime;
    m_dateTime->setDate(QDate::currentDate());
    m_dateTime->setTime(QTime::currentTime());
    m_ms = new int;
    m_s = new int;
    *m_ms = 125;
    *m_s = 125;

    m_InitTimer->setInterval(16);
    m_InitTimer->start();
//    if(onLine)
//    {
//        m_dataTimer->setInterval(4);
//    }
//    else
//    {
        m_graphicsTimer->setInterval(16);
//    }
}

/*****************CONNECTIONS*******************/
{
    connect(m_graphicsTimer, SIGNAL(timeout()), this, SLOT(GameLoop()));
    connect(m_InitTimer, SIGNAL(timeout()), this, SLOT(GameInit()));
}

}
LWGMainWindow::~LWGMainWindow()
{

}


void LWGMainWindow::InitControles() //initialize game controllers
{
    //instance controles
        upIsPressed = new bool;
        downIsPressed = new bool;
        leftIsPressed = new bool;
        rightIsPressed = new bool;
        aIsPressed = new bool;
        bIsPressed = new bool;
        cIsPressed = new bool;
        dIsPressed = new bool;
        spaceIsPressed = new bool;
        fiIsPressed = new bool;
        fiiIsPressed = new bool;
        R1Value = new bool;
        L1Value = new bool;
        xLValue = new double;
        yLValue = new double;
        xRValue = new double;
        yRValue = new double;
        R2Value = new double;
        L2Value = new double;
        //pII
        pIIupIsPressed = new bool;
        pIIdownIsPressed = new bool;
        pIIleftIsPressed = new bool;
        pIIrightIsPressed = new bool;
        pIIaIsPressed = new bool;
        pIIbIsPressed = new bool;
        pIIcIsPressed = new bool;
        pIIdIsPressed = new bool;
        pIIspaceIsPressed = new bool;
    //controlles initialization
        *upIsPressed = false;
        *downIsPressed = false;
        *leftIsPressed = false;
        *rightIsPressed = false;
        *aIsPressed = false;
        *bIsPressed = false;
        *cIsPressed = false;
        *dIsPressed = false;
        *spaceIsPressed = false;
        *fiIsPressed = false;
        *fiiIsPressed = false;
        *R1Value = false;
        *L1Value = false;
        *xLValue = 0;
        *yLValue = 0;
        *xRValue = 0;
        *yRValue = 0;
        *R2Value = 0;
        *L2Value = 0;
        //pII
        *pIIupIsPressed = false;
        *pIIdownIsPressed = false;
        *pIIleftIsPressed = false;
        *pIIrightIsPressed = false;
        *pIIaIsPressed = false;
        *pIIbIsPressed = false;
        *pIIcIsPressed = false;
        *pIIdIsPressed = false;
        *pIIspaceIsPressed = false;
}
void LWGMainWindow::InitScene() //initialize the graphics scene and vue
{
    view = new QGraphicsView(this);                 //instance the view for graphics items
    scene = new QGraphicsScene;                     //instance the scene for graphics items
    camera = new QList<QGraphicsItem *>;            //instance the graphics items array
    posO = new QPointF;                             //instance the origine point of the graphics scene
    modulsScale = new double;
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);
    posO->setX(0);
    posO->setY(0);
    *modulsScale = 0.4;
    view->setGeometry(screenGeom);
    view->setScene(scene);
    scene->setSceneRect(view->rect().x(), view->rect().y(), view->rect().width() + 8000, view->rect().height() + 8000);
    scene->setSceneRect(view->rect().x() + 2, view->rect().y() + 2, view->rect().width() - 4, view->rect().height() - 4);
    scene->setBackgroundBrush(QBrush(QColor(0,10,60)));

    Tconsole = new QGraphicsTextItem();             //get the debugging output in console
    Tconsole->setPos(posO->x()+20, posO->y()+20);
    Tconsole->setTextWidth(10);
    Tconsole->setScale(2);
    Tconsole->setPlainText("YO Bitche neggew");
    Tconsole->setZValue(20);
    scene->addItem(Tconsole);
}
void LWGMainWindow::InitArena() //initialize arena moduls
{
    //Borders
        ItemBorderLeft = new QGraphicsPixmapItem();
        ItemBorderRight = new QGraphicsPixmapItem();
        ItemBorderTop = new QGraphicsPixmapItem();
        ItemBorderBot = new QGraphicsPixmapItem();
        ItemCornerTopLeft = new QGraphicsPixmapItem();
        ItemCornerTopRight = new QGraphicsPixmapItem();
        ItemCornerBotLeft = new QGraphicsPixmapItem();
        ItemCornerBotRight = new QGraphicsPixmapItem();

        ItemPlate1 = new QGraphicsPixmapItem();
        ItemPlate2 = new QGraphicsPixmapItem();
        ItemPlate3 = new QGraphicsPixmapItem();
        ItemPlate4 = new QGraphicsPixmapItem();
        ItemPlate5 = new QGraphicsPixmapItem();
        ItemPlate6 = new QGraphicsPixmapItem();
        ItemCorner1 = new QGraphicsPixmapItem();
        ItemCorner2 = new QGraphicsPixmapItem();
        ItemCorner3 = new QGraphicsPixmapItem();
        ItemPad1 = new QGraphicsPixmapItem();
        ItemPad2 = new QGraphicsPixmapItem();
        pointer1 = new QGraphicsPixmapItem();
        pointer2 = new QGraphicsPixmapItem();

        ItemBorderTop = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanMetalPlateItem.png")); //(202,1056)
        ItemBorderTop->setPos(posO->x() + scene->sceneRect().width() / 2 - 150, posO->y() - 600);
        ItemBorderTop->setScale(2);
        ItemBorderTop->setZValue(1);
        ItemBorderTop->setTransformOriginPoint(202 * 0.5, 1056 * 0.5);
        ItemBorderTop->setRotation(90);
        ItemBorderTop->setOpacity(1);
        ItemBorderLeft = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanMetalPlateItem.png")); //(202,1056)
        ItemBorderLeft->setPos(posO->x() - 150, posO->y() + scene->sceneRect().height() / 2 - 150);
        ItemBorderLeft->setScale(2);
        ItemBorderLeft->setZValue(1);
        ItemBorderLeft->setTransformOriginPoint(202 * 0.5, 1056 * 0.5);
        ItemBorderLeft->setRotation(0);
        ItemBorderLeft->setOpacity(1);
        ItemBorderRight = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanMetalPlateItem.png")); //(202,1056)
        ItemBorderRight->setPos(posO->x() + scene->sceneRect().width() - 50, posO->y() + scene->sceneRect().height() / 2 - 150);
        ItemBorderRight->setScale(2);
        ItemBorderRight->setZValue(1);
        ItemBorderRight->setTransformOriginPoint(202 * 0.5, 1056 * 0.5);
        ItemBorderRight->setRotation(180);
        ItemBorderRight->setOpacity(1);
        ItemBorderBot = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanMetalPlateItem.png")); //(202,1056)
        ItemBorderBot->setPos(posO->x() + scene->sceneRect().width() / 2 - 150, posO->y() + scene->sceneRect().height() - 500);
        ItemBorderBot->setScale(2);
        ItemBorderBot->setZValue(1);
        ItemBorderBot->setTransformOriginPoint(202 * 0.5, 1056 * 0.5);
        ItemBorderBot->setRotation(-90);
        ItemBorderBot->setOpacity(1);



        ItemPlate1 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanSemiMetalPlateItem.png")); //(200,600)
        ItemPlate1->setPos(posO->x() + 410, posO->y() + 10);
        ItemPlate1->setScale(0.5);
        ItemPlate1->setZValue(2);
        ItemPlate1->setTransformOriginPoint(200 * 0.5, 600 * 0.5);
        ItemPlate1->setRotation(90);
        ItemPlate1->setOpacity(1);
        ItemPlate2 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanSemiMetalPlateItem.png")); //(200,600)
        ItemPlate2->setPos(posO->x() + 710, posO->y() + 10);
        ItemPlate2->setScale(0.5);
        ItemPlate2->setZValue(2);
        ItemPlate2->setTransformOriginPoint(200 * 0.5, 600 * 0.5);
        ItemPlate2->setRotation(90);
        ItemPlate2->setOpacity(1);
        ItemPlate3 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanSemiMetalPlateItem.png")); //(200,600)
        ItemPlate3->setPos(posO->x() + 1010, posO->y() + 10);
        ItemPlate3->setScale(0.5);
        ItemPlate3->setZValue(2);
        ItemPlate3->setTransformOriginPoint(200 * 0.5, 600 * 0.5);
        ItemPlate3->setRotation(90);
        ItemPlate3->setOpacity(1);
        ItemPlate4 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanSemiMetalPlateItem.png")); //(200,600)
        ItemPlate4->setPos(posO->x() + 1310, posO->y() + 10);
        ItemPlate4->setScale(0.5);
        ItemPlate4->setZValue(2);
        ItemPlate4->setTransformOriginPoint(200 * 0.5, 600 * 0.5);
        ItemPlate4->setRotation(90);
        ItemPlate4->setOpacity(1);
        ItemPlate5 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanSemiMetalPlateItem.png")); //(200,600)
        ItemPlate5->setPos(posO->x() +1490, posO->y() + 230);
        ItemPlate5->setScale(0.5);
        ItemPlate5->setZValue(2);
        ItemPlate5->setTransformOriginPoint(200 * 0.5, 600 * 0.5);
        ItemPlate5->setRotation(180);
        ItemPlate5->setOpacity(1);
        ItemPlate6 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanSemiMetalPlateItem.png")); //(200,600)
        ItemPlate6->setPos(posO->x() + 1270, posO->y() + 410);
        ItemPlate6->setScale(0.5);
        ItemPlate6->setZValue(2);
        ItemPlate6->setTransformOriginPoint(200 * 0.5, 600 * 0.5);
        ItemPlate6->setRotation(270);
        ItemPlate6->setOpacity(1);
        ItemCorner1 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanMetalCornerItem.png")); //(200,600)
        ItemCorner1->setPos(posO->x() + 190, posO->y() + 90);
        ItemCorner1->setScale(0.5);
        ItemCorner1->setZValue(2);
        ItemCorner1->setTransformOriginPoint(200 * 0.5, 200 * 0.5);
        ItemCorner1->setRotation(0);
        ItemCorner1->setOpacity(1);
        ItemCorner2 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanMetalCornerItem.png")); //(200,600)
        ItemCorner2->setPos(posO->x() + 1240, posO->y() + 220);
        ItemCorner2->setScale(0.5);
        ItemCorner2->setZValue(2);
        ItemCorner2->setTransformOriginPoint(200 * 0.5, 200 * 0.5);
        ItemCorner2->setRotation(90);
        ItemCorner2->setOpacity(1);
        ItemPad1 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanPadItem.png")); //(200,200)
        ItemPad1->setPos(posO->x() + 1270, posO->y() + 500);
        ItemPad1->setScale(0.5);
        ItemPad1->setZValue(2);
        ItemPad1->setTransformOriginPoint(200 * 0.5, 200 * 0.5);
        ItemPad1->setRotation(270);
        ItemPad1->setOpacity(1);
        ItemPad2 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanPadItem.png")); //(200,200)
        ItemPad2->setPos(posO->x() + 1270, posO->y() + 600);
        ItemPad2->setScale(0.5);
        ItemPad2->setZValue(2);
        ItemPad2->setTransformOriginPoint(200 * 0.5, 200 * 0.5);
        ItemPad2->setRotation(270);
        ItemPad2->setOpacity(1);

        pointer1 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/pointer.png")); //(20,20)
        pointer1->setPos(posO->x() + 1650, posO->y() + 750);
        pointer1->setScale(0.5);
        pointer1->setZValue(10);
        pointer2 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/pointer.png")); //(20,20)
        pointer2->setPos(posO->x() + 240, posO->y() + 220);
        pointer2->setScale(0.5);
        pointer2->setZValue(10);



    //Walls
//        QGraphicsItem *ItemColide;
//        QGraphicsItem *ItemBole;
//        QGraphicsItem *ItemWallTop;
//        QGraphicsItem *ItemWallFront;
//        QGraphicsItem *ItemWallBack;
//        QGraphicsItem *ItemWallLeft;
//        QGraphicsItem *ItemWallRight;
//        ItemBorderTop = new QGraphicsPixmapItem();
//        ItemBorderBot = new QGraphicsPixmapItem();
//        ItemCornerTopLeft = new QGraphicsPixmapItem();
//        ItemCornerTopRight = new QGraphicsPixmapItem();
//        ItemCornerBotLeft = new QGraphicsPixmapItem();
//        ItemCornerBotRight = new QGraphicsPixmapItem();
}
void LWGMainWindow::InitStatsBar() //initialize the statsbar vue
{

}
void LWGMainWindow::InitSpellBar() //initialize the spellbar vue
{

}
void LWGMainWindow::InitModuls() //initialize player moduls
{
    //instance player I position points
        ItemWheelPI = new QGraphicsPixmapItem();        //instance the first player wheel pixmap item
        ItemSelectorPI = new QGraphicsPixmapItem();     //instance the first player selector pixmap item
        sizeWheelI = new double;
        sizeSelectorI = new double;
        posI = new QPointF;
        aItem1 = new double;
        speedItem1 = new double;
        movenessItem1 = new double;
        magnaItem1 = new double;
        *speedItem1 = 0.04;
        *movenessItem1 = 0;
        *aItem1 = 2 * 3.14159265359;
        *magnaItem1 = (2 * 3.14159265359 / 16 / 8); //8->12 = moins de magnabilité
    //instance player II position points
        ItemWheelPII = new QGraphicsPixmapItem();        //instance the second player wheel pixmap item
        ItemSelectorPII = new QGraphicsPixmapItem();     //instance the second player selector pixmap item
        sizeWheelII = new double;
        sizeSelectorII = new double;
        posII = new QPointF;
        aItem2 = new double;
        speedItem2 = new double;
        movenessItem2 = new double;
        magnaItem2 = new double;
        *speedItem2 = 0.08;
        *movenessItem2 = 0;
        *aItem2 = 2 * 3.14159265359;
        *magnaItem2 = (2 * 3.14159265359 / 16 / 8); //8->12 = moins de magnabilité
    //instance player III position points
        ItemWheelPIII = new QGraphicsPixmapItem();        //instance the third player wheel pixmap item
        ItemSelectorPIII = new QGraphicsPixmapItem();     //instance the third player selector pixmap item
        sizeWheelIII = new double;
        sizeSelectorIII = new double;
        posIII = new QPointF;
//        aItem3 = new double;
//        speedItem3 = new double;
//        movenessItem3 = new double;
//        magnaItem3 = new double;
//        *speedItem3 = 0.08;
//        *movenessItem3 = 0;
//        *aItem3 = 2 * 3.14159265359;
//        *magnaItem3 = (2 * 3.14159265359 / 16 / 8); //8->12 = moins de magnabilité
    //instance player IV position points
        ItemWheelPIV = new QGraphicsPixmapItem();        //instance the fourth player wheel pixmap item
        ItemSelectorPIV = new QGraphicsPixmapItem();     //instance the fourth player selector pixmap item
        sizeWheelIV = new double;
        sizeSelectorIV = new double;
        posIV = new QPointF;
//        aItem4 = new double;
//        speedItem4 = new double;
//        movenessItem4 = new double;
//        magnaItem4 = new double;
//        *speedItem4 = 0.08;
//        *movenessItem4 = 0;
//        *aItem4 = 2 * 3.14159265359;
//        *magnaItem4 = (2 * 3.14159265359 / 16 / 8); //8->12 = moins de magnabilité



    //Player I
        posI->setX(posO->x() + 200);
        posI->setY(posO->y() + 200);
        *sizeWheelI = 160 * *modulsScale; //(111,109)
        *sizeSelectorI = 180 * *modulsScale; //(130,270)
        ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen.png")); //(134,134)*0.66=(88,88)
        ItemWheelPI->setPos(posI->x(), posI->y());
        ItemWheelPI->setScale(*modulsScale);
        ItemWheelPI->setZValue(10);
        ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        ItemSelectorPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameSelectorItemGreen.png"));
        ItemSelectorPI->setPos(posI->x(), posI->y());
        ItemSelectorPI->setRotation(180);
        ItemSelectorPI->setScale(*modulsScale);
        ItemSelectorPI->setZValue(9.4);
        ItemSelectorPI->setOpacity(0.4);
        ItemSelectorPI->setTransformOriginPoint(*sizeSelectorI * *modulsScale * 0.5, *sizeSelectorI * *modulsScale * 0.5);
    //Player II
        posII->setX(posO->x() + 800);
        posII->setY(posO->y() + 400);
        *sizeWheelII = 160 * *modulsScale;
        *sizeSelectorII = 180 * *modulsScale;
        ItemWheelPII = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapRed.png")); //(134,134)*0.66=(88,88)
        ItemWheelPII->setPos(posII->x(), posII->y());
        ItemWheelPII->setScale(*modulsScale);
        ItemWheelPII->setZValue(10);
        ItemWheelPII->setTransformOriginPoint(*sizeWheelII * *modulsScale * 0.5, *sizeWheelII * *modulsScale * 0.5);
        ItemSelectorPII = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameSelectorItemRed.png"));
        ItemSelectorPII->setPos(posII->x(), posII->y());
        ItemSelectorPII->setRotation(180);
        ItemSelectorPII->setScale(*modulsScale);
        ItemSelectorPII->setZValue(9.4);
        ItemSelectorPII->setOpacity(0.4);
        ItemSelectorPII->setTransformOriginPoint(*sizeSelectorII * *modulsScale * 0.5, *sizeSelectorII * *modulsScale * 0.5);
    //Player III
        posIII->setX(posO->x() + 800);
        posIII->setY(posO->y() + 600);
        *sizeWheelIII = 0.6;
        *sizeSelectorIII = 0.7;
        ItemWheelPIII = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapBlue.png")); //(134,134)*0.66=(88,88)
        ItemWheelPIII->setPos(posIII->x(), posIII->y());
        ItemWheelPIII->setScale(*modulsScale * 0.6);
        ItemWheelPIII->setZValue(10);
        ItemSelectorPIII = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameSelectorItemBlue.png"));
        ItemSelectorPIII->setPos(posIII->x(), posIII->y());
        ItemSelectorPIII->setRotation(180);
        ItemSelectorPIII->setScale(*modulsScale * 0.7);
        ItemSelectorPIII->setZValue(9.4);
        ItemSelectorPIII->setOpacity(0.4);
    //Player IV
        posIV->setX(posO->x() + 800);
        posIV->setY(posO->y() + 800);
        *sizeWheelIV = 0.6;
        *sizeSelectorIV = 0.7;
        ItemWheelPIV = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapYellow.png")); //(134,134)*0.66=(88,88)
        ItemWheelPIV->setPos(posIV->x(), posIV->y());
        ItemWheelPIV->setScale(*modulsScale * 0.6);
        ItemWheelPIV->setZValue(10);
        ItemSelectorPIV = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameSelectorItemYellow.png"));
        ItemSelectorPIV->setPos(posIV->x(), posIV->y());
        ItemSelectorPIV->setRotation(180);
        ItemSelectorPIV->setScale(*modulsScale * 0.7);
        ItemSelectorPIV->setZValue(9.4);
        ItemSelectorPIV->setOpacity(0.4);

    //test AbstractWheel
        //wheelTest = new TechnomanAbstractWheel(new QString("WheelPlayerI"));

}
void LWGMainWindow::InitEffects() //initialize spell effects and attributes
{
    fxFireCount = new double;
    *fxFireCount = 0;

    posIdl1 = new QPointF;
    posIdl2 = new QPointF;
    posIdl3 = new QPointF;
    posIdl4 = new QPointF;
    posIdl5 = new QPointF;
    posIdl6 = new QPointF;
    posIdl7 = new QPointF;
    posIdl8 = new QPointF;
    posIdl9 = new QPointF;
    posIdl10 = new QPointF;
    *posIdl1 = *posI;
    *posIdl2 = *posI;
    *posIdl3 = *posI;
    *posIdl4 = *posI;
    *posIdl5 = *posI;
    *posIdl6 = *posI;
    *posIdl7 = *posI;
    *posIdl8 = *posI;
    *posIdl9 = *posI;
    *posIdl10 = *posI;
    ItemWheelPIdl1 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen01.png")); //(134,134)*0.66=(88,88)
    ItemWheelPIdl1->setPos(posI->x(), posI->y());
    ItemWheelPIdl1->setScale(*modulsScale);
    ItemWheelPIdl1->setZValue(9.9);
    ItemWheelPIdl1->setOpacity(0.8);
    ItemWheelPIdl1->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
    ItemWheelPIdl2 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen02.png")); //(134,134)*0.66=(88,88)
    ItemWheelPIdl2->setPos(posI->x(), posI->y());
    ItemWheelPIdl2->setScale(*modulsScale);
    ItemWheelPIdl2->setZValue(9.8);
    ItemWheelPIdl2->setOpacity(0.6);
    ItemWheelPIdl2->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
    ItemWheelPIdl3 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen03.png")); //(134,134)*0.66=(88,88)
    ItemWheelPIdl3->setPos(posI->x(), posI->y());
    ItemWheelPIdl3->setScale(*modulsScale);
    ItemWheelPIdl3->setZValue(9.7);
    ItemWheelPIdl3->setOpacity(0.4);
    ItemWheelPIdl3->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
    ItemWheelPIdl4 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen04.png")); //(134,134)*0.66=(88,88)
    ItemWheelPIdl4->setPos(posI->x(), posI->y());
    ItemWheelPIdl4->setScale(*modulsScale);
    ItemWheelPIdl4->setZValue(9.6);
    ItemWheelPIdl4->setOpacity(0.25);
    ItemWheelPIdl4->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
    ItemWheelPIdl5 = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen05.png")); //(134,134)*0.66=(88,88)
    ItemWheelPIdl5->setPos(posI->x(), posI->y());
    ItemWheelPIdl5->setScale(*modulsScale);
    ItemWheelPIdl5->setZValue(9.5);
    ItemWheelPIdl5->setOpacity(0.1);
    ItemWheelPIdl5->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
}


void LWGMainWindow::GameLoop()
{
        setFocus();

    /****Variables****/
    {
        *m_s = (QTime::currentTime().msec());
        //pI
//        if(*xLValue == 0.01){*xLValue = 0;}
//        if(*R2Value == 0.01){*yRValue = 0;}
//        *m_s = (QTime::currentTime().msec());
//        if(*aIsPressed){*speedItem1 = 0.04;}else{*speedItem1 = 0.03;}
//        *aItem1 = (*aItem1 - *magnaItem1 * *xLValue / 100);
//        *movenessItem1 += (*R2Value - *L2Value) * *speedItem1;
//        *movenessItem1 *= 0.98;
        if(*aIsPressed){*speedItem1 = 0.04;}else{*speedItem1 = 0.03;}
        if(*leftIsPressed && !*rightIsPressed){*aItem1 = (*aItem1 + *magnaItem1 * 100 / 100);}
        else if(!*leftIsPressed && *rightIsPressed){*aItem1 = (*aItem1 - *magnaItem1 * 100 / 100);}
        if(*upIsPressed && !*downIsPressed){*movenessItem1 += 100 * *speedItem1;}
        else if(!*upIsPressed && *downIsPressed){*movenessItem1 -= 100 * *speedItem1;}
        *movenessItem1 *= 0.98;
        //pII
        if(*pIIaIsPressed){*speedItem2 = 0.04;}else{*speedItem2 = 0.03;}
        if(*pIIleftIsPressed && !*pIIrightIsPressed){*aItem2 = (*aItem2 + *magnaItem2 * 100 / 100);}
        else if(!*pIIleftIsPressed && *pIIrightIsPressed){*aItem2 = (*aItem2 - *magnaItem2 * 100 / 100);}
        if(*pIIupIsPressed && !*pIIdownIsPressed){*movenessItem2 += 100 * *speedItem2;}
        else if(!*pIIupIsPressed && *pIIdownIsPressed){*movenessItem2 -= 100 * *speedItem2;}
        *movenessItem2 *= 0.98;
    }

    /****ResetTransform****/
    {
        //pI
        ItemWheelPI->resetTransform();
        ItemSelectorPI->resetTransform();
        scene->removeItem(ItemWheelPI);
        scene->removeItem(ItemSelectorPI);

        *posIdl10 = *posIdl9;
        *posIdl9 = *posIdl8;
        *posIdl8 = *posIdl7;
        *posIdl7 = *posIdl6;
        *posIdl6 = *posIdl5;
        *posIdl5 = *posIdl4;
        *posIdl4 = *posIdl3;
        *posIdl3 = *posIdl2;
        *posIdl2 = *posIdl1;
        *posIdl1 = *posI;
        ItemWheelPIdl1->resetTransform();
        ItemWheelPIdl2->resetTransform();
        ItemWheelPIdl3->resetTransform();
        ItemWheelPIdl4->resetTransform();
        ItemWheelPIdl5->resetTransform();
        scene->removeItem(ItemWheelPIdl1);
        scene->removeItem(ItemWheelPIdl2);
        scene->removeItem(ItemWheelPIdl3);
        scene->removeItem(ItemWheelPIdl4);
        scene->removeItem(ItemWheelPIdl5);

        //pII
        ItemWheelPII->resetTransform();
        ItemSelectorPII->resetTransform();
        scene->removeItem(ItemWheelPII);
        scene->removeItem(ItemSelectorPII);

//        *posIdl10 = *posIdl9;
//        *posIdl9 = *posIdl8;
//        *posIdl8 = *posIdl7;
//        *posIdl7 = *posIdl6;
//        *posIdl6 = *posIdl5;
//        *posIdl5 = *posIdl4;
//        *posIdl4 = *posIdl3;
//        *posIdl3 = *posIdl2;
//        *posIdl2 = *posIdl1;
//        *posIdl1 = *posI;
//        ItemWheelPIdl1->resetTransform();
//        ItemWheelPIdl2->resetTransform();
//        ItemWheelPIdl3->resetTransform();
//        ItemWheelPIdl4->resetTransform();
//        ItemWheelPIdl5->resetTransform();
//        scene->removeItem(ItemWheelPIdl1);
//        scene->removeItem(ItemWheelPIdl2);
//        scene->removeItem(ItemWheelPIdl3);
//        scene->removeItem(ItemWheelPIdl4);
//        scene->removeItem(ItemWheelPIdl5);
    }

    /****Effects****/
    {
        if(*cIsPressed && *fxFireCount < 41)
        {
            *fxFireCount += 0.2;
        }
        else if(!*cIsPressed && *fxFireCount > 0)
        {
            *fxFireCount -= 0.1;
        }

        if(*fxFireCount < 9 && *fxFireCount > 0)
        {
            scene->removeItem(ItemWheelPI);
            ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen.png")); //(134,134)*0.66=(88,88)
            ItemWheelPI->setScale(*modulsScale);
            ItemWheelPI->setZValue(10);
            ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        }
        else if(*fxFireCount >= 9 && *fxFireCount < 14)
        {
            scene->removeItem(ItemWheelPI);
            ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen01.png")); //(134,134)*0.66=(88,88)
            ItemWheelPI->setScale(*modulsScale);
            ItemWheelPI->setZValue(10);
            ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        }
        else if(*fxFireCount >= 14 && *fxFireCount < 18)
        {
            scene->removeItem(ItemWheelPI);
            ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen02.png")); //(134,134)*0.66=(88,88)
            ItemWheelPI->setScale(*modulsScale);
            ItemWheelPI->setZValue(10);
            ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        }
        else if(*fxFireCount >= 18 && *fxFireCount < 23)
        {
            scene->removeItem(ItemWheelPI);
            ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen03.png")); //(134,134)*0.66=(88,88)
            ItemWheelPI->setScale(*modulsScale);
            ItemWheelPI->setZValue(10);
            ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        }
        else if(*fxFireCount >= 23 && *fxFireCount < 27)
        {
            scene->removeItem(ItemWheelPI);
            ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen04.png")); //(134,134)*0.66=(88,88)
            ItemWheelPI->setScale(*modulsScale);
            ItemWheelPI->setZValue(10);
            ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        }
        else if(*fxFireCount >= 27 && *fxFireCount < 32)
        {
            scene->removeItem(ItemWheelPI);
            ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen05.png")); //(134,134)*0.66=(88,88)
            ItemWheelPI->setScale(*modulsScale);
            ItemWheelPI->setZValue(10);
            ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        }
        else if(*fxFireCount >= 32)
        {
            scene->removeItem(ItemWheelPI);
            ItemWheelPI = scene->addPixmap(QPixmap("../T_Plateforme/SRC/LWG/TechnomanLightWheelsGameTrapGreen06.png")); //(134,134)*0.66=(88,88)
            ItemWheelPI->setScale(*modulsScale);
            ItemWheelPI->setZValue(10);
            ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        }
        else
        {

        }
    }

    /****Positions****/
    {
        //pI
        posI->setX(posI->x() - *speedItem1 * *movenessItem1 * cos(*aItem1));
        posI->setY(posI->y() - *speedItem1 * *movenessItem1 * cos(*aItem1 + 3.14159265359 / 2));

        ItemWheelPI->setPos(QPointF(posI->x() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posI->y() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
        ItemWheelPI->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        ItemWheelPI->setRotation(360 * *m_s / 500);

        ItemSelectorPI->setPos(QPointF(posI->x() + *sizeSelectorI * *modulsScale * cos(*aItem1 + (2 * 3.14159265359) + (3.14159265359 / 4)), posI->y() - *sizeSelectorI * *modulsScale * cos(*aItem1 - (2 * 3.14159265359) - (3.14159265359 / 4))));
        ItemSelectorPI->setTransformOriginPoint(*sizeSelectorI * *modulsScale * 0.5, *sizeSelectorI * *modulsScale * 0.5);
        ItemSelectorPI->setRotation(360 * *aItem1 / - 2 / 3.14159265359 + 90);

        //pII
        posII->setX(posII->x() - *speedItem2 * *movenessItem2 * cos(*aItem2));
        posII->setY(posII->y() - *speedItem2 * *movenessItem2 * cos(*aItem2 + 3.14159265359 / 2));

        ItemWheelPII->setPos(QPointF(posII->x() - *sizeWheelII * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posII->y() - *sizeWheelII * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
        ItemWheelPII->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
        ItemWheelPII->setRotation(360 * *m_s / 500);

        ItemSelectorPII->setPos(QPointF(posII->x() + *sizeSelectorII * *modulsScale * cos(*aItem2 + (2 * 3.14159265359) + (3.14159265359 / 4)), posII->y() - *sizeSelectorII * *modulsScale * cos(*aItem2 - (2 * 3.14159265359) - (3.14159265359 / 4))));
        ItemSelectorPII->setTransformOriginPoint(*sizeSelectorII * *modulsScale * 0.5, *sizeSelectorII * *modulsScale * 0.5);
        ItemSelectorPII->setRotation(360 * *aItem2 / - 2 / 3.14159265359 + 90);
    }

    /****Collisions****/
    {
        // Players collisions
            //PI colides others
            if(isColliding(*posI, *posII, 1, 20) != "") /**PI & PII**/
            {
                QString decal = isColliding(*posI, *posII, 1, 20);
                QList<QString> decalList = decal.split(","); //decalList[0] = x, decalList[1] = y
                posI->setX(posI->x() + decalList[0].toDouble());
                posI->setY(posI->y() + decalList[1].toDouble());
                Tconsole->setPlainText("Colide" + decal);
            }
            if(isColliding(*posI, *posIII, 1.2, 20) != "") /**PI & PIII**/
            {
                QString decal = isColliding(*posI, *posIII, 1.2, 20);
                QList<QString> decalList = decal.split(","); //decalList[0] = x, decalList[1] = y
                posI->setX(posI->x() + decalList[0].toDouble());
                posI->setY(posI->y() + decalList[1].toDouble());
                Tconsole->setPlainText("Colide" + decal);
            }
            if(isColliding(*posI, *posIV, 1.5, 20) != "") /**PI & PIV**/
            {
                QString decal = isColliding(*posI, *posIV, 1.5, 20);
                QList<QString> decalList = decal.split(","); //decalList[0] = x, decalList[1] = y
                posI->setX(posI->x() + decalList[0].toDouble());
                posI->setY(posI->y() + decalList[1].toDouble());
                Tconsole->setPlainText("Colide" + decal);
            }
            //PII colides others
            if(isColliding(*posII, *posI, 1.2, 20) != "") /**PII & PI**/
            {
                QString decal = isColliding(*posII, *posI, 1, 20);
                QList<QString> decalList = decal.split(","); //decalList[0] = x, decalList[1] = y
                posII->setX(posII->x() + decalList[0].toDouble());
                posII->setY(posII->y() + decalList[1].toDouble());
                Tconsole->setPlainText("Colide" + decal);
            }
            if(isColliding(*posII, *posIII, 1.4, 20) != "") /**PII & PIII**/
            {
                QString decal = isColliding(*posII, *posIII, 1.2, 20);
                QList<QString> decalList = decal.split(","); //decalList[0] = x, decalList[1] = y
                posII->setX(posII->x() + decalList[0].toDouble());
                posII->setY(posII->y() + decalList[1].toDouble());
                Tconsole->setPlainText("Colide" + decal);
            }
            if(isColliding(*posII, *posIV, 1.7, 20) != "") /**PII & PIV**/
            {
                QString decal = isColliding(*posII, *posIV, 1.5, 20);
                QList<QString> decalList = decal.split(","); //decalList[0] = x, decalList[1] = y
                posII->setX(posII->x() + decalList[0].toDouble());
                posII->setY(posII->y() + decalList[1].toDouble());
                Tconsole->setPlainText("Colide" + decal);
            }
        //PI Borders collisions and slides
            /**PI & inclined Top**/
            if(posI->y() < posO->y() + 100)
            {
                posI->setY(posI->y() + 0.05 * (posO->y() - posI->y() + 100));
            }
            /**PI & inclined Bot**/
            if(posI->y() > posO->y() + scene->height() * 0.95 - 100)
            {
                posI->setY(posI->y() - 0.05 * (posI->y() - posO->y() - scene->height() * 0.95 + 100));
            }
            /**PI & inclined Left**/
            if(posI->x() < posO->x() + 100)
            {
                posI->setX(posI->x() + 0.05 * (posO->x() - posI->x() + 100));
            }
            /**PI & inclined Right**/
            if(posI->x() > posO->x() + scene->width() * 0.95  - 100)
            {
                posI->setX(posI->x() - 0.05 * (posI->x() - posO->x() - scene->width() * 0.95 + 100));
            }
            /**PI & Border Top**/
            if(posI->y() < posO->y())
            {
                posI->setY(posI->y() + 25);
            }
            /**PI & Border Bot**/
            if(posI->y() > posO->y() + scene->height() * 0.98)
            {
                posI->setY(posI->y() - 25);
            }
            /**PI & Border Left**/
            if(posI->x() < posO->x())
            {
                posI->setX(posI->x() + 25);
            }
            /**PI & Border Right**/
            if(posI->x() > posO->x() + scene->width() * 0.98)
            {
                posI->setX(posI->x() - 25);
            }
            /**PI & plate1 up**/
            if(posI->x() > (posO->x() + 250) && posI->x() < (posO->x() + 1650) && posI->y() > (posO->y() + 200) && posI->y() < posO->y() + 250)
            {
                posI->setY(posI->y() - 25);
            }
            /**PI & plate1 down**/
            if(posI->x() > (posO->x() + 250) && posI->x() < (posO->x() + 1650) && posI->y() > (posO->y() + 250) && posI->y() < posO->y() + 320)
            {
                posI->setY(posI->y() + 25);
            }
            /**PI & plate1 left**/
            if(posI->x() > (posO->x() + 250) && posI->x() < (posO->x() + 300) && posI->y() > (posO->y() + 200) && posI->y() < posO->y() + 350)
            {
                posI->setX(posI->x() - 25);
            }
            /**PI & plate1 right**/
            if(posI->x() > (posO->x() + 1600) && posI->x() < (posO->x() + 1650) && posI->y() > (posO->y() + 200) && posI->y() < posO->y() + 700)
            {
                posI->setX(posI->x() + 25);
            }
            /**PI & plate2 left**/
            if(posI->x() > (posO->x() + 1600) && posI->x() < (posO->x() + 1550) && posI->y() > (posO->y() + 250) && posI->y() < posO->y() + 700)
            {
                posI->setX(posI->x() - 25);
            }
            /**PI & Pad1**/
            if(posI->x() > (posO->x() + 1200) && posI->x() < (posO->x() + 1350) && posI->y() > (posO->y() + 700) && posI->y() < posO->y() + 900)
            {
                posI->setX(posI->x() - 5);
            }
            /**PI & Pad2**/
            if(posI->x() > (posO->x() - 1240) && posI->x() < (posO->x() - 1340) && posI->y() > (posO->y() - 565) && posI->y() < posO->y() - 675)
            {
                posI->setY(posI->y() - 5);
            }
        //PII Borders collisions and slides
            /**PII & inclined Top**/
            if(posII->y() < posO->y() + 100)
            {
                posII->setY(posII->y() + 0.05 * (posO->y() - posII->y() + 100));
            }
            /**PII & inclined Bot**/
            if(posII->y() > posO->y() + scene->height() * 0.95 - 100)
            {
                posII->setY(posII->y() - 0.05 * (posII->y() - posO->y() - scene->height() * 0.95 + 100));
            }
            /**PII & inclined Left**/
            if(posII->x() < posO->x() + 100)
            {
                posII->setX(posII->x() + 0.05 * (posO->x() - posII->x() + 100));
            }
            /**PII & inclined Right**/
            if(posI->x() > posO->x() + scene->width() * 0.95  - 100)
            {
                posII->setX(posII->x() - 0.05 * (posII->x() - posO->x() - scene->width() * 0.95 + 100));
            }
            /**PII & Border Top**/
            if(posII->y() < posO->y())
            {
                posII->setY(posII->y() + 25);
            }
            /**PII & Border Bot**/
            if(posII->y() > posO->y() + scene->height() * 0.98)
            {
                posII->setY(posII->y() - 25);
            }
            /**PII & Border Left**/
            if(posII->x() < posO->x())
            {
                posII->setX(posII->x() + 25);
            }
            /**PII & Border Right**/
            if(posII->x() > posO->x() + scene->width() * 0.98)
            {
                posII->setX(posII->x() - 25);
            }
            /**PII & plate1 up**/
            if(posII->x() > (posO->x() + 250) && posII->x() < (posO->x() + 1330) && posII->y() > (posO->y() + 190) && posII->y() < posO->y() + 250)
            {
                posII->setY(posII->y() - 25);
            }
            /**PII & plate1 down**/
            if(posII->x() > (posO->x() + 250) && posII->x() < (posO->x() + 1330) && posII->y() > (posO->y() + 250) && posII->y() < posO->y() + 310)
            {
                posII->setY(posII->y() + 25);
            }
            /**PII & plate1 left**/
            if(posII->x() > (posO->x() + 250) && posII->x() < (posO->x() + 300) && posII->y() > (posO->y() + 190) && posII->y() < posO->y() + 310)
            {
                posII->setX(posII->x() - 25);
            }
            /**PII & plate1 right**/
            if(posII->x() > (posO->x() + 900) && posII->x() < (posO->x() + 1330) && posII->y() > (posO->y() + 190) && posII->y() < posO->y() + 310)
            {
                posII->setX(posII->x() + 25);
            }
            /**PII & plate2 right**/
            if(posII->x() > (posO->x() + 1270) && posII->x() < (posO->x() + 1330) && posII->y() > (posO->y() + 190) && posII->y() < posO->y() + 670)
            {
                posII->setX(posII->x() + 25);
            }
            /**PII & plate2 left**/
            if(posII->x() > (posO->x() + 1200) && posII->x() < (posO->x() + 1300) && posII->y() > (posO->y() + 190) && posII->y() < posO->y() + 670)
            {
                posII->setX(posII->x() - 25);
            }
            /**PII & Pad1**/
            if(posII->x() > (posO->x() + 1050) && posII->x() < (posO->x() + 1150) && posII->y() > (posO->y() + 665) && posII->y() < posO->y() + 765)
            {
                posII->setX(posII->x() - 5);
            }
            /**PII & Pad2**/
            if(posII->x() > (posO->x() + 950) && posII->x() < (posO->x() + 1050) && posII->y() > (posO->y() + 565) && posII->y() < posO->y() + 665)
            {
                posII->setY(posII->y() - 5);
            }
    }

    /****AddItems****/
    {

            ItemWheelPIdl1->setPos(QPointF(posIdl2->x() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posIdl2->y() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
            ItemWheelPIdl1->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
            ItemWheelPIdl1->setRotation(360 * *m_s / 500);
            scene->addItem(ItemWheelPIdl1);
            ItemWheelPIdl2->setPos(QPointF(posIdl4->x() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posIdl4->y() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
            ItemWheelPIdl2->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
            ItemWheelPIdl2->setRotation(360 * *m_s / 500);
            scene->addItem(ItemWheelPIdl2);
            ItemWheelPIdl3->setPos(QPointF(posIdl6->x() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posIdl6->y() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
            ItemWheelPIdl3->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
            ItemWheelPIdl3->setRotation(360 * *m_s / 500);
            scene->addItem(ItemWheelPIdl3);
            ItemWheelPIdl4->setPos(QPointF(posIdl8->x() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posIdl8->y() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
            ItemWheelPIdl4->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
            ItemWheelPIdl4->setRotation(360 * *m_s / 500);
            scene->addItem(ItemWheelPIdl4);
            ItemWheelPIdl5->setPos(QPointF(posIdl10->x() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posIdl10->y() - *sizeWheelI * *modulsScale * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
            ItemWheelPIdl5->setTransformOriginPoint(*sizeWheelI * *modulsScale * 0.5, *sizeWheelI * *modulsScale * 0.5);
            ItemWheelPIdl5->setRotation(360 * *m_s / 500);
            scene->addItem(ItemWheelPIdl5);

        Tconsole->setPlainText(*cIsPressed + QString::number(*fxFireCount));
        scene->addItem(ItemWheelPI);
        scene->addItem(ItemSelectorPI);
        scene->addItem(ItemWheelPII);
        scene->addItem(ItemSelectorPII);

//    scene->removeItem(Tconsole);
//    Tconsole->resetTransform();
//    Tconsole->setPlainText(QString::number(ItemWheelPI->x()) + "/" + QString::number(ItemWheelPI->y()));
//    scene->addItem(Tconsole);
    }

    /****StartLoop****/
        m_graphicsTimer->start();
}
void LWGMainWindow::GameInit()
{
        setFocus();
        if(*m_ms > 0)
        {
//            scene->setFocus();
            *m_ms = (*m_ms - 1);
//            *speed = 0.42;
            *m_s = (QTime::currentTime().msec());
//            ItemWheelPI->resetTransform();
//            scene->removeItem(ItemWheelPI);

            if(*m_ms > 54 && *m_ms < 125)
            {
//                posIV->setX(613 + 0.12 * (125 - *m_ms));
    //            *sXPos+=0.12;
            }
    //        if(*m_ms > 0 && *m_ms < 55)
            else
            {
//                posIV->setY(123 + 0.12 * (54 - *m_ms));
    //            *sYPos+=0.12;
            }

//            ItemWheelPI->setPos(QPointF(posIV->x() - 62 * cos((2 * 3.14159265359) * *m_s / 500 + (3.14159265359 / 4)), posIV->y() - 62 * cos((2 * 3.14159265359) * *m_s / 500 - (3.14159265359 / 4))));
//            ItemWheelPI->setRotation(360 * *m_s / 500);
//            scene->addItem(ItemWheelPI);
        }
        else
        {
//    //        if(onLine)
//    //        {
//    //            m_dataTimer->start();
//    //            GameLoopOnLine();
//    //        }
//    //        else
//    //        {
                m_graphicsTimer->start();
                GameLoop();
//    //        }
        }
}


void LWGMainWindow::setControl(QString ctrl)
{
    Tconsole->setPlainText(ctrl);
    scene->removeItem(Tconsole);
    scene->addItem(Tconsole);
    Tconsole->show();
    if(ctrl.left(2) == "LS")
    {
        QString ctrl1 = ctrl.replace("LS ", "");
        ctrl1 = ctrl1.replace("x:", "");
        ctrl1 = ctrl1.replace("y:", "");
        QList<QString> ctrlList = ctrl1.split(","); //crtlList[0] = xPos, crtlList[1] = yPos
        *xLValue = 2 * (ctrlList.at(0).toDouble() - 50);
        *yLValue = 2 * (ctrlList.at(1).toDouble() - 50);
        Tconsole->setPlainText("LSx" + QString::number(*xLValue) + "LSy" + QString::number(*yLValue));
    }
    else if(ctrl.left(2) == "RS")
    {
        QString ctrl1 = ctrl.replace("RS ", "");
        ctrl1 = ctrl1.replace("x:", "");
        ctrl1 = ctrl1.replace("y:", "");
        QList<QString> ctrlList = ctrl1.split(","); //crtlList[0] = xPos, crtlList[1] = yPos
        *xRValue = 2 * (ctrlList.at(0).toDouble() - 50);
        *yRValue = 2 * (ctrlList.at(1).toDouble() - 50);
        Tconsole->setPlainText("RSx" + QString::number(*xRValue) + "RSy" + QString::number(*yRValue));
    }
    else if(ctrl.left(1) == "X")
    {
        if(ctrl == "X Pushed")
        {
            Tconsole->setPlainText("X+");
            *cIsPressed = true;
        }
        else if(ctrl == "X Released")
        {
            Tconsole->setPlainText("X-");
            *cIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("X0");
        }
    }
    else if(ctrl.left(1) == "Y")
    {
        if(ctrl == "Y Pushed")
        {
            Tconsole->setPlainText("Y+");
            *dIsPressed = true;
            posI->setX(posI->x() -  150 * cos(*aItem1));
            posI->setY(posI->y() -  150 * cos(*aItem1 + 3.14159265359 / 2));
        }
        else if(ctrl == "Y Released")
        {
            Tconsole->setPlainText("Y-");
            *dIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Y0");
        }
    }
    else if(ctrl.left(1) == "A")
    {
        if(ctrl == "A Pushed")
        {
            Tconsole->setPlainText("A+");
            *aIsPressed = true;
        }
        else if(ctrl == "A Released")
        {
            Tconsole->setPlainText("A-");
            *aIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("A0");
        }
    }
    else if(ctrl.left(1) == "B")
    {
        if(ctrl == "B Pushed")
        {
            Tconsole->setPlainText("B+");
            *bIsPressed = true;
        }
        else if(ctrl == "B Released")
        {
            Tconsole->setPlainText("B-");
            *bIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("B0");
        }
    }
    else if(ctrl.left(2) == "Up")
    {
        if(ctrl == "Up Pushed")
        {
            Tconsole->setPlainText("Up+");
            *upIsPressed = true;
        }
        else if(ctrl == "Up Released")
        {
            Tconsole->setPlainText("Up-");
            *upIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Up0");
        }
    }
    else if(ctrl.left(4) == "Down")
    {
        if(ctrl == "Down Pushed")
        {
            Tconsole->setPlainText("Down+");
            *downIsPressed =true;
        }
        else if(ctrl == "Down Released")
        {
            Tconsole->setPlainText("Down-");
            *downIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Down0");
        }
    }
    else if(ctrl.left(5) == "Right")
    {
        if(ctrl == "Right Pushed")
        {
            Tconsole->setPlainText("Right+");
            *rightIsPressed =true;
        }
        else if(ctrl == "Right Released")
        {
            Tconsole->setPlainText("Right-");
            *rightIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Right0");
        }
    }
    else if(ctrl.left(4) == "Left")
    {
        if(ctrl == "Left Pushed")
        {
            Tconsole->setPlainText("Left+");
            *leftIsPressed =true;
        }
        else if(ctrl == "Left Released")
        {
            Tconsole->setPlainText("Left-");
            *leftIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Left0");
        }
    }
    else if(ctrl.left(5) == "Start")
    {
        if(ctrl == "Start Pushed")
        {
            Tconsole->setPlainText("Start+");
            //*startIsPressed =true;
            qApp->quit();
        }
        else if(ctrl == "Start Released")
        {
            Tconsole->setPlainText("Start-");
            //*startIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Start0");
        }
    }
    else if(ctrl.left(6) == "Select")
    {
        if(ctrl == "Select Pushed")
        {
            Tconsole->setPlainText("Select+");
            posI->setX(posO->x());
            posI->setY(posO->y());
        }
        else if(ctrl == "Select Released")
        {
            Tconsole->setPlainText("Select-");
        }
        else
        {
            Tconsole->setPlainText("Select0");
        }
    }
    else if(ctrl.left(2) == "L1")
    {
        if(ctrl == "L1 Pushed")
        {
            Tconsole->setPlainText("L1+");
            *L1Value =true;
        }
        else if(ctrl == "L1 Released")
        {
            Tconsole->setPlainText("L1-");
            *L1Value = false;
        }
        else
        {
            Tconsole->setPlainText("L10");
        }
    }
    else if(ctrl.left(2) == "L2")
    {
        QString ctrl1 = ctrl.replace("L2", "");
        if(ctrl1 == " Released")
        {
            *L2Value = 0;
        }
        else
        {
            ctrl1 = ctrl.replace(":", "");
            *L2Value = 100 * (ctrl1.toDouble());
        }
        Tconsole->setPlainText("L2" + QString::number(*L2Value));
    }
    else if(ctrl.left(2) == "L3")
    {
        if(ctrl == "L3 Pushed")
        {
            Tconsole->setPlainText("L3+");
            //*L3Value =true;
        }
        else if(ctrl == "L3 Released")
        {
            Tconsole->setPlainText("L3-");
            //*L3Value = false;
        }
        else
        {
            Tconsole->setPlainText("L30");
        }
    }
    else if(ctrl.left(2) == "R1")
    {
        if(ctrl == "R1 Pushed")
        {
            Tconsole->setPlainText("R1+");
            *R1Value =true;
        }
        else if(ctrl == "R1 Released")
        {
            Tconsole->setPlainText("R1-");
            *R1Value = false;
        }
        else
        {
            Tconsole->setPlainText("R10");
        }
    }
    else if(ctrl.left(2) == "R2")
    {
        QString ctrl1 = ctrl.replace("R2", "");
        if(ctrl1 == " Released")
        {
            *R2Value = 0;
        }
        else
        {
            ctrl1 = ctrl.replace(":", "");
            *R2Value = 100 * (ctrl1.toDouble());
        }
        Tconsole->setPlainText("R2" + QString::number(*R2Value));
    }
    else if(ctrl.left(2) == "R3")
    {
        if(ctrl == "R3 Pushed")
        {
            Tconsole->setPlainText("R3+");
            //*L3Value = true;
        }
        else if(ctrl == "R3 Released")
        {
            Tconsole->setPlainText("R3-");
            //*L3Value = false;
        }
        else
        {
            Tconsole->setPlainText("R30");
        }
    }
    else
    {

    }
}
void LWGMainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z)
    {
        controlChanged(QString("keyZ"), true);
    }
    else if(event->key() == Qt::Key_Q)
    {
        controlChanged(QString("keyQ"), true);
    }
    else if(event->key() == Qt::Key_D)
    {
        controlChanged(QString("keyD"), true);
    }
    else if(event->key() == Qt::Key_S)
    {
        controlChanged(QString("keyS"), true);
    }
    else if(event->key() == Qt::Key_O)
    {
        controlChanged(QString("keyO"), true);
    }
    else if(event->key() == Qt::Key_K)
    {
        controlChanged(QString("keyK"), true);
    }
    else if(event->key() == Qt::Key_L)
    {
        controlChanged(QString("keyL"), true);
    }
    else if(event->key() == Qt::Key_M)
    {
        controlChanged(QString("keyM"), true);
    }
    else if(event->key() == Qt::Key_Up)
    {
        controlChanged(QString("keyUp"), true);
    }
    else if(event->key() == Qt::Key_Down)
    {
        controlChanged(QString("keyDown"), true);
    }
    else if(event->key() == Qt::Key_Left)
    {
        controlChanged(QString("keyLeft"), true);
    }
    else if(event->key() == Qt::Key_Right)
    {
        controlChanged(QString("keyRight"), true);
    }
    else if(event->key() == Qt::Key_8)
    {
        controlChanged(QString("key8"), true);
    }
    else if(event->key() == Qt::Key_4)
    {
        controlChanged(QString("key4"), true);
    }
    else if(event->key() == Qt::Key_5)
    {
        controlChanged(QString("key5"), true);
    }
    else if(event->key() == Qt::Key_6)
    {
        controlChanged(QString("key6"), true);
    }
    else if(event->key() == Qt::Key_Escape)
    {
        qApp->quit();
    }
    else if(event->key() == Qt::Key_Space)
    {
    }
    else
    {
        qDebug()<< Qt::Key(event->key());
    }
}
void LWGMainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z)
    {
        controlChanged(QString("keyZ"), false);
    }
    else if(event->key() == Qt::Key_Q)
    {
        controlChanged(QString("keyQ"), false);
    }
    else if(event->key() == Qt::Key_D)
    {
        controlChanged(QString("keyD"), false);
    }
    else if(event->key() == Qt::Key_S)
    {
        controlChanged(QString("keyS"), false);
    }
    else if(event->key() == Qt::Key_O)
    {
        controlChanged(QString("keyO"), false);
    }
    else if(event->key() == Qt::Key_K)
    {
        controlChanged(QString("keyK"), false);
    }
    else if(event->key() == Qt::Key_L)
    {
        controlChanged(QString("keyL"), false);
    }
    else if(event->key() == Qt::Key_M)
    {
        controlChanged(QString("keyM"), false);
    }
    else if(event->key() == Qt::Key_Up)
    {
        controlChanged(QString("keyUp"), false);
    }
    else if(event->key() == Qt::Key_Down)
    {
        controlChanged(QString("keyDown"), false);
    }
    else if(event->key() == Qt::Key_Left)
    {
        controlChanged(QString("keyLeft"), false);
    }
    else if(event->key() == Qt::Key_Right)
    {
        controlChanged(QString("keyRight"), false);
    }
    else if(event->key() == Qt::Key_8)
    {
        controlChanged(QString("key8"), false);
    }
    else if(event->key() == Qt::Key_4)
    {
        controlChanged(QString("key4"), false);
    }
    else if(event->key() == Qt::Key_5)
    {
        controlChanged(QString("key5"), false);
    }
    else if(event->key() == Qt::Key_6)
    {
        controlChanged(QString("key6"), false);
    }
}
void LWGMainWindow::controlChanged(QString cmd, bool valueB)
{
    if(cmd.left(3) == "key")
    {
        cmd.replace(0,3,"");
        if(cmd=="Z"){cmd="Up"; *pIIupIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="Q"){cmd="Left"; *pIIleftIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="S"){cmd="Down"; *pIIdownIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="D"){cmd="Right"; *pIIrightIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="O"){cmd="Y"; *pIIdIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="K"){cmd="X"; *pIIcIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="L"){cmd="A"; *pIIaIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="M"){cmd="B"; *pIIbIsPressed=valueB; controlChanged(1, cmd, valueB);}
        else if(cmd=="Up"){cmd="Up"; *upIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else if(cmd=="Down"){cmd="Down"; *downIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else if(cmd=="Left"){cmd="Left"; *leftIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else if(cmd=="Right"){cmd="Right"; *rightIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else if(cmd=="8"){cmd="Y"; *dIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else if(cmd=="4"){cmd="X"; *cIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else if(cmd=="5"){cmd="A"; *aIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else if(cmd=="6"){cmd="B"; *bIsPressed=valueB; controlChanged(2, cmd, valueB);}
        else{cmd="";}
        //controlChanged(1, cmd, valueB);
    }
}
void LWGMainWindow::controlChanged(int player, QString cmd, int value)
{
    /*if(cmd == "Left")
    {
        *xLValue = 2 * value;
        *yLValue = 2 * value;
    }
    else if(cmd == "Right")
    {
        QString ctrl1 = ctrl.replace("RS ", "");
        ctrl1 = ctrl1.replace("x:", "");
        ctrl1 = ctrl1.replace("y:", "");
        QList<QString> ctrlList = ctrl1.split(","); //crtlList[0] = xPos, crtlList[1] = yPos
        *xRValue = 2 * (ctrlList.at(0).toDouble() - 50);
        *yRValue = 2 * (ctrlList.at(1).toDouble() - 50);
        Tconsole->setPlainText("RSx" + QString::number(*xRValue) + "RSy" + QString::number(*yRValue));
    }
    else if(ctrl.left(1) == "X")
    {
        if(ctrl == "X Pushed")
        {
            Tconsole->setPlainText("X+");
            *cIsPressed = true;
        }
        else if(ctrl == "X Released")
        {
            Tconsole->setPlainText("X-");
            *cIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("X0");
        }
    }
    else if(ctrl.left(1) == "Y")
    {
        if(ctrl == "Y Pushed")
        {
            Tconsole->setPlainText("Y+");
            *dIsPressed = true;
            posI->setX(posI->x() -  150 * cos(*aItem1));
            posI->setY(posI->y() -  150 * cos(*aItem1 + 3.14159265359 / 2));
        }
        else if(ctrl == "Y Released")
        {
            Tconsole->setPlainText("Y-");
            *dIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Y0");
        }
    }
    else if(ctrl.left(1) == "A")
    {
        if(ctrl == "A Pushed")
        {
            Tconsole->setPlainText("A+");
            *aIsPressed = true;
        }
        else if(ctrl == "A Released")
        {
            Tconsole->setPlainText("A-");
            *aIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("A0");
        }
    }
    else if(ctrl.left(1) == "B")
    {
        if(ctrl == "B Pushed")
        {
            Tconsole->setPlainText("B+");
            *bIsPressed = true;
        }
        else if(ctrl == "B Released")
        {
            Tconsole->setPlainText("B-");
            *bIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("B0");
        }
    }
    else if(ctrl.left(2) == "Up")
    {
        if(ctrl == "Up Pushed")
        {
            Tconsole->setPlainText("Up+");
            *upIsPressed = true;
        }
        else if(ctrl == "Up Released")
        {
            Tconsole->setPlainText("Up-");
            *upIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Up0");
        }
    }
    else if(ctrl.left(4) == "Down")
    {
        if(ctrl == "Down Pushed")
        {
            Tconsole->setPlainText("Down+");
            *downIsPressed =true;
        }
        else if(ctrl == "Down Released")
        {
            Tconsole->setPlainText("Down-");
            *downIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Down0");
        }
    }
    else if(ctrl.left(5) == "Right")
    {
        if(ctrl == "Right Pushed")
        {
            Tconsole->setPlainText("Right+");
            *rightIsPressed =true;
        }
        else if(ctrl == "Right Released")
        {
            Tconsole->setPlainText("Right-");
            *rightIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Right0");
        }
    }
    else if(ctrl.left(4) == "Left")
    {
        if(ctrl == "Left Pushed")
        {
            Tconsole->setPlainText("Left+");
            *leftIsPressed =true;
        }
        else if(ctrl == "Left Released")
        {
            Tconsole->setPlainText("Left-");
            *leftIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Left0");
        }
    }
    else if(ctrl.left(5) == "Start")
    {
        if(ctrl == "Start Pushed")
        {
            Tconsole->setPlainText("Start+");
            // *startIsPressed =true;
            qApp->quit();
        }
        else if(ctrl == "Start Released")
        {
            Tconsole->setPlainText("Start-");
            // *startIsPressed = false;
        }
        else
        {
            Tconsole->setPlainText("Start0");
        }
    }
    else if(ctrl.left(6) == "Select")
    {
        if(ctrl == "Select Pushed")
        {
            Tconsole->setPlainText("Select+");
            posI->setX(posO->x());
            posI->setY(posO->y());
        }
        else if(ctrl == "Select Released")
        {
            Tconsole->setPlainText("Select-");
        }
        else
        {
            Tconsole->setPlainText("Select0");
        }
    }
    else if(ctrl.left(2) == "L1")
    {
        if(ctrl == "L1 Pushed")
        {
            Tconsole->setPlainText("L1+");
            *L1Value =true;
        }
        else if(ctrl == "L1 Released")
        {
            Tconsole->setPlainText("L1-");
            *L1Value = false;
        }
        else
        {
            Tconsole->setPlainText("L10");
        }
    }
    else if(ctrl.left(2) == "L2")
    {
        QString ctrl1 = ctrl.replace("L2", "");
        if(ctrl1 == " Released")
        {
            *L2Value = 0;
        }
        else
        {
            ctrl1 = ctrl.replace(":", "");
            *L2Value = 100 * (ctrl1.toDouble());
        }
        Tconsole->setPlainText("L2" + QString::number(*L2Value));
    }
    else if(ctrl.left(2) == "L3")
    {
        if(ctrl == "L3 Pushed")
        {
            Tconsole->setPlainText("L3+");
            // *L3Value =true;
        }
        else if(ctrl == "L3 Released")
        {
            Tconsole->setPlainText("L3-");
            // *L3Value = false;
        }
        else
        {
            Tconsole->setPlainText("L30");
        }
    }
    else if(ctrl.left(2) == "R1")
    {
        if(ctrl == "R1 Pushed")
        {
            Tconsole->setPlainText("R1+");
            *R1Value =true;
        }
        else if(ctrl == "R1 Released")
        {
            Tconsole->setPlainText("R1-");
            *R1Value = false;
        }
        else
        {
            Tconsole->setPlainText("R10");
        }
    }
    else if(ctrl.left(2) == "R2")
    {
        QString ctrl1 = ctrl.replace("R2", "");
        if(ctrl1 == " Released")
        {
            *R2Value = 0;
        }
        else
        {
            ctrl1 = ctrl.replace(":", "");
            *R2Value = 100 * (ctrl1.toDouble());
        }
        Tconsole->setPlainText("R2" + QString::number(*R2Value));
    }
    else if(ctrl.left(2) == "R3")
    {
        if(ctrl == "R3 Pushed")
        {
            Tconsole->setPlainText("R3+");
            // *L3Value = true;
        }
        else if(ctrl == "R3 Released")
        {
            Tconsole->setPlainText("R3-");
            // *L3Value = false;
        }
        else
        {
            Tconsole->setPlainText("R30");
        }
    }
    else
    {

    }*/
}
QString LWGMainWindow::isColliding(QPointF pos1, QPointF pos2, double recoil, double distX, double distY)
{
    QString decale;
    decale = "";
    if(distY == NULL) //si distY n'est pas renseigné alors la distance de recule est la meme sur les deux axes x,y
    {
        if(((pos1.x() - pos2.x()) <= distX && (pos2.x() - pos1.x()) <= distX) && ((pos1.y() - pos2.y()) <= distX && (pos2.y() - pos1.y()) <= distX))
        {
            if(pos1.x() < pos2.x())
            {
                decale.append("-" + QString::number((distX * recoil + pos2.x() - pos1.x())) + ",");
            }
            else
            {
                decale.append(QString::number((distX * recoil + pos2.x() - pos1.x())) + ",");
            }
            if(pos1.y() < pos2.y())
            {
                decale.append("-" + QString::number((distX * recoil + pos2.y() - pos1.y())));
            }
            else
            {
                decale.append(QString::number((distX * recoil + pos2.y() - pos1.y())));
            }
        }
    }
    else
    {
        if(((pos1.x() - pos2.x()) <= distX && (pos2.x() - pos1.x()) <= distX) && ((pos1.y() - pos2.y()) <= distY && (pos2.y() - pos1.y()) <= distY))
        {
            if(pos1.x() < pos2.x())
            {
                decale.append("-" + QString::number((distX - pos2.x() + pos1.x()) * recoil) + ",");
            }
            else
            {
                decale.append(QString::number((distX - pos1.x() + pos2.x()) * recoil) + ",");
            }
            if(pos1.y() < pos2.y())
            {
                decale.append("-" + QString::number((distY - pos2.y() + pos1.y()) * recoil));
            }
            else
            {
                decale.append(QString::number((distY - pos1.y() + pos2.y()) * recoil));
            }
        }
    }
    return decale;
}
void LWGMainWindow::shot()
{

}
