#include "CDirectory.hpp"
#include "CFile.hpp"

QString CDirectory::getObjectName()
{
   QString str = "I am Directory";
   return str;
}

void CDirectory::addObject(IFileSystemObject *pSystemObject)
{
    listObject.push_back(pSystemObject);
}

CDirectory::~CDirectory()
{
    while(!listObject.empty())
           {
             list<IFileSystemObject*>::iterator it = listObject.begin();
             delete *it;
             listObject.erase(it);
           }
}
