#include "CFile.h"

CFile::CFile(QString fileName)
{
    mFileName = fileName;
    mResult.clear();
}

void CFile::scanFile(list<QString> *mask)
{
    QFile myFile(mFileName);
    myFile.open(QIODevice::ReadOnly);
    QTextStream in (&myFile);
    const QString content = in.readAll();

    for (list<QString>::iterator it = mask->begin(); it != mask->end(); ++it)
    {
        if(content.contains(*it))
        {
            qDebug() << mFileName << "contains " << *it;
            mResult.push_back("File " + myFile.fileName() + " contains " + *it);
        }
    }
    myFile.close();
}
