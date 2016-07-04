#ifndef CSHAPE7_H
#define CSHAPE7_H

#include "IItemBehavior.h"

class CShape7: public IItemBehavior
{
public:
    CShape7();
    void setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide);
    void rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide);
};

#endif // CSHAPE7_H
