#ifndef TISPRITE_H
#define TISPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>

class TiSprite : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit TiSprite(QObject *parent = 0);

public slots:
    int nextFrame();
    bool changeAnimation(int *numAnim);
    bool setMaxAnimation(int *animCount);
    bool setMaxFrame(int *FrameCount, int *animCount);
    bool setPixmap(QString *pixmapPath);
    QPoint getCurrent();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    QRectF boundingRect() const;

    QPixmap *spriteImage;
    int currentFrame;
    int currentAnim;
    int maxAnim;
    QList<int > maxFrame;
};


#endif // TISPRITE_H
