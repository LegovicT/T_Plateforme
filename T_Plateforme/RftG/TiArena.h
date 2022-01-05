#ifndef TIARENA_H
#define TIARENA_H

#include <QtGui>
#include <QWidget>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

#include <QPushButton>

#include "TiDoodad.h"
#include "TiEffects.h"

class TiArena : public QObject
{
    Q_OBJECT

public:
    TiArena(QWidget *parent = 0);
    ~TiArena();

public slots:
    void setName(QString arenaName);
    void setDescription(QString arenaDescription);
    void setIcon(QString iconPath);
    void setBackground(QString backgroundPath);
    void setForground(QString forgroundPath);
    //void addDoodad(TiDoodad newDoodad);
    //void setDoodads(QList<TiDoodad *> newDoodadList);
    void setPos(QPointF newPos);
    void setBackgroundPos(QPointF newPos);
    void setForgroundPos(QPointF newPos);
    void setDoodadPos(int id, QPointF newPos);
    void setSize(QPointF newSize);
    void setBackgroundSize(QPointF newSize);
    void setForgroundSize(QPointF newSize);
    void setDoodadSize(int id, QPointF newSize);

    QString getName();
    QString getDescription();
    QString getIcon();
    QString getBackground();
    QString getForground();
    QString getDoodad(int id=0);
    int getDoodadsCount();
    QPointF getPos();
    QPointF getBackgroundPos();
    QPointF getForgroundPos();
    QPointF getDoodadPos(int id);
    QPointF getSize();
    QPointF getBackgroundSize();
    QPointF getForgroundSize();
    QPointF getDoodadSize(int id);

private:
    QString *name;                                                           //identifient of the arena
    QString *description;
    QString *icon;
    QString *background;
    QString *forground;
    QPointF *pos;
    QPointF *bgPos;
    QPointF *fgPos;
    QPointF *size;
    QPointF *bgSize;
    QPointF *fgSize;
    //QList<TiDoodad *> *destructibleList;
    QList<QPointF *> *destructibleSizeList;
    QList<QPointF *> *destructiblePosList;
};

#endif // TIARENA_H
