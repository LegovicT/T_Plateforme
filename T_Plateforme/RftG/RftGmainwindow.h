#ifndef RFTGMAINWINDOW_H
#define RFTGMAINWINDOW_H

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

#include "RftgSelectionMenu.h"
#include "TiGameWindow.h"
#include "TiCharacter.h"
#include "TiPlayer.h"
#include "TiArena.h"
#include "TiDoodad.h"
#include "TiEffects.h"

class RftgMainWindow : public QWidget
{
    Q_OBJECT

public:
    RftgMainWindow(QWidget *parent = nullptr);
    ~RftgMainWindow();

    QList<TiPlayer *> *playerList;
    QList<TiCharacter *> *characterList;
    QList<TiArena *> *arenaList;
    QList<TiEffects *> *effectsList;
    QList<TiDoodad *> *doodadsList;

    RftgSelectionMenu *selectMenu;
    TiGameWindow *gameWindow;
    QWidget *loader;
    QTextEdit *loadingText;

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);

public slots:
/*******************INITIALIZATIONS*****************/
        void InitArena();                           // Arenas Initialization
        void InitCharacters();                      // Characters Initialization
        void InitPlayers();                         // Players Initialization
        void InitLayers();                          // Layers Initialisation
        void InitEffects();                         // Effects Initialization

/************************LOOPS**********************/
        void GameInit();                            // Main Setup
        void GameLoop();                            // Main Loop
        void TextLoading(QString *text);             // Change the text value of loading

/***********************SETTERS*********************/
        void addPlayer(int idChar, int noPlayer=0);
        void addPlayer(TiPlayer *player, int noPlayer=0);
        void addPlayer(TiCharacter *character, int noPlayer=0);

/*********************EVENTS************************/
        void setControl(QString ctrl);                      // Pad Controler
        void controlChanged(QString cmd, bool valueB);      // Control Manager
        void controlChanged(QString cmd, qreal valueB);     // Control Manager
        void controlChanged(QString cmd, QPointF valueB);   // Control Manager

/***************************************************/
/***************************************************/

private:
        QPushButton *test;                          // Debuger ingame
        QTimer *timer;                              // Loop Timer

};

#endif // RFTGMAINWINDOW_H
