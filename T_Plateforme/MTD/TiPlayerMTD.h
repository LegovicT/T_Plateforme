#ifndef TIPLAYERMTD_H
#define TIPLAYERMTD_H

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

#include "TiCharacterMTD.h"
#include "TiBattleField.h"

class TiPlayerMTD : public QWidget
{
    Q_OBJECT

    public:
        TiPlayerMTD(QString mName, QWidget *parent = nullptr);
        ~TiPlayerMTD();

    public slots:
        /**** GETTERS ****/
        QString getName();
        int getLife();
        int getGolds();
        bool isAlive();

        /**** SETTERS ****/
        void getDamages(int *damages);
        void getHealed(int *heal);
        void earnGold(int *earn);
        bool payGold(int *pay);
        void addCharacter(TiCharacterMTD *rt);
        void removeCharacter(TiCharacterMTD *crt);
        void moveCharacter(TiCharacterMTD *crt, int *pos);

    protected :
        QString *name;
        int *life;
        int *gold;
        bool *alive;
        int *faith;
        int *technology;
        int *arcane;
        TiBattleField *battlefield;
        QList<TiCharacterMTD *> *characters;
//        TiMainField *mainfield;
//        TiField *field;

};

#endif // TIPLAYERMTD_H
