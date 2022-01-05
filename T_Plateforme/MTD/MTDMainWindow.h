#ifndef MTDMAINWINDOW_H
#define MTDMAINWINDOW_H

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

#include "TiPlayerMTD.h"


class MTDMainWindow : public QWidget
{
    Q_OBJECT

    public:
        MTDMainWindow(QWidget *parent = nullptr);
        ~MTDMainWindow();

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

protected:
        void keyPressEvent(QKeyEvent *);
        void keyReleaseEvent(QKeyEvent *);
        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);

    private:
    /**** TIMER ****/
        int *m_s;
        int *m_ms;
        QTimer *m_InitTimer;
        QTimer *m_graphicsTimer;
        QTimer *m_dataTimer;
        QDateTime *m_dateTime;
        QPointF *cliced;
        QPointF *moved;
        QPointF *released;
        QTextEdit *debugger;
        QGraphicsView *view;
        QGraphicsScene *scene;
        double *worldScale;
        QList<QGraphicsItem *> *camera;            //instance the graphics items array
        QList<TiPlayerMTD *> *players;
};
#endif // MTDMAINWINDOW_H
