#ifndef TECHNOMANCORE_H
#define TECHNOMANCORE_H

#include <QtGui>
#include <QtWidgets>
#include <QTimer>
#include <QList>

class TechnomanCore : public QObject
{
    Q_OBJECT

public:
    TechnomanCore(TechnomanCore *core);
    TechnomanCore
    (
        QString *corName, double *corLevel=0, double *corCost=0, double *corType=0, double *corClass=0,
        QString *corTips=0,
        QGraphicsItem *graphicsItem=0,
        double *width=0, double *height=0, double *depth=0,
        double *weight=0, double *resistance=0,
        QWidget *parent=0
    );
    ~TechnomanCore();

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
    void setName(QString *corName);
    void setLevel(double *corLevel);
    void setCost(double *corCost);
    void setType(double *corType);
    void setClass(double *corClass);
    void setTips(QString *corTips);
    void setGraphicsItem(QGraphicsItem *graphicsItem);
    void setWidth(double *width);
    void setHeight(double *height);
    void setDepth(double *depth);
    void setWeight(double *weight);
    void setResistance(double *resistance);
    void setParent(QWidget *parent);

};


#endif // TECHNOMANCORE_H
