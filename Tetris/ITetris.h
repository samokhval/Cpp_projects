#ifndef ITETRIS_H
#define ITETRIS_H

#include "CBoard.h"

class ITetris
{
public:
    virtual void startGame() = 0;
    virtual void moveItem()  = 0;
    virtual void endGame()  = 0;
};

#endif // ITETRIS_H
