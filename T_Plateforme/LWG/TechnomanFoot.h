#ifndef TECHNOMANFOOT_H
#define TECHNOMANFOOT_H

#include <QtGui>
#include <QtWidgets>
#include <QTimer>
#include <QList>

class TechnomanFoot : public QObject
{
    Q_OBJECT

public:
    TechnomanFoot(TechnomanFoot *foot);
    TechnomanFoot
    (
        QString *fooName, double *fooLevel=0, double *fooCost=0, double *fooType=0, double *fooClass=0,
        QString *fooTips=0,
        QGraphicsItem *graphicsItem=0,
        double *width=0, double *height=0, double *depth=0,
        double *weight=0, double *resistance=0,
        QWidget *parent=0
    );
    ~TechnomanFoot();

protected:
    QString *m_Name;
    double *m_Level;
    double *m_Cost;
    double *m_Type;
    double *m_Class;
    QString *m_Tips;
    QGraphicsItem *m_graphicsItem;
    double *m_width;
    double *m_height;
    double *m_depth;
    double *m_weight;
    double *m_resistance;
    QWidget *m_parent;

public slots:
    void setName(QString *fooName);
    void setLevel(double *fooLevel);
    void setCost(double *fooCost);
    void setType(double *fooType);
    void setClass(double *fooClass);
    void setTips(QString *fooTips);
    void setGraphicsItem(QGraphicsItem *graphicsItem);
    void setWidth(double *width);
    void setHeight(double *height);
    void setDepth(double *depth);
    void setWeight(double *weight);
    void setResistance(double *resistance);
    void setParent(QWidget *parent);

};


#endif // TECHNOMANFOOT_H
