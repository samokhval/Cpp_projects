#include "TestUI.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestUI obj_UI;    

    obj_UI.setSizeUI(400,167);
    obj_UI.show();

    return a.exec();
}
