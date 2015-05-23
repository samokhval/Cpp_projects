#include "IFileOperations.hpp"
#include "CDirectory.hpp"

#ifndef CFILEOPERATIONS_HPP
#define CFILEOPERATIONS_HPP

using namespace std;

class CFileOperations : public IFileOperations
{
public:
    CFileOperations();
    void setPath(QString path);
    void findFile(QString name);
    void viewDirectoryContent();
    ~CFileOperations(){delete pFileSystemObject;}

protected:
    IFileSystemObject *pFileSystemObject;
private:
    QString m_path;
};

#endif // CFILEOPERATIONS_HPP
