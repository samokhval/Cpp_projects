#include "TestUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestUI obj_UI;
    TestQuestions obj_Q[10];
    TestDB obj_DB;

    obj_DB.CreateTable();
//  Объясни зачем этот объект тут если потом у тебя есть еще
//    void TestUI::ButtonPress()
//    {
//        // изучаем цикл жизни переменных
    int max = obj_Q[0].getMaxQuestion();

    for (int i = 0; i < max; i++)
    {
      obj_Q[i].generateQuestion(i+1);
    }

    obj_UI.setSizeUI(400,167);
    obj_UI.show();
    return a.exec();
}
