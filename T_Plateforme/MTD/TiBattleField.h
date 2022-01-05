#ifndef TIBATTLEFIELD_H
#define TIBATTLEFIELD_H

#include <QApplication>
#include <QObject>
#include <QDebug>
#include <QDesktopWidget>
#include <QtWidgets>
#include <QWidget>

#include <QtGui>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QStandardItemModel>
#include <QPushButton>

#include <QTimer>
#include <QDateTimeEdit>

#include <QKeyEvent>
#include <QMouseEvent>

class TiBattleField : public QWidget
{
    Q_OBJECT

    public:
        TiBattleField(QString *mName, int *mWidth, int *mHeight, QWidget *parent = nullptr);
        TiBattleField(QString *mName, QPoint *mSize, QWidget *parent = nullptr);
        TiBattleField(QWidget *parent = nullptr);
        ~TiBattleField();

    public slots:
        /**** GETTERS ****/
        QString getName();
        QPoint getSize();
        int getFaith();
        int getTechnology();
        int getArcane();

        /**** SETTERS ****/
        //void addElement(TiElement *element, QPoint *pos);
        //void moveElement(TiElement *element, QPoint *pos);
        //void removeElement(TiElement *element);
        //void sellElement(TiElement *element);

    protected :
        QString *name;
        QPoint *size;
        //TiElement[][] *elements;
};

#endif // TIBATTLEFIELD_H
