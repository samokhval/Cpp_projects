#include "CBoard.h"

CBoard::CBoard(QGraphicsScene *pScene):QGraphicsView(pScene, 0)
{
    // Members initialization
    currentScene = pScene;
    currentItem = nullptr;
    QFont fnt;
    fnt.setRawName("Helvetica");
    fnt.setPointSize(14);
    pScore = new QGraphicsTextItem();
    pScore->setDefaultTextColor(Qt::white);
    pScore->setPos(380,20);
    pScore->setFont(fnt);
    pScore->setHtml("Score: 0");
    currentScene->addItem(pScore);
    is_start = false;
    is_end = false;
    stop_move = false;
    leftBorder =  -1*currentScene->width()/2;
    rightBorder =  currentScene->width()/2;
    downBorder = currentScene->height();
    angleOfRotate = 0;
    timer = new QTimer(this);    
    connect(timer, SIGNAL(timeout()), this, SLOT(updateItemPosition()));
    boardItems.clear();
    collisionItems.clear();
    mScore = 0;
    mDelay = 0;
    mCountFigure = 0;

    //Set fixed Board size
    setFixedSize(currentScene->width(),currentScene->height());
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

CBoard::~CBoard()
{
    for (QList<CItem *>::iterator it = boardItems.begin(); it != boardItems.end(); it++)
    {
        delete *it;
    }
    delete pScore;
    delete currentItem;
    delete currentScene;
    delete timer;    
}

void CBoard::generateItem()
{
    if (!is_end)
    {
        mCountFigure++;
        currentItem = new CItem();
        currentScene->addItem(currentItem);
        currentItem->setPos(currentScene->width()/2,0);
        timer->blockSignals(false);

        if ((mScore >= 0) && (mScore < 500))
            mDelay = TIMER_DELAY;
        else if ((mScore >= 500) && (mScore < 1000))
            mDelay = TIMER_DELAY/2;
        else if ((mScore >= 1000) && (mScore < 1500))
            mDelay = TIMER_DELAY/4;
        else
            mDelay = TIMER_DELAY/5;
        timer->start(mDelay);
    }
}

void CBoard::addToBoardItemList()
{
    foreach (QGraphicsItem* it, currentItem->childItems())
    {
        collisionItems.push_back(it);
    }
}

void CBoard::updateItemPosition()
{    
    if (!checkDownBorder() && (!stop_move) && (!is_end))
    {
        if (checkVCollision())
        {
            timer->stop();
            foreach (QGraphicsItem * it, currentItem->childItems())
            {
                if (it->y() == 0)
                {
                    timer->blockSignals(true);
                    stop_move = true;
                    is_end = true;
                    QMessageBox::about(0, "Game over!", " Your score = " + QString::number(mScore) + " ,count of figures " + QString::number(mCountFigure) + ".\n If you want play new game please  enter key 'N' or key 'Q' for quit!");
                    break;
                }
            }

            if (!is_end)
            {
                addToBoardItemList();
                boardItems.push_back(currentItem);
                checkFullLine();
                generateItem();
            }
        }
        else
        {
            currentItem->moveDown(STEP);
        }
    }
}

void CBoard::setGameScore()
{
   QString tmpStr;
   mScore = mScore + 50;
   tmpStr = "Score: " + QString::number(mScore);
   pScore->setHtml(tmpStr);
}

void CBoard::setItemAngle()
{
    int tmpValue;
    if (angleOfRotate < 270)
    {
        angleOfRotate = angleOfRotate + 90;
        if ((angleOfRotate == 90) || (angleOfRotate == 270))
        {
            tmpValue = currentItem->getItemHeight();
            currentItem->setItemHeight(currentItem->getItemWidth());
            currentItem->setItemWidth(tmpValue);
        }
    }
    else
    {
        angleOfRotate = 0;
    }
}

bool CBoard::checkDownBorder() // check collision with the lower border
{
    bool check = false;
    foreach (QGraphicsItem * it, currentItem->childItems())
    {
        if (it->y() + CItem::ITEM_SIDE >= downBorder)
        {
            check = true;
            addToBoardItemList();
            boardItems.push_back(currentItem);
            checkFullLine();
            generateItem();
            break;
        }
    }
    return check;
}

bool CBoard::checkLeftBorder()// check collision with the right border
{
    bool check = false;
    foreach (QGraphicsItem * it, currentItem->childItems())
    {
        if (it->x() <= leftBorder)
        {
            check = true;
        }
    }
    return check;
}

bool CBoard::checkRightBorder() // check collision with the left border
{
    bool check = false;
    foreach (QGraphicsItem * it, currentItem->childItems())
    {
        if (it->x() + CItem::ITEM_SIDE >= rightBorder)
        {
            check = true;
        }
    }
    return check;
}

bool CBoard::checkVCollision() //check collision with the lower figure
{
    bool is_check = false;
    for (QList<QGraphicsItem *>::iterator it2 = currentItem->childItems().begin();it2 != currentItem->childItems().end();it2++)
    {
        foreach (QGraphicsItem *it, collisionItems)
        {
            if (((*it2)->y()+CItem::ITEM_SIDE >= it->y()) && ((*it2)->x() == it->x()) && ((*it2)->x()+CItem::ITEM_SIDE == it->x()+CItem::ITEM_SIDE))
            {
                is_check = true;
                break;
            }
        }
    }
    return is_check;
}

bool CBoard::checkHLCollision() //check collision with the left figure
{
    bool is_check = false;
    for (QList<QGraphicsItem *>::iterator it2 = currentItem->childItems().begin();it2 != currentItem->childItems().end();it2++)
    {
        foreach (QGraphicsItem *it, collisionItems)
        {
            if (((*it2)->x() <= it->x()+CItem::ITEM_SIDE) && ((*it2)->y() >= it->y()) && ((*it2)->y() <= it->y()+CItem::ITEM_SIDE))
            {
                is_check = true;
                break;
            }
        }
    }
    return is_check;
}

bool CBoard::checkHRCollision() // check collision with the right figure
{
    bool is_check = false;
    for (QList<QGraphicsItem *>::iterator it2 = currentItem->childItems().begin();it2 != currentItem->childItems().end();it2++)
    {
        foreach (QGraphicsItem *it, collisionItems)
        {
            if (((*it2)->x()+CItem::ITEM_SIDE >= it->x()) && ((*it2)->y() >= it->y()) && ((*it2)->y() <= it->y()+CItem::ITEM_SIDE))
            {
                is_check = true;
                break;
            }
        }
    }
    return is_check;
}

void CBoard::checkFullLine() // check full line
{
    int i = 16;//max count of elements in the line
    int count = 0;
    int maxY = 0;

    for (QList<QGraphicsItem *>::iterator it2 = currentItem->childItems().begin();it2 != currentItem->childItems().end();it2++)
    {
        if ((*it2)->y() > maxY)
            maxY = (*it2)->y();
    }

    foreach (QGraphicsItem *it, collisionItems)
    {
       if (it->y() == maxY)
       {
           count++;
       }
    }

    if (count == i)
    {
        setGameScore();
        foreach(CItem *it, boardItems)
        {
            foreach(QGraphicsItem *ip, it->childItems())
            {
                if (ip->y() == maxY)
                    currentScene->removeItem(ip);
                    ip = nullptr;
                    currentScene->update(QRectF(0, 0, 480, 720));
                    repaint();
            }
        }

        foreach(CItem *it, boardItems)
        {
            foreach(QGraphicsItem *ip, it->childItems())
            {
                if (ip->y() < maxY)
                    ip->setY(ip->y()+CItem::ITEM_SIDE);
                    currentScene->update(QRectF(0, 0, 480, 720));
                    repaint();
            }
        }
    }
}

void CBoard::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key())
    {
      case Qt::Key_N://New game
          if (is_end)
          {            
            for (QList<CItem *>::iterator it = boardItems.begin(); it != boardItems.end(); it++)
            {
               delete *it;
            }
            boardItems.clear();
            currentItem = nullptr;
            currentScene->clear();
            timer->blockSignals(false);
            stop_move = false;
            is_end = false;
            generateItem();
          }
          break;
      case Qt::Key_S://Start the game
            timer->blockSignals(false);
            stop_move = false;
            timer->start(TIMER_DELAY);
            break;
      case Qt::Key_P: //Pause the game
            timer->blockSignals(true);
            timer->stop();
            stop_move = true;
            break;
      case Qt::Key_Left://Move left
            if ((!checkLeftBorder()) && (!checkHLCollision()) && (!stop_move) && (!is_end))
            {
                currentItem->moveLeft(STEP);
            }
            break;
      case Qt::Key_Right://Move right
            if ((!checkRightBorder()) && (!checkHRCollision()) && (!stop_move) && (!is_end))
            {
                currentItem->moveRight(STEP);
            }
            break;
      case Qt::Key_Up://Rotate figure
            if (!stop_move)
            {
                setItemAngle();
                currentItem->rotateItem(angleOfRotate);               
            }
            break;
      case Qt::Key_Down://Move down
            if ((!checkDownBorder()) && (!checkVCollision()) && (!stop_move) && (!is_end))
            {
               currentItem->moveDown(STEP);
            }
            break;
    case Qt::Key_Q://Exit the game

            if (!boardItems.empty())
            {
                for (QList<CItem *>::iterator it = boardItems.begin(); it != boardItems.end(); it++)
                {
                    delete *it;
                }
            }           
            if (currentItem != nullptr)
                delete currentItem;
            delete currentScene;
            exit(0);
            break;
    }
}
