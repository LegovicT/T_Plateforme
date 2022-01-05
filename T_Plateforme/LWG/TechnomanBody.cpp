#include"TechnomanBody.h"


TechnomanBody::TechnomanBody(TechnomanBody *body)
{
    m_Name = new QString(*body->m_Name);
    m_Level = new double(*body->m_Level);
    m_Cost = new double(*body->m_Cost);
    m_Type = new double(*body->m_Type);
    m_Class = new double(*body->m_Class);
    m_Tips = new QString(*body->m_Tips);
    m_graphicsItem = new QGraphicsPixmapItem(body->m_graphicsItem);
    m_width = new double(*body->m_width);
    m_height = new double(*body->m_height);
    m_depth = new double(*body->m_depth);
    m_weight = new double(*body->m_weight);
    m_resistance = new double(*body->m_resistance);
    m_parent = new QWidget(body->m_parent);
}

TechnomanBody::TechnomanBody
(
    QString *bodName, double *bodLevel, double *bodCost, double *bodType, double *bodClass,
    QString *bodTips,
    QGraphicsItem *graphicsItem,
    double *width, double *height, double *depth,
    double *weight, double *resistance,
    QWidget *parent
)
{
    m_Name = new QString(*bodName);
    m_Level = new double(*bodLevel);
    m_Cost = new double(*bodCost);
    m_Type = new double(*bodType);
    m_Class = new double(*bodClass);
    m_Tips = new QString(*bodTips);
    m_graphicsItem = new QGraphicsPixmapItem(graphicsItem);
    m_width = new double(*width);
    m_height = new double(*height);
    m_depth = new double(*depth);
    m_weight = new double(*weight);
    m_resistance = new double(*resistance);
    m_parent = new QWidget(parent);

}

TechnomanBody::~TechnomanBody()
{

}


void TechnomanBody::setName(QString *appName)
{

}

void TechnomanBody::setLevel(double *appLevel)
{

}

void TechnomanBody::setCost(double *appCost)
{

}

void TechnomanBody::setType(double *appType)
{

}

void TechnomanBody::setClass(double *appClass)
{

}

void TechnomanBody::setTips(QString *appTips)
{

}

void TechnomanBody::setGraphicsItem(QGraphicsItem *graphicsItem)
{

}

void TechnomanBody::setWidth(double *width)
{

}

void TechnomanBody::setHeight(double *height)
{

}

void TechnomanBody::setDepth(double *depth)
{

}

void TechnomanBody::setWeight(double *weight)
{

}

void TechnomanBody::setResistance(double *resistance)
{

}

void TechnomanBody::setParent(QWidget *parent)
{

}

