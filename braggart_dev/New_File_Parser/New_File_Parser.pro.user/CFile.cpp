#include "CFile.hpp"

const QString CFile::getName()
{
    QString nameFile = "I am File";
    qDebug() << nameFile;
    return nameFile;
}

int CFile::getSize()
{
    int size = 0;
    qDebug() << "Size of File = " << size;
    return size;
}
