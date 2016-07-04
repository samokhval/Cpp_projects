#ifndef CITEM_H
#define CITEM_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QString>
#include <QDebug>
#include "CShape1.h"
#include "CShape2.h"
#include "CShape3.h"
#include "CShape4.h"
#include "CShape5.h"
#include "CShape6.h"
#include "CShape7.h"
#include <time.h>

class CItem:public QGraphicsItemGroup
{
public:
    CItem();
    inline void setItemHeight(int h){heightItem = h;}
    inline void setItemWidth(int w){widthItem = w;}
    int getItemHeight() const {return heightItem;}
    int getItemWidth() const { return widthItem;}
    void rotateItem(int angle);
    void moveRight(int value);
    void moveLeft(int value);
    void moveDown(int value);
    enum {ITEM_SIDE = 30, START_POS = 0};
    ~CItem();
private:
    int widthItem;
    int heightItem;
    bool is_rotate;
    QGraphicsPixmapItem *unit1;
    QGraphicsPixmapItem *unit2;
    QGraphicsPixmapItem *unit3;
    QGraphicsPixmapItem *unit4;
    IItemBehavior *pItemB;

};

#endif // CITEM_H
