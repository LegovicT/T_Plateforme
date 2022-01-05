#ifndef TECHNOMANAPPENDAGES_H
#define TECHNOMANAPPENDAGES_H

#include <QtGui>
#include <QtWidgets>
#include <QTimer>
#include <QList>

class TechnomanAppendage : public QObject
{
    Q_OBJECT

public:
    TechnomanAppendage(TechnomanAppendage *appendage);
    TechnomanAppendage
    (
        QString *appName, double *appLevel=0, double *appCost=0, double *appType=0, double *appClass=0,
        QString *appTips=0,
        QGraphicsPixmapItem *graphicsItem=0,
        double *width=0, double *height=0, double *depth=0,
        double *weight=0, double *resistance=0,
        QWidget *parent=0
    );
    ~TechnomanAppendage();

protected:
    QString *m_Name;
    double *m_Level;
    double *m_Cost;
    double *m_Type;
    double *m_Class;
    QString *m_Tips;
    QGraphicsPixmapItem *m_graphicsItem;
    double *m_width;
    double *m_height;
    double *m_depth;
    double *m_weight;
    double *m_resistance;
    QWidget *m_parent;

public slots:
    void setName(QString *appName);
    void setLevel(double *appLevel);
    void setCost(double *appCost);
    void setType(double *appType);
    void setClass(double *appClass);
    void setTips(QString *appTips);
    void setGraphicsItem(QGraphicsItem *graphicsItem);
    void setWidth(double *width);
    void setHeight(double *height);
    void setDepth(double *depth);
    void setWeight(double *weight);
    void setResistance(double *resistance);
    void setParent(QWidget *parent);

};

#endif // TECHNOMANAPPENDAGES_H
