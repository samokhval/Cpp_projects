#include "CItem.h"

CItem::CItem():QGraphicsItemGroup()
{
    int choice;

    is_rotate = false;
    setY(START_POS);
    unit1 = new QGraphicsPixmapItem();
    unit1->setPixmap(QPixmap(QString::fromUtf8(PRO_FILE_PWD)+"/figure.gif").scaled(ITEM_SIDE,ITEM_SIDE));
    unit2 = new QGraphicsPixmapItem();
    unit2->setPixmap(QPixmap(QString::fromUtf8(PRO_FILE_PWD)+"/figure.gif").scaled(ITEM_SIDE,ITEM_SIDE));
    //unit2->setParentItem(unit1);
    unit3 = new QGraphicsPixmapItem();
    unit3->setPixmap(QPixmap(QString::fromUtf8(PRO_FILE_PWD)+"/figure.gif").scaled(ITEM_SIDE,ITEM_SIDE));
    //unit3->setParentItem(unit1);
    unit4 = new QGraphicsPixmapItem();
    unit4->setPixmap(QPixmap(QString::fromUtf8(PRO_FILE_PWD)+"/figure.gif").scaled(ITEM_SIDE,ITEM_SIDE));
    //unit4->setParentItem(unit1);

    srand (time(NULL));
    choice = rand() % 7 + 1;
    switch (choice)
    {
        case 1: pItemB = new CShape1();
                widthItem = 2*ITEM_SIDE;
                heightItem = 2*ITEM_SIDE;
                break;
        case 2: pItemB = new CShape2();
                widthItem = 2*ITEM_SIDE;
                heightItem = 3*ITEM_SIDE;
                break;
        case 3: pItemB = new CShape3();
                widthItem = 2*ITEM_SIDE;
                heightItem = 3*ITEM_SIDE;
                break;
        case 4: pItemB = new CShape4();
                widthItem = 3*ITEM_SIDE;
                heightItem = 2*ITEM_SIDE;
                break;
        case 5: pItemB = new CShape5();
                widthItem = 3*ITEM_SIDE;
                heightItem = 2*ITEM_SIDE;
                break;
        case 6: pItemB = new CShape6();
                widthItem = 4*ITEM_SIDE;
                heightItem = 1*ITEM_SIDE;
                break;
        case 7: pItemB = new CShape7();
                widthItem = 3*ITEM_SIDE;
                heightItem = 2*ITEM_SIDE;
                break;
    }

    pItemB->setPos(unit1,unit2,unit3,unit4,ITEM_SIDE);

    addToGroup(unit1);
    addToGroup(unit2);
    addToGroup(unit3);
    addToGroup(unit4);
}

CItem::~CItem()
{
    delete unit1;
    delete unit2;
    delete unit3;
    delete unit4;
}

void CItem::rotateItem(int angle)
{
    pItemB->rotate(unit1, unit2, unit3, unit4, angle,ITEM_SIDE);
}

void CItem::moveRight(int value)
{
    unit1->setX(unit1->x() + value);
    unit2->setX(unit2->x() + value);
    unit3->setX(unit3->x() + value);
    unit4->setX(unit4->x() + value);
}

void CItem::moveLeft(int value)
{
    unit1->setX(unit1->x() - value);
    unit2->setX(unit2->x() - value);
    unit3->setX(unit3->x() - value);
    unit4->setX(unit4->x() - value);
}

void CItem::moveDown(int value)
{    
    unit1->setY(unit1->y() + value);
    unit2->setY(unit2->y() + value);
    unit3->setY(unit3->y() + value);
    unit4->setY(unit4->y() + value);
}
