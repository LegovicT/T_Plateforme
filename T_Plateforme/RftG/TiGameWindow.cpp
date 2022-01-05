#include "TiGameWindow.h"

TiGameWindow::TiGameWindow(QWidget *parent) : QWidget(parent)
{
    //setMouseTracking(true);                       //get the focus on this widget for MouseEvents
    setWindowTitle("Game :: Reach For The God");

    test = new QPushButton(this);
    test->setText("WHAT???");
    test->setFont(QFont("Times", 10, QFont::Bold));
    test->setGeometry(0,0,1920,100);

/****************INITIALIZATIONS****************/
    {
        InitWorld();                                    //initialize graphics scene and vue
        InitArena();                                    //initialize arena moduls
        InitPlayers();                                  //initialize players graphics moduls
        InitLayers();                                   //initialize the players stats vues
        InitEffects();                                  //initialize graphics effects
    }

/*********************TIMERS*********************/
    {
        counter = new int(0);
        gameTimer = new QTimer;
        gameTimer->setInterval(12); //16ms == 60ips
        //GameInit();
    }

/*********************DEBUGGER*******************/
    {/*
        QString *block = new QString;
        block->append("");
        // Test Character reading //
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
        test->setText(*block);*/
        test->show();
    }

/*****************CONNECTIONS*******************/
    {
        connect(gameTimer, SIGNAL(timeout()), this, SLOT(GameLoop()));
    }

}
TiGameWindow::~TiGameWindow()
{
}

/***Initializations***/
void TiGameWindow::InitWorld() //initialize the graphics scene and vue
{
    view = new QGraphicsView(this);                 //instance the view for graphics items
    scene = new QGraphicsScene;                     //instance the scene for graphics items
    posO = new QPointF;                             //instance the origine point of the world
    arenaGeo = new QPointF;                         //instance the width and height
    worldScale = new double;                        //instance the scale of the world

    camera = new QList<QGraphicsItem *>;            //instance the graphics items array
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);
    *worldScale = 1;
    view->setGeometry(screenGeom.x(), screenGeom.y() + 100, screenGeom.width(), screenGeom.height());
    view->setScene(scene);
    scene->setSceneRect(view->rect().x(), view->rect().y(), view->rect().width() + 8000, view->rect().height() + 8000);
    scene->setSceneRect(view->rect().x() + 2, view->rect().y() + 2, view->rect().width() - 4, view->rect().height() - 4);
    scene->setBackgroundBrush(QBrush(QColor(0,10,60)));
    posO->setX(scene->width() / 2);
    posO->setY(750);
    arenaGeo->setX(1000); //width
    arenaGeo->setY(40);   //height

    pointerList = new QList<QGraphicsPixmapItem *>;
}
void TiGameWindow::InitArena() //initialize arena moduls
{
    doodadsList = new QList<TiDoodad *>;
    doodadsPixList = new QList<QGraphicsPixmapItem *>;
    doodadsBoxList = new QList<QGraphicsPixmapItem *>;

    //setBackgroundColor(Qt::black);
}
void TiGameWindow::InitPlayers() //initialize player moduls
{
    playerList = new QList<TiPlayer *>;
    spriteSheetList = new QList<QPixmap *>;
    spriteList = new QList<QGraphicsPixmapItem *>;
    hurtboxList = new QList<QGraphicsPixmapItem *>;
    hitboxList = new QList<QGraphicsPixmapItem *>;

    playerSpriteList = new QList<QList<QList<QPixmap *> *> *>;
    playerHitboxList = new QList<QList<QList<QPixmap *> *> *>;
    playerHurtboxList = new QList<QList<QList<QPixmap *> *> *>;
}
void TiGameWindow::InitLayers() //initialize the statsbar vue
{
}
void TiGameWindow::InitEffects() //initialize spell effects and attributes
{
    effectsList = new QList<TiEffects *>;
    fxSpritePixListArena = new QList<QList<QList<QGraphicsPixmapItem *> *> *>;
    fxHitboxPixListArena = new QList<QList<QList<QGraphicsPixmapItem *> *> *>;
    fxSpritePixListPI = new QList<QList<QList<QGraphicsPixmapItem *> *> *>;
    fxHitboxPixListPI = new QList<QList<QList<QGraphicsPixmapItem *> *> *>;
    fxSpritePixListPII = new QList<QList<QList<QGraphicsPixmapItem *> *> *>;
    fxHitboxPixListPII = new QList<QList<QList<QGraphicsPixmapItem *> *> *>;
}

/***Setters***/
void TiGameWindow::setBackgroundColor(QColor color)
{
    view->setBackgroundBrush(color);
}
void TiGameWindow::addPlayer(TiPlayer *newPlayer, int noPlayer)
{
    TiPlayer *player = new TiPlayer;
    //player = newPlayer;
    playerList->append(player);
    playerList->at(noPlayer)->character->setIcon(newPlayer->character->getIcon());
    playerList->at(noPlayer)->character->setName(newPlayer->character->getName());
    playerList->at(noPlayer)->character->setWeight(newPlayer->character->getWeight());
    playerList->at(noPlayer)->character->setMaxLife(newPlayer->character->getMaxLife());
    playerList->at(noPlayer)->character->setMaxStamina(newPlayer->character->getMaxStamina());

    playerList->at(noPlayer)->character->setSprite(newPlayer->character->getSprite("sprite"), "sprite");
    playerList->at(noPlayer)->character->setSprite(newPlayer->character->getSprite("hitbox"), "hitbox");
    playerList->at(noPlayer)->character->setSprite(newPlayer->character->getSprite("hurtbox"), "hurtbox");

    if(noPlayer==int(0))
    {
        playerList->at(noPlayer)->character->setSprite(newPlayer->character->getSprite("sprite"), "sprite");
        playerList->at(noPlayer)->character->setPos(QPointF(posO->x() - 500, posO->y() - 300));
        playerList->at(noPlayer)->character->setOrientation(false);

        playerList->at(noPlayer)->setCommandes(0.0, "Up");
        playerList->at(noPlayer)->setCommandes(0.0, "Down");
        playerList->at(noPlayer)->setCommandes(0.0, "Left");
        playerList->at(noPlayer)->setCommandes(0.0, "Right");
        playerList->at(noPlayer)->setCommandes(0.0, "A");
        playerList->at(noPlayer)->setCommandes(0.0, "B");
        playerList->at(noPlayer)->setCommandes(0.0, "X");
        playerList->at(noPlayer)->setCommandes(0.0, "Y");
        playerList->at(noPlayer)->setCommandes(0.0, "Start");
        playerList->at(noPlayer)->setCommandes(0.0, "Select");
        playerList->at(noPlayer)->setCommandes(0.0, "R1");
        playerList->at(noPlayer)->setCommandes(0.0, "R2");
        playerList->at(noPlayer)->setCommandes(0.0, "R3");
        playerList->at(noPlayer)->setCommandes(0.0, "L1");
        playerList->at(noPlayer)->setCommandes(0.0, "L2");
        playerList->at(noPlayer)->setCommandes(0.0, "L3");
        playerList->at(noPlayer)->setCommandes(0.0, "xJoyL");
        playerList->at(noPlayer)->setCommandes(0.0, "yJoyL");
        playerList->at(noPlayer)->setCommandes(0.0, "xJoyR");
        playerList->at(noPlayer)->setCommandes(0.0, "yJoyR");
    }
    else if(noPlayer==int(1))
    {
        playerList->at(noPlayer)->character->setSprite(newPlayer->character->getSprite("sprite"), "sprite");
        if(newPlayer->character->getSprite("sprite") == playerList->at(0)->character->getSprite("sprite"))
        {
            QString altSprite(newPlayer->character->getSprite("sprite"));
            altSprite.replace(altSprite.size() - 4, 4, "_alt.png");
            playerList->at(noPlayer)->character->setSprite(altSprite, "sprite");
            test->setText(altSprite);
        }
        playerList->at(noPlayer)->character->setPos(QPointF(posO->x() + 500, posO->y() - 300));
        playerList->at(noPlayer)->character->setOrientation(true);

        playerList->at(noPlayer)->setCommandes(0.0, "Up");
        playerList->at(noPlayer)->setCommandes(0.0, "Down");
        playerList->at(noPlayer)->setCommandes(0.0, "Left");
        playerList->at(noPlayer)->setCommandes(0.0, "Right");
        playerList->at(noPlayer)->setCommandes(0.0, "A");
        playerList->at(noPlayer)->setCommandes(0.0, "B");
        playerList->at(noPlayer)->setCommandes(0.0, "X");
        playerList->at(noPlayer)->setCommandes(0.0, "Y");
        playerList->at(noPlayer)->setCommandes(0.0, "Start");
        playerList->at(noPlayer)->setCommandes(0.0, "Select");
        playerList->at(noPlayer)->setCommandes(0.0, "R1");
        playerList->at(noPlayer)->setCommandes(0.0, "R2");
        playerList->at(noPlayer)->setCommandes(0.0, "R3");
        playerList->at(noPlayer)->setCommandes(0.0, "L1");
        playerList->at(noPlayer)->setCommandes(0.0, "L2");
        playerList->at(noPlayer)->setCommandes(0.0, "L3");
        playerList->at(noPlayer)->setCommandes(0.0, "xJoyL");
        playerList->at(noPlayer)->setCommandes(0.0, "yJoyL");
        playerList->at(noPlayer)->setCommandes(0.0, "xJoyR");
        playerList->at(noPlayer)->setCommandes(0.0, "yJoyR");
    }
    else
    {
        player->character->setSprite(newPlayer->character->getSprite("sprite"), "sprite");
        player->character->setPos(QPointF(posO->x(), posO->y() - 300));
        player->character->setOrientation(false);

        player->setCommandes(0.0, "Up");
        player->setCommandes(0.0, "Down");
        player->setCommandes(0.0, "Left");
        player->setCommandes(0.0, "Right");
        player->setCommandes(0.0, "A");
        player->setCommandes(0.0, "B");
        player->setCommandes(0.0, "X");
        player->setCommandes(0.0, "Y");
        player->setCommandes(0.0, "Start");
        player->setCommandes(0.0, "Select");
        player->setCommandes(0.0, "R1");
        player->setCommandes(0.0, "R2");
        player->setCommandes(0.0, "R3");
        player->setCommandes(0.0, "L1");
        player->setCommandes(0.0, "L2");
        player->setCommandes(0.0, "L3");
        player->setCommandes(0.0, "xJoyL");
        player->setCommandes(0.0, "yJoyL");
        player->setCommandes(0.0, "xJoyR");
        player->setCommandes(0.0, "yJoyR");
    }

    qDebug()<<"game Fx num";
    qDebug()<<playerList->at(noPlayer)->character->getName();
    qDebug()<<playerList->at(noPlayer)->character->effectList->size();
    for(int fx=0; fx < playerList->at(noPlayer)->character->effectList->size(); fx++)
    {
        //ajouter fx
        qDebug()<<playerList->at(noPlayer)->character->effectList->at(fx)->getName();
    }

    playerList->at(noPlayer)->character->setAnimation(QString("stand"), int(0), int(5));
    playerList->at(noPlayer)->character->setAnimation(QString("walk"), int(1), int(4));
    playerList->at(noPlayer)->character->setAnimation(QString("qAtk"), int(2), int(5));
    playerList->at(noPlayer)->character->setAnimation(QString("guard"), int(3), int(2));
    playerList->at(noPlayer)->character->setAnimation(QString("fall"), int(4), int(2));
    playerList->at(noPlayer)->character->setAnimation(QString("jump"), int(5), int(2));
    playerList->at(noPlayer)->character->setAnimation(QString("qAirAtk"), int(6), int(3));
    playerList->at(noPlayer)->character->setAnimation(QString("crouch"), int(7), int(1));
    playerList->at(noPlayer)->character->setAnimation(QString("qCrouchAtk"), int(8), int(4));
    playerList->at(noPlayer)->character->setAnimation(QString("guardCrouch"), int(9), int(1));

    for(int ani = 0; ani < newPlayer->character->getAnimCount(); ani++)
    {
        playerList->at(noPlayer)->character->setAnimation(newPlayer->character->getAnimName(ani), ani, newPlayer->character->getFrameCount(ani));
        for(int fra=0; fra < newPlayer->character->getFrameCount(ani); fra++)
        {
            playerList->at(noPlayer)->character->setPropulsions(ani, fra, newPlayer->character->getPropulsion(ani, fra));
            playerList->at(noPlayer)->character->setDamages(ani, fra, newPlayer->character->getDamages(ani, fra));
        }
    }

    QGraphicsPixmapItem *pointerPix = new QGraphicsPixmapItem;
    pointerList->append(pointerPix);
}
void TiGameWindow::setArena(TiArena *newArena)
{
    arena = new TiArena;
    arena = newArena;
    /*arena->setName(newArena->getName());
    arena->setBackground(newArena->getBackground());
    arena->setForground(newArena->getForground());

    arena->setPos(newArena->getPos());
    arena->setBackgroundPos(newArena->getBackgroundPos());
    arena->setForgroundPos(newArena->getForgroundPos());
    arena->setSize(newArena->getSize());
    arena->setBackgroundSize(newArena->getBackgroundSize());
    arena->setForgroundSize(newArena->getForgroundSize());*/

    for(int i=0; i < newArena->getDoodadsCount()-1; i++)
    {
        TiDoodad *doodad = new TiDoodad;
        arena->setDoodadPos(i, newArena->getDoodadPos(i));
        arena->setDoodadSize(i, newArena->getDoodadSize(i));
        QGraphicsPixmapItem *doodadPix = new QGraphicsPixmapItem();
        doodadPix = scene->addPixmap(QPixmap("../T_Plateforme/SRC/RftG/" + newArena->getDoodad(i)));
        QTransform fgTrans;
        fgTrans.scale(1, 1);
        fgTrans.translate(arena->getDoodadPos(i).x() * scene->width() - arena->getDoodadSize(i).x() / 2, arena->getDoodadPos(i).y() * scene->height() - arena->getDoodadSize(i).y() / 2);
        doodadPix->setTransform(fgTrans);
        doodadPix->setZValue(5);
        doodad->setName(arena->getDoodad(i));
        doodad->setSize(arena->getDoodadSize(i));
        doodad->setPos(arena->getDoodadPos(i).x() * scene->width() - arena->getDoodadSize(i).x() / 2, arena->getDoodadPos(i).y() * scene->height() - arena->getDoodadSize(i).y() / 2);
        doodad->setPixmap("../T_Plateforme/SRC/RftG/Arena/MetalBox.png.png");
        //doodad->setPixmap("../T_Plateforme/SRC/RftG/" + arena->getDoodad(i) + ".png");
        doodadsList->append(doodad);
        scene->addPixmap(doodadsList->at(i)->getPixmap());
    }

    background = new QGraphicsPixmapItem();
    background = scene->addPixmap(QPixmap("../T_Plateforme/SRC/RftG/" + arena->getBackground()));
    QTransform bgTrans;
    bgTrans.scale(0.7, 0.75);
    //bgTrans.scale(3.4, 3);
    background->setTransform(bgTrans);
    background->setZValue(3);

    forground = new QGraphicsPixmapItem();
    forground = scene->addPixmap(QPixmap("../T_Plateforme/SRC/RftG/" + arena->getForground()));
    QTransform fgTrans;
    fgTrans.scale(1, 1);
    forground->setPos(arena->getForgroundPos().x() * scene->width() - arena->getForgroundSize().x() / 2, arena->getForgroundPos().y() * scene->height() - arena->getForgroundSize().y() / 2 + 80);
    forground->setTransform(fgTrans);
    forground->setZValue(5);

    fgTrans.reset();
    forgroundBox = new QGraphicsPixmapItem();
    forgroundBox = scene->addPixmap(QPixmap("../T_Plateforme/SRC/RftG/" + arena->getForground()));
    fgTrans.scale(1, 1);
    forgroundBox->setPos(arena->getForgroundPos().x() * scene->width() - arena->getForgroundSize().x() / 2, arena->getForgroundPos().y() * scene->height() - 15 - arena->getForgroundSize().y() / 2 + 80);
    forgroundBox->setTransform(fgTrans);
    forgroundBox->setZValue(4);


    TiDoodad *doodad = new TiDoodad;
    doodad->setName("MetalCube");
    doodad->setSize(1.0, 1.0);
    doodad->setPos(0.5 * scene->width() - 200 / 2, 0.5 * scene->height() - 200 / 2);
    doodad->setPixmap("../T_Plateforme/SRC/RftG/Arenas/MetalBox.png");
    QGraphicsPixmapItem *doodadPix = new QGraphicsPixmapItem();
    doodadPix = scene->addPixmap(QPixmap(doodad->getPixmap()));
    //QTransform doodTrans;
    //doodTrans.scale(doodad->getSize().x(), doodad->getSize().y());
    //doodTrans.translate(0.5 * scene->width() - 200 / 2, 0.5 * scene->height() - 200 / 2);
    //doodadPix->setTransform(doodTrans);
    doodadPix->setScale(0.5);
    doodadPix->setPos(*posO);
    doodadPix->setZValue(6);
    doodadsPixList->append(doodadPix);
    doodadsPixList->replace(0, doodadPix);
    doodadsPixList->at(0)->setScale(0.9);
    doodadsPixList->at(0)->setPos(posO->x() + scene->width() / 3 - 200 * 0.9 / 2 + 120, posO->y() - scene->height() / 4 + 200 * 0.9 / 2 + 180);
    doodadsPixList->at(0)->setZValue(5);
    scene->addItem(doodadsPixList->at(0));

    QGraphicsPixmapItem *doodadBox = new QGraphicsPixmapItem();
    doodadBox = scene->addPixmap(QPixmap("../T_Plateforme/SRC/RftG/Arenas/ForgroundMetal.png"));
    doodadsBoxList->append(doodadBox);
    doodadsBoxList->replace(0, doodadBox);
    doodadsBoxList->at(0)->setScale(1);
    doodadsBoxList->at(0)->setPos(posO->x() + scene->width() / 3 - 200 / 2 + 110, posO->y() - scene->height() / 4 + 200 / 2 + 180 - 30);
    doodadsBoxList->at(0)->setZValue(4);
    scene->addItem(doodadsBoxList->at(0));

    QGraphicsPixmapItem *pointerPixbg = new QGraphicsPixmapItem;
    pointerList->append(pointerPixbg);
    QGraphicsPixmapItem *pointerPixfg = new QGraphicsPixmapItem;
    pointerList->append(pointerPixfg);
    QGraphicsPixmapItem *pointerPixdood = new QGraphicsPixmapItem;
    pointerList->append(pointerPixdood);
}

void TiGameWindow::GameInit()
{
    //Pointers
    {
        for(int i=0; i<pointerList->size();i++)
        {
            pointerList->at(i)->setPixmap(QPixmap("../T_Plateforme/SRC/RftG/Images/PointerGreen.png"));
            pointerList->at(i)->setScale(5);
            pointerList->at(i)->setZValue(10);
        }
        pointerList->at(0)->setPixmap(QPixmap("../T_Plateforme/SRC/RftG/Images/PointerRed.png"));
        pointerList->at(1)->setPixmap(QPixmap("../T_Plateforme/SRC/RftG/Images/PointerRed.png"));
        pointerList->at(3)->setPixmap(QPixmap("../T_Plateforme/SRC/RftG/Images/PointerRed.png"));
    }

    //enregistrement des frames des anims de chaques joueurs : playerSpriteList = joueurs(anims(frames))
    {
        QString *txtLoad = new QString;
        int maxPercent(0);
        int currentPercent(0);
        for(int player = 0; player < playerList->size(); player++)
        {
            for(int anim = 0; anim < playerList->at(player)->character->getAnimCount(); anim++)
            {
                for(int frame = 0; frame < playerList->at(player)->character->getFrameCount(anim); frame++)
                {
                    maxPercent+=1;
                }
            }

            //Effects list
            for(int fx=0; fx < playerList->at(player)->character->effectList->size(); fx++)
            {
                //Anim list
                for(int anim=0; anim < 3; anim++)
                {
                    //Frame list
                    for(int frm=0; frm < playerList->at(player)->character->effectList->at(fx)->getFrameCount("start"); frm++)
                    {
                        maxPercent+=2;
                    }
                }
            }
        }

        for(int player = 0; player < playerList->size(); player++)
        {
            QList<QList<QPixmap *> *> *spriteAnimList = new QList<QList<QPixmap *> *>;
            QList<QList<QPixmap *> *> *hitboxAnimList = new QList<QList<QPixmap *> *>;
            QList<QList<QPixmap *> *> *hurtboxAnimList = new QList<QList<QPixmap *> *>;
            for(int anim = 0; anim < playerList->at(player)->character->getAnimCount(); anim++)
            {
                QList<QPixmap *> *spriteFrameList = new QList<QPixmap *>;
                QList<QPixmap *> *hitboxFrameList = new QList<QPixmap *>;
                QList<QPixmap *> *hurtboxFrameList = new QList<QPixmap *>;
                for(int frame = 0; frame < playerList->at(player)->character->getFrameCount(anim); frame++)
                {
                    currentPercent+=1;
                    txtLoad->clear();
                    txtLoad->append((QString::number(currentPercent * 100 / maxPercent) + "% : " + QString::number(currentPercent) + "/" + QString::number(maxPercent)));
                    emit(loadingText(txtLoad));
                    qDebug()<<(QString::number(currentPercent * 100 / maxPercent) + "% : " + QString::number(currentPercent) + "/" + QString::number(maxPercent));
                    //qDebug()<<"Game::Player" + QString::number(player) + " : anim:" + QString::number(anim) + " : frame:" + QString::number(frame);
                    QPixmap *spriteSheet  = new QPixmap;
                    QPixmap *spritePixmap = new QPixmap;
                    spriteSheet->load(playerList->at(player)->character->getSprite("sprite"));
                    //qDebug()<<"-sprite" + playerList->at(player)->character->getSprite("sprite");
                    *spritePixmap = spriteSheet->copy(frame * 500, anim * 500, 500, 500);
                    spriteFrameList->append(spritePixmap);
                    QPixmap *hitboxPixmap = new QPixmap;
                    spriteSheet->load(playerList->at(player)->character->getSprite("hitbox"));
                    //qDebug()<<"-hitbox" + playerList->at(player)->character->getSprite("hitbox");
                    *hitboxPixmap = spriteSheet->copy(frame * 500, anim * 500, 500, 500);
                    hitboxFrameList->append(hitboxPixmap);
                    QPixmap *hurtboxPixmap = new QPixmap;
                    spriteSheet->load(playerList->at(player)->character->getSprite("hurtbox"));
                    //qDebug()<<"-hurtbox" + playerList->at(player)->character->getSprite("hurtbox");
                    *hurtboxPixmap = spriteSheet->copy(frame * 500, anim * 500, 500, 500);
                    hurtboxFrameList->append(hurtboxPixmap);
                }

                spriteAnimList->append(spriteFrameList);
                hitboxAnimList->append(hitboxFrameList);
                hurtboxAnimList->append(hurtboxFrameList);


                //Effects list
                for(int fx=0; fx < playerList->at(player)->character->effectList->size(); fx++)
                {
                    QPixmap *fxSprite = new QPixmap(playerList->at(player)->character->effectList->at(fx)->getPath("sprite"));
                    QPixmap *fxHitbox = new QPixmap(playerList->at(player)->character->effectList->at(fx)->getPath("hitbox"));
                    QList<QList<QGraphicsPixmapItem *> *> *listAnimSprite = new QList<QList<QGraphicsPixmapItem *> *>;
                    QList<QList<QGraphicsPixmapItem *> *> *listAnimHitbox = new QList<QList<QGraphicsPixmapItem *> *>;
                    //Anim list
                    for(int anim=0; anim < 3; anim++)
                    {
                        QList<QGraphicsPixmapItem *> *listFrameSprite = new QList<QGraphicsPixmapItem *>;
                        QList<QGraphicsPixmapItem *> *listFrameHitbox = new QList<QGraphicsPixmapItem *>;
                        //Frame list
                        for(int frm=0; frm < playerList->at(player)->character->effectList->at(fx)->getFrameCount("start"); frm++)
                        {
                            //percent loading
                            currentPercent+=2;
                            txtLoad->clear();
                            txtLoad->append((QString::number(currentPercent * 100 / maxPercent) + "% : " + QString::number(currentPercent) + "/" + QString::number(maxPercent)));
                            emit(loadingText(txtLoad));
                            qDebug()<<(QString::number(currentPercent * 100 / maxPercent) + "% : " + QString::number(currentPercent) + "/" + QString::number(maxPercent));


                            QPixmap *framePixSprite = new QPixmap();
                            QPixmap *framePixHitbox = new QPixmap();
                            *framePixSprite = fxSprite->copy(frm * 500, anim * 500, 500, 500);
                            *framePixHitbox = fxHitbox->copy(frm * 500, anim * 500, 500, 500);
                            QGraphicsPixmapItem *frameSprite = new QGraphicsPixmapItem();
                            QGraphicsPixmapItem *frameHitbox = new QGraphicsPixmapItem();
                            frameSprite->setPixmap(*framePixSprite);
                            frameHitbox->setPixmap(*framePixHitbox);
                            listFrameSprite->append(frameSprite);
                            listFrameHitbox->append(frameHitbox);
                        }
                        listAnimSprite->append(listFrameSprite);
                        listAnimHitbox->append(listFrameHitbox);
                    }
                    fxSpritePixListPI->append(listAnimSprite);
                    fxHitboxPixListPI->append(listAnimHitbox);
                }
            }

            playerSpriteList->append(spriteAnimList);
            playerHitboxList->append(hitboxAnimList);
            playerHurtboxList->append(hurtboxAnimList);

            QGraphicsPixmapItem *sprite = new QGraphicsPixmapItem(QPixmap(*playerSpriteList->at(player)->at(0)->at(0)));
            QGraphicsPixmapItem *hitbox = new QGraphicsPixmapItem(QPixmap(*playerHitboxList->at(player)->at(0)->at(0)));
            QGraphicsPixmapItem *hurtbox = new QGraphicsPixmapItem(QPixmap(*playerHurtboxList->at(player)->at(0)->at(0)));
            spriteList->append(sprite);
            hitboxList->append(hitbox);
            hurtboxList->append(hurtbox);
            spriteList->at(player)->setPos(QPointF(playerList->at(player)->character->getPos().x() + 250, playerList->at(player)->character->getPos().y() - 250));
            hitboxList->at(player)->setPos(QPointF(playerList->at(player)->character->getPos().x() + 250, playerList->at(player)->character->getPos().y() - 250));
            hurtboxList->at(player)->setPos(QPointF(playerList->at(player)->character->getPos().x() + 250, playerList->at(player)->character->getPos().y() - 250));
            scene->addItem(spriteList->at(player));
            scene->addItem(hitboxList->at(player));
            scene->addItem(hurtboxList->at(player));
        }

        txtLoad->clear();
        txtLoad->append("End");
        emit loadingText(txtLoad);
    }


    view->show();
    GameLoop();
}
void TiGameWindow::GameLoop()
{
    animateEvent("character", 0);
    animateEvent("character", 1);
    if(playerList->at(0)->character->getPos().y() > 2000)
    {
        playerList->at(0)->character->setPos(doodadsPixList->at(0)->pos().x() + 100, doodadsPixList->at(0)->pos().y() - 800);
    }
    if(playerList->at(1)->character->getPos().y() > 2000)
    {
        playerList->at(1)->character->setPos(posO->x(), posO->y() + 200);
        playerList->at(1)->character->setSpeeds(QPointF(playerList->at(1)->character->getSpeeds().x(), playerList->at(1)->character->getSpeeds().y()-20));
    }

    *counter+=1;

    if(*counter>5)
    {
        //qDebug()<<"Game::Player0 , anim:" + playerList->at(0)->character->currentAnimName() + " , frame:" + QString::number(playerList->at(0)->character->currentAnimFrame().x());
        //qDebug()<<"Game::Player1 , anim:" + playerList->at(1)->character->currentAnimName() + " , frame:" + QString::number(playerList->at(1)->character->currentAnimFrame().x());
        *counter=0;

        QString block(playerList->at(0)->character->getIcon());
        /*block.append(" _ animation: " + playerList->at(0)->character->currentAnimName() + " " + QString::number(playerList->at(0)->character->currentAnimFrame().x()));
        block.append(" -Pos:" + QString::number(int(posO->x()) - int(playerList->at(0)->character->getPos().x() * 10)) + ":" + QString::number(int(posO->y()) - int(playerList->at(0)->character->getPos().y() * 10)));
        block.append(" -DeltaPos:" + QString::number(int(playerList->at(0)->character->getSpeeds().x() * 10)) + ":" + QString::number(int(playerList->at(0)->character->getSpeeds().y() * 10)));
        block.append(" -Damages:" + QString::number(characterList->at(0)->getDamages(playerList->at(0)->character->currentAnimFrame())));
        block.append(" -Propulsions:" + QString::number(characterList->at(0)->getPropulsion(playerList->at(0)->character->currentAnimFrame())));*/
        //test->setText(block);
        //test->setIcon(QPixmap(*playerSpriteList->at(0)->at(0)->at(0)));
        test->setIcon(*playerSpriteList->at(0)->at(playerList->at(0)->character->currentAnimFrame().y())->at(playerList->at(0)->character->currentAnimFrame().x()));
        test->setIconSize(QSize(100,100));
        test->show();

        /**Pointers**/
        {
            pointerList->at(0)->resetTransform();
            scene->removeItem(pointerList->at(0));
            pointerList->at(0)->setPos(playerList->at(0)->character->getPos());
            scene->addItem(pointerList->at(0));

            pointerList->at(1)->resetTransform();
            scene->removeItem(pointerList->at(1));
            pointerList->at(1)->setPos(playerList->at(1)->character->getPos());
            scene->addItem(pointerList->at(1));

            pointerList->at(2)->resetTransform();
            scene->removeItem(pointerList->at(2));
            pointerList->at(2)->setPos(forgroundBox->pos());
            scene->addItem(pointerList->at(2));

            pointerList->at(3)->resetTransform();
            scene->removeItem(pointerList->at(3));
            pointerList->at(3)->setPos(doodadsPixList->at(0)->pos());
            scene->addItem(pointerList->at(3));

            pointerList->at(4)->resetTransform();
            scene->removeItem(pointerList->at(4));
            pointerList->at(4)->setPos(doodadsBoxList->at(0)->pos());
            scene->addItem(pointerList->at(4));
        }
    }

    view->show();
    gameTimer->start();
}

/***Controls Event***/
void TiGameWindow::controlChanged(int idPlayer, QString cmd, bool valueB)
{
    qreal val;
    if(valueB == true){val = 1.0;}
    else{val = 0.0;}
    playerList->at(idPlayer)->setCommandes(val, cmd);
}
void TiGameWindow::controlChanged(int idPlayer, QString cmd, qreal valueB)
{
    playerList->at(idPlayer)->setCommandes(qreal(valueB), cmd);
}
void TiGameWindow::controlChanged(int idPlayer, QString cmd, QPointF valueB)
{
    if(cmd == "JoyL")
    {
        playerList->at(idPlayer)->setCommandes(valueB.x(), "xJoyL");
        playerList->at(idPlayer)->setCommandes(valueB.y(), "yJoyL");
    }
    else if(cmd == "JoyR")
    {
        playerList->at(idPlayer)->setCommandes(valueB.x(), "xJoyR");
        playerList->at(idPlayer)->setCommandes(valueB.y(), "yJoyR");
    }
}

/***Characters Events***/
void TiGameWindow::animateEvent(QString type, int noPlayer)
{
    if(type == "character")
    {
        //check collisions and animations played
        changeAnim(type, noPlayer);
        changePos(type, noPlayer);
        changePixmap(type, noPlayer);
    }

}
void TiGameWindow::changeAnim(QString type, int noPlayer)
{
    bool isfalling = (playerList->at(noPlayer)->character->getSpeeds().y() > 0);
    bool isjumping = (playerList->at(noPlayer)->character->getSpeeds().y() < 0);

    if(*counter == 0)
    {
        //falling
        if(isfalling)
        {
            //qAirAtk
            if(playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk"
               && playerList->at(noPlayer)->getCommande("X") != 0)
            {
                playerList->at(noPlayer)->character->playAnim("qAirAtk");
            }
            //fall
            else if(playerList->at(noPlayer)->character->currentAnimName() != "fall"
                    && playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk")
            {
                playerList->at(noPlayer)->character->playAnim("fall");
            }
        }
        //jump
        else if(isjumping)
        {
            //qAirAtk
            if(playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk"
               && playerList->at(noPlayer)->getCommande("X") != 0)
            {
                playerList->at(noPlayer)->character->playAnim("qAirAtk");
            }
            //jump
            else if(playerList->at(noPlayer)->character->currentAnimName() != "jump"
                    && playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk")
            {
                playerList->at(noPlayer)->character->playAnim("jump");
            }
        }
        //walk ->
        else if(playerList->at(noPlayer)->getCommande("Right") != 0
                && playerList->at(noPlayer)->getCommande("Left") == 0
                && playerList->at(noPlayer)->getCommande("Down") == 0
                && playerList->at(noPlayer)->getCommande("A") == 0
                && playerList->at(noPlayer)->getCommande("X") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "qAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guard"
                && playerList->at(noPlayer)->character->currentAnimName() != "crouch"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guardCrouch")
        {
            if(playerList->at(noPlayer)->character->currentAnimName() != "walk")
            {
                playerList->at(noPlayer)->character->playAnim("walk");
            }
        }
        //walk <-
        else if(playerList->at(noPlayer)->getCommande("Left") != 0
                && playerList->at(noPlayer)->getCommande("Right") == 0
                && playerList->at(noPlayer)->getCommande("Down") == 0
                && playerList->at(noPlayer)->getCommande("A") == 0
                && playerList->at(noPlayer)->getCommande("X") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "qAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guard"
                && playerList->at(noPlayer)->character->currentAnimName() != "crouch"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guardCrouch")
        {
            if(playerList->at(noPlayer)->character->currentAnimName() != "walk")
            {
                playerList->at(noPlayer)->character->playAnim("walk");
            }
        }
        //qCrouchAtk
        else if(playerList->at(noPlayer)->getCommande("Down") != 0
                && playerList->at(noPlayer)->getCommande("X") != 0
                && playerList->at(noPlayer)->getCommande("A") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "qAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guard"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk")
        {
            playerList->at(noPlayer)->character->playAnim("crouchAtk");
        }
        //guardCrouch
        else if(playerList->at(noPlayer)->getCommande("Down") != 0
                && playerList->at(noPlayer)->getCommande("A") != 0
                && playerList->at(noPlayer)->getCommande("X") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "qAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guard"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guardCrouch")
        {
            playerList->at(noPlayer)->character->playAnim("guardCrouch");
        }
        //qAtk
        else if(playerList->at(noPlayer)->getCommande("X") != 0
                && playerList->at(noPlayer)->getCommande("L2") == 0
                && playerList->at(noPlayer)->getCommande("Down") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "fall"
                && playerList->at(noPlayer)->character->currentAnimName() != "jump"
                && playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "crouch"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guardCrouch")
        {
            if(playerList->at(noPlayer)->character->currentAnimName() != "qAtk")
            {
                playerList->at(noPlayer)->character->playAnim("qAtk");
            }
        }
        //guard
        else if(playerList->at(noPlayer)->getCommande("A") != 0
                && playerList->at(noPlayer)->getCommande("L2") == 0
                && playerList->at(noPlayer)->getCommande("Down") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "qAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "fall"
                && playerList->at(noPlayer)->character->currentAnimName() != "jump"
                && playerList->at(noPlayer)->character->currentAnimName() != "crouch"
                && playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guardCrouch")
        {
            if(playerList->at(noPlayer)->character->currentAnimName() != "guard")
            {
                playerList->at(noPlayer)->character->playAnim("guard");
            }
        }
        //crouch
        else if(playerList->at(noPlayer)->getCommande("Down") != 0
                && playerList->at(noPlayer)->getCommande("L1") == 0
                && playerList->at(noPlayer)->getCommande("L2") == 0
                && playerList->at(noPlayer)->getCommande("X") == 0
                && playerList->at(noPlayer)->getCommande("Y") == 0
                && playerList->at(noPlayer)->getCommande("B") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "qAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guard"
                && playerList->at(noPlayer)->character->currentAnimName() != "fall"
                && playerList->at(noPlayer)->character->currentAnimName() != "jump"
                && playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guardCrouch")
        {
            if(playerList->at(noPlayer)->character->currentAnimName() != "crouch")
            {
                playerList->at(noPlayer)->character->playAnim("crouch");
            }
        }
        //stand
        else if(playerList->at(noPlayer)->getCommande("Down") == 0
                && playerList->at(noPlayer)->getCommande("A") == 0
                && playerList->at(noPlayer)->getCommande("B") == 0
                && playerList->at(noPlayer)->getCommande("X") == 0
                && playerList->at(noPlayer)->getCommande("Y") == 0
                && playerList->at(noPlayer)->getCommande("Up") == 0
                && playerList->at(noPlayer)->getCommande("Left") == 0
                && playerList->at(noPlayer)->getCommande("Right") == 0
                && playerList->at(noPlayer)->character->currentAnimName() != "stand"
                && playerList->at(noPlayer)->character->currentAnimName() != "walk"
                && playerList->at(noPlayer)->character->currentAnimName() != "qAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "fall"
                && playerList->at(noPlayer)->character->currentAnimName() != "jump"
                && playerList->at(noPlayer)->character->currentAnimName() != "qAirAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "crouch"
                && playerList->at(noPlayer)->character->currentAnimName() != "qCrouchAtk"
                && playerList->at(noPlayer)->character->currentAnimName() != "guardCrouch")
        {
            if(playerList->at(noPlayer)->character->currentAnimName() != "stand")
            {
                playerList->at(noPlayer)->character->playAnim("stand");
            }
        }
        else
        {
            if(playerList->at(noPlayer)->character->currentAnimName() != "stand")
            {
                playerList->at(noPlayer)->character->playAnim("stand");
            }
        }

        playerList->at(noPlayer)->character->nextFrame();
    }
}
void TiGameWindow::changePos(QString type, int noPlayer)
{
    bool isColliding = false;
    bool isfalling = true;

    /**** collision avec la plateforme ****/
    {
        //** collision avec le hitbox plateforme **//
        if(spriteList->at(noPlayer)->collidesWithItem(forgroundBox))
        {
            //** collision avec le sprite plateforme **//
            if(spriteList->at(noPlayer)->collidesWithItem(forground))
            {
                //** à droite du sprite platforme **//
                if(playerList->at(noPlayer)->character->getPos().x() > (forground->x() + forground->pixmap().width() - 20))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() + 10, playerList->at(noPlayer)->character->getPos().y());
                }
                //** à gauche du sprite platforme **//
                else if(playerList->at(noPlayer)->character->getPos().x() < forground->x() + 20)
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() - 10, playerList->at(noPlayer)->character->getPos().y());
                }
                //** dedans le sprite platforme **//
                else
                {
                    isfalling = false;
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x(), playerList->at(noPlayer)->character->getPos().y() - 10.0);
                }
            }
            //** collision avec le hitbox plateforme **//
            else
            {
                //** à droite du hitbox platforme **//
                if(playerList->at(noPlayer)->character->getPos().x() > (forgroundBox->x() + forgroundBox->pixmap().width() - 20))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() + 10, playerList->at(noPlayer)->character->getPos().y());
                }
                //** à gauche du hitbox platforme **//
                else if(playerList->at(noPlayer)->character->getPos().x() < forgroundBox->x() + 20)
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() - 10, playerList->at(noPlayer)->character->getPos().y());
                }
                //** dedans le hitbox platforme **//
                else
                {
                    isfalling = false;
                }
            }

        }
        //** collision avec le hitbox cube **//
        else if(spriteList->at(noPlayer)->collidesWithItem(doodadsBoxList->at(0)))
        {
            //** collision avec le sprite cube **//
            if(spriteList->at(noPlayer)->collidesWithItem(doodadsPixList->at(0)))
            {
                //** en haut le sprite cube **//
                if(spriteList->at(noPlayer)->pos().y() < (doodadsPixList->at(0)->pos().y() - doodadsPixList->at(0)->pixmap().height() / 2))
                {
                    isfalling = false;
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x(), playerList->at(noPlayer)->character->getPos().y() - 10.0);
                }
                //** à droite le sprite cube **//
                else if(spriteList->at(noPlayer)->pos().x() > (doodadsPixList->at(0)->pos().x() + doodadsPixList->at(0)->pixmap().width() / 2))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() + 10.0, playerList->at(noPlayer)->character->getPos().y());
                }
                //** à gauche le sprite cube **//
                else if(spriteList->at(noPlayer)->pos().x() < (doodadsPixList->at(0)->pos().x() + doodadsPixList->at(0)->pixmap().width() / 2))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() - 10.0, playerList->at(noPlayer)->character->getPos().y());
                }
                //** en bas le sprite cube **//
                else if(spriteList->at(noPlayer)->pos().y() < (doodadsPixList->at(0)->pos().y() - doodadsPixList->at(0)->pixmap().height() / 2))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x(), playerList->at(noPlayer)->character->getPos().y() + 10.0);
                }
            }
            //** collision avec le hitbox cube **//
            else
            {
                //** est dessus le hitbox cube **//
                if(spriteList->at(noPlayer)->pos().y() < (doodadsBoxList->at(0)->pos().y() - doodadsBoxList->at(0)->pixmap().height() / 4))
                {
                    isfalling = false;
                }
                //** à droite le hitbox cube **//
                else if(spriteList->at(noPlayer)->pos().x() > (doodadsBoxList->at(0)->pos().x() + doodadsBoxList->at(0)->pixmap().width() / 2))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() + 10.0, playerList->at(noPlayer)->character->getPos().y());
                }
                //** à gauche le hitbox cube **//
                else if(spriteList->at(noPlayer)->pos().x() < (doodadsBoxList->at(0)->pos().x() + doodadsBoxList->at(0)->pixmap().width() / 2))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() - 10.0, playerList->at(noPlayer)->character->getPos().y());
                }
                //** est dessous le hitbox cube **//
                else if(spriteList->at(noPlayer)->pos().y() < (doodadsBoxList->at(0)->pos().y() - doodadsBoxList->at(0)->pixmap().height() / 2))
                {
                    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() - 10.0, playerList->at(noPlayer)->character->getPos().y());
                }
                else
                {
                    playerList->at(noPlayer)->character->setSpeeds(QPointF(playerList->at(noPlayer)->character->getSpeeds().x()-10, playerList->at(noPlayer)->character->getSpeeds().y()-10));
                }
            }
        }
        //** pas de collision **//
        else
        {
            isfalling = true;
        }

    }
    /**** collision avec les autres joueurs  ****/
    {
        for(int i=0; i < hitboxList->size(); i++)
        {
            /**** i frappe noPlayer ****/
            if(hurtboxList->at(noPlayer)->collidesWithItem(hitboxList->at(i)) && i != noPlayer)
            {
                /**** noPlayer & i se frappent mutuelement ****/
                if(hitboxList->at(noPlayer)->collidesWithItem(hitboxList->at(i)))
                {
                    //** i est en guard & noPlayer attaque **//
                    if((playerList->at(i)->character->currentAnimName() == "guard"
                        || playerList->at(i)->character->currentAnimName() == "guardCrouch")
                    && (playerList->at(noPlayer)->character->currentAnimName() == "qAtk"
                        || playerList->at(noPlayer)->character->currentAnimName() == "qAirAtk"
                        || playerList->at(noPlayer)->character->currentAnimName() == "qCrouchAtk"))
                    {
                        //** i est a gauche de noPlayer **//
                        if(playerList->at(i)->character->getPos().x() < playerList->at(noPlayer)->character->getPos().x())
                        {
                            playerList->at(i)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + playerList->at(i)->character->getWeight() - playerList->at(noPlayer)->character->getWeight() + characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(noPlayer)->character->getSpeeds().x() + playerList->at(i)->character->getSpeeds().x());
                        }
                        //** noPlayer est a gauche de i **//
                        else
                        {
                            playerList->at(i)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - playerList->at(i)->character->getWeight() + playerList->at(noPlayer)->character->getWeight() - characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(noPlayer)->character->getSpeeds().x() + playerList->at(i)->character->getSpeeds().x());
                        }
                    }
                    //** noPlayer est en guard & i attaque **//
                    else if((playerList->at(noPlayer)->character->currentAnimName() == "guard"
                            || playerList->at(noPlayer)->character->currentAnimName() == "guardCrouch")
                        && (playerList->at(i)->character->currentAnimName() == "qAtk"
                            || playerList->at(i)->character->currentAnimName() == "qAirAtk"
                            || playerList->at(i)->character->currentAnimName() == "qCrouchAtk"))
                    {
                        //** i est a gauche de noPlayer **//
                        if(playerList->at(noPlayer)->character->getPos().x() < playerList->at(noPlayer)->character->getPos().x())
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + playerList->at(i)->character->getWeight() + characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(noPlayer)->character->getSpeeds().x() + playerList->at(i)->character->getSpeeds().x());
                            playerList->at(noPlayer)->character->recieveDamage(playerList->at(i)->character->currentDamages() / 2);
                        }
                        //** noPlayer est a gauche de i **//
                        else
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - playerList->at(i)->character->getWeight() - characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(noPlayer)->character->getSpeeds().x() + playerList->at(i)->character->getSpeeds().x());
                            playerList->at(noPlayer)->character->recieveDamage(playerList->at(i)->character->currentDamages() / 2);
                        }
                    }
                    //** i & noPlayer sont en guard **//
                    else if((playerList->at(noPlayer)->character->currentAnimName() == "guard"
                        || playerList->at(noPlayer)->character->currentAnimName() == "guardCrouch")
                    && (playerList->at(i)->character->currentAnimName() == "guard"
                        || playerList->at(i)->character->currentAnimName() == "guardCrouch"))
                    {
                        //** i est a gauche de noPlayer **//
                        if(playerList->at(i)->character->getPos().x() < playerList->at(noPlayer)->character->getPos().x())
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + playerList->at(i)->character->getWeight() - playerList->at(noPlayer)->character->getWeight() + characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(noPlayer)->character->getSpeeds().x() + playerList->at(i)->character->getSpeeds().x());
                        }
                        //** noPlayer est a gauche de i **//
                        else
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - playerList->at(i)->character->getWeight() + playerList->at(noPlayer)->character->getWeight() - characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(noPlayer)->character->getSpeeds().x() + playerList->at(i)->character->getSpeeds().x());
                        }
                    }
                    //** i & noPlayer attaquent **//
                    else if((playerList->at(noPlayer)->character->currentAnimName() == "qAtk"
                        || playerList->at(noPlayer)->character->currentAnimName() == "qAirAtk"
                        || playerList->at(noPlayer)->character->currentAnimName() == "qCrouchAtk")
                    && (playerList->at(i)->character->currentAnimName() == "qAtk"
                        || playerList->at(i)->character->currentAnimName() == "qAirAtk"
                        || playerList->at(i)->character->currentAnimName() == "qCrouchAtk"))
                    {
                        //** i est a gauche de noPlayer **//
                        if(playerList->at(i)->character->getPos().x() < playerList->at(noPlayer)->character->getPos().x())
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + playerList->at(i)->character->getWeight() + characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(i)->character->getSpeeds().x());
                            playerList->at(noPlayer)->character->recieveDamage(playerList->at(i)->character->currentDamages());
                        }
                        //** noPlayer est a gauche de i **//
                        else
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - playerList->at(i)->character->getWeight() - characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(i)->character->getSpeeds().x());
                            playerList->at(noPlayer)->character->recieveDamage(playerList->at(i)->character->currentDamages());
                        }
                    }
                    //** autre **//
                    else
                    {
                        //** i est a gauche de noPlayer **//
                        if(playerList->at(i)->character->getPos().x() < playerList->at(noPlayer)->character->getPos().x())
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + playerList->at(i)->character->getWeight() + characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(i)->character->getSpeeds().x());
                        }
                        //** noPlayer est a gauche de i **//
                        else
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - playerList->at(i)->character->getWeight() - characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(i)->character->getSpeeds().x());
                        }
                    }
                }
                /**** noPlayer est frappé par i ****/
                else
                {
                    //** i est en guard **//
                    if(playerList->at(i)->character->currentAnimName() == "guard"
                    || playerList->at(i)->character->currentAnimName() == "guardCrouch")
                    {
                        //** noPlayer a gauche de i**//
                        if(playerList->at(noPlayer)->character->getPos().x() < playerList->at(i)->character->getPos().x())
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + 20 + playerList->at(i)->character->getWeight() - playerList->at(noPlayer)->character->getWeight() + playerList->at(i)->character->getSpeeds().x() * 2 - playerList->at(noPlayer)->character->getSpeeds().x() * 2 );
                        }
                        //** i a gauche de noPlayer**//
                        else
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - 20 - playerList->at(i)->character->getWeight() + playerList->at(noPlayer)->character->getWeight() + playerList->at(i)->character->getSpeeds().x() * 2 - playerList->at(noPlayer)->character->getSpeeds().x() * 2 );
                        }
                    }
                    //** i attaque noPlayer
                    else if(playerList->at(i)->character->currentAnimName() == "qAtk"
                    || playerList->at(i)->character->currentAnimName() == "qAirAtk"
                    || playerList->at(i)->character->currentAnimName() == "qCrouchAtk")
                    {
                        //** i est a gauche de noPlayer **//
                        if(hurtboxList->at(noPlayer)->x() > hitboxList->at(i)->x())
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + playerList->at(i)->character->getWeight() - playerList->at(noPlayer)->character->getWeight() + characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(i)->character->getSpeeds().x() * 2);
                            playerList->at(noPlayer)->character->recieveDamage(playerList->at(i)->character->currentDamages());
                        }
                        //** noPlayer est a gauche de i **//
                        else
                        {
                            playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - playerList->at(i)->character->getWeight() + playerList->at(noPlayer)->character->getWeight() - characterList->at(0)->getPropulsion(playerList->at(i)->character->currentAnimFrame()) + playerList->at(i)->character->getSpeeds().x() * 2);
                            playerList->at(noPlayer)->character->recieveDamage(playerList->at(i)->character->currentDamages());
                        }
                    }
                }
            }
            /**** i & noPlayer se rentrent dedant sans attaquer ****/
            else if(hurtboxList->at(noPlayer)->collidesWithItem(hurtboxList->at(i)) && i != noPlayer
            && (playerList->at(noPlayer)->character->currentAnimName() == "walk"
                || playerList->at(noPlayer)->character->currentAnimName() == "fall"
                || playerList->at(noPlayer)->character->currentAnimName() == "jump"
                || playerList->at(noPlayer)->character->currentAnimName() == "stand"
                || playerList->at(noPlayer)->character->currentAnimName() == "crouch")
            && (playerList->at(i)->character->currentAnimName() == "walk"
                || playerList->at(i)->character->currentAnimName() == "fall"
                || playerList->at(i)->character->currentAnimName() == "jump"
                || playerList->at(i)->character->currentAnimName() == "stand"
                || playerList->at(i)->character->currentAnimName() == "crouch"))
            {
                //** noPlayer a gauche de i**//
                if(playerList->at(noPlayer)->character->getPos().x() < playerList->at(i)->character->getPos().x())
                {
                     playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() + 10 + playerList->at(i)->character->getSpeeds().x() * 2 - playerList->at(noPlayer)->character->getSpeeds().x() * 2 );
                }
                //** i a gauche de noPlayer**//
                else
                {
                    playerList->at(noPlayer)->character->getPos().setX(playerList->at(noPlayer)->character->getPos().x() - 10 + playerList->at(i)->character->getSpeeds().x() * 2 - playerList->at(noPlayer)->character->getSpeeds().x() * 2 );
                }
            }
        }
    }

    /**** déplacements ****/
    {
        //** fall **//
        if(isfalling)
        {
            //** fast-falling **//
            if(playerList->at(noPlayer)->getCommande("Down") != 0)
            {
                playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x(), playerList->at(noPlayer)->character->getSpeeds().y() + (playerList->at(noPlayer)->character->getSpeeds().y() + playerList->at(noPlayer)->character->getWeight() / 4.9) / 4);
            }
            //** falling **//
            else
            {
                playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x(), playerList->at(noPlayer)->character->getSpeeds().y() + (playerList->at(noPlayer)->character->getSpeeds().y() + playerList->at(noPlayer)->character->getWeight() / 4.9) / 8);
            }
//                playerList->at(i)->character->getPos().setX(playerList->at(i)->character->getPos().x());
//                playerList->at(i)->character->getPos().setY(playerList->at(i)->character->getPos().y() + 1);
        }
        //** ne tombe pas **//
        else
        {
            playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x(), 0);
        }
        //** Jump **//
        if(playerList->at(noPlayer)->getCommande("Up") != 0 && !isfalling)
        {
            playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x(), playerList->at(noPlayer)->character->getSpeeds().y() - 30.0);
        }
        //** walk -> **//
        if(playerList->at(noPlayer)->getCommande("Right") != 0 && playerList->at(noPlayer)->getCommande("Left") == 0 && playerList->at(noPlayer)->getCommande("Down") == 0)
        {
            playerList->at(noPlayer)->character->setOrientation(false);
            if(isfalling)
            {
                if(playerList->at(noPlayer)->character->getSpeeds().x() < 4.0 )
                {
                    playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x() + 3.0, playerList->at(noPlayer)->character->getSpeeds().y());
                }
            }
            else
            {
                if(playerList->at(noPlayer)->character->getSpeeds().x() < 6.0 )
                {
                    playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x() + 4.0, playerList->at(noPlayer)->character->getSpeeds().y());
                }
            }
        }
        //** walk <- **//
        if(playerList->at(noPlayer)->getCommande("Left") != 0 && playerList->at(noPlayer)->getCommande("Right") == 0 && playerList->at(noPlayer)->getCommande("Down") == 0)
        {
            playerList->at(noPlayer)->character->setOrientation(true);
            if(isfalling)
            {
                if(playerList->at(noPlayer)->character->getSpeeds().x() > - 4.0 )
                {
                    playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x() - 3.0, playerList->at(noPlayer)->character->getSpeeds().y());
                }
            }
            else
            {
                if(playerList->at(noPlayer)->character->getSpeeds().x() > - 6.0 )
                {
                    playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x() - 4.0, playerList->at(noPlayer)->character->getSpeeds().y());
                }
            }
        }

    }

    //** reset des ammorties de déplassements **//
    if((playerList->at(noPlayer)->character->getSpeeds().x() < 0.01 && playerList->at(noPlayer)->character->getSpeeds().x() > -0.01) && (playerList->at(noPlayer)->character->getSpeeds().y() < 0.01 && playerList->at(noPlayer)->character->getSpeeds().y() > -0.01))
    {
        playerList->at(noPlayer)->character->setSpeeds(0, 0);
    }
    //** reset des ammorties de glissades **//
    else if(playerList->at(noPlayer)->character->getSpeeds().x() < 0.01 && playerList->at(noPlayer)->character->getSpeeds().x() > -0.01)
    {
        playerList->at(noPlayer)->character->setSpeeds(0, playerList->at(noPlayer)->character->getSpeeds().y() * 0.85);
    }
    //** reset des ammorties de gravité **//
    else if(playerList->at(noPlayer)->character->getSpeeds().y() < 0.01 && playerList->at(noPlayer)->character->getSpeeds().y() > -0.01)
    {
        playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x() * 0.96, 0);
    }
    //** ammorties de déplassements **//
    else
    {
        playerList->at(noPlayer)->character->setSpeeds(playerList->at(noPlayer)->character->getSpeeds().x() * 0.96, playerList->at(noPlayer)->character->getSpeeds().y() * 0.85);
    }

    //** associer les ammorties **//
    playerList->at(noPlayer)->character->setPos(playerList->at(noPlayer)->character->getPos().x() + playerList->at(noPlayer)->character->getSpeeds().x(), playerList->at(noPlayer)->character->getPos().y() + playerList->at(noPlayer)->character->getSpeeds().y());
}
void TiGameWindow::changePixmap(QString type, int noPlayer)
{
    spriteList->at(noPlayer)->resetTransform();
    hitboxList->at(noPlayer)->resetTransform();
    hurtboxList->at(noPlayer)->resetTransform();
    qDebug()<<spriteList->at(noPlayer);
    qDebug()<<hitboxList->at(noPlayer);
    qDebug()<<hurtboxList->at(noPlayer);
    scene->removeItem(spriteList->at(noPlayer));
    scene->removeItem(hitboxList->at(noPlayer));
    scene->removeItem(hurtboxList->at(noPlayer));
    QTransform trans1;
    spriteList->at(noPlayer)->setPixmap(*playerSpriteList->at(noPlayer)->at(playerList->at(noPlayer)->character->currentAnimFrame().y())->at(playerList->at(noPlayer)->character->currentAnimFrame().x()));
    hitboxList->at(noPlayer)->setPixmap(*playerHitboxList->at(noPlayer)->at(playerList->at(noPlayer)->character->currentAnimFrame().y())->at(playerList->at(noPlayer)->character->currentAnimFrame().x()));
    hurtboxList->at(noPlayer)->setPixmap(*playerHurtboxList->at(noPlayer)->at(playerList->at(noPlayer)->character->currentAnimFrame().y())->at(playerList->at(noPlayer)->character->currentAnimFrame().x()));
    if(playerList->at(noPlayer)->character->getOrientation())
    {
        spriteList->at(noPlayer)->setPos(QPointF(playerList->at(noPlayer)->character->getPos().x() + 250 * 0.79, playerList->at(noPlayer)->character->getPos().y() - 250 * 0.79));
        hitboxList->at(noPlayer)->setPos(QPointF(playerList->at(noPlayer)->character->getPos().x() + 250 * 0.79, playerList->at(noPlayer)->character->getPos().y() - 250 * 0.79));
        hurtboxList->at(noPlayer)->setPos(QPointF(playerList->at(noPlayer)->character->getPos().x() + 250 * 0.79, playerList->at(noPlayer)->character->getPos().y() - 250 * 0.79));
        trans1.scale(-0.8,0.8);
    }
    else
    {
        spriteList->at(noPlayer)->setPos(QPointF(playerList->at(noPlayer)->character->getPos().x() - 250 * 0.79, playerList->at(noPlayer)->character->getPos().y() - 250 * 0.79));
        hitboxList->at(noPlayer)->setPos(QPointF(playerList->at(noPlayer)->character->getPos().x() - 250 * 0.79, playerList->at(noPlayer)->character->getPos().y() - 250 * 0.79));
        hurtboxList->at(noPlayer)->setPos(QPointF(playerList->at(noPlayer)->character->getPos().x() - 250 * 0.79, playerList->at(noPlayer)->character->getPos().y() - 250 * 0.79));
        trans1.scale(0.8,0.8);
    }
    //trans1.scale(1.1,1.1);
    spriteList->at(noPlayer)->setTransform(trans1);
    hitboxList->at(noPlayer)->setTransform(trans1);
    hurtboxList->at(noPlayer)->setTransform(trans1);
    spriteList->at(noPlayer)->setZValue(6);
    hitboxList->at(noPlayer)->setZValue(5);
    hurtboxList->at(noPlayer)->setZValue(5);
    scene->addItem(spriteList->at(noPlayer));
    scene->addItem(hitboxList->at(noPlayer));
    scene->addItem(hurtboxList->at(noPlayer));
}

/***Doodads Events***/
void TiGameWindow::animateEvent(TiDoodad *doodAnimated)
{
    //check collisions and animations played
    changeAnim(doodAnimated);
    changePos(doodAnimated);
    changePixmap(doodAnimated);
}
void TiGameWindow::changeAnim(TiDoodad *doodAnimated)
{

}
void TiGameWindow::changePos(TiDoodad *doodAnimated)
{

}
void TiGameWindow::changePixmap(TiDoodad *doodAnimated)
{

}

/***Effects Events***/
void TiGameWindow::animateEvent(TiEffects *fxAnimated)
{
    //check collisions and animations played
    changeAnim(fxAnimated);
    changePos(fxAnimated);
    changePixmap(fxAnimated);
}
void TiGameWindow::changeAnim(TiEffects *fxAnimated)
{

}
void TiGameWindow::changePos(TiEffects *fxAnimated)
{

}
void TiGameWindow::changePixmap(TiEffects *fxAnimated)
{

}

