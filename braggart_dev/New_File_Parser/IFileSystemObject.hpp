#include <list>
#include <QString>
#include <QDebug>
#include <windows.h>

#ifndef IFILESYSTEMOBJECT_HPP
#define IFILESYSTEMOBJECT_HPP

class IFileSystemObject
{

public:
    IFileSystemObject(QString path):m_fullPath(path){}
    virtual void getName() = 0;
    virtual void addObject(IFileSystemObject *pSystemObject) = 0;
    virtual ~IFileSystemObject(){}
    QString m_fullPath;
};

#endif // IFILESYSTEMOBJECT_HPP
