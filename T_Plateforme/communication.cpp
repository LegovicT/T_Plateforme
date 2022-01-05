#include "communication.h"

communication::communication(QObject *parent) : QObject(parent)
{
    rftgGame = new RftgMainWindow();
//    rftgGame->show();
    rftgGame->close();
    lwgGame = new LWGMainWindow();
//    lwgGame->show();
    lwgGame->close();
    mtdGame = new MTDMainWindow();
    mtdGame->show();
//    mtdGame->close();


    /*GamePad Controller*/
    {
//        QList<int> manettes = QGamepadManager::instance()->connectedGamepads();
//        if (manettes.isEmpty())
//        {
//            qDebug() << "Aucune manette détectée !";
//        }
//        else
//        {
//            qDebug() << "Nombre de manettes :" << manettes.size();
//        }
//        for (auto m : manettes)
//        {
//            QGamepad *manette = new QGamepad(m);
//            qDebug() << "Manette :" << m;
//            qDebug() << "  device id :   " << manette->deviceId();
//            qDebug() << "  nom:        " << manette->name();
//            qDebug() << "  connecte ?" << manette->isConnected();
//        }

//        gpad = new QGamepad(manettes.first());
//        qDebug() << "Manette :" << "first";
//        qDebug() << "  device id :   " << gpad->deviceId();
//        qDebug() << "  nom:        " << gpad->name();
//        qDebug() << "  connecte ?" << gpad->isConnected();
    }

    if(rftgGame->isVisible())
    {
        qDebug()<<QString("rftg visible");
        connect(this, SIGNAL(aBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("A"), bool value)));
        connect(this, SIGNAL(bBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("B"), bool value)));
        connect(this, SIGNAL(xBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("X"), bool value)));
        connect(this, SIGNAL(yBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("Y"), bool value)));
        connect(this, SIGNAL(upBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("Up"), bool value)));
        connect(this, SIGNAL(downBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("Down"), bool value)));
        connect(this, SIGNAL(leftBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("Left"), bool value)));
        connect(this, SIGNAL(rightBtnChanged(bool value)), rftgGame, SLOT(controlChanged(QString("Right"), bool value)));
    }
    if(lwgGame->isVisible())
    {
        qDebug()<<QString("lwg visible");
        connect(this, SIGNAL(aBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("A"), bool value)));
        connect(this, SIGNAL(bBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("B"), bool value)));
        connect(this, SIGNAL(xBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("X"), bool value)));
        connect(this, SIGNAL(yBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("Y"), bool value)));
        connect(this, SIGNAL(upBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("Up"), bool value)));
        connect(this, SIGNAL(downBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("Down"), bool value)));
        connect(this, SIGNAL(leftBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("Left"), bool value)));
        connect(this, SIGNAL(rightBtnChanged(bool value)), lwgGame, SLOT(controlChanged(QString("Right"), bool value)));
    }

}

QString communication::toStringCpp()
{
//    QString r = "You have clicked on QML Button";
//    qDebug()<<r;
//    return r;

    compteur++;
    text = "New txt!"+QString::number(compteur,'f',0);
    //text = "New txt!";
    qDebug()<<text;
    emit changeCpp(text);
    return text;
}void communication::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z)
    {
        rftgGame->controlChanged(QString("keyZ"), true);
        lwgGame->controlChanged(QString("keyZ"), true);
    }
    else if(event->key() == Qt::Key_Q)
    {
        rftgGame->controlChanged(QString("keyQ"), true);
        lwgGame->controlChanged(QString("keyQ"), true);
    }
    else if(event->key() == Qt::Key_D)
    {
        rftgGame->controlChanged(QString("keyD"), true);
        lwgGame->controlChanged(QString("keyD"), true);
    }
    else if(event->key() == Qt::Key_S)
    {
        rftgGame->controlChanged(QString("keyS"), true);
        lwgGame->controlChanged(QString("keyS"), true);
    }
    else if(event->key() == Qt::Key_O)
    {
        rftgGame->controlChanged(QString("keyO"), true);
        lwgGame->controlChanged(QString("keyO"), true);
    }
    else if(event->key() == Qt::Key_K)
    {
        rftgGame->controlChanged(QString("keyK"), true);
        lwgGame->controlChanged(QString("keyK"), true);
    }
    else if(event->key() == Qt::Key_L)
    {
        rftgGame->controlChanged(QString("keyL"), true);
        lwgGame->controlChanged(QString("keyL"), true);
    }
    else if(event->key() == Qt::Key_M)
    {
        rftgGame->controlChanged(QString("keyM"), true);
        lwgGame->controlChanged(QString("keyM"), true);
    }
    else if(event->key() == Qt::Key_Escape)
    {
        qApp->quit();
    }
    else if(event->key() == Qt::Key_Space)
    {
    }
    else
    {
        qDebug()<< Qt::Key(event->key());
    }
}
void communication::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Z)
    {
        rftgGame->controlChanged(QString("keyZ"), false);
        lwgGame->controlChanged(QString("keyZ"), false);
    }
    else if(event->key() == Qt::Key_Q)
    {
        rftgGame->controlChanged(QString("keyQ"), false);
        lwgGame->controlChanged(QString("keyQ"), false);
    }
    else if(event->key() == Qt::Key_D)
    {
        rftgGame->controlChanged(QString("keyD"), false);
        lwgGame->controlChanged(QString("keyD"), false);
    }
    else if(event->key() == Qt::Key_S)
    {
        rftgGame->controlChanged(QString("keyS"), false);
        lwgGame->controlChanged(QString("keyS"), false);
    }
    else if(event->key() == Qt::Key_O)
    {
        rftgGame->controlChanged(QString("keyO"), false);
        lwgGame->controlChanged(QString("keyO"), false);
    }
    else if(event->key() == Qt::Key_K)
    {
        rftgGame->controlChanged(QString("keyK"), false);
        lwgGame->controlChanged(QString("keyK"), false);
    }
    else if(event->key() == Qt::Key_L)
    {
        rftgGame->controlChanged(QString("keyL"), false);
        lwgGame->controlChanged(QString("keyL"), false);
    }
    else if(event->key() == Qt::Key_M)
    {
        rftgGame->controlChanged(QString("keyM"), false);
        lwgGame->controlChanged(QString("keyM"), false);
    }
}
void communication::mousePressEvent(QMouseEvent *event)
{
    int Xpressed = event ->x();
    int Ypressed = event ->y();
}
void communication::mouseReleaseEvent(QMouseEvent *event)
{
    int Xreleased = event ->x();
    int Yreleased = event ->y();
}
void communication::mouseMoveEvent(QMouseEvent *event)
{
    int Xmoved = event ->x();
    int Ymoved = event ->y();
}


QString communication::toJoyRightCpp(qreal RJoyX, qreal RJoyY)
{
    text = "RS x:"+QString::number(RJoyX)+", y:"+QString::number(RJoyY);
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toJoyLeftCpp(qreal LJoyX, qreal LJoyY)
{
    text = "LS x:"+QString::number(LJoyX)+", y:"+QString::number(LJoyY);
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;

}
QString communication::toXbtnCpp(bool xPushed)
{
    if(xPushed)
    {
        text = "X Pushed";
    }
    else
    {
        text = "X Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toYbtnCpp(bool yPushed)
{
    if(yPushed)
    {
        text = "Y Pushed";
    }
    else
    {
        text = "Y Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toAbtnCpp(bool aPushed)
{
    if(aPushed)
    {
        text = "A Pushed";
    }
    else
    {
        text = "A Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toBbtnCpp(bool bPushed)
{
    if(bPushed)
    {
        text = "B Pushed";
    }
    else
    {
        text = "B Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toUpbtnCpp(bool upPushed)
{
    if(upPushed)
    {
        text = "Up Pushed";
    }
    else
    {
        text = "Up Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toDownbtnCpp(bool downPushed)
{
    if(downPushed)
    {
        text = "Down Pushed";
    }
    else
    {
        text = "Down Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toRightbtnCpp(bool rightPushed)
{
    if(rightPushed)
    {
        text = "Right Pushed";
    }
    else
    {
        text = "Right Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toLeftbtnCpp(bool leftPushed)
{
    if(leftPushed)
    {
        text = "Left Pushed";
    }
    else
    {
        text = "Left Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toStartbtnCpp(bool startPushed)
{
    if(startPushed)
    {
        text = "Start Pushed";
    }
    else
    {
        text = "Start Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toSelectbtnCpp(bool selectPushed)
{
    if(selectPushed)
    {
        text = "Select Pushed";
    }
    else
    {
        text = "Select Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toLIbtnCpp(bool lIPushed)
{
    if(lIPushed)
    {
        text = "L1 Pushed";
    }
    else
    {
        text = "L1 Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toLIIbtnCpp(qreal lIIPushed)
{
    if(lIIPushed != 0.0)
    {
        text = "L2:"+QString::number(lIIPushed);
    }
    else
    {
        text = "L2 Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toRIbtnCpp(bool rIPushed)
{
    if(rIPushed)
    {
        text = "R1 Pushed";
    }
    else
    {
        text = "R1 Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toRIIbtnCpp(qreal rIIPushed)
{
    if(rIIPushed != 0.0)
    {
        text = "R2:"+QString::number(rIIPushed);
    }
    else
    {
        text = "R2 Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toLIIIbtnCpp(bool lIIIPushed)
{
    if(lIIIPushed)
    {
        text = "L3 Pushed";
    }
    else
    {
        text = "L3 Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
QString communication::toRIIIbtnCpp(bool rIIIPushed)
{
    if(rIIIPushed)
    {
        text = "R3 Pushed";
    }
    else
    {
        text = "R3 Released";
    }
        qDebug()<<text;
        emit changeCpp(text);
        lwgGame->setControl(text);
        rftgGame->setControl(text);
        return text;
}
