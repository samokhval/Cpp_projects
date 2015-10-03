#ifndef CDIRECTORY_HPP
#define CDIRECTORY_HPP

#include "IFileSystemObject.hpp"

class CDirectory : public IFileSystemObject
{
public:
    CDirectory(QString path, QString name):IFileSystemObject(path,name){}
    void addObject(IFileSystemObject *pSystemObject){listObject.push_back(pSystemObject);}
    QString getObjectName(){return m_name;}
    QString getObjectPath(){return m_path;}
    list<IFileSystemObject*> listObject;
    virtual ~CDirectory();
};

#endif // CDIRECTORY_HPP
