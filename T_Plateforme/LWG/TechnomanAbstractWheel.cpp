#include"TechnomanAbstractWheel.h"


TechnomanAbstractWheel::TechnomanAbstractWheel(TechnomanAbstractWheel *abstractWheel)
{
    m_parent = new QWidget(abstractWheel->m_parent);
    m_name = new QString(abstractWheel->name());
    m_core = new TechnomanCore(abstractWheel->m_core);
    m_body = new TechnomanBody(abstractWheel->m_body);
    m_foot = new TechnomanFoot(abstractWheel->m_foot);
    m_shield = new TechnomanShield(abstractWheel->m_shield);
    m_appendage1 = new TechnomanAppendage(abstractWheel->m_appendage1);
    m_appendage2 = new TechnomanAppendage(abstractWheel->m_appendage2);
    m_appendage3 = new TechnomanAppendage(abstractWheel->m_appendage3);
    m_appendage4 = new TechnomanAppendage(abstractWheel->m_appendage4);
    m_appendage5 = new TechnomanAppendage(abstractWheel->m_appendage5);
    m_appendage6 = new TechnomanAppendage(abstractWheel->m_appendage6);
    m_appendage7 = new TechnomanAppendage(abstractWheel->m_appendage7);
    m_appendage8 = new TechnomanAppendage(abstractWheel->m_appendage8);
    m_selectorItem = new QGraphicsPixmapItem(abstractWheel->m_selectorItem);
    m_attachmentItem = new QGraphicsPixmapItem(abstractWheel->m_attachmentItem);
    m_itemI = new QGraphicsPixmapItem(abstractWheel->m_itemI);
    m_itemII = new QGraphicsPixmapItem(abstractWheel->m_itemII);
    m_itemIII = new QGraphicsPixmapItem(abstractWheel->m_itemIII);
    m_itemIV = new QGraphicsPixmapItem(abstractWheel->m_itemIV);
    m_x = new double;
    m_y = new double;
    m_z = new double;
    m_angle = new double;
    m_velocity = new double;
    m_velMax = new double;
    m_acceleration = new double;
    m_rotation = new double;
    m_magnability = new double;
    m_life = new double;
    m_collisionZone = new double;
    m_power = new double;
    m_chocResist = new double;
    m_pixAnimList = new QList<QList<QPixmap *> *>;
    m_nameAnimList = new QList<QString *>;
    m_animDurationList = new QList<double *>;


    m_x = abstractWheel->m_x;
    m_y = abstractWheel->m_y;
    m_z = abstractWheel->m_z;
    m_angle = abstractWheel->m_angle;
    m_velocity = abstractWheel->m_velocity;
    m_velMax = abstractWheel->m_velMax;
    m_acceleration = abstractWheel->m_acceleration;
    m_rotation = abstractWheel->m_rotation;
    m_magnability = abstractWheel->m_magnability;
    m_life = abstractWheel->m_life;
    m_collisionZone = abstractWheel->m_collisionZone;
    m_power = abstractWheel->m_power;
    m_chocResist = abstractWheel->m_chocResist;
    m_pixAnimList = abstractWheel->m_pixAnimList;
    m_nameAnimList = abstractWheel->m_nameAnimList;
    m_animDurationList = abstractWheel->m_animDurationList;
}

TechnomanAbstractWheel::TechnomanAbstractWheel
(
    QString *name,
    TechnomanCore *core, TechnomanBody *body, TechnomanFoot *foot, TechnomanShield *shield,
    TechnomanAppendage *appendage1, TechnomanAppendage *appendage2, TechnomanAppendage *appendage3, TechnomanAppendage *appendage4,
    TechnomanAppendage *appendage5, TechnomanAppendage *appendage6, TechnomanAppendage *appendage7, TechnomanAppendage *appendage8,
    QGraphicsPixmapItem *selectorItem, QGraphicsPixmapItem *attachmentItem,
    QGraphicsPixmapItem *itemI, QGraphicsPixmapItem *itemII, QGraphicsPixmapItem *itemIII, QGraphicsPixmapItem *itemIV,
    double *x, double *y, double *z, double *angle,
    double *velocity, double *velMax, double *acceleration, double *rotation, double *magnability, double *life, double *collisionZone, double *power, double *chocResist,
    QWidget *parent
)
{
    m_name = new QString(*name);
//    m_core = new TechnomanCore(core);
//    m_body = new TechnomanBody(body);
//    m_foot = new TechnomanFoot(foot);
//    m_shield = new TechnomanShield(shield);
//    m_appendage1 = new TechnomanAppendage(appendage1);
//    m_appendage2 = new TechnomanAppendage(appendage2);
//    m_appendage3 = new TechnomanAppendage(appendage3);
//    m_appendage4 = new TechnomanAppendage(appendage4);
//    m_appendage5 = new TechnomanAppendage(appendage5);
//    m_appendage6 = new TechnomanAppendage(appendage6);
//    m_appendage7 = new TechnomanAppendage(appendage7);
//    m_appendage8 = new TechnomanAppendage(appendage8);
//    m_selectorItem = new QGraphicsPixmapItem(selectorItem);
//    m_attachmentItem = new QGraphicsPixmapItem(attachmentItem);
//    m_itemI = new QGraphicsPixmapItem(itemI);
//    m_itemII = new QGraphicsPixmapItem(itemII);
//    m_itemIII = new QGraphicsPixmapItem(itemIII);
//    m_itemIV = new QGraphicsPixmapItem(itemIV);
//    m_x = new double;
//    m_y = new double;
//    m_z = new double;
//    m_angle = new double;
//    m_velocity = new double;
//    m_velMax = new double;
//    m_acceleration = new double;
//    m_rotation = new double;
//    m_magnability = new double;
//    m_parent = new QWidget(parent);


//    m_x = x;
//    m_y = y;
//    m_z = z;
//    m_angle = angle;
//    m_velocity = velocity;
//    m_velMax = velMax;
//    m_acceleration = acceleration;
//    m_rotation = rotation;
//    m_magnability = magnability;
}

TechnomanAbstractWheel::~TechnomanAbstractWheel()
{

}


void TechnomanAbstractWheel::setParent(QWidget *parent){m_parent = parent;}
void TechnomanAbstractWheel::setName(QString *name){m_name=name;}
void TechnomanAbstractWheel::setWheel(QGraphicsPixmapItem *item){m_wheel = item;}
void TechnomanAbstractWheel::setSelector(QGraphicsPixmapItem *item){m_selectorItem = item;}
void TechnomanAbstractWheel::setAttachment(QGraphicsPixmapItem *item){m_attachmentItem = item;}
void TechnomanAbstractWheel::setItemI(QGraphicsPixmapItem *item){m_itemI = item;}
void TechnomanAbstractWheel::setItemII(QGraphicsPixmapItem *item){m_itemII = item;}
void TechnomanAbstractWheel::setItemIII(QGraphicsPixmapItem *item){m_itemIII = item;}
void TechnomanAbstractWheel::setItemIV(QGraphicsPixmapItem *item){m_itemIV = item;}
void TechnomanAbstractWheel::setX(double *x){m_x = x;}
void TechnomanAbstractWheel::setY(double *y){m_y = y;}
void TechnomanAbstractWheel::setZ(double *z){m_z = z;}
void TechnomanAbstractWheel::setAngle(double *angle){m_angle = angle;}
void TechnomanAbstractWheel::setVelocity(double *velocity){m_velocity = velocity;}
void TechnomanAbstractWheel::setVelMax(double *velMax){ m_velMax = velMax;}
void TechnomanAbstractWheel::setAcceleration(double *acceleration){m_acceleration = acceleration;}
void TechnomanAbstractWheel::setRotation(double *rotation){m_rotation = rotation;}
void TechnomanAbstractWheel::setMagnability(double *magnability){m_magnability = magnability;}
void TechnomanAbstractWheel::setLife(double *life){m_life = life;}
void TechnomanAbstractWheel::setCollideZone(double *collisionZone){m_collisionZone = collisionZone;}
void TechnomanAbstractWheel::setPower(double *power){m_power = power;}
void TechnomanAbstractWheel::setChocResist(double *chocResist){m_chocResist = chocResist;}
void TechnomanAbstractWheel::setPixAnimList(QList<QList<QPixmap *> *> *pixAnimList){m_pixAnimList = pixAnimList;}
void TechnomanAbstractWheel::changePixAnimAt(int id, QList<QPixmap *> *pixAnimList){m_pixAnimList->at(id)->clear(); m_pixAnimList->at(id)->append(*pixAnimList);}
void TechnomanAbstractWheel::setNameAnimList(QList<QString *> *nameAnimList){m_nameAnimList = nameAnimList;}
void TechnomanAbstractWheel::setDurationAnimList(QList<double *> *animDurationList){m_animDurationList = animDurationList;}


QString TechnomanAbstractWheel::name(){return *m_name;}
double TechnomanAbstractWheel::x(){return *m_x;}
double TechnomanAbstractWheel::y(){return *m_y;}
double TechnomanAbstractWheel::angle(){return *m_angle;}
double TechnomanAbstractWheel::velocity(){return *m_velocity;}
double TechnomanAbstractWheel::velMax(){return *m_velMax;}
double TechnomanAbstractWheel::acceleration(){return *m_acceleration;}
double TechnomanAbstractWheel::rotation(){return *m_rotation;}
double TechnomanAbstractWheel::magnability(){return *m_magnability;}
double TechnomanAbstractWheel::life(){return *m_life;}
double TechnomanAbstractWheel::collisionZone(){return *m_collisionZone;}
double TechnomanAbstractWheel::power(){return *m_power;}
double TechnomanAbstractWheel::chocResist(){return *m_chocResist;}
void TechnomanAbstractWheel::wheel(){emit graphicsWheel(m_wheel);}
void TechnomanAbstractWheel::selector(){emit graphicsSelector(m_selectorItem);}
void TechnomanAbstractWheel::attachment(){emit graphicsAttachment(m_attachmentItem);}
void TechnomanAbstractWheel::itemI(){emit graphicsItemI(m_itemI);}
void TechnomanAbstractWheel::itemII(){emit graphicsItemII(m_itemII);}
void TechnomanAbstractWheel::itemIII(){emit graphicsItemIII(m_itemIII);}
void TechnomanAbstractWheel::itemIV(){emit graphicsItemIV(m_itemIV);}
void TechnomanAbstractWheel::playAnim(int *i){}
//void TechnomanAbstractWheel::parent(){emit widgetParent(m_parent);}
