#include "IFileOperations.hpp"
#include "CDirectory.hpp"
#include "CFile.hpp"

#ifndef CFILEOPERATIONS_HPP
#define CFILEOPERATIONS_HPP

using namespace std;

class CFileOperations : public IFileOperations
{
public:
    CFileOperations();
    void setPath(QString path);
    void findFile(QString name);
    void viewDirectoryContent(QString path);
    ~CFileOperations(){delete rootDir;}

protected:
    CDirectory *rootDir;
};

#endif // CFILEOPERATIONS_HPP