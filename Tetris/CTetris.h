#ifndef CTETRIS_H
#define CTETRIS_H

#include "ITetris.h"

class CTetris: public ITetris
{
public:
    CTetris();
    void startGame();
    void moveItem();
    void endGame();
    ~CTetris();
private:
    QGraphicsScene *scene;
    CBoard *currentBoard;
};

#endif // CTETRIS_H
