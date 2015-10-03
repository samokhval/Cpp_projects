#ifndef IFILESYSTEMOBJECT_HPP
#define IFILESYSTEMOBJECT_HPP


#include <QString>
#include <QDebug>
#include <windows.h>

using namespace std;

class IFileSystemObject
{

public:
    IFileSystemObject(QString path, QString name):m_path(path),m_name(name){}
    virtual void addObject(IFileSystemObject *pSystemObject) = 0;
    virtual QString getObjectName() = 0;
    virtual QString getObjectPath() = 0;
    virtual ~IFileSystemObject(){}

protected:
    QString m_path;
    QString m_name;
};

#endif // IFILESYSTEMOBJECT_HPP
