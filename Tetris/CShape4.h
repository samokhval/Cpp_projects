#ifndef CSHAPE4_H
#define CSHAPE4_H

#include "IItemBehavior.h"

class CShape4: public IItemBehavior
{
public:
    CShape4();
    void setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide);
    void rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide);
};

#endif // CSHAPE4_H
