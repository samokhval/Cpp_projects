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
    QString buffer;

    hFile = FindFirstFile(tmpPath.toStdString().c_str(),&winFileData);

    if (hFile!=INVALID_HANDLE_VALUE)
    {
        do
        {
            if (!strcmp(winFileData.cFileName, ".") || !strcmp(winFileData.cFileName, ".."))
                continue;

            if (winFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
            {
                cout << "[" << winFileData.cFileName << "]" << endl;

                CDirectory *pDir = new CDirectory(QString::fromUtf8(winFileData.cFileName));

                if (!strcmp(winFileData.cFileName, ".") || !strcmp(winFileData.cFileName, ".."))
                {
                    rootDir->addObject(pDir);
                }
                buffer = path + "\\" + winFileData.cFileName ;
                viewDirectoryContent(buffer);
            }
            else
                cout << winFileData.cFileName << endl;
                rootDir->addObject(new CFile(QString::fromUtf8(winFileData.cFileName)));
        }
        while (FindNextFile(hFile,&winFileData)!=0);

        FindClose(hFile);
     }

}

void CFileOperations::setPath(QString path)
{
    rootDir = new CDirectory(path);
}
