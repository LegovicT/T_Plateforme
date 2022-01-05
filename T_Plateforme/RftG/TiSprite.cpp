#include "TiSprite.h"

TiSprite::TiSprite(QObject *parent) : QObject(parent), QGraphicsItem()
{

    maxAnim = 0;
    maxFrame ;
    currentFrame = 0;
    currentAnim = 0;
    spriteImage = new QPixmap("");

}

int TiSprite::nextFrame()
{
    if(currentFrame < maxFrame[currentAnim])
    {
        currentFrame += 1;
    }
    else{currentFrame = 0;}
    this->update(-270.5, -267.8, 541, 535.6);
    return currentFrame;
}
bool TiSprite::changeAnimation(int *numAnim)
{
    if(*numAnim <= maxAnim)
    {
        currentFrame = 0;
        currentAnim = *numAnim;
        return true;
    }
    else{return false;}
}

QPoint TiSprite::getCurrent()
{
    QPoint point(currentAnim, currentFrame);
    return point;
}

bool TiSprite::setMaxAnimation(int *animCount)
{
    if(maxFrame.count() < *animCount)
    {
        for(int i=0; i < *animCount; i++)
        {
            maxFrame.append(1);
        }
    }
    return maxAnim = *animCount;
}
bool TiSprite::setMaxFrame(int *FrameCount, int *animCount)
{
    if(maxFrame.count() < *animCount)
    {
        for(int i=0; i < *animCount; i++)
        {
            maxFrame.append(1);
        }
    }
    if(*animCount <= maxAnim)
    {
        maxFrame.insert(*animCount, *FrameCount);
    }
    else{return false;}
}
bool TiSprite::setPixmap(QString *pixmapPath)
{
    return spriteImage->load(*pixmapPath);
}

QRectF TiSprite::boundingRect() const
{
    return QRectF(-270.5, -267.8, 541, 535.6);
}
void TiSprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-270.5, -267.8, *spriteImage, currentFrame * 541, currentAnim * 535.6, 541, 535.6);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
