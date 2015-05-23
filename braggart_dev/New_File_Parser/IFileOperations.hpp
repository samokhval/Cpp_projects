#include "IFileSystemObject.hpp"
#include <iostream>
#include <windows.h>

#ifndef IFILEOPERATIONS_HPP
#define IFILEOPERATIONS_HPP

class IFileOperations
{
public:

    virtual void setPath(QString path) = 0;
    virtual void findFile(QString name) = 0;
    virtual void viewDirectoryContent() = 0;
    virtual ~IFileOperations(){}

};

#endif // IFILEOPERATIONS_HPP
