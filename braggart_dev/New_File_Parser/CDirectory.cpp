#include "CDirectory.hpp"
#include "CFile.hpp"

void CDirectory::getObjectName(QString path)
{
    WIN32_FIND_DATA winFileData;
    HANDLE hFile;
    QString tmpPath = path + "\\*.*";
    QString buffer;
    CDirectory *pDir = new CDirectory(path);

    hFile = FindFirstFile(tmpPath.toStdString().c_str(),&winFileData);

    if (hFile!=INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!strcmp(winFileData.cFileName, ".") || !strcmp(winFileData.cFileName, ".."))
                continue;

            if (winFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
            {
                buffer = path + "\\" + winFileData.cFileName;
                addObject(pDir);
                getObjectName(buffer);
            }
            else
            {
                buffer = path + "\\" + winFileData.cFileName;
                addObject(new CFile(buffer));
            }

        }
        while (FindNextFile(hFile,&winFileData)!=0);

        FindClose(hFile);
    }
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
