#ifndef TIGAMEWINDOW_H
#define TIGAMEWINDOW_H

#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QWidget>
#include <QKeyEvent>

#include <QtGui>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStandardItemModel>
#include <QPushButton>

#include <QTimer>
#include <QDateTimeEdit>

#include "TiCharacter.h"
#include "TiPlayer.h"
#include "TiArena.h"
#include "TiDoodad.h"
#include "TiEffects.h"

class TiGameWindow : public QWidget
{
    Q_OBJECT

public:
    TiGameWindow(QWidget *parent = nullptr);
    ~TiGameWindow();

    QList<TiPlayer *> *playerList;
    QList<TiCharacter *> *characterList;
    TiArena *arena;
    QList<TiDoodad *> *doodadsList;
    QList<TiEffects *> *effectsList;

public slots:
/*******************INITIALIZATIONS*****************/
        void InitWorld();
        void InitArena();
        void InitPlayers();
        void InitLayers();
        void InitEffects();

/************************LOOPS**********************/
        void GameInit();
        void GameLoop();

/***********************SETTERS*********************/
        void setBackgroundColor(QColor color);
        void addPlayer(TiPlayer *newPlayer, int noPlayer=0);
        void setArena(TiArena *newArena);

/*********************EVENTS************************/
        void controlChanged(int idPlayer, QString cmd, bool valueB);
        void controlChanged(int idPlayer, QString cmd, qreal valueB);
        void controlChanged(int idPlayer, QString cmd, QPointF valueB);
        void animateEvent(QString type, int noPlayer);       // check the collisions and animations
        void animateEvent(TiDoodad *doodAnimated);          // check the collisions and animations
        void animateEvent(TiEffects *fxAnimated);           // check the collisions and animations
        void changeAnim(QString type, int noPlayer);         // update the animation
        void changeAnim(TiDoodad *doodAnimated);
        void changeAnim(TiEffects *fxAnimated);
        void changePos(QString type, int noPlayer);          // change the position in scene
        void changePos(TiDoodad *doodAnimated);
        void changePos(TiEffects *fxAnimated);
        void changePixmap(QString type, int noPlayer);       // change the image in scene
        void changePixmap(TiDoodad *doodAnimated);
        void changePixmap(TiEffects *fxAnimated);

/***************************************************/
/***************************************************/

private:
/**********************TIMERS***********************/
        QTimer *gameTimer;
        int *m_s;

/**********************WORLD************************/
        QGraphicsView *view;
        QGraphicsScene *scene;
        QPointF *posO;
        QPointF *arenaGeo;
        double *worldScale;

        QList<QGraphicsItem *> *camera;
        QList<QGraphicsPixmapItem *> *pointerList;

/**********************ARENA************************/
        QGraphicsPixmapItem *background;
        QGraphicsPixmapItem *forground;
        QGraphicsPixmapItem *forgroundBox;

        QList<QGraphicsPixmapItem *> *doodadsPixList;
        QList<QGraphicsPixmapItem *> *doodadsBoxList;

/*********************PLAYERS***********************/
        QGraphicsPixmapItem *spriteO;
        QList<QPixmap *> *spriteSheetList;
        QList<QGraphicsPixmapItem *> *spriteList;
        QList<QGraphicsPixmapItem *> *hurtboxList;
        QList<QGraphicsPixmapItem *> *hitboxList;
        QList<QList<QList<QPixmap *> *> *> *playerSpriteList;
        QList<QList<QList<QPixmap *> *> *> *playerHitboxList;
        QList<QList<QList<QPixmap *> *> *> *playerHurtboxList;

/*********************LAYERS************************/
        //QList<TiLayers *> *layersList;

/*********************EFFECTS***********************/
        QList<QList<QList<QGraphicsPixmapItem *> *> *> *fxSpritePixListArena; //list->fx->Anim->frame
        QList<QList<QList<QGraphicsPixmapItem *> *> *> *fxHitboxPixListArena;
        QList<QList<QList<QGraphicsPixmapItem *> *> *> *fxSpritePixListPI;
        QList<QList<QList<QGraphicsPixmapItem *> *> *> *fxHitboxPixListPI; //list->fx->Anim->frame
        QList<QList<QList<QGraphicsPixmapItem *> *> *> *fxSpritePixListPII;
        QList<QList<QList<QGraphicsPixmapItem *> *> *> *fxHitboxPixListPII;

/**********************OTHERS***********************/
        QPushButton *test;
        int *counter;

signals:
        void loadingText(QString *txt);
};

#endif // TIGAMEWINDOW_H
