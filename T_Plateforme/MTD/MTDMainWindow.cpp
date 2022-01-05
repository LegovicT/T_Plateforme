#include "MTDMainWindow.h"

MTDMainWindow::MTDMainWindow(QWidget *parent) : QWidget(parent)
{
    setFocus();                                     //get the focus on this widget for KeyEvents
    setMouseTracking(true);                       //get the focus on this widget for MouseEvents
    setWindowTitle("MTD");
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
    m_graphicsTimer->setInterval(4);
    m_graphicsTimer->start();

    cliced = new QPointF(0.0, 0.0);
    moved = new QPointF(0.0, 0.0);
    released = new QPointF(0.0, 0.0);
    debugger = new QTextEdit("0000000000000000000000", this);

//    m_InitTimer->setInterval(16);
//    m_InitTimer->start();
//    if(onLine)
//    {
//        m_dataTimer->setInterval(4);
//    }
//    else
//    {
//        m_graphicsTimer->setInterval(16);
//    }
}

/*****************CONNECTIONS*******************/
{
    connect(m_graphicsTimer, SIGNAL(timeout()), this, SLOT(GameLoop()));
//    connect(m_InitTimer, SIGNAL(timeout()), this, SLOT(GameInit()));
}

}
MTDMainWindow::~MTDMainWindow()
{

}


void MTDMainWindow::InitControles() //initialize game controllers
{
}
void MTDMainWindow::InitScene() //initialize the graphics scene and vue
{
    view = new QGraphicsView(this);                 //instance the view for graphics items
    scene = new QGraphicsScene;                     //instance the scene for graphics items
    worldScale = new double;                        //instance the scale of the world
    *worldScale = 1;

    camera = new QList<QGraphicsItem *>;            //instance the graphics items array
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);
    view->setGeometry(screenGeom.x(), screenGeom.y() + 100, screenGeom.width(), screenGeom.height());
    view->setScene(scene);
    scene->setSceneRect(view->rect().x(), view->rect().y(), view->rect().width() + 8000, view->rect().height() + 8000);
    scene->setSceneRect(view->rect().x() + 2, view->rect().y() + 2, view->rect().width() - 4, view->rect().height() - 4);
    scene->setBackgroundBrush(QBrush(QColor(0,10,60)));
    view->setMouseTracking(true);
    view->setFocus();
}
void MTDMainWindow::InitArena() //initialize arena moduls
{
    players = new QList<TiPlayerMTD *>;
    TiPlayerMTD *player1 = new TiPlayerMTD("p1");
    TiPlayerMTD *player2 = new TiPlayerMTD("p2");
    TiPlayerMTD *player3 = new TiPlayerMTD("p3");
    TiPlayerMTD *player4 = new TiPlayerMTD("p4");
    players->append(player1);
    players->append(player2);
    players->append(player3);
    players->append(player4);
}
void MTDMainWindow::InitStatsBar() //initialize the statsbar vue
{
}
void MTDMainWindow::InitSpellBar() //initialize the spellbar vue
{
}
void MTDMainWindow::InitModuls() //initialize player moduls
{
}
void MTDMainWindow::InitEffects() //initialize spell effects and attributes
{
}

void MTDMainWindow::keyPressEvent(QKeyEvent *event)
{/*
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
    else*/ if(event->key() == Qt::Key_Escape)
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
void MTDMainWindow::keyReleaseEvent(QKeyEvent *event)
{/*
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
    }*/
}
void MTDMainWindow::mousePressEvent(QMouseEvent *event)
{
    cliced->setX(event->x());
    cliced->setY(event->y());
}
void MTDMainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    released->setX(event->x());
    released->setY(event->y());
}
void MTDMainWindow::mouseMoveEvent(QMouseEvent *event)
{
    moved->setX(event->x());
    moved->setY(event->y());
}

void MTDMainWindow::GameLoop()
{
        setFocus();
        view->setMouseTracking(true);
        view->setFocus();


    /****Debugger****/
    {
        debugger->setPlainText("pressed: "+QString().number(cliced->x())+"/ "+QString().number(cliced->y())+"released: "+QString().number(released->x())+"/ "+QString().number(released->y())+"moved: "+QString().number(moved->x())+"/ "+QString().number(moved->y()));
        debugger->show();
    }

    /****Variables****/
    {
        *m_s = (QTime::currentTime().msec());
    }

    /****ResetTransform****/
    {
    }

    /****Effects****/
    {
    }

    /****Positions****/
    {
    }

    /****Collisions****/
    {
    }

    /****AddItems****/
    {
    }

     view->show();
    /****StartLoop****/
     m_graphicsTimer->start();
}
void MTDMainWindow::GameInit()
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
