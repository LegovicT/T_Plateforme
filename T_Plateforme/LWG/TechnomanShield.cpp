#include"TechnomanShield.h"


TechnomanShield::TechnomanShield(TechnomanShield *shield)
{
    m_Name = new QString(*shield->m_Name);
    m_Level = new double(*shield->m_Level);
    m_Cost = new double(*shield->m_Cost);
    m_Type = new double(*shield->m_Type);
    m_Class = new double(*shield->m_Class);
    m_Tips = new QString(*shield->m_Tips);
    m_graphicsItem = new QGraphicsPixmapItem(shield->m_graphicsItem);
    m_width = new double(*shield->m_width);
    m_height = new double(*shield->m_height);
    m_depth = new double(*shield->m_depth);
    m_weight = new double(*shield->m_weight);
    m_resistance = new double(*shield->m_resistance);
    m_parent = new QWidget(shield->m_parent);
}

TechnomanShield::TechnomanShield
(
    QString *shiName, double *shiLevel, double *shiCost, double *shiType, double *shiClass,
    QString *shiTips,
    QGraphicsItem *graphicsItem,
    double *width, double *height, double *depth,
    double *weight, double *resistance,
    QWidget *parent
)
{
    m_Name = new QString(*shiName);
    m_Level = new double(*shiLevel);
    m_Cost = new double(*shiCost);
    m_Type = new double(*shiType);
    m_Class = new double(*shiClass);
    m_Tips = new QString(*shiTips);
    m_graphicsItem = new QGraphicsPixmapItem(graphicsItem);
    m_width = new double(*width);
    m_height = new double(*height);
    m_depth = new double(*depth);
    m_weight = new double(*weight);
    m_resistance = new double(*resistance);
    m_parent = new QWidget(parent);

}

TechnomanShield::~TechnomanShield()
{

}


void TechnomanShield::setName(QString *appName)
{

}

void TechnomanShield::setLevel(double *appLevel)
{

}

void TechnomanShield::setCost(double *appCost)
{

}

void TechnomanShield::setType(double *appType)
{

}

void TechnomanShield::setClass(double *appClass)
{

}

void TechnomanShield::setTips(QString *appTips)
{

}

void TechnomanShield::setGraphicsItem(QGraphicsItem *graphicsItem)
{

}

void TechnomanShield::setWidth(double *width)
{

}

void TechnomanShield::setHeight(double *height)
{

}

void TechnomanShield::setDepth(double *depth)
{

}

void TechnomanShield::setWeight(double *weight)
{

}

void TechnomanShield::setResistance(double *resistance)
{

}

void TechnomanShield::setParent(QWidget *parent)
{

}

