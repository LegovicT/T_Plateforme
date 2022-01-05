#ifndef TECHNOMANBODY_H
#define TECHNOMANBODY_H

#include <QtGui>
#include <QtWidgets>
#include <QTimer>
#include <QList>

class TechnomanBody : public QObject
{
    Q_OBJECT

public:
    TechnomanBody(TechnomanBody *body);
    TechnomanBody
    (
        QString *bodName, double *bodLevel=0, double *bodCost=0, double *bodType=0, double *bodClass=0,
        QString *bodTips=0,
        QGraphicsItem *graphicsItem=0,
        double *width=0, double *height=0, double *depth=0,
        double *weight=0, double *resistance=0,
        QWidget *parent=0
    );
    ~TechnomanBody();

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
    void setName(QString *bodName);
    void setLevel(double *bodLevel);
    void setCost(double *bodCost);
    void setType(double *bodType);
    void setClass(double *bodClass);
    void setTips(QString *bodTips);
    void setGraphicsItem(QGraphicsItem *graphicsItem);
    void setWidth(double *width);
    void setHeight(double *height);
    void setDepth(double *depth);
    void setWeight(double *weight);
    void setResistance(double *resistance);
    void setParent(QWidget *parent);

};


#endif // TECHNOMANBODY_H
