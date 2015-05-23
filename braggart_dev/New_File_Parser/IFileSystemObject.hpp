#include <list>
#include <QString>
#include <QDebug>

#ifndef IFILESYSTEMOBJECT_HPP
#define IFILESYSTEMOBJECT_HPP

class IFileSystemObject
{

public:
    IFileSystemObject(QString path);
    const virtual QString getName() = 0;
    virtual int getSize() = 0;
    virtual void addObject(IFileSystemObject *pSystemObject) = 0;
    const list<IFileSystemObject*> listObj;
    virtual ~IFileSystemObject(){}
};

#endif // IFILESYSTEMOBJECT_HPP
