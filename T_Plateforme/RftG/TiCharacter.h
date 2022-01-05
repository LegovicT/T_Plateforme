#ifndef TICHARACTER_H
#define TICHARACTER_H

#include <QtGui>
#include <QPixmap>
#include <QList>
#include <QTimer>
#include <QObject>
#include "TiEffects.h"

class TiCharacter : public QObject
{
    Q_OBJECT

public:
    TiCharacter(QObject *parent = 0);
    ~TiCharacter();

    QList<TiEffects *> *effectList;

public slots:
    //////////SETTERS///////////
    void setName(QString charName);
    void setIcon(QString iconPath);
    void setSprite(QString sprite, QString box);
    void setMaxLife(int charLife);
    void setMaxStamina(int charStamina);
    void setWeight(qreal charWeight);
    void setDescription(QString characterDescription);
    void setTips(QString characterTips);
    void setAnimations(QString name, QString animPath=0, int box=0, int idAnim=0, int idFrame=0, int xSpriteSheetPos=0, int ySpriteSheetPos=0);
    void setAnimation(QString name, int idAnim, int idFrame);
    void setAnimation(QString name, QPoint posAnim);
    void setDamages(QList<qreal> damages, int idAnim);
    void setPropulsions(QList<qreal> propulsions, int idAnim);
    void setDamages(int noAnim, int noFrame, qreal damage);
    void setDamages(QPoint animFrame, qreal damage);
    void setPropulsions(int noAnim, int noFrame, qreal damage);
    void setPropulsions(QPoint animFrame, qreal damage);
    void setSpeeds(QPointF speed);
    void setSpeeds(qreal speedX, qreal speedY);
    void addEffect(TiEffects *fx, QPoint numFrameAnim);


    void setPos(qreal charPosX, qreal charPosY);
    void setPos(QPointF charPos);
    void setOrientation(bool charOrientation);                              //orientation of the character (true==left, false==right)
    void recieveDamage(int damageTaken);
    void reduceStamina(int reduceRate);
    void gainStamina(int gainRate);
    void startCombo();
    void finishCombo();
    void playAnim(int numAnim);                                             //
    void playAnim(QString nameAnim);                                        //
    void nextFrame();

    ///////////GETTERS//////////
    QString getName();
    QString getIcon();
    int getMaxLife();
    int getMaxStamina();
    QString getDescription();
    QString getTips();
    QString getSprite(QString box);

    QPoint currentAnimFrame();
    QString currentAnimName();
    QString getAnimName(int noAnim);

    int getCurrentLife();
    int getCurrentStamina();
    QPointF getPos();
    bool getOrientation();
    qreal getWeight();
    QPointF getSpeeds();
    qreal currentDamages();
    qreal currentPropulsion();
    qreal getDamages(int anim, int frame);
    qreal getPropulsion(int anim, int frame);
    qreal getDamages(QPoint animFrame);
    qreal getPropulsion(QPoint animFrame);
    int getAnimCount();
    int getFrameCount(int noAnim);
    int getFrameCount(QString nameAnim);
    QString getEffect(QPoint numFrameAnim);
    QString getEffect();

    QPoint getDetailsCount(int noAnim);
    QPoint getDetailCount();

private:
    QString *name;                                                          //name
    QString *icon;                                                          //Icon of the character
    QString *description;
    QString *tips;
    int *pvMax;                                                             //max potential of life points
    qreal *weight;                                                          //weight of the character
    int *staminaMax;                                                        //max potential of stamina level
    QList<QString > *animationNameList;                                     //animations name list
    QString *spritePath;
    QString *hitboxPath;
    QString *hurtboxPath;
    QList<int> *animCount;
    QPoint *animPos;
    QList<QPoint> *fxFrameAnim;

    int *pv;                                                                //current life points
    int *stamina;                                                           //current stamina level
    QPointF *pos;                                                           //Position of the character
    bool *orientation;                                                      //orientation of the character (true==left, false==right)
    QList<QList<qreal *> *> *damageList;
    QList<QList<qreal *> *> *propulsionList;
    QPointF *speeds;                                                        //speed on the axes (for the y : jump/fall and x : for the dash/run/slide)
    int *hitCounter;                                                        //count the hits given
    QList<int *> *comboCounter;                                             //save every animations identifients played durring the current combo
    int *buffer;                                                            //save the next anim when a button is pressed and when an anim is currently playing

    /*
//-------------------------------------------
    TiAnimations *intro_Anim;         //00
    TiAnimations *victory_Anim;       //01
    TiAnimations *lose_Anim;          //02
    TiAnimations *taunt_Anim;         //03
//states
    TiAnimations *stand_Anim;          //04
    TiAnimations *fall_Anim;           //05
    TiAnimations *crouch_Anim;         //06
    TiAnimations *floor_Anim;          //07
    TiAnimations *guard_Anim;          //08
    TiAnimations *guard_Crouch_Anim;   //09
//hurted
    TiAnimations *hurt_Anim;           //10
    TiAnimations *hurt_Floor_Anim;     //11
    TiAnimations *hurt_Crouch_Anim;    //12
    TiAnimations *hurt_Air_Anim;       //13
    TiAnimations *hurt_Top_Anim;       //14
    TiAnimations *hurt_Bot_Anim;       //15
//moving
    TiAnimations *walk_Front_Anim;          //16
    TiAnimations *Walk_Back_Anim;           //17
    TiAnimations *walk_Crouch_Front_Anim;   //18
    TiAnimations *walk_Crouch_Back_Anim;    //19
    TiAnimations *walk_Guard_Front_Anim;    //20
    TiAnimations *walk_Guard_Back_Anim;     //21

//special moving
    TiAnimations *run_Anim;                 //22
    TiAnimations *jump_Small_Anim;          //23
    TiAnimations *jump_Big_Anim;            //24
    TiAnimations *dash_Front_Anim;          //25
    TiAnimations *dash_Back_Anim;           //26
    TiAnimations *rise_Anim;                //27
    TiAnimations *rise_Front_Anim;          //28
    TiAnimations *rise_Back_Anim;           //29
    TiAnimations *rise_Qatk_Anim;           //30
    TiAnimations *rise_Hatk_Anim;           //31
    TiAnimations *rise_Guard_Anim;          //32

//--- dash
    TiAnimations *dash_Front_Dodge_Anim;    //33
    TiAnimations *dash_Front_Qatk_Anim;     //34
    TiAnimations *dash_Front_Hatk_Anim;     //35

    TiAnimations *dash_Back_Dodge_Anim;    //36
    TiAnimations *dash_Back_QAtk_Anim;     //37
    TiAnimations *dash_Back_HAtk_Anim;     //38

//special
    TiAnimations *counter_Anim;         //39
    TiAnimations *counter_Air_Anim;     //40
    TiAnimations *counter_Crouch_Anim;  //41

    TiAnimations *ultimate_Anim;         //42
    TiAnimations *ultimate_Air_Anim;     //43

//attack

//--stand attack

    //----Qatk
    TiAnimations *qAtk1_Anim;      //44
    TiAnimations *qAtk2_Anim;      //45

    TiAnimations *qAtk_Front_Anim;  //46
    TiAnimations *qAtk_Back_Anim;   //47
    TiAnimations *qAtk_Up_Anim;     //48
    TiAnimations *qAtk_Down_Anim;   //49

    //----Hatk
    TiAnimations *hAtk1_Anim;      //50
    TiAnimations *hAtk2_Anim;      //51

    TiAnimations *hAtk_Front_Anim;  //52
    TiAnimations *hAtk_Back_Anim;   //53
    TiAnimations *hAtk_Up_Anim;     //54
    TiAnimations *hAtk_Down_Anim;   //55

    //----Impact
    TiAnimations *pushImpact_Anim;           //56
    TiAnimations *pushImpact_Front_Anim;     //57
    TiAnimations *pushImpact_Back_Anim;      //58
    TiAnimations *pushImpact_Up_Anim;        //59
    TiAnimations *pushImpact_Down_Anim;      //60

    TiAnimations *releaseImpact_Anim;        //61
    TiAnimations *releaseImpact_Front_Anim;  //62
    TiAnimations *releaseImpact_Back_Anim;   //63
    TiAnimations *releaseImpact_Up_Anim;     //64
    TiAnimations *releaseImpact_Down_Anim;   //65

    //----Grab
    TiAnimations *grab_Side_Anim;           //66
    TiAnimations *grab_Up_Anim;             //67

    //----Run special
    TiAnimations *run_Qatk_Anim;           //68
    TiAnimations *run_Hatk_Anim;           //69
    TiAnimations *run_Cancel_Anim;         //70

    //----Spells
    TiAnimations *spellA_Anim;            //71
    TiAnimations *spellB_Anim;            //72
    TiAnimations *spellX_Anim;            //73
    TiAnimations *spellY_Anim;            //74

//--crouch attack

    //----Qatk
    TiAnimations *qAtk1_Crouch_Anim;      //75
    TiAnimations *qAtk2_Crouch_Anim;      //76

    TiAnimations *qAtk_Crouch_Front_Anim;  //77
    TiAnimations *qAtk_Crouch_Back_Anim;   //78

    //----Hatk
    TiAnimations *hAtk1_Crouch_Anim;      //79
    TiAnimations *hAtk2_Crouch_Anim;      //80

    TiAnimations *hAtk_Crouch_Front_Anim;  //81
    TiAnimations *hAtk_Crouch_Back_Anim;   //82


//--air attack

    //----air Qatk
    TiAnimations *qAtk_Air_Anim;        //83

    TiAnimations *qAtk_Air_Front_Anim;  //84
    TiAnimations *qAtk_Air_Back_Anim;   //85
    TiAnimations *qAtk_Air_Up_Anim;     //86
    TiAnimations *qAtk_Air_Down_Anim;   //87

    //----air Hatk
    TiAnimations *hAtk_Air_Anim;        //88

    TiAnimations *hAtk_Air_Front_Anim;  //89
    TiAnimations *hAtk_Air_Back_Anim;   //90
    TiAnimations *hAtk_Air_Up_Anim;     //91
    TiAnimations *hAtk_Air_Down_Anim;   //92

    //----air Impact
    TiAnimations *Impact_Air_Anim;           //93
    TiAnimations *Impact_Air_Front_Anim;     //94
    TiAnimations *Impact_Air_Back_Anim;      //95
    TiAnimations *Impact_Air_Up_Anim;        //96
    TiAnimations *Impact_Air_Down_Anim;      //97

    //----air Grab
    TiAnimations *grab_Air_Side_Anim;           //98
    TiAnimations *grab_Air_Up_Anim;             //99
    TiAnimations *grab_Air_Down_Anim;           //100

    //----air Spells
    TiAnimations *spellA_Air_Anim;            //101
    TiAnimations *spellB_Air_Anim;            //102
    TiAnimations *spellX_Air_Anim;            //103
    TiAnimations *spellY_Air_Anim;            //104
    */
};

#endif // TICHARACTER_H
