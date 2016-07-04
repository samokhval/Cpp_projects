#include "CTetris.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ITetris *myGame = new CTetris();
    myGame->startGame();
    return a.exec();
}

