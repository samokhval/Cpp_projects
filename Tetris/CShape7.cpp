#include "CShape7.h"

CShape7::CShape7()
{
}

void CShape7::setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide)
{
    pUnit2->setX(pUnit1->x());
    pUnit2->setY(pUnit1->y()+sizeSide);
    pUnit3->setX(pUnit2->x()-sizeSide);
    pUnit3->setY(pUnit2->y());
    pUnit4->setX(pUnit2->x()+sizeSide);
    pUnit4->setY(pUnit2->y());
}

void CShape7::rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide)
{
    if (angle == 0)
    {
        pUnit2->setX(pUnit1->x());
        pUnit2->setY(pUnit1->y()+sizeSide);
        pUnit3->setX(pUnit2->x()-sizeSide);
        pUnit3->setY(pUnit2->y());
        pUnit4->setX(pUnit2->x()+sizeSide);
        pUnit4->setY(pUnit2->y());
    }
    else if (angle == 90)
    {
        pUnit2->setX(pUnit1->x()+sizeSide);
        pUnit2->setY(pUnit1->y());
        pUnit3->setX(pUnit2->x());
        pUnit3->setY(pUnit2->y()+sizeSide);
        pUnit4->setX(pUnit2->x());
        pUnit4->setY(pUnit2->y()-sizeSide);
    }
    else if (angle == 180)
    {
        pUnit2->setX(pUnit1->x());
        pUnit2->setY(pUnit1->y()-sizeSide);
        pUnit3->setX(pUnit2->x()+sizeSide);
        pUnit3->setY(pUnit2->y());
        pUnit4->setX(pUnit2->x()-sizeSide);
        pUnit4->setY(pUnit2->y());
    }
    else
    {
        pUnit2->setX(pUnit1->x()-sizeSide);
        pUnit2->setY(pUnit1->y());
        pUnit3->setX(pUnit2->x());
        pUnit3->setY(pUnit2->y()-sizeSide);
        pUnit4->setX(pUnit2->x());
        pUnit4->setY(pUnit2->y()+sizeSide);
    }
}
