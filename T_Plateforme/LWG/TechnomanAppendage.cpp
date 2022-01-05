#include "TechnomanAppendage.h"


TechnomanAppendage::TechnomanAppendage(TechnomanAppendage *appendage)
{
    m_Name = new QString(*appendage->m_Name);
    m_Level = new double(*appendage->m_Level);
    m_Cost = new double(*appendage->m_Cost);
    m_Type = new double(*appendage->m_Type);
    m_Class = new double(*appendage->m_Class);
    m_Tips = new QString(*appendage->m_Tips);
    m_graphicsItem = new QGraphicsPixmapItem(appendage->m_graphicsItem);
    m_width = new double(*appendage->m_width);
    m_height = new double(*appendage->m_height);
    m_depth = new double(*appendage->m_depth);
    m_weight = new double(*appendage->m_weight);
    m_resistance = new double(*appendage->m_resistance);
    m_parent = new QWidget(appendage->m_parent);
}

TechnomanAppendage::TechnomanAppendage
(
    QString *appName, double *appLevel, double *appCost, double *appType, double *appClass,
    QString *appTips,
    QGraphicsPixmapItem *graphicsItem,
    double *width, double *height, double *depth,
    double *weight, double *resistance,
    QWidget *parent
)
{
    m_Name = new QString(*appName);
    m_Level = new double(*appLevel);
    m_Cost = new double(*appCost);
    m_Type = new double(*appType);
    m_Class = new double(*appClass);
    m_Tips = new QString(*appTips);
    m_graphicsItem = new QGraphicsPixmapItem(graphicsItem);
    m_width = new double(*width);
    m_height = new double(*height);
    m_depth = new double(*depth);
    m_weight = new double(*weight);
    m_resistance = new double(*resistance);
    m_parent = new QWidget(parent);

}

TechnomanAppendage::~TechnomanAppendage()
{

}


void TechnomanAppendage::setName(QString *appName)
{

}

void TechnomanAppendage::setLevel(double *appLevel)
{

}

void TechnomanAppendage::setCost(double *appCost)
{

}

void TechnomanAppendage::setType(double *appType)
{

}

void TechnomanAppendage::setClass(double *appClass)
{

}

void TechnomanAppendage::setTips(QString *appTips)
{

}

void TechnomanAppendage::setGraphicsItem(QGraphicsItem *graphicsItem)
{

}

void TechnomanAppendage::setWidth(double *width)
{

}

void TechnomanAppendage::setHeight(double *height)
{

}

void TechnomanAppendage::setDepth(double *depth)
{

}

void TechnomanAppendage::setWeight(double *weight)
{

}

void TechnomanAppendage::setResistance(double *resistance)
{

}

void TechnomanAppendage::setParent(QWidget *parent)
{

}
