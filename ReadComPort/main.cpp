#include "CPort.h"
#include <thread>
#include <windows.h>
#include <QTimer>

using namespace std;

int main()
{
    CTable tempTable;
    list<QString> outputList;
    CPort port1("COM2", tempTable);
    CPort port2("COM3", tempTable);

    cout << "The program ready to read data from the ports!" << endl;

    thread t1(&CPort::readDataFromPort,&port1);
    t1.detach();

    thread t2(&CPort::readDataFromPort,&port2);
    t2.detach();

    Sleep(60000);

    cout << "The table contents next information:" << endl;
    cout << "-------------------|----|--------------------------------------------------" << endl;
    cout << "   Date and Time   |Port|                  Content                         " << endl;
    cout << "-------------------|----|--------------------------------------------------" << endl;
    outputList = tempTable.getInfo();
    for (list<QString>::iterator it = outputList.begin(); it != outputList.end(); ++it)
    {

        cout << (*it).toStdString();
    }
    return 0;
}

