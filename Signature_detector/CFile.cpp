#include "CFile.h"

CFile::CFile(QString fileName)
{
    mFileName = fileName;
    mResult.clear();
}

void CFile::scanFile(const QMap<QString, QString> *mask)
{
    QFile myFile(mFileName);
    myFile.open(QIODevice::ReadOnly);
    QTextStream in (&myFile);
    const QString content = in.readAll();

    for (QMap<QString, QString>::const_iterator it = mask->begin(); it != mask->end(); ++it)
    {
        if(content.contains(it.key()))
        {
            qDebug() << mFileName << "contains " << it.value();
            mResult.push_back("File " + myFile.fileName() + " contains " + it.value());
        }
    }
    myFile.close();
}
