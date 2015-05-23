#include "CFileOperations.hpp"

CFileOperations::CFileOperations()
{
}

void CFileOperations::findFile(QString name)
{
    qDebug() << "Find file " << name;
}

void CFileOperations::viewDirectoryContent(QString path)
{
    WIN32_FIND_DATA winFileData;
    HANDLE hFile;
    QString tmpPath = path + "\\*.*";

    hFile = FindFirstFile(tmpPath.toStdString().c_str(),&winFileData);

    if (hFile!=INVALID_HANDLE_VALUE)
    {
        do
        {
            if (winFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
            {
                cout << "[" << winFileData.cFileName << "]" << endl;
            }
            else
                cout << winFileData.cFileName << endl;
        }
        while (FindNextFile(hFile,&winFileData)!=0);

        FindClose(hFile);
     }
}

void CFileOperations::setPath(QString path)
{
    pFileSystemObject = new CDirectory(path);
    pFileSystemObject->getObjectName(path);
}
