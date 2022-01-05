#ifndef TIANIMATIONS_H
#define TIANIMATIONS_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class TiAnimations : public QObject
{
    Q_OBJECT

public:
    TiAnimations(QObject *parent = 0);
    ~TiAnimations();

public slots:
    //////////SETTERS///////////
    void nextFrame();
    void playAnim(int numAnim);
    bool setSprite(QString sprite, QString box);
    bool setDamages(QList<QList<int> > damages);
    bool setPropultions(QList<QList<qreal>> propultions);

    ///////////GETTERS//////////
    QString getSprite(QString box);
    int getDamage(QPoint idAnimFrame=QPoint(0,0));
    qreal getPropultion(QPoint idAnimFrame=QPoint(0,0));
    QPoint currentFrame();  //(n°frame, n°anime)
    QString currentFrameName();
    QPoint animFrameCount();

private:
    QList<QString *> *animeNameList;        //names of the animations
    QString *spriteImage;
    QString *hitboxImage;
    QString *hurtboxImage;
    QPoint *curFrame;                        //(n°frame, n°anime)
    QList<QList<int *> *> *dmgList;
    QList<QList<qreal *> *> *propultionList;
};

#endif // TIANIMATIONS_H
