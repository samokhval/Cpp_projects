#include "CFileOperations.hpp"

CFileOperations::CFileOperations()
{
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
                static int level;

                level++;

                if (level == 1)
                {
                    cout << "[" << winFileData.cFileName << "]" << endl;
                }
                buffer = path + "\\" + winFileData.cFileName ;
                pObject->addObject(new CDirectory(buffer,winFileData.cFileName));
                viewDirectoryContent(buffer);
            }
            else
            {
                pObject->addObject(new CFile(path,winFileData.cFileName));
                cout << winFileData.cFileName << endl;
            }
         }
        while (FindNextFile(hFile,&winFileData)!=0);

        FindClose(hFile);
     }
}

void CFileOperations::setPath(QString path)
{
    cout << "Content of main directory:" << endl;
    pObject = new CDirectory(path,"");
    viewDirectoryContent(path);
    cout << endl;
    cout << path.toStdString() << "\\";
}

void CFileOperations::findFile(QString name)
{
    QString str_list;
    QString fName;
    QString fPath;
    int pos;
    list<QString> file_list;

    foreach (IFileSystemObject* pObjFile,pObject->listObject)
    {
        fName = pObjFile->getObjectName();
        fPath = pObjFile->getObjectPath();
        file_list.push_back(fPath+"\\"+fName);
    }

    qDebug() << "Was found next objects: ";
    for(list<QString>::iterator list_iter = file_list.begin();
        list_iter != file_list.end(); list_iter++)
    {
        str_list = *list_iter;
        str_list = str_list.toLower();
        name = name.toLower();
        pos = str_list.indexOf(name);
        if (pos != -1)
            cout << str_list.toStdString() << endl;
    }
}
