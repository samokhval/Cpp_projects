#ifndef CFILE_HPP
#define CFILE_HPP

#include "CDirectory.hpp"

class CFile : public IFileSystemObject
{
public:
    CFile(QString path,QString name):IFileSystemObject(path,name){}
    void addObject(IFileSystemObject *pSystemObject){}
    QString getObjectName(){return m_name;}
    QString getObjectPath(){return m_path;}
    virtual ~CFile(){}
};

#endif // CFILE_HPP
