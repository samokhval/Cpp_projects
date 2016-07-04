#ifndef CSHAPE2_H
#define CSHAPE2_H

#include "IItemBehavior.h"

class CShape2: public IItemBehavior
{
public:
    CShape2();
    void setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide);
    void rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide);
};

#endif // CSHAPE2_H
