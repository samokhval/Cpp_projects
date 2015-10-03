#include "CDirectory.hpp"

CDirectory::~CDirectory()
{
    for (list<IFileSystemObject*>::iterator it = listObject.begin(); it != listObject.end(); it++)
    {
        delete(*it);
    }
}
