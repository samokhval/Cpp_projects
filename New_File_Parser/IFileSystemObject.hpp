#include <list>
#include <QString>
#include <QDebug>
#include <windows.h>

#ifndef IFILESYSTEMOBJECT_HPP
#define IFILESYSTEMOBJECT_HPP

using namespace std;

class IFileSystemObject
{

public:
    IFileSystemObject(QString path):m_path(path){}
    virtual QString getObjectName() = 0;
    virtual void addObject(IFileSystemObject *pSystemObject) = 0;
    list<IFileSystemObject*> listObject;
    virtual ~IFileSystemObject(){}

    QString m_path;

};

#endif // IFILESYSTEMOBJECT_HPP
