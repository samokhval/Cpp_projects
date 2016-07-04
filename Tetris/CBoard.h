#ifndef CBOARD_H
#define CBOARD_H

#include <QApplication>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QList>
#include <QFont>
#include <stdlib.h>
#include <time.h>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include "CItem.h"

class CBoard:public QGraphicsView
{
    Q_OBJECT
public:
    CBoard(QGraphicsScene *ps);
    inline void setStartGame(){is_start = true;}
    inline void setEndGame(){is_end = true;}
    void addToBoardItemList();
    void generateItem();
    void setItemAngle();
    void setGameScore();
    bool checkEndGame() const {return is_end;}
    bool checkLeftBorder();
    bool checkRightBorder();
    bool checkDownBorder();
    bool checkVCollision();
    bool checkHLCollision();
    bool checkHRCollision();
    void checkFullLine();
    void keyPressEvent(QKeyEvent * keyEvent);
    enum {STEP = 30, TIMER_DELAY = 500};
    ~CBoard();
public slots:
    void updateItemPosition();
private:
    QGraphicsScene *currentScene;    
    CItem *currentItem;
    QTimer *timer;
    QGraphicsTextItem *pScore;
    QList<QGraphicsItem *> collisionItems;
    QList<CItem *> boardItems;
    bool is_start;
    bool is_end;
    bool stop_move;
    int leftBorder;
    int rightBorder;
    int downBorder;
    int angleOfRotate;    
    int mScore;
    int mDelay;
    int mCountFigure;
};

#endif // CBOARD_H
