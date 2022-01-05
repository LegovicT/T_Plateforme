#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QDebug>
#include <QObject>
#include <QGamepad>
#include <QtGamepad>
#include <QKeyEvent>

#include "LWG/LWGmainwindow.h" //include the laucher interface header fot LWG
#include "RftG/RftGmainwindow.h" //include the laucher interface header for RftG
#include "MTD/MTDMainWindow.h" //include the laucher interface header for MTD


class communication : public QObject  // IMPORTANT : pour être utilisable dans le code QML, votre classe doit dériver de QObject ou QQuickItem.
{
    Q_OBJECT
    //Q_PROPERTY(QString text READ text WRITE append NOTIFY valueChanged)
public:
    explicit communication(QObject *parent = 0);

public slots:
    //
    QString toStringCpp();
    //Get gamepad events
    QString toJoyRightCpp(qreal RJroyX, qreal RJoyY);
    QString toJoyLeftCpp(qreal LJoyX, qreal LJoyY);
    QString toXbtnCpp(bool xPushed);
    QString toYbtnCpp(bool yPushed);
    QString toAbtnCpp(bool aPushed);
    QString toBbtnCpp(bool bPushed);
    QString toUpbtnCpp(bool upPushed);
    QString toDownbtnCpp(bool downPushed);
    QString toRightbtnCpp(bool rightPushed);
    QString toLeftbtnCpp(bool leftPushed);
    QString toStartbtnCpp(bool startPushed);
    QString toSelectbtnCpp(bool selectPushed);
    QString toLIbtnCpp(bool lIPushed);
    QString toLIIbtnCpp(qreal lIIPushed);
    QString toRIbtnCpp(bool rIPushed);
    QString toRIIbtnCpp(qreal rIIPushed);
    QString toLIIIbtnCpp(bool lIIIPushed);
    QString toRIIIbtnCpp(bool rIIIPushed);

protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QString text;
    int compteur = 0;
    LWGMainWindow *lwgGame;
    RftgMainWindow *rftgGame;
    MTDMainWindow *mtdGame;
    QGamepad *gpad;

signals:
    void changeCpp(QString text);
    void joyLeftChanged(QPointF value);
    void joyRightChanged(QPointF value);
    void aBtnChanged(bool value);
    void bBtnChanged(bool value);
    void xBtnChanged(bool value);
    void yBtnChanged(bool value);
    void upBtnChanged(bool value);
    void downBtnChanged(bool value);
    void leftBtnChanged(bool value);
    void rightBtnChanged(bool value);
    void startBtnChanged(bool value);
    void selectBtnChanged(bool value);
    void lIBtnChanged(bool value);
    void lIIBtnChanged(qreal value);
    void rIBtnChanged(bool value);
    void rIIBtnChanged(qreal value);
    void lIIIBtnChanged(bool value);
    void rIIIBtnChanged(bool value);
};

#endif // COMMUNICATION_H
