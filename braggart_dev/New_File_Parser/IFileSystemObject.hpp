#include <list>
#include <QString>
#include <QDebug>
#include <windows.h>

#ifndef IFILESYSTEMOBJECT_HPP
#define IFILESYSTEMOBJECT_HPP

class IFileSystemObject
{

public:
    virtual void getObjectName(QString path) = 0;
    virtual void addObject(IFileSystemObject *pSystemObject) = 0;
    virtual ~IFileSystemObject(){}
};

#endif // IFILESYSTEMOBJECT_HPP
