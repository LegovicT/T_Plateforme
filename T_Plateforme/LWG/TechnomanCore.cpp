#include"TechnomanCore.h"


TechnomanCore::TechnomanCore(TechnomanCore *core)
{
    m_Name = new QString(*core->m_Name);
    m_Level = new double(*core->m_Level);
    m_Cost = new double(*core->m_Cost);
    m_Type = new double(*core->m_Type);
    m_Class = new double(*core->m_Class);
    m_Tips = new QString(*core->m_Tips);
    m_graphicsItem = new QGraphicsPixmapItem(core->m_graphicsItem);
    m_width = new double(*core->m_width);
    m_height = new double(*core->m_height);
    m_depth = new double(*core->m_depth);
    m_weight = new double(*core->m_weight);
    m_resistance = new double(*core->m_resistance);
    m_parent = new QWidget(core->m_parent);
}

TechnomanCore::TechnomanCore
(
    QString *corName, double *corLevel, double *corCost, double *corType, double *corClass,
    QString *corTips,
    QGraphicsItem *graphicsItem,
    double *width, double *height, double *depth,
    double *weight, double *resistance,
    QWidget *parent
)
{
    m_Name = new QString(*corName);
    m_Level = new double(*corLevel);
    m_Cost = new double(*corCost);
    m_Type = new double(*corType);
    m_Class = new double(*corClass);
    m_Tips = new QString(*corTips);
    m_graphicsItem = new QGraphicsPixmapItem(graphicsItem);
    m_width = new double(*width);
    m_height = new double(*height);
    m_depth = new double(*depth);
    m_weight = new double(*weight);
    m_resistance = new double(*resistance);
    m_parent = new QWidget(parent);

}

TechnomanCore::~TechnomanCore()
{

}


void TechnomanCore::setName(QString *appName)
{

}

void TechnomanCore::setLevel(double *appLevel)
{

}

void TechnomanCore::setCost(double *appCost)
{

}

void TechnomanCore::setType(double *appType)
{

}

void TechnomanCore::setClass(double *appClass)
{

}

void TechnomanCore::setTips(QString *appTips)
{

}

void TechnomanCore::setGraphicsItem(QGraphicsItem *graphicsItem)
{

}

void TechnomanCore::setWidth(double *width)
{

}

void TechnomanCore::setHeight(double *height)
{

}

void TechnomanCore::setDepth(double *depth)
{

}

void TechnomanCore::setWeight(double *weight)
{

}

void TechnomanCore::setResistance(double *resistance)
{

}

void TechnomanCore::setParent(QWidget *parent)
{

}

