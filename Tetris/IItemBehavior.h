#ifndef IITEMBEHAVIOR_H
#define IITEMBEHAVIOR_H

#include <QGraphicsPixmapItem>

class IItemBehavior
{
public:
    virtual void setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide) = 0;
    virtual void rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide) = 0;
};

#endif // IITEMBEHAVIOR_H
