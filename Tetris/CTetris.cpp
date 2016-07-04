#include "CTetris.h"

CTetris::CTetris()
{
    scene = new QGraphicsScene(QRectF(0, 0, 480, 720));
    scene->setBackgroundBrush(QImage(QString::fromUtf8(PRO_FILE_PWD)+"/fon.jpg"));
    currentBoard = new CBoard(scene);
}

CTetris::~CTetris()
{
    delete scene;
    delete currentBoard;
}

void CTetris::startGame()
{
    currentBoard->show();
    currentBoard->setStartGame();
    QMessageBox::about(0, "About game", "Welcome! For move figure use arrow keys, \n key 'R' - rotate figure, key 'P' - pause, \n key 'S' - continue, key 'Q' - quit!");
    currentBoard->generateItem();
}

void CTetris::endGame()
{
    currentBoard->setEndGame();
}

void CTetris::moveItem()
{
}
