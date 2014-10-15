#include "dialog.h"
#include "tdatabase.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    tDataBase base;
    base.CreateTable();
    w.show();
    return a.exec();
}
