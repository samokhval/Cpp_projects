#include "IFileSystemObject.hpp"

#ifndef CDIRECTORY_HPP
#define CDIRECTORY_HPP

using namespace std;

class CDirectory : public IFileSystemObject
{
public:
    CDirectory(QString path):IFileSystemObject(path){}
    QString getObjectName();
    void addObject(IFileSystemObject *pSystemObject);
    list<IFileSystemObject*> listObject;
    ~CDirectory();
};

#endif // CDIRECTORY_HPP
