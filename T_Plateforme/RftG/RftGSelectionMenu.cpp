#include "RftGSelectionMenu.h"

RftgSelectionMenu::RftgSelectionMenu(QWidget *parent)
{
    setWindowTitle("Selection :: Reach For The God");

/*******************PUBLICS***********************/
    {
        arenaList = new QList<TiArena *>;
        characterList = new QList<TiCharacter *>;
        playerList = new QList<TiPlayer *>;
        selectionList = new QList<int >;
        selectionArena = new int(-1);
        readyPlayers = new bool(false);
        readyArena = new bool(false);
        startGameBtn = new QPushButton;
        startGameBtn->setText("");
        startGameBtn->setGeometry(this->geometry().width() / 8, this->geometry().height() / 8, this->geometry().width() * 6 / 8, this->geometry().height() * 6 / 8);
        startGameBtn->setWindowOpacity(0.6);
        startGameBtn->hide();
    }

/********************TIMER************************/
    {
        timer = new QTimer;
        counter = new int(0);
        timer->setInterval(64); //16ms == 60ips
    }

/********************WIDGETS**********************/
    {
        view = new QGraphicsView(this);
        scene = new QGraphicsScene;
        posO = new QPointF;

        test = new QPushButton(this);
        test->setText("WHAT???");
        test->setFont(QFont("Times", 10, QFont::Bold));
        test->setGeometry(0,0,1920,100);
    }

/**********************UI*************************/
    {
        arenaIconList = new QList<QGraphicsPixmapItem *>;
        characterIconList = new QList<QGraphicsPixmapItem *>;
        playerFocusList = new QList<QPoint >;
    }

/******************SELECTORS**********************/
    {
        arenaPixSelected = new QGraphicsPixmapItem(QPixmap("../T_Plateforme/SRC/RftG/Images/CharacterSelectionBox1.png"));
        selectorPix = new QPixmap("../T_Plateforme/SRC/RftG/Images/CharacterSelectionBox0.png");
        selectedPix = new QPixmap("../T_Plateforme/SRC/RftG/Images/CharacterSelectionBox.png");
        selectors = new QList<QGraphicsPixmapItem *>;
        charactersPixSelected = new QList<QGraphicsPixmapItem *>;
    }

/***************SELECTION VIEWER******************/
    {
            arenaSelection = new QGraphicsPixmapItem;
            charactersAnimSelection = new QList<QGraphicsPixmapItem *>;
            charactersNameSelection = new QList<QPushButton *>;
            charactersDescriptionSelection = new QList<QTextEdit *>;
            charactersTipsSelection = new QList<QTextEdit *>;

            standAnimsSelection = new QList<QList<QPixmap *> *>;
            frameAnimSelection = new QList<int *>;

            QPixmap *randSprite = new QPixmap("../T_Plateforme/SRC/RftG/Images/RandomSelectionSprite.png");
            QList<QPixmap *> *randomAnim = new QList<QPixmap *>;
            for(int fra=0; fra < 11; fra++)
            {
                QPixmap *randFrame = new QPixmap();
                *randFrame = randSprite->copy(fra * 500, 0, 500, 500);
                randomAnim->append(randFrame);
            }
            standAnimsSelection->append(randomAnim);
    }

/******************CONNECTIONS********************/
    {
        connect(timer, SIGNAL(timeout()), this, SLOT(startLoop()));
    }

}
RftgSelectionMenu::~RftgSelectionMenu()
{
}


void RftgSelectionMenu::addArena(TiArena *arena)
{
    arenaList->append(arena);
}
void RftgSelectionMenu::addCharacter(TiCharacter *character)
{
    characterList->append(character);

    QPixmap *charSprite = new QPixmap(character->getSprite("sprite"));
    QList<QPixmap *> *charAnim = new QList<QPixmap *>;
    for(int fra=0; fra < character->getFrameCount("stand"); fra++)
    {
        QPixmap *charFrame = new QPixmap();
        *charFrame = charSprite->copy(fra * 500, 0, 500, 500);
        charAnim->append(charFrame);
    }
    standAnimsSelection->append(charAnim);
}
void RftgSelectionMenu::addPlayer(TiPlayer *player)
{
    playerList->append(player);
    playerFocusList->append(QPoint(0, 0));
    selectionList->append(-1);

    QGraphicsPixmapItem *charAnimSelection = new QGraphicsPixmapItem;
    QPushButton *charNameSelection = new QPushButton(this);
    QTextEdit *charDescriptionSelection = new QTextEdit(this);
    QTextEdit *charTipsSelection = new QTextEdit(this);
    charactersNameSelection->append(charNameSelection);
    charactersDescriptionSelection->append(charDescriptionSelection);
    charactersTipsSelection->append(charTipsSelection);
    charactersAnimSelection->append(charAnimSelection);
    frameAnimSelection->append(new int(0));
}
void RftgSelectionMenu::characterSelected(QString playerName, int idCharacter)
{
    for(int plr=0; plr < playerList->size(); plr++)
    {
        if(playerList->at(plr)->getName() == playerName)
        {
            selectionList->replace(plr, idCharacter);
        }
    }
}
void RftgSelectionMenu::characterSelected(TiPlayer *player, TiCharacter *character)
{
    player->character = character;
}
void RftgSelectionMenu::arenaSelected(int idArena)
{
    *selectionArena = idArena;
}
void RftgSelectionMenu::initSelection()
{
//#### Window Init ####//
    {
        QDesktopWidget screen;
        QRect screenGeom = screen.screenGeometry(this);
        view->setGeometry(screenGeom.x(), screenGeom.y() + 000, screenGeom.width(), screenGeom.height());
        view->setScene(scene);
        scene->setSceneRect(view->rect().x(), view->rect().y(), view->rect().width() + 8000, view->rect().height() + 8000);
        scene->setSceneRect(view->rect().x() + 2, view->rect().y() + 2, view->rect().width() - 4, view->rect().height() - 4);
        scene->setBackgroundBrush(QBrush(QColor(0,10,60)));
        posO->setX(scene->width() / 2);
        posO->setY(750);
    }

//#### Arenas & Characters Icons ####//
    {
        for(int rna=0; rna < arenaList->size(); rna++)
        {
            QGraphicsPixmapItem *newItem = new QGraphicsPixmapItem(QPixmap(arenaList->at(rna)->getIcon()));
            arenaIconList->append(newItem);
        }

        for(int crtr=0; crtr < characterList->size(); crtr++)
        {
            QGraphicsPixmapItem *newItem = new QGraphicsPixmapItem(QPixmap(characterList->at(crtr)->getIcon()));
            arenaIconList->append(newItem);
        }
    }

//#### Arenas & Characters Cases ####//
    {
        int aNum;
    //Arenas
        if(arenaList->size() < 12){aNum = 12;}
        else{aNum = arenaList->size();}
        for(int rna=0; rna < aNum; rna++)
        {
            QGraphicsPixmapItem *caseIco = new QGraphicsPixmapItem;
            caseIco->setPixmap(QPixmap("../T_Plateforme/SRC/RftG/Images/CharacterSelectionCase.png"));
            caseIco->setPos(QPointF(50 + caseIco->pixmap().width() * rna, 50));
            caseIco->setZValue(4);
            scene->addItem(caseIco);

            if(arenaList->size() > rna)
            {
                QGraphicsPixmapItem *arenaIco = new QGraphicsPixmapItem;
                arenaIco->setPixmap(arenaList->at(rna)->getIcon());
                arenaIconList->append(arenaIco);
                arenaIconList->at(rna)->setPos(QPointF(50 + caseIco->pixmap().width() * rna, 50));
                arenaIconList->at(rna)->setScale(qreal(caseIco->pixmap().width() / arenaIco->pixmap().width()));
                arenaIconList->at(rna)->setZValue(5);
                scene->addItem(arenaIconList->at(rna));
            }
        }
    //Characters
        if(characterList->size() < 12){aNum = 12;}
        else{aNum = characterList->size();}
        for(int crtr=0; crtr < aNum; crtr++)
        {
            QGraphicsPixmapItem *caseIco = new QGraphicsPixmapItem;
            caseIco->setPixmap(QPixmap("../T_Plateforme/SRC/RftG/Images/CharacterSelectionCase.png"));
            caseIco->setPos(QPointF(50 + caseIco->pixmap().width() * crtr, 200));
            caseIco->setZValue(4);
            scene->addItem(caseIco);

            if(characterList->size() > crtr)
            {
                QGraphicsPixmapItem *charIco = new QGraphicsPixmapItem;
                charIco->setPixmap(characterList->at(crtr)->getIcon());
                characterIconList->append(charIco);
                characterIconList->at(crtr)->setPos(QPointF(50 + charIco->pixmap().width() * crtr, 200));
                characterIconList->at(crtr)->setScale(qreal(caseIco->pixmap().width() / charIco->pixmap().width()));
                characterIconList->at(crtr)->setZValue(5);
                scene->addItem(characterIconList->at(crtr));
            }
        }
    }

//#### Selectors ####//
    {
        for(int plr=0; plr < playerList->size();plr++)
        {
            //Character Selectors
            QPixmap *pix = new QPixmap;
            *pix = selectorPix->copy(0, plr * 150, 150, 150);
            QGraphicsPixmapItem *selecteur = new QGraphicsPixmapItem(*pix);
            selecteur->setPixmap(*pix);
            selecteur->setPos(QPointF(50 + pix->width() * plr, 150));
            selecteur->setZValue(7);
            charactersPixSelected->append(selecteur);
            scene->addItem(charactersPixSelected->at(plr));

            //Player Selectors
            QPixmap *pixSelect = new QPixmap;
            *pixSelect = selectedPix->copy(0, plr * 150, 150, 150);
            QGraphicsPixmapItem *selector = new QGraphicsPixmapItem(*pixSelect);
            selector->setPixmap(*pixSelect);
            selector->setPos(QPointF(50 + pixSelect->width() * plr, 150));
            selector->setZValue(6);
            selectors->append(selector);
            scene->addItem(selectors->at(plr));
        }

        //Arena Selectors
        QPixmap *pixSelect = new QPixmap;
        *pixSelect = selectedPix->copy(0, 450, 150, 150);
        arenaPixSelected->setPixmap(*pixSelect);
        arenaPixSelected->setPos(QPointF(50, 150));
        arenaPixSelected->setZValue(6);
        scene->addItem(arenaPixSelected);

    }

    for(int plr=0; plr < playerList->size();plr++)
    {
//        QPixmap *charPix = new QPixmap;
//        *pix = selectorPix->copy(0, plr * 150, 150, 150);
//        charactersAnimSelection->append(charAnimSelection);

        if(plr==int(0))
        {
            charactersAnimSelection->at(plr)->setPos(200, 500);
            charactersNameSelection->at(plr)->setGeometry(5,500,200,50);
            charactersDescriptionSelection->at(plr)->setGeometry(5,550,200,100);
            charactersTipsSelection->at(plr)->setGeometry(5,650,200,200);
        }
        else
        {
            charactersAnimSelection->at(plr)->setPos(1300, 500);
            charactersNameSelection->at(plr)->setGeometry(1715,500,200,50);
            charactersDescriptionSelection->at(plr)->setGeometry(1715,550,200,100);
            charactersTipsSelection->at(plr)->setGeometry(1715,650,200,200);
        }
        charactersAnimSelection->at(plr)->setPixmap(*standAnimsSelection->at(0)->at(0));
        charactersAnimSelection->at(plr)->setScale(0.8);
        charactersAnimSelection->at(plr)->setZValue(6);
        scene->addItem(charactersAnimSelection->at(plr));
        charactersNameSelection->at(plr)->setText(playerList->at(plr)->getName());
        charactersDescriptionSelection->at(plr)->setText("Description : ");
        charactersTipsSelection->at(plr)->setText("Tips : ");

    }

    arenaSelection->setPos(0, 0);
    arenaSelection->setZValue(3);
    scene->addItem(arenaSelection);


    view->show();
    startLoop();
}
void RftgSelectionMenu::startLoop()
{
    //#### Start Conditions ####//
    {
        bool playersStart(true);

        //check players
        for(int slct=0; slct < selectionList->size(); slct++)
        {
            if(selectionList->at(slct) != -1 && playersStart != false)
            {
                *readyPlayers = true;
            }
            else
            {
                *readyPlayers = false;
                playersStart = false;
            }
        }

        //check arena
        if(*selectionArena != -1)
        {
            *readyArena = true;
            scene->removeItem(arenaSelection);
            arenaSelection->resetTransform();
            arenaSelection->setPixmap("../T_Plateforme/SRC/RftG/" + arenaList->at(*selectionArena)->getBackground());
            arenaSelection->setPos((this->width() - arenaSelection->pixmap().width()) / 2, (this->height() - arenaSelection->pixmap().height()) / 2);
            //arenaSelection->setScale(500 / arenaSelection->pixmap().height());
            scene->addItem(arenaSelection);
        }
        else
        {
            *readyArena = false;
            scene->removeItem(arenaSelection);
            arenaSelection->resetTransform();
            arenaSelection->setPixmap(QPixmap("../T_Plateforme/SRC/RftG/Images/ArenaSelectionCase1(1920-1080).png"));
            arenaSelection->setPos(0,0);
            scene->addItem(arenaSelection);
        }

        //check all
        if(*readyArena==true && *readyPlayers==true)
        {
            startGameBtn->setText("Press \"SELECT\" for start the game");
            startGameBtn->show();
        }
        else if(startGameBtn->isVisible())
        {
            startGameBtn->setText("");
            startGameBtn->hide();
        }
    }


    QString block;
    //test.append(" #P"+QString::number(0) + " Name:" + playerList->at(0)->getName() + " Icon:" + characterList->at(0)->getIcon());
    //test.append(" #P"+QString::number(0) + " X:" + QString::number(playerFocusList->at(0).x()) + " Y:" + QString::number(playerFocusList->at(0).y()));
    //test.append(" #A"+QString::number(0) + " Icon:" + arenaList->at(0)->getIcon());
    //test.append(" #A"+QString::number(1) + " Icon:" + arenaList->at(1)->getIcon());

    //update selector pos
    for(int plr=0; plr < playerList->size(); plr++)
    {
        //test.append(" #P"+QString::number(plr) + " Char:" + playerList->at(plr)->character->getName());
        block.append(" #P"+QString::number(plr) + " X:" + QString::number(playerFocusList->at(plr).x()) + " Y:" + QString::number(playerFocusList->at(plr).y()));

        charactersPixSelected->at(plr)->resetTransform();
        scene->removeItem(charactersPixSelected->at(plr));
        charactersPixSelected->at(plr)->setPos(50 + charactersPixSelected->at(plr)->pixmap().width() * playerFocusList->at(plr).x(), 50 + 150 * playerFocusList->at(plr).y());
        scene->addItem(charactersPixSelected->at(plr));

        selectors->at(plr)->resetTransform();
        scene->removeItem(selectors->at(plr));
        if(selectionList->at(plr) != -1)
        {
            selectors->at(plr)->setPos(QPointF(50 + selectors->at(plr)->pixmap().width() * selectionList->at(plr), 200));

            *frameAnimSelection->at(plr) = *frameAnimSelection->at(plr) + 1;
            if(*frameAnimSelection->at(plr) > standAnimsSelection->at(selectionList->at(plr)+1)->count()-1)
            {*frameAnimSelection->at(plr) = 0;}
            scene->removeItem(charactersAnimSelection->at(plr));
            charactersAnimSelection->at(plr)->resetTransform();
            charactersAnimSelection->at(plr)->setPixmap(*standAnimsSelection->at(selectionList->at(plr) + 1)->at(*frameAnimSelection->at(plr)));
            scene->addItem(charactersAnimSelection->at(plr));

            charactersNameSelection->at(plr)->setText(characterList->at(selectionList->at(plr))->getName());
            charactersDescriptionSelection->at(plr)->setText(characterList->at(selectionList->at(plr))->getDescription());
            charactersTipsSelection->at(plr)->setText(characterList->at(selectionList->at(plr))->getTips());
        }
        else
        {
            selectors->at(plr)->setPos(QPointF(50 + selectors->at(plr)->pixmap().width() * selectionList->at(plr), - 200));

            if(playerFocusList->at(plr).y() == 1 && playerFocusList->at(plr).x() < characterList->size())
            {
                *frameAnimSelection->at(plr) = *frameAnimSelection->at(plr) + 1;
                if(*frameAnimSelection->at(plr) > standAnimsSelection->at(playerFocusList->at(plr).x() + 1)->count()-1)
                {*frameAnimSelection->at(plr) = 0;}
                scene->removeItem(charactersAnimSelection->at(plr));
                charactersAnimSelection->at(plr)->resetTransform();
                charactersAnimSelection->at(plr)->setPixmap(*standAnimsSelection->at(playerFocusList->at(plr).x() + 1)->at(*frameAnimSelection->at(plr)));
                scene->addItem(charactersAnimSelection->at(plr));

                charactersNameSelection->at(plr)->setText(characterList->at(playerFocusList->at(plr).x())->getName());
                charactersDescriptionSelection->at(plr)->setText(characterList->at(playerFocusList->at(plr).x())->getDescription());
                charactersTipsSelection->at(plr)->setText(characterList->at(playerFocusList->at(plr).x())->getTips());
            }
            else
            {
                *frameAnimSelection->at(plr) = *frameAnimSelection->at(plr) + 1;
                if(*frameAnimSelection->at(plr) > 9)
                {*frameAnimSelection->at(plr) = 0;}
                scene->removeItem(charactersAnimSelection->at(plr));
                charactersAnimSelection->at(plr)->resetTransform();
                charactersAnimSelection->at(plr)->setPixmap(*standAnimsSelection->at(0)->at(*frameAnimSelection->at(plr)));
                scene->addItem(charactersAnimSelection->at(plr));

                charactersNameSelection->at(plr)->setText(playerList->at(plr)->getName());
                charactersDescriptionSelection->at(plr)->setText("Description : ");
                charactersTipsSelection->at(plr)->setText("Tips : ");
            }
        }
        scene->addItem(selectors->at(plr));
    }


    arenaPixSelected->resetTransform();
    scene->removeItem(arenaPixSelected);
    if(*selectionArena != -1)
    {
        arenaPixSelected->setPos(QPointF(50 + arenaPixSelected->pixmap().width() * *selectionArena, 50));
    }
    else
    {
        arenaPixSelected->setPos(QPointF(50 + arenaPixSelected->pixmap().width() * *selectionArena, - 150));
    }
    scene->addItem(arenaPixSelected);

    block.append(" _A: " + QString::number(arenaList->size()) + " _C:" + QString::number(characterList->size()) + " _P:" + QString::number(playerList->size()));
    //test.append(" #P"+QString::number(0) + " X:" + QString::number(charactersPixSelected->at(0)->pos().x()) + " Y:" + QString::number(charactersPixSelected->at(0)->pos().y()));

    //counter++;
    test->setText(block);
    //btn->setIcon(QPixmap("../T_Plateforme/SRC/RftG/Arenas/nightCity_ico.png"));
    test->setIcon(QPixmap(*standAnimsSelection->at(1)->at(0)));
    test->setIconSize(QSize(100,100));
    test->hide();
    view->show();
    timer->start();
}

void RftgSelectionMenu::actionPlayer(int idPlayer, QString act)
{
//    test->setText(QString::number(idPlayer) + act);
//    test->show();

    if(act == "Up")
    {
        if(playerFocusList->at(idPlayer).y() == 0)
        {playerFocusList->replace(idPlayer, QPoint(0, 2));}
        else
        {playerFocusList->replace(idPlayer, QPoint(0, playerFocusList->at(idPlayer).y() - 1));}
    }
    else if(act == "Down")
    {
        if(playerFocusList->at(idPlayer).y() == 2)
        {playerFocusList->replace(idPlayer, QPoint(0, 0));}
        else
        {playerFocusList->replace(idPlayer, QPoint(0, playerFocusList->at(idPlayer).y() + 1));}
    }
    else if(act == "Left")
    {
        if(playerFocusList->at(idPlayer).y() == 1) // characters selection
        {
            if(playerFocusList->at(idPlayer).x() == 0)
            {
                if(characterList->size() < 12)
                {
                    playerFocusList->replace(idPlayer, QPoint(11, 1));
                }
                else
                {
                    playerFocusList->replace(idPlayer, QPoint(characterList->size()-1, 1));
                }
            }
            else
            {
                playerFocusList->replace(idPlayer, QPoint(playerFocusList->at(idPlayer).x() - 1, 1));
            }
        }
        else if(playerFocusList->at(idPlayer).y() == 0) // arenas selection
        {
            if(playerFocusList->at(idPlayer).x() == 0)
            {
                if(arenaList->size() < 12)
                {
                    playerFocusList->replace(idPlayer, QPoint(11, 0));
                }
                else
                {
                    playerFocusList->replace(idPlayer, QPoint(arenaList->size()-1, 0));
                }
            }
            else
            {
                playerFocusList->replace(idPlayer, QPoint(playerFocusList->at(idPlayer).x() - 1, 0));
            }
        }
        else{} // == 2 // parametres selection
    }
    else if(act == "Right")
    {
        if(playerFocusList->at(idPlayer).y() == 1) // characters selection
        {
            if(characterList->size() < 12)
            {
                if(playerFocusList->at(idPlayer).x() == 11)
                {
                    playerFocusList->replace(idPlayer, QPoint(0, 1));
                }
                else
                {
                    playerFocusList->replace(idPlayer, QPoint(playerFocusList->at(idPlayer).x() + 1, 1));
                }
            }
            else
            {
                if(playerFocusList->at(idPlayer).x() == characterList->size()-1)
                {
                    playerFocusList->replace(idPlayer, QPoint(0, 1));
                }
                else
                {
                    playerFocusList->replace(idPlayer, QPoint(playerFocusList->at(idPlayer).x() + 1, 1));
                }
            }
        }
        else if(playerFocusList->at(idPlayer).y() == 0) // arenas selection
        {
            if(characterList->size() < 12)
            {
                if(playerFocusList->at(idPlayer).x() == 11)
                {
                    playerFocusList->replace(idPlayer, QPoint(0, 0));
                }
                else
                {
                    playerFocusList->replace(idPlayer, QPoint(playerFocusList->at(idPlayer).x() + 1, 0));
                }
            }
            else
            {
                if(playerFocusList->at(idPlayer).x() == arenaList->size()-1)
                {
                    playerFocusList->replace(idPlayer, QPoint(0, 0));
                }
                else
                {
                    playerFocusList->replace(idPlayer, QPoint(playerFocusList->at(idPlayer).x() + 1, 0));
                }
            }
        }
        else{} // == 2 // parametres selection
    }
    else if(act == "A")
    {
        if(playerFocusList->at(idPlayer).y() == 1) // characters selection
        {
            if(playerFocusList->at(idPlayer).x() < characterList->size())
            {
                selectionList->replace(idPlayer, playerFocusList->at(idPlayer).x());
                characterSelected(playerList->at(idPlayer), characterList->at(playerFocusList->at(idPlayer).x()));
            }
            else
            {
                selectionList->replace(idPlayer, -1);
                characterSelected(playerList->at(idPlayer), 0);
            }
        }
        else if(playerFocusList->at(idPlayer).y() == 0) // arenas selection
        {
            if(playerFocusList->at(idPlayer).x() < arenaList->size())
            {
                *selectionArena = playerFocusList->at(idPlayer).x();
            }
            else
            {
                *selectionArena = -1;
            }
        }
        else{} // == 2 // parametres selection
    }
    else if(act == "B")
    {
        if(playerFocusList->at(idPlayer).y() == 1) // characters selection
        {
            selectionList->replace(idPlayer, int(-1));
            characterSelected(playerList->at(idPlayer), 0);
        }
        else if(playerFocusList->at(idPlayer).y() == 0) // arenas selection
        {
            *selectionArena =  int(-1);
        }
        else{} // == 2 // parametres selection
    }
    else if(act == "X")
    {

    }
    else if(act == "Y")
    {

    }
    else if(act =="Select")
    {
        if(startGameBtn->isVisible())
        {
            startGameBtn->close();
            emit startGame();
        }
    }
    else
    {

    }
}

QString RftgSelectionMenu::getSelections()
{
    QString selection("");
    selection.append(QString::number(*selectionArena));
    for(int plr = 0; plr < playerList->size(); plr++)
    {
        selection.append("," + QString::number(playerFocusList->at(plr).x()));
    }
    return selection;

}
QString RftgSelectionMenu::getCharacterSelected(QString playerName)
{
    int idPlayer = 0;
    for(int plr = 0; plr < playerList->size(); plr++)
    {
        if(playerName == playerList->at(plr)->getName())
        {
            idPlayer = plr;
        }
    }
    return characterList->at(playerFocusList->at(idPlayer).x())->getName();
}
int RftgSelectionMenu::getArenaSelected()
{
    return *selectionArena;
}
