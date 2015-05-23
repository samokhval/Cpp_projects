#include "IFileSystemObject.hpp"

#ifndef CDIRECTORY_HPP
#define CDIRECTORY_HPP

using namespace std;

class CDirectory : public IFileSystemObject
{
public:
    CDirectory(QString path):IFileSystemObject(path){}
    const QString getName();
    int getSize();
    void addObject(IFileSystemObject *pSystemObject);

protected:
    list<IFileSystemObject*> listObj;
};

#endif // CDIRECTORY_HPP
