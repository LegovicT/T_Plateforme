#ifndef TIPLAYER_H
#define TIPLAYER_H

#include <QtGui>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include <QObject>

#include "TiCharacter.h"


class TiPlayer : public QObject
{
    Q_OBJECT

public:
    TiPlayer(QObject *parent = 0);
    ~TiPlayer();

    TiCharacter *character;
    QList<QString > *commandeList;
    QList<qreal > *buttonList;

public slots:
    //////////SETTERS///////////
    void setName(QString newName);
    void setIcon(QString iconPath);
    void setLevel(int lvl);
    void setExperience(int exp);
    void setCommandes(qreal newCmd, QString cmd);
    void gainExp(int exp);

    ///////////GETTERS//////////
    QString getName();
    QString getIcon();
    int getLevel();
    int getExperience();
    qreal getCommande(QString cmd);

private:
    QString *name;                                                          //Player name
    QString *icon;                                                          //Icon of the player
    int *level;
    int *experience;

signals:
    int levelup(int *level);
};

#endif // TIPLAYER_H
