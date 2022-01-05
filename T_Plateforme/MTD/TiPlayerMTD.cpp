#include "TiPlayerMTD.h"

TiPlayerMTD::TiPlayerMTD(QString mName, QWidget *parent) : QWidget(parent)
{
    name = new QString(mName);
    life = new int(100);
    gold = new int(100);
    alive = new bool(true);
    faith = new int(0);
    technology = new int(0);
    arcane = new int(0);
    characters = new QList<TiCharacterMTD *>();
    characters->append(new TiCharacterMTD);
    battlefield = new TiBattleField(this);
//    mainfield = new TiMainField(this);
//    field = new TiField(this);
}
TiPlayerMTD::~TiPlayerMTD()
{

}


/**** GETTERS ****/
QString TiPlayerMTD::getName()
{
    return *name;
}
int TiPlayerMTD::getLife()
{
    return *life;
}
int TiPlayerMTD::getGolds()
{
    return *gold;
}
bool TiPlayerMTD::isAlive()
{
    return *alive;
}

/**** SETTERS ****/
void TiPlayerMTD::getDamages(int *damages)
{
    if(*life - *damages <= 0)
    {
        *alive = false;
        *life = 0;
    }
    else
    {
        *life -= *damages;
    }
}
void TiPlayerMTD::getHealed(int *heal)
{
    if(*life + *heal >= 100)
    {
        *life = 100;
    }
    else
    {
        *life += *heal;
    }
}
void TiPlayerMTD::earnGold(int *earn)
{
    *gold += *earn;
}
bool TiPlayerMTD::payGold(int *pay)
{
    if(*gold - *pay <= 0)
    {
        return false;
    }
    else
    {
        *gold -= *pay;
        return true;
    }
}
void TiPlayerMTD::addCharacter(TiCharacterMTD *crt)
{
    characters->append(crt);
}
void TiPlayerMTD::removeCharacter(TiCharacterMTD *crt)
{
    characters->removeOne(crt);
}
void TiPlayerMTD::moveCharacter(TiCharacterMTD *crt, int *pos)
{
    if(characters->at(*pos) == crt)
    characters->move(characters->indexOf(crt), *pos);
}
