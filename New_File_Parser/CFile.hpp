#include "IFileSystemObject.hpp"

#ifndef CFILE_HPP
#define CFILE_HPP

class CFile : public IFileSystemObject
{
public:
    CFile(QString path){}
    void getObjectName(QString path);
    virtual void addObject(IFileSystemObject *pSystemObject);
};

#endif // CFILE_HPP
