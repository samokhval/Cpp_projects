#ifndef CPORT_H
#define CPORT_H

#include "CTable.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTextStream>
#include <QByteArray>
#include <QDebug>
#include <time.h>

using namespace std;

class CPort
{
public:
    CPort(QString namePort, CTable &refTable);
    bool openPort();
    void readDataFromPort();

private:
    QString mPortName;
    QSerialPort *pSerialPort;
    CTable *pTable;
};

#endif // CPORT_H
