#include "CFileOperations.hpp"

CFileOperations::CFileOperations()
{
}

void CFileOperations::findFile(QString name)
{
    qDebug() << "Find file " << name;
    //pFileSystemObject->listObj.size();
}

void CFileOperations::viewDirectoryContent()
{
    WIN32_FIND_DATA winFileData;
    HANDLE hFile;
    QString tmpPath = m_path + "\\*.*";

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
    m_path = path;
    pFileSystemObject = new CDirectory(m_path);
}
