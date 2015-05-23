#include "IFileSystemObject.hpp"

#ifndef CDIRECTORY_HPP
#define CDIRECTORY_HPP

using namespace std;

class CDirectory : public IFileSystemObject
{
public:
    CDirectory(QString path){}
    void getObjectName(QString path);
    void addObject(IFileSystemObject *pSystemObject);
    ~CDirectory();

protected:
    list<IFileSystemObject*> listObject;
};

#endif // CDIRECTORY_HPP
