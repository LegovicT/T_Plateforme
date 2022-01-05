#ifndef TIDOODAD_H
#define TIDOODAD_H

#include <QtGui>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include <QList>
#include <QObject>

//#include "TiAnimations.h"

class TiDoodad : public QObject
{
    Q_OBJECT

public:
    TiDoodad(QObject *parent = 0);
    ~TiDoodad();

public slots:
    QString getName();
    QPointF getPos();
    QPointF getOrigine();
    QPointF getSize();
    QString getPixmap();
    void setName(QString newName);
    void setPos(qreal newPosX, qreal newPosY);
    void setPos(QPointF newPos);
    void setOrigine(qreal newPosX, qreal newPosY);
    void setOrigine(QPointF newPos);
    void setSize(qreal newSizeX, qreal newSizeY);
    void setSize(QPointF newSize);
    void setPixmap(QString path);

private:
    QString *name;                                                           //identifient of the HBox
    QPointF *pos;
    QPointF *origine;
    QPointF *size;
    QPointF *resize;
    QString *pixmapPath;

};

#endif // TIDOODAD_H
