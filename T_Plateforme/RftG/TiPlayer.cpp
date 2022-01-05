#include "TiPlayer.h"

TiPlayer::TiPlayer(QObject *parent) : QObject(parent)
{
    name = new QString("name"); //name
    icon = new QString("null"); //Icon of the player
    level = new int(0);
    experience = new int(0);
    character = new TiCharacter;
    buttonList = new QList<qreal >;
    commandeList = new QList<QString >;
    commandeList->append("Up");
    commandeList->append("Down");
    commandeList->append("Left");
    commandeList->append("Right");
    commandeList->append("A");
    commandeList->append("B");
    commandeList->append("X");
    commandeList->append("Y");
    commandeList->append("Start");
    commandeList->append("Select");
    commandeList->append("R1");
    commandeList->append("R2");
    commandeList->append("R3");
    commandeList->append("L1");
    commandeList->append("L2");
    commandeList->append("L3");
    commandeList->append("xJoyL");
    commandeList->append("yJoyL");
    commandeList->append("xJoyR");
    commandeList->append("yJoyR");
    for(int cmd=0; cmd < 21; cmd++)
    {
        buttonList->append(0.0);
    }
}
TiPlayer::~TiPlayer()
{

}


void TiPlayer::setName(QString newName)
{
    *name = newName;
}
void TiPlayer::setIcon(QString iconPath)
{
    *icon = iconPath;
}
void TiPlayer::setLevel(int lvl)
{
    *level = lvl;
}
void TiPlayer::setExperience(int exp)
{
    *experience = exp;
}
void TiPlayer::setCommandes(qreal newCmd, QString cmd)
{
    buttonList->replace(commandeList->indexOf(cmd), newCmd);
}
void TiPlayer::gainExp(int exp)
{
    *experience = *experience + exp;
    if(*experience > (*level * 10))
    {
        *experience = *experience - (*level * 10);
        *level = *level + 1;
        emit levelup(level);
    }
}

QString TiPlayer::getName()
{
    return *name;
}
QString TiPlayer::getIcon()
{
    return *name;
}
int TiPlayer::getLevel()
{
    return *level;
}
int TiPlayer::getExperience()
{
    return *experience;
}
qreal TiPlayer::getCommande(QString cmd)
{
    return buttonList->at(commandeList->indexOf(cmd));
}
