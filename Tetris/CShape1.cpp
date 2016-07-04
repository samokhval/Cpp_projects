#include "CShape1.h"

CShape1::CShape1()
{
}

void CShape1::setPos(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int sizeSide)
{
    pUnit2->setX(pUnit1->x()+sizeSide);
    pUnit2->setY(pUnit1->y());
    pUnit3->setX(pUnit1->x());
    pUnit3->setY(pUnit1->y()+sizeSide);
    pUnit4->setX(pUnit3->x()+sizeSide);
    pUnit4->setY(pUnit3->y());
}

void CShape1::rotate(QGraphicsPixmapItem *pUnit1, QGraphicsPixmapItem *pUnit2, QGraphicsPixmapItem *pUnit3, QGraphicsPixmapItem *pUnit4, int angle, int sizeSide)
{
    pUnit2->setX(pUnit1->x()+sizeSide);
    pUnit2->setY(pUnit1->y());
    pUnit3->setX(pUnit1->x());
    pUnit3->setY(pUnit1->y()+sizeSide);
    pUnit4->setX(pUnit3->x()+sizeSide);
    pUnit4->setY(pUnit3->y());
}
