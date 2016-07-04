#ifndef CSHAPE1_H
#define CSHAPE1_H

#include "IItemBehavior.h"

class CShape1: public IItemBehavior
{
public:
    CShape1();
    void setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide);
    void rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide);
};

#endif // CSHAPE1_H
