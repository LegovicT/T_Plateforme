#ifndef TECHNOMANSHIELD_H
#define TECHNOMANSHIELD_H

#include <QtGui>
#include <QtWidgets>
#include <QTimer>
#include <QList>

class TechnomanShield : public QObject
{
    Q_OBJECT

public:
    TechnomanShield(TechnomanShield *shield);
    TechnomanShield
    (
        QString *shiName, double *shiLevel=0, double *shiCost=0, double *shiType=0, double *shiClass=0,
        QString *shiTips=0,
        QGraphicsItem *graphicsItem=0,
        double *width=0, double *height=0, double *depth=0,
        double *weight=0, double *resistance=0,
        QWidget *parent=0
    );
    ~TechnomanShield();

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
    void setName(QString *shiName);
    void setLevel(double *shiLevel);
    void setCost(double *shiCost);
    void setType(double *shiType);
    void setClass(double *shiClass);
    void setTips(QString *shiTips);
    void setGraphicsItem(QGraphicsItem *graphicsItem);
    void setWidth(double *width);
    void setHeight(double *height);
    void setDepth(double *depth);
    void setWeight(double *weight);
    void setResistance(double *resistance);
    void setParent(QWidget *parent);

};


#endif // TECHNOMANSHIELD_H
