#ifndef TIEFFECTS_H
#define TIEFFECTS_H

#include <QtGui>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include <QList>
#include <QObject>

class TiEffects : public QObject
{
    Q_OBJECT

public:
    TiEffects(QObject *parent = 0);
    ~TiEffects();

public slots:
    void setName(QString newName);
    void setPath(QString newPath);
    void setSprite(QString newPath);
    void setHitbox(QString newPath);
    void setType(QString newType);
    void setMove(QString newMove);
    void setPos(QPointF newPos);
    void setDamages(QPoint frameAnim, qreal dmg);
    void setPropulsion(QPoint frameAnim, qreal prpsl);
    void setSound(int idAnim, QString path);
    void setStartFrames(int noFrames);
    void setLoopFrames(int noFrames);
    void setEndFrames(int noFrames);
    void setCharacterFrame(QPoint newCharFrm);

    void playAnim(int numAnim);                                 //
    void nextFrame();

    QString getName();                                 //
    QString getPath(QString box);                                 //box = "sprite" or "hitbox" for png file path or "xml" for xml file path
    QString getType();                                 //
    QPointF getPos();                                 //
    QString getMove();
    qreal getDamages(QPoint frameAnim);
    qreal getPropulsion(QPoint frameAnim);
    qreal getDamages();
    qreal getPropulsion();
    int getFrameCount(int idAnim);
    int getFrameCount(QString anim);
    QPoint getCharacterFrame();

    QPoint currentAnimFrame();

private:
    QString *name;                                              //name of the effect
    QString *pathFx;                                            //path of the effect xml
    QString *spritePath;                                   //path of the sprite png
    QString *hitboxPath;                                   //path of the hitbox png
    QString *typeFx;                                            //type of effect (chanel, cast, launch)
    QString *move;                                          //movement of the effect (front, up, back, down, none)
    QPointF *posFx;
    QPoint *frameAnimFx;
    QPoint *frameCharFx;
    QList<QList<qreal *> *> *damageList;
    QList<QList<qreal *> *> *propulsionList;
    int *startFrames;
    int *loopFrames;
    int *endFrames;

    QString *soundStart;                                    //path of the mp3 start effect
    QString *soundLoop;
    QString *soundEnd;

signals:
    void playSound(QString *soundPath);                     //emitted when an start/loop/end anim begin (if the path is not empty)
    void endFx();

};

#endif // TIEFFECTS_H
