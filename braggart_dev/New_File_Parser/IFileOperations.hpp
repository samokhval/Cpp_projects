#ifndef IFILEOPERATIONS_HPP
#define IFILEOPERATIONS_HPP

#include <QString>

class IFileOperations
{
public:
    IFileOperations(){}
    virtual void setPath(QString path) = 0;
    virtual void viewDirectoryContent(QString path) = 0;
    virtual void findFile(QString name) = 0;
    virtual ~IFileOperations(){}
};

#endif // IFILEOPERATIONS_HPP
