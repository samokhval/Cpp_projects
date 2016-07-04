#include "CPort.h"

CPort::CPort(QString namePort, CTable &refTable)
{
    pTable = &refTable;
    mPortName = namePort;
    pSerialPort = new QSerialPort;
    pSerialPort->setPortName(mPortName);

    if (openPort())
        cout << "The port " << mPortName.toStdString() << " is open!" << endl;
    else
        cout << "The port " << mPortName.toStdString() << " cann't be open!" << endl;

    pSerialPort->setBaudRate(QSerialPort::Baud9600);
    pSerialPort->setDataBits(QSerialPort::Data8);
    pSerialPort->setParity(QSerialPort::NoParity);
    pSerialPort->setStopBits(QSerialPort::OneStop);
    pSerialPort->setFlowControl(QSerialPort::HardwareControl);

}

bool CPort::openPort()
{
    return pSerialPort->open(QIODevice::ReadOnly);
}

void CPort::readDataFromPort()
{
    time_t     now;
    struct tm  tstruct;
    char       buf[80];
    QTextStream standardOutput(stdout);
    QByteArray readData;
    while (true)
    {
        pSerialPort->waitForReadyRead(3000);
        readData = pSerialPort->readAll();
        if (!readData.isEmpty())
        {
            now = time(0);
            tstruct = *localtime(&now);
            strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
            if (pTable->InsertToBase(QString::fromUtf8(buf),mPortName,readData))
            {
                standardOutput << QObject::tr("You get data from the port %1 :").arg(mPortName)<< readData << ", in the " << buf << ".The info is loading to database!" << endl;
            }
        }
    }
}
