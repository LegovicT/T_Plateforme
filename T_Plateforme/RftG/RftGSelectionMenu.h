#ifndef RFTGSELECTIONMENU_H
#define RFTGSELECTIONMENU_H

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

#include "TiPlayer.h"
#include "TiCharacter.h"
#include "TiArena.h"
#include "TiDoodad.h"
#include "TiEffects.h"

class RftgSelectionMenu : public QWidget
{
    Q_OBJECT

public:
    RftgSelectionMenu(QWidget *parent = nullptr);
    ~RftgSelectionMenu();

public slots:
    void addArena(TiArena *arena);
    void addCharacter(TiCharacter *character);
    void addPlayer(TiPlayer *player);
    void characterSelected(QString playerName, int idCharacter);
    void characterSelected(TiPlayer *player, TiCharacter *character);
    void arenaSelected(int idArena);
    void startLoop();
    void initSelection();
    void actionPlayer(int idPlayer, QString act);

    QString getSelections(); // return arenas id and characters ids by aviables players
    QString getCharacterSelected(QString playerName); // return character name selected by player
    int getArenaSelected(); // return arena id

public:

    QList<TiArena *> *arenaList;
    QList<TiCharacter *> *characterList;
    QList<TiPlayer *> *playerList;
    QList<int > *selectionList; // selected characters id
    int *selectionArena; // selected arena id

    QPushButton *startGameBtn;
    bool *readyPlayers;
    bool *readyArena;

private:
    QPushButton *test;
    //**TIMER**//
    QTimer *timer;
    int *counter;

    //**SELECTORS**//
    QGraphicsPixmapItem *arenaPixSelected;
    QPixmap *selectorPix;
    QPixmap *selectedPix;
    QList<QGraphicsPixmapItem *> *selectors;
    QList<QGraphicsPixmapItem *> *charactersPixSelected;

    //**SELECTION VIEWER**//
    QGraphicsPixmapItem *arenaSelection;
    QList<QGraphicsPixmapItem *> *charactersAnimSelection;
    QList<int *> *frameAnimSelection;
    QList<QPushButton *> *charactersNameSelection;
    QList<QTextEdit *> *charactersDescriptionSelection;
    QList<QTextEdit *> *charactersTipsSelection;
    QList<QList<QPixmap *> *> *standAnimsSelection;

    //**UI IMAGES**//
    QList<QGraphicsPixmapItem *> *arenaIconList;
    QList<QGraphicsPixmapItem *> *characterIconList;
    QList<QPoint > *playerFocusList;

    //**WIDGETS**//
    QGraphicsView *view;
    QGraphicsScene *scene;
    QPointF *posO;

signals:
    void startGame();
};
#endif // RFTGSELECTIONMENU_H
