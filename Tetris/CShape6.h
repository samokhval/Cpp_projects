#ifndef CSHAPE6_H
#define CSHAPE6_H

#include "IItemBehavior.h"

class CShape6: public IItemBehavior
{
public:
    CShape6();
    void setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide);
    void rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide);
};

#endif // CSHAPE6_H
