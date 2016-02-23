#include <QApplication>
#include "Scanner.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scanner signDetect;
    signDetect.showUI();
    return a.exec();
}
