#ifndef CFILE_H
#define CFILE_H

#include <QString>
#include <QFile>
#include <QDebug>
#include <list>

using namespace std;

class CFile
{
public:
    CFile(QString fileName);
    void scanFile(const QMap<QString, QString> *mask);
    list<QString> getResultScan() const {return mResult;}
private:
    QString mFileName;
    list<QString> mResult;
};

#endif // CFILE_H
