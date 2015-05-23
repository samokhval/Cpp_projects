#include "CDirectory.hpp"

const QString CDirectory::getName()
{
    QString nameDir = "I am Directory";
    qDebug() << nameDir;
    return nameDir;
}

int CDirectory::getSize()
{
    int size = 2;
    qDebug() << "Size of Directory = " << size;
    return size;
}

void CDirectory::addObject(IFileSystemObject *pSystemObject)
{
    listObj.push_back(pSystemObject);
}
