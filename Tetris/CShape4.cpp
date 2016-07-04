#include "CShape4.h"
#include <QDebug>

CShape4::CShape4()
{
}

void CShape4::setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide)
{
    pUnit2->setX(pUnit1->x());
    pUnit2->setY(pUnit1->y()-sizeSide);
    pUnit3->setX(pUnit1->x()+sizeSide);
    pUnit3->setY(pUnit1->y());
    pUnit4->setX(pUnit3->x()+sizeSide);
    pUnit4->setY(pUnit3->y());
}

void CShape4::rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide)
{
    if (angle == 0)
    {
        pUnit2->setX(pUnit1->x());
        pUnit2->setY(pUnit1->y()-sizeSide);
        pUnit3->setX(pUnit1->x()+sizeSide);
        pUnit3->setY(pUnit1->y());
        pUnit4->setX(pUnit3->x()+sizeSide);
        pUnit4->setY(pUnit3->y());
    }
    else if (angle == 90)
    {
        pUnit2->setX(pUnit1->x()-sizeSide);
        pUnit2->setY(pUnit1->y());
        pUnit3->setX(pUnit1->x());
        pUnit3->setY(pUnit1->y()-sizeSide);
        pUnit4->setX(pUnit3->x());
        pUnit4->setY(pUnit3->y()-sizeSide);
    }
    else if (angle == 180)
    {
        pUnit2->setX(pUnit1->x());
        pUnit2->setY(pUnit1->y()+sizeSide);
        pUnit3->setX(pUnit1->x()-sizeSide);
        pUnit3->setY(pUnit1->y());
        pUnit4->setX(pUnit3->x()-sizeSide);
        pUnit4->setY(pUnit3->y());
    }
    else
    {
        pUnit2->setX(pUnit1->x()+sizeSide);
        pUnit2->setY(pUnit1->y());
        pUnit3->setX(pUnit1->x());
        pUnit3->setY(pUnit1->y()+sizeSide);
        pUnit4->setX(pUnit3->x());
        pUnit4->setY(pUnit3->y()+sizeSide);
    }
}

