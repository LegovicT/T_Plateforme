#include"TechnomanFoot.h"


TechnomanFoot::TechnomanFoot(TechnomanFoot *foot)
{
    m_Name = new QString(*foot->m_Name);
    m_Level = new double(*foot->m_Level);
    m_Cost = new double(*foot->m_Cost);
    m_Type = new double(*foot->m_Type);
    m_Class = new double(*foot->m_Class);
    m_Tips = new QString(*foot->m_Tips);
    m_graphicsItem = new QGraphicsPixmapItem(foot->m_graphicsItem);
    m_width = new double(*foot->m_width);
    m_height = new double(*foot->m_height);
    m_depth = new double(*foot->m_depth);
    m_weight = new double(*foot->m_weight);
    m_resistance = new double(*foot->m_resistance);
    m_parent = new QWidget(foot->m_parent);
}

TechnomanFoot::TechnomanFoot
(
    QString *fooName, double *fooLevel, double *fooCost, double *fooType, double *fooClass,
    QString *fooTips,
    QGraphicsItem *graphicsItem,
    double *width, double *height, double *depth,
    double *weight, double *resistance,
    QWidget *parent
)
{
    m_Name = new QString(*fooName);
    m_Level = new double(*fooLevel);
    m_Cost = new double(*fooCost);
    m_Type = new double(*fooType);
    m_Class = new double(*fooClass);
    m_Tips = new QString(*fooTips);
    m_graphicsItem = new QGraphicsPixmapItem(graphicsItem);
    m_width = new double(*width);
    m_height = new double(*height);
    m_depth = new double(*depth);
    m_weight = new double(*weight);
    m_resistance = new double(*resistance);
    m_parent = new QWidget(parent);

}

TechnomanFoot::~TechnomanFoot()
{

}


void TechnomanFoot::setName(QString *appName)
{

}

void TechnomanFoot::setLevel(double *appLevel)
{

}

void TechnomanFoot::setCost(double *appCost)
{

}

void TechnomanFoot::setType(double *appType)
{

}

void TechnomanFoot::setClass(double *appClass)
{

}

void TechnomanFoot::setTips(QString *appTips)
{

}

void TechnomanFoot::setGraphicsItem(QGraphicsItem *graphicsItem)
{

}

void TechnomanFoot::setWidth(double *width)
{

}

void TechnomanFoot::setHeight(double *height)
{

}

void TechnomanFoot::setDepth(double *depth)
{

}

void TechnomanFoot::setWeight(double *weight)
{

}

void TechnomanFoot::setResistance(double *resistance)
{

}

void TechnomanFoot::setParent(QWidget *parent)
{

}

