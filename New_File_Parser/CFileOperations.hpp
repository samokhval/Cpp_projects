#ifndef CFILEOPERATIONS_HPP
#define CFILEOPERATIONS_HPP

#include "IFileOperations.hpp"
#include "CDirectory.hpp"
#include "CFile.hpp"
#include <windows.h>
#include <iostream>

using namespace std;

class CFileOperations : public IFileOperations
{
public:
    CFileOperations();
    void setPath(QString path);
    void findFile(QString name);
    void viewDirectoryContent(QString path);
    ~CFileOperations(){delete pObject;}

private:
    CDirectory *pObject;
};

#endif // CFILEOPERATIONS_HPP
