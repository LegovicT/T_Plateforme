#include "RftGmainwindow.h"
#include <QIODevice>

RftgMainWindow::RftgMainWindow(QWidget *parent) : QWidget(parent)
{
/****************WINDOW PROPERTIES*****************/
    {
        setFocus();                                     //get the focus on this widget for KeyEvents
        setWindowTitle("Main :: Reach For The God");
        setWindowOpacity(0);
        this->hide();
    }

/*****************DEBUGER INIT*********************/
    {
        test = new QPushButton(this);
        test->setText("WHAT???");
        test->setFont(QFont("Times", 10, QFont::Bold));
        test->setGeometry(0,0,1920,100);

        timer = new QTimer;
        timer->setInterval(16); //16ms == 60ips
        timer->start();


        loader = new QWidget();
        loadingText = new QTextEdit(loader);
//        loadingText->setGeometry(parent->geometry());
        loader->hide();
    }

/****************MAIN FILE READING*****************/
    {
        characterList = new QList<TiCharacter *>;
        arenaList = new QList<TiArena *>;
        doodadsList = new QList<TiDoodad *>;
        effectsList = new QList<TiEffects *>;

        QFile mainFile("../T_Plateforme/SRC/RftG/main.xml");
        mainFile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream flux(&mainFile);
        while(!flux.atEnd())
        {
            QString baliseList = flux.readLine();
            if(baliseList.contains("Character"))
            {
                QString characterName = baliseList.split("\"").at(1);
                TiCharacter *character = new TiCharacter;
                character->setName(characterName);
                characterList->append(character);
            }
            else if(baliseList.contains("Arena"))
            {
                QString arenaName = baliseList.split("\"").at(1);
                TiArena *arena = new TiArena;
                arena->setName(arenaName);
                arenaList->append(arena);
            }
        }
    }

/*****************INITIALIZATIONS******************/
    {
        InitArena();                                    //initialize arena moduls
        InitCharacters();                               //initialize characters
        InitPlayers();                                  //initialize players graphics moduls
        InitLayers();                                   //initialize the players stats vues
        InitEffects();                                  //initialize graphics effects
    }

/*****************SELECTION MENU*******************/
    {
        selectMenu = new RftgSelectionMenu(this);

        for(int rna=0; rna < arenaList->size(); rna++)
        {
            selectMenu->addArena(arenaList->at(rna));
        }
        for(int chtr=0; chtr < characterList->size(); chtr++)
        {
            selectMenu->addCharacter(characterList->at(chtr));
        }
        for(int plr=0; plr < playerList->size(); plr++)
        {
            selectMenu->addPlayer(playerList->at(plr));
        }

        selectMenu->initSelection();
        selectMenu->showFullScreen();
    }

/******************GAME WINDOW*********************/
    {
        gameWindow = new TiGameWindow();
    }

/******************DEBUGER SETUP*******************/
    {
        QString *block = new QString;
        block->append("");
        /* Test Character reading */
        for(int i = 0; i < characterList->count(); i++)
        {
            block->append(QString::number(i+1) + "/" + QString::number(characterList->count()));
            block->append(" _ name: " + characterList->at(i)->getName());
            block->append(" _ life: " + QString::number(characterList->at(i)->getMaxLife()));
            block->append(" _ stamina: " + QString::number(characterList->at(i)->getMaxStamina()));
            if(characterList->at(i)->getOrientation())
                {block->append(" _ orientation: left");}
                else{block->append(" _ orientation: right");}
            block->append(" _ weight: " + QString::number(characterList->at(i)->getWeight()));
            //block->append(" _ animations: " + characterList->at(i)->getAnimations());
            block->append(" _ position: x=" + QString::number(characterList->at(i)->getPos().x()) + ", y=" + QString::number(characterList->at(i)->getPos().y()));
            block->append(" _ speeds: sX=" + QString::number(characterList->at(i)->getSpeeds().x()) + ", sY=" + QString::number(characterList->at(i)->getSpeeds().y()));
            block->append(" _ sprite: " + characterList->at(i)->getSprite("sprite"));
            block->append(" _ hitbox: " + characterList->at(i)->getSprite("hitbox"));
            block->append(" _ hurtbox: " + characterList->at(i)->getSprite("hurtbox"));
        }
        /* Test Arena reading
        for(int i = 0; i < arenaList->count(); i++)
        {
            block->append(QString::number(i+1) + "/" + QString::number(arenaList->count()));
            block->append(" _ name: " + arenaList->at(i)->getName());
            block->append(" _ icon: " + arenaList->at(i)->getIcon());
            block->append(" _ background: " + arenaList->at(i)->getBackground());
            block->append(" _ size: w=" + QString::number(arenaList->at(i)->getBackgroundPos().x()) + ", h=" + QString::number(arenaList->at(i)->getForgroundPos().y()));
            block->append(" _ description: " + arenaList->at(i)->getDescription());
            for(int j = 0; j < arenaList->at(i)->getDoodadsCount(); j++)
            {
                block->append(" _ Doodad" + QString::number(j) + " Size: w=" + QString::number(arenaList->at(i)->getDoodadSize(j).x()) + ", h=" + QString::number(arenaList->at(i)->getDoodadSize(j).y()));
            }
        } */
        test->setText(*block);
        test->show();
    }

/*******************CONNECTIONS********************/
    {
        connect(selectMenu, SIGNAL(startGame()), this, SLOT(GameInit()));
        connect(gameWindow, SIGNAL(loadingText(QString &)), this, SLOT(TextLoading(QString &)));
        connect(timer, SIGNAL(timeout()), this, SLOT(GameLoop()));
    }

}
RftgMainWindow::~RftgMainWindow()
{
}

void RftgMainWindow::InitArena() //initialize arena moduls
{
/****************ARENAS FILE READING********************/
{
    for(int i=0; i < arenaList->count(); i++)
    {
        QString fileName;
        fileName.append("../T_Plateforme/SRC/RftG/Arenas/");
        fileName.append(arenaList->at(i)->getName());
        fileName.append(".xml");
        QFile arenaFile(fileName);
        arenaFile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream flux(&arenaFile);

        QString lineRead;
        QString doodad;
        QString img("");
        int idDoodad = 0;
        int idAnim = 0;
        int idFrame = 0;
        while(!flux.atEnd())
        {
             lineRead = flux.readLine();
             if(lineRead.contains("<icon="))
             {
                arenaList->at(i)->setIcon("../T_Plateforme/SRC/RftG/" + lineRead.split("\"").at(1));
             }
             else if(lineRead.contains("<background="))
             {
                 img = "background";
                 arenaList->at(i)->setBackground(lineRead.split("\"").at(1));
             }
             else if(lineRead.contains("<forground="))
             {
                 img = "forground";
                 arenaList->at(i)->setForground(lineRead.split("\"").at(1));
             }
             else if(lineRead.contains("</forground>") || lineRead.contains("</background>") || lineRead.contains("</sprite>"))
             {
                 img = "";
             }
             else if(lineRead.contains("<size="))
             {
                if(img=="background") //baseSize of the background
                {
                     QImageReader reader("../T_Plateforme/SRC/RftG/" + arenaList->at(i)->getBackground());
                     QSize sizeOfImage = reader.size();
                     arenaList->at(i)->setBackgroundSize(QPointF(sizeOfImage.width(), sizeOfImage.height()));
                }
                else if(img=="forground") //baseSize of the forground
                {
                    QImageReader reader("../T_Plateforme/SRC/RftG/" + arenaList->at(i)->getForground());
                    QSize sizeOfImage = reader.size();
                    arenaList->at(i)->setForgroundSize(QPointF(sizeOfImage.width(), sizeOfImage.height()));
                }
                else if(img[0]=="d") //baseSize of the current doodad
                {
                    QImageReader reader("../T_Plateforme/SRC/RftG/" + doodadsList->at(idDoodad)->getName() + ".png");
                    QSize sizeOfImage = reader.size();
                    arenaList->at(i)->setDoodadSize(idDoodad ,QPointF(sizeOfImage.width(), sizeOfImage.height()));
                }
             }
             /*else if(lineRead.contains("<resize="))
             {
                 if(img=="background") //resize of the background
                    {arenaList->at(i)->setBackgroundResize(QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
                 else if(img=="forground") //resize of the forground
                    {arenaList->at(i)->setForgroundResize(QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
                 else if(img=="") //resize of the arena
                    {arenaList->at(i)->setResize(QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
                 //else if(img[0]=="d") //resize of the current doodad
                    //{arenaList->at(i)->setDoodadResize(idDoodad ,QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
             }*/
             else if(lineRead.contains("<pos="))
             {
                 //position of the background
                 if(img=="background")
                    {arenaList->at(i)->setBackgroundPos(QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
                 //position of the forground
                 else if(img=="forground")
                    {arenaList->at(i)->setForgroundPos(QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
                 //position of the arena
                 else if(img=="")
                    {arenaList->at(i)->setPos(QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
                 //position of the current doodad
                 //else if(img[0]=="d")
                    //{arenaList->at(i)->setDoodadPos(idDoodad ,QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));}
             }
             else if(lineRead.contains("<description="))
             {
                 arenaList->at(i)->setDescription(lineRead.split("\"").at(1));
             }
             else if(lineRead.contains("<doodad>"))
             {
                 doodad.clear();
                 idAnim = 0;
                 idFrame = 0;
                 idDoodad = lineRead.split("\"").at(1).toInt();
             }
             else if(lineRead.contains("<animation"))
             {
                 idFrame = 0;
                 if(lineRead.split("\"").at(1) == "none"){}
                 else{idAnim = lineRead.split("\"").at(1).toInt();}
             }
             else if(lineRead.contains("<frame"))
             {
                 if(lineRead.split("\"").at(1) == "none"){}
                 else{idFrame = lineRead.split("\"").at(1).toInt();}
             }
             else if(lineRead.contains("<sprite="))
             {
                 //arenaList->at(i)->getDoodad(idDoodad).setSpritePath(lineRead.split("\"").at(1));
                 img = "d" + QString::number(idDoodad);
             }
             else if(lineRead.contains("<force="))
             {
                //arenaList->at(i)->getDoodad(idDoodad).setForce(QPointF(lineRead.split("\"").at(1).split("x").at(0).toFloat(), lineRead.split("\"").at(1).split("x").at(1).toFloat()));
             }
             else if(lineRead.contains("<name="))
             {
                //arenaList->at(i)->getDoodad(idDoodad).setName(lineRead.split("\"").at(1));
             }
        }
    }
}
}
void RftgMainWindow::InitCharacters()
{
/****************CHARACTERS FILE READING********************/
    {
        for(int i=0; i < characterList->count(); i++)
        {
            QString fileName;
            fileName.append("../T_Plateforme/SRC/RftG/Characters/");
            fileName.append(characterList->at(i)->getName());
            fileName.append(".xml");
            QFile characterFile(fileName);
            characterFile.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream flux(&characterFile);

            QString lineRead;
            QString anim;
            int idAnim = 0;
            int idFrame = 0;
            QList<qreal> damageList;
            QList<qreal> propulsionList;


            while(!flux.atEnd())
            {
                 lineRead = flux.readLine();
                 if(lineRead.contains("<sprite="))
                 {
                     QString sprite;
                     sprite = lineRead.split("\"").at(1);
                     characterList->at(i)->setSprite("../T_Plateforme/SRC/RftG/" + sprite, "sprite");
                     characterList->at(i)->setSprite("../T_Plateforme/SRC/RftG/" + sprite.split(".").at(0) + "_hibox.png", "hitbox");
                     characterList->at(i)->setSprite("../T_Plateforme/SRC/RftG/" + sprite.split(".").at(0) + "_hurtbox.png", "hurtbox");
                 }
                 else if(lineRead.contains("<hitbox="))
                 {
                     QString sprite;
                     sprite = lineRead.split("\"").at(1);
                     characterList->at(i)->setSprite("../T_Plateforme/SRC/RftG/" + sprite, "hitbox");
                 }
                 else if(lineRead.contains("<hurtbox="))
                 {
                     QString sprite;
                     sprite = lineRead.split("\"").at(1);
                     characterList->at(i)->setSprite("../T_Plateforme/SRC/RftG/" + sprite, "hurtbox");
                 }
                 else if(lineRead.contains("<icon="))
                 {
                     characterList->at(i)->setIcon("../T_Plateforme/SRC/RftG/" + lineRead.split("\"").at(1));
                 }
                 else if(lineRead.contains("<life="))
                 {
                     characterList->at(i)->setMaxLife(lineRead.split("\"").at(1).toInt());
                 }
                 else if(lineRead.contains("<stamina="))
                 {
                     characterList->at(i)->setMaxStamina(lineRead.split("\"").at(1).toInt());
                 }
                 else if(lineRead.contains("<weight="))
                 {
                     characterList->at(i)->setWeight(lineRead.split("\"").at(1).toFloat());
                 }
                 else if(lineRead.contains("<description="))
                 {
                     characterList->at(i)->setDescription(lineRead.split("\"").at(1));
                 }
                 else if(lineRead.contains("<tips="))
                 {
                     characterList->at(i)->setTips(lineRead.split("\"").at(1));
                 }
                 //anims n frames
                 else if(lineRead.contains("<animation"))
                 {
                     anim.clear();
                     anim.append(lineRead.split("\"").at(3));
                     idAnim = lineRead.split("\"").at(1).toInt();
                     //idAnim = lineRead.section(lineRead.indexOf("id=\"") + 4, 2).toInt();
                     damageList.clear();
                     propulsionList.clear();
                 }
                 else if(lineRead.contains("<frame"))
                 {
                     idFrame = lineRead.split("\"").at(1).toInt();
                     //idFrame = lineRead.section(lineRead.indexOf("id=\"") + 4, 2).toInt();
                     damageList.append(0);
                     propulsionList.append(0);
                     characterList->at(i)->setDamages(idAnim, idFrame, qreal(0.0));
                     characterList->at(i)->setPropulsions(idAnim, idFrame, qreal(0.0));
                 }
                 else if(lineRead.contains("<damages"))
                 {
                     //damageList.replace(idFrame, lineRead.split("\"").at(1).toFloat());
                     qreal dmg;
                     dmg = lineRead.split("\"").at(1).toFloat();
                     characterList->at(i)->setDamages(idAnim, idFrame, dmg);
                 }
                 else if(lineRead.contains("<propulsion"))
                 {
                     //propulsionList.replace(idFrame, lineRead.split("\"").at(1).toFloat());
                     qreal prpltn;
                     prpltn = lineRead.split("\"").at(1).toFloat();
                     characterList->at(i)->setPropulsions(idAnim, idFrame, prpltn);
                 }
                 else if(lineRead.contains("<effect"))
                 {
                     TiEffects *newfx = new TiEffects;

                     QString fxName;
                     fxName = lineRead.split("\"").at(1);
                     newfx->setName(fxName);
                     newfx->setCharacterFrame(QPoint(idFrame, idAnim));

                     characterList->at(i)->addEffect(newfx, QPoint(idFrame, idAnim));

                     effectsList->append(newfx);
                 }
                 else if(lineRead.contains("</frame>"))
                 {
                 }
                 else if(lineRead.contains("</animation>"))
                 {
                     characterList->at(i)->setAnimation(anim, idAnim, int(idFrame + 1));
                     //characterList->at(i)->setDamages(damageList, idAnim);
                     //characterList->at(i)->setPropulsions(propulsionList, idAnim);
                 }
            }
        }
    }
}
void RftgMainWindow::InitPlayers() //initialize player moduls
{
    playerList = new QList<TiPlayer *>;
    TiPlayer *player1 = new TiPlayer;
    TiPlayer *player2 = new TiPlayer;
    player1->setName("P1");
    player2->setName("P2");
    playerList->append(player1);
    playerList->append(player2);
}
void RftgMainWindow::InitLayers() //initialize the statsbar vue
{
}
void RftgMainWindow::InitEffects() //initialize spell effects and attributes
{
/****************EFFECTS FILE READING********************/
    {
        for(int i=0; i < effectsList->count(); i++)
        {
            QString fileName;
            fileName.append("../T_Plateforme/SRC/RftG/Effects/");
            fileName.append(effectsList->at(i)->getName());
            fileName.append(".xml");
            QFile EffectFile(fileName);
            EffectFile.open(QIODevice::ReadOnly | QIODevice::Text);
            QTextStream flux(&EffectFile);

            QString lineRead;
            QString anim;
            int idAnim = 0;
            int idFrame = 0;
            QList<qreal> damageList;
            QList<qreal> propulsionList;


            while(!flux.atEnd())
            {
                 lineRead = flux.readLine();
                 if(lineRead.contains("<sprite="))
                 {
                     QString sprite;
                     sprite = lineRead.split("\"").at(1);
                     effectsList->at(i)->setSprite("../T_Plateforme/SRC/RftG/" + sprite);
                     effectsList->at(i)->setHitbox("../T_Plateforme/SRC/RftG/" + sprite.split(".").at(0) + "_hibox.png");
                 }
                 else if(lineRead.contains("<hitbox="))
                 {
                     QString hitbox;
                     hitbox = lineRead.split("\"").at(1);
                     effectsList->at(i)->setHitbox("../T_Plateforme/SRC/RftG/" + hitbox);
                 }
                 else if(lineRead.contains("<type="))
                 {
                     QString fxType;
                     fxType = lineRead.split("\"").at(1);
                     effectsList->at(i)->setType(fxType);
                 }
                 else if(lineRead.contains("<move="))
                 {
                     QString move;
                     move = lineRead.split("\"").at(1);
                     effectsList->at(i)->setMove(move);
                 }
                 else if(lineRead.contains("<start="))
                 {
                     idAnim = 0;
                     idFrame = 0;
                     effectsList->at(i)->setStartFrames(lineRead.split("\"").at(1).toInt());
                 }
                 else if(lineRead.contains("<loop="))
                 {
                     idAnim = 1;
                     idFrame = 0;
                     effectsList->at(i)->setLoopFrames(lineRead.split("\"").at(1).toInt());
                     qDebug()<<"fx "+effectsList->at(i)->getName()+"_frameCount"+QString::number(lineRead.split("\"").at(1).toInt())+" anim"+QString::number(idAnim)+" frame"+QString::number(idFrame);
                 }
                 else if(lineRead.contains("<end="))
                 {
                     idAnim = 2;
                     idFrame = 0;
                     effectsList->at(i)->setEndFrames(lineRead.split("\"").at(1).toInt());
                 }
                 else if(lineRead.contains("<sound="))
                 {
                     effectsList->at(i)->setSound(idAnim, lineRead.split("\"").at(1));
                 }
                 else if(lineRead.contains("<frame="))
                 {
                     idFrame = lineRead.split("\"").at(1).toInt();
                     effectsList->at(i)->setPropulsion(QPoint(idFrame, idAnim), 0.0);
                     effectsList->at(i)->setDamages(QPoint(idFrame, idAnim), 0.0);
                 }
                 //anims n frames
                 else if(lineRead.contains("<propulsion"))
                 {
                     effectsList->at(i)->setPropulsion(QPoint(idFrame, idAnim), lineRead.split("\"").at(1).toLong());
                 }
                 else if(lineRead.contains("<damages"))
                 {
                     effectsList->at(i)->setDamages(QPoint(idFrame, idAnim), lineRead.split("\"").at(1).toLong());
                 }
            }
        }
    }
}

void RftgMainWindow::GameLoop()
{
    activateWindow();

    /*QString block;

    block.append(" _ animation: " + playerList->at(0)->character->currentAnimName() + " " + QString::number(playerList->at(0)->character->currentAnimFrame().x()));
    block.append(" -Pos:" + QString::number(int(playerList->at(0)->character->getPos().x() * 10)) + ":" + QString::number(int(playerList->at(0)->character->getPos().y() * 10)));
    block.append(" -DeltaPos:" + QString::number(int(playerList->at(0)->character->getSpeeds().x() * 10)) + ":" + QString::number(int(playerList->at(0)->character->getSpeeds().y() * 10)));
    block.append(" -Damages:" + QString::number(characterList->at(0)->getDamages(playerList->at(0)->character->currentAnimFrame())));
    block.append(" -Propulsions:" + QString::number(characterList->at(0)->getPropulsion(playerList->at(0)->character->currentAnimFrame())));


    block.append(" _A: " + QString::number(arenaList->size()) + " _C:" + QString::number(characterList->size()) + " _P:" + QString::number(playerList->size()));
    test->setText(block);
    test->show();*/
}
void RftgMainWindow::GameInit()
{
    //add arena
    gameWindow->setArena(selectMenu->arenaList->at(*selectMenu->selectionArena));
    //add all players
    for(int plr=0; plr < selectMenu->playerList->size(); plr++)
    {
        //add player
        gameWindow->addPlayer(selectMenu->playerList->at(plr), int(plr));

        //add effect for character player
        qDebug()<<"main Fx num"+QString::number(plr);
        qDebug()<<selectMenu->playerList->at(plr)->character->effectList->size();
        qDebug()<<playerList->at(plr)->character->effectList->size();

        for(int efx=0; efx < selectMenu->playerList->at(plr)->character->effectList->size(); efx++)
        {
            qDebug()<<"main fx"+QString::number(efx);
            qDebug()<<selectMenu->playerList->at(plr)->character->effectList->at(efx)->getName();

            TiEffects *fx = new TiEffects;
            fx->setMove(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getMove());
            fx->setPath(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getPath("xml"));
            fx->setType(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getType());
            fx->setSprite(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getPath("sprite"));
            fx->setHitbox(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getPath("hitbox"));
            fx->setStartFrames(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getFrameCount("start"));
            fx->setLoopFrames(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getFrameCount("loop"));
            fx->setEndFrames(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getFrameCount("end"));

            for(int anim=0; anim < 3; anim++)
            {
                qDebug()<<"main anim"+QString::number(anim);
                qDebug()<<selectMenu->playerList->at(plr)->character->effectList->at(efx)->getFrameCount(anim);

                if(selectMenu->playerList->at(plr)->character->effectList->at(efx)->getFrameCount(anim) != 0)
                {
                    for(int frame=0; frame < selectMenu->playerList->at(plr)->character->effectList->at(efx)->getFrameCount(anim); frame++)
                    {
                        qDebug()<<"main frame"+QString::number(frame);
                        qDebug()<<selectMenu->playerList->at(plr)->character->effectList->at(efx)->getPropulsion(QPoint(frame, anim));
                        qDebug()<<selectMenu->playerList->at(plr)->character->effectList->at(efx)->getDamages(QPoint(frame, anim));

                        //fx->setPropulsion(QPoint(frame, anim), selectMenu->playerList->at(plr)->character->effectList->at(efx)->getPropulsion(QPoint(frame, anim)));
                        //fx->setDamages(QPoint(frame, anim), selectMenu->playerList->at(plr)->character->effectList->at(efx)->getDamages(QPoint(frame, anim)));
                    }
                }
            }
            gameWindow->playerList->last()->character->addEffect(fx, selectMenu->playerList->at(plr)->character->effectList->at(efx)->getCharacterFrame());
        }
    }

    gameWindow->GameInit();
    gameWindow->showFullScreen();
    disconnect(selectMenu, SIGNAL(startGame()),this, SLOT(GameInit()));
    selectMenu->startGameBtn->close();
    selectMenu->close();
}
void RftgMainWindow::TextLoading(QString *text)
{
    if(loader->isHidden())
    {
        loader->showFullScreen();
    }
    if(*text=="End")
    {
        loader->close();
    }
    qDebug()<<*text;
    loadingText->setText(*text);
    //loadingText->show();
}

void RftgMainWindow::addPlayer(TiPlayer *player, int noPlayer)
{
    if(playerList->size() < noPlayer+1)
    {
        playerList->append(player);
    }
    else
    {
        playerList->replace(noPlayer, player);
    }
}
void RftgMainWindow::addPlayer(TiCharacter *character, int noPlayer)
{
    if(noPlayer==0)
    {
        TiPlayer *player = new TiPlayer;
        player->character = character;
        player->setName("newPlayer");
        playerList->append(player);
    }
    else
    {
        for(int plr=0; plr < noPlayer+1; plr++)
        {
            if(playerList->size()-1 < noPlayer)
            {
                addPlayer(0, plr);
            }
            else
            {
                TiPlayer *player = new TiPlayer;
                player->character = character;
                player->setName("newPlayer");
                playerList->append(player);
            }
        }
    }
}
void RftgMainWindow::addPlayer(int idChar, int noPlayer)
{
    TiPlayer *player = new TiPlayer;
    player->character->setName(characterList->at(idChar)->getName());
    player->character->setIcon(characterList->at(idChar)->getIcon());
    player->character->setWeight(characterList->at(idChar)->getWeight());
    player->character->setMaxLife(characterList->at(idChar)->getMaxLife());
    player->character->setMaxStamina(characterList->at(idChar)->getMaxStamina());

    player->character->setSprite(characterList->at(idChar)->getSprite("sprite"), "sprite");
    player->character->setSprite(characterList->at(idChar)->getSprite("hitbox"), "hitbox");
    player->character->setSprite(characterList->at(idChar)->getSprite("hurtbox"), "hurtbox");
    if(noPlayer==1)
    {
        player->character->setSprite(characterList->at(idChar)->getSprite("sprite"), "sprite");
        player->character->setPos(QPointF(- 500, - 300));
        player->character->setOrientation(false);
    }
    else if(noPlayer==2)
    {
        player->character->setSprite(characterList->at(idChar)->getSprite("sprite"), "sprite");
        player->character->setSprite("../T_Plateforme/SRC/RftG/Images/Bob_alt.png", "sprite");
        player->character->setPos(QPointF(500, - 300));
        player->character->setOrientation(true);
    }
    else
    {
        player->character->setSprite(characterList->at(idChar)->getSprite("sprite"), "sprite");
        player->character->setPos(QPointF(0, - 300));
        player->character->setOrientation(false);
    }

    player->character->setAnimation(QString("stand"), int(0), int(5));
    player->character->setAnimation(QString("walk"), int(1), int(4));
    player->character->setAnimation(QString("qAtk"), int(2), int(5));
    player->character->setAnimation(QString("guard"), int(3), int(2));
    player->character->setAnimation(QString("fall"), int(4), int(2));
    player->character->setAnimation(QString("jump"), int(5), int(2));
    player->character->setAnimation(QString("qAirAtk"), int(6), int(3));
    player->character->setAnimation(QString("crouch"), int(7), int(1));
    player->character->setAnimation(QString("qCrouchAtk"), int(8), int(4));
    player->character->setAnimation(QString("guardCrouch"), int(9), int(1));

    for(int ani = 0; ani < characterList->at(idChar)->getAnimCount(); ani++)
    {
        player->character->setAnimation(characterList->at(idChar)->getAnimName(ani), ani, characterList->at(idChar)->getFrameCount(ani));
        for(int fra=0; fra < characterList->at(idChar)->getFrameCount(ani); fra++)
        {
            player->character->setPropulsions(ani, fra, characterList->at(idChar)->getPropulsion(ani, fra));
            player->character->setDamages(ani, fra, characterList->at(idChar)->getDamages(ani, fra));
        }
    }
    playerList->append(player);
}

/***CONTROL EVENT***/
void RftgMainWindow::setControl(QString ctrl)
{
    if(ctrl.left(2) == "LS")
    {
        QString ctrl1 = ctrl.replace("LS ", "");
        ctrl1 = ctrl1.replace("x:", "");
        ctrl1 = ctrl1.replace("y:", "");
        QList<QString> ctrlList = ctrl1.split(","); //crtlList[0] = xPos, crtlList[1] = yPos
        QPointF values = QPointF(2 * (ctrlList.at(0).toDouble() - 50), 2 * (ctrlList.at(1).toDouble() - 50));
        controlChanged(QString("padJL"), values);
    }
    else if(ctrl.left(2) == "RS")
    {
        QString ctrl1 = ctrl.replace("RS ", "");
        ctrl1 = ctrl1.replace("x:", "");
        ctrl1 = ctrl1.replace("y:", "");
        QList<QString> ctrlList = ctrl1.split(","); //crtlList[0] = xPos, crtlList[1] = yPos
        QPointF values = QPointF(2 * (ctrlList.at(0).toDouble() - 50), 2 * (ctrlList.at(1).toDouble() - 50));
        controlChanged(QString("padJR"), values);
    }
    else if(ctrl.left(1) == "X")
    {
        if(ctrl == "X Pushed")
        {controlChanged(QString("padX"), true);}
        else if(ctrl == "X Released")
        {controlChanged(QString("padX"), false);}
    }
    else if(ctrl.left(1) == "Y")
    {
        for(int efct=0; efct < effectsList->size(); efct++)
        {
            qDebug()<<effectsList->at(efct)->getName();
            qDebug()<<characterList->at(0)->getAnimName(effectsList->at(efct)->getCharacterFrame().y())+QString::number((effectsList->at(efct)->getCharacterFrame().x()));
        }
        if(ctrl == "Y Pushed")
        {controlChanged(QString("padY"), true);}
        else if(ctrl == "Y Released")
        {controlChanged(QString("padY"), false);}
    }
    else if(ctrl.left(1) == "A")
    {
        if(ctrl == "A Pushed")
        {controlChanged(QString("padA"), true);}
        else if(ctrl == "A Released")
        {controlChanged(QString("padA"), false);}
    }
    else if(ctrl.left(1) == "B")
    {
        if(ctrl == "B Pushed")
        {controlChanged(QString("padB"), true);}
        else if(ctrl == "B Released")
        {controlChanged(QString("padB"), false);}
    }
    else if(ctrl.left(2) == "Up")
    {
        if(ctrl == "Up Pushed")
        {controlChanged(QString("padUp"), true);}
        else if(ctrl == "Up Released")
        {controlChanged(QString("padUp"), false);}
    }
    else if(ctrl.left(4) == "Down")
    {
        if(ctrl == "Down Pushed")
        {controlChanged(QString("padDown"), true);}
        else if(ctrl == "Down Released")
        {controlChanged(QString("padDown"), false);}
    }
    else if(ctrl.left(5) == "Right")
    {
        if(ctrl == "Right Pushed")
        {controlChanged(QString("padRight"), true);}
        else if(ctrl == "Right Released")
        {controlChanged(QString("padRight"), false);}
    }
    else if(ctrl.left(4) == "Left")
    {
        if(ctrl == "Left Pushed")
        {controlChanged(QString("padLeft"), true);}
        else if(ctrl == "Left Released")
        {controlChanged(QString("padLeft"), false);}
    }
    else if(ctrl.left(5) == "Start")
    {
        if(ctrl == "Start Pushed")
        {controlChanged(QString("padStart"), true);
            qApp->quit();}
        else if(ctrl == "Start Released")
        {controlChanged(QString("padStart"), false);}
    }
    else if(ctrl.left(6) == "Select")
    {
        if(ctrl == "Select Pushed")
        {controlChanged(QString("padSelect"), true);}
        else if(ctrl == "Select Released")
        {controlChanged(QString("padSelect"), false);}
    }
    else if(ctrl.left(2) == "L1")
    {
        if(ctrl == "L1 Pushed")
        {controlChanged(QString("padL1"), true);}
        else if(ctrl == "L1 Released")
        {controlChanged(QString("padL1"), false);}
    }
    else if(ctrl.left(2) == "L2")
    {
        QString ctrl1 = ctrl.replace("L2", "");
        if(ctrl1 == " Released")
        {controlChanged(QString("padL2"), 0.0);}
        else
        {ctrl1 = ctrl.replace(":", "");
            controlChanged(QString("padL2"), qreal(100 * (ctrl1.toDouble())));}
    }
    else if(ctrl.left(2) == "L3")
    {
        if(ctrl == "L3 Pushed")
        {controlChanged(QString("padL3"), true);}
        else if(ctrl == "L3 Released")
        {controlChanged(QString("padL3"), false);}
    }
    else if(ctrl.left(2) == "R1")
    {
        if(ctrl == "R1 Pushed")
        {controlChanged(QString("padR1"), true);}
        else if(ctrl == "R1 Released")
        {controlChanged(QString("padR1"), false);}
    }
    else if(ctrl.left(2) == "R2")
    {
        QString ctrl1 = ctrl.replace("R2", "");
        if(ctrl1 == " Released")
        {controlChanged(QString("padR2"), 0.0);}
        else
        {ctrl1 = ctrl.replace(":", "");
            controlChanged(QString("padR2"), qreal(100 * (ctrl1.toDouble())));}
    }
    else if(ctrl.left(2) == "R3")
    {
        if(ctrl == "R3 Pushed")
        {controlChanged(QString("padR3"), true);}
        else if(ctrl == "R3 Released")
        {controlChanged(QString("padR3"), false);}
    }
    else{}
}
void RftgMainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z)
    {
        controlChanged(QString("keyZ"), true);
    }
    else if(event->key() == Qt::Key_Q)
    {
        controlChanged(QString("keyQ"), true);
    }
    else if(event->key() == Qt::Key_D)
    {
        controlChanged(QString("keyD"), true);
    }
    else if(event->key() == Qt::Key_S)
    {
        controlChanged(QString("keyS"), true);
    }
    else if(event->key() == Qt::Key_O)
    {
        controlChanged(QString("keyO"), true);
    }
    else if(event->key() == Qt::Key_K)
    {
        controlChanged(QString("keyK"), true);
    }
    else if(event->key() == Qt::Key_L)
    {
        controlChanged(QString("keyL"), true);
    }
    else if(event->key() == Qt::Key_M)
    {
        controlChanged(QString("keyM"), true);
    }
    else if(event->key() == Qt::Key_Escape)
    {
        qApp->quit();
    }
    else if(event->key() == Qt::Key_Space)
    {
        qDebug()<< QString("player number : " + QString::number(playerList->size()));
        qDebug()<< QString("character number : " + QString::number(characterList->size()));
        qDebug()<< QString("arena number : " + QString::number(arenaList->size()));
    }
    else
    {
        qDebug()<< Qt::Key(event->key());
    }
}
void RftgMainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z)
    {
        controlChanged(QString("keyZ"), false);
    }
    else if(event->key() == Qt::Key_Q)
    {
        controlChanged(QString("keyQ"), false);
    }
    else if(event->key() == Qt::Key_D)
    {
        controlChanged(QString("keyD"), false);
    }
    else if(event->key() == Qt::Key_S)
    {
        controlChanged(QString("keyS"), false);
    }
    else if(event->key() == Qt::Key_O)
    {
        controlChanged(QString("keyO"), false);
    }
    else if(event->key() == Qt::Key_K)
    {
        controlChanged(QString("keyK"), false);
    }
    else if(event->key() == Qt::Key_L)
    {
        controlChanged(QString("keyL"), false);
    }
    else if(event->key() == Qt::Key_M)
    {
        controlChanged(QString("keyM"), false);
    }
}
void RftgMainWindow::controlChanged(QString cmd, bool valueB)
{
    //test->setText(cmd);
    //test->show();
    if(selectMenu->isVisible())
    {
        if(valueB)
        {
            if(cmd.left(3) == "pad")
            {
                cmd.replace(0,3,"");
                selectMenu->actionPlayer(0, cmd);
            }
            else if(cmd.left(3) == "key")
            {
                cmd.replace(0,3,"");
                if(cmd=="Z"){cmd="Up";}
                else if(cmd=="Q"){cmd="Left";}
                else if(cmd=="S"){cmd="Down";}
                else if(cmd=="D"){cmd="Right";}
                else if(cmd=="O"){cmd="Y";}
                else if(cmd=="K"){cmd="X";}
                else if(cmd=="L"){cmd="A";}
                else if(cmd=="M"){cmd="B";}
                else{cmd="";}
                selectMenu->actionPlayer(1, cmd);
            }
        }
        else{}
    }
    else
    {
        if(cmd.left(3) == "pad")
        {
            cmd.replace(0,3,"");
            gameWindow->controlChanged(0, cmd, valueB);
        }
        else if(cmd.left(3) == "key")
        {
            cmd.replace(0,3,"");
            if(cmd=="Z"){cmd="Up";}
            else if(cmd=="Q"){cmd="Left";}
            else if(cmd=="S"){cmd="Down";}
            else if(cmd=="D"){cmd="Right";}
            else if(cmd=="O"){cmd="Y";}
            else if(cmd=="K"){cmd="X";}
            else if(cmd=="L"){cmd="A";}
            else if(cmd=="M"){cmd="B";}
            else{cmd="";}
            gameWindow->controlChanged(1, cmd, valueB);
        }
    }
}
void RftgMainWindow::controlChanged(QString cmd, qreal valueB)
{
    cmd.replace(0,3,"");
    if(!selectMenu->isVisible())
    {gameWindow->controlChanged(0, cmd, qreal(valueB));}
}
void RftgMainWindow::controlChanged(QString cmd, QPointF valueB)
{
    cmd.replace(0,3,"");
    if(!selectMenu->isVisible())
    {
        if(cmd == "JL")
        {
            gameWindow->controlChanged(0, "JoyL", valueB);
        }
        else if(cmd == "JR")
        {
            gameWindow->controlChanged(0, "JoyR", valueB);
        }
    }
}
