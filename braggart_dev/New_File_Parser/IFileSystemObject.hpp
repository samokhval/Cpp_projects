#include <list>
#include <QString>
#include <QDebug>

#ifndef IFILESYSTEMOBJECT_HPP
#define IFILESYSTEMOBJECT_HPP

class IFileSystemObject
{

public:
    IFileSystemObject(QString path):m_fullPath(path){}
    const virtual QString getName() = 0;
    virtual int getSize() = 0;
    virtual void addObject(IFileSystemObject *pSystemObject) = 0;
    virtual ~IFileSystemObject(){}
    QString m_fullPath;
};

#endif // IFILESYSTEMOBJECT_HPP
