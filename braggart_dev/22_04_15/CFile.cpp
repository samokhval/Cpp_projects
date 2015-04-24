#include "CFile.h"

void CFile::AddItem(IFileParser *pItem)
{
    cout<<"Cannot add to a LeafElement"<<endl;
}

void CFile::FindFile(string name)
{
    cout << name;
}

void CFile::viewDirContent()
{

}

void CFile::setPath(string dir)
{
    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    SYSTEMTIME sysTime, fLocTime;

    string buffer;
    char cmdpath[MAX_PATH];

    strcpy(cmdpath, dir.c_str());
    strcat(cmdpath, "\\*.*");

    hFind = FindFirstFile(cmdpath, &FindFileData);

    if (hFind!=INVALID_HANDLE_VALUE)
    {
      do
      {
        if (!strcmp(FindFileData.cFileName, ".") || !strcmp(FindFileData.cFileName, ".."))
            continue;

            if (!(FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY))
            {
                buffer = dir + "\\" + FindFileData.cFileName;
                //cout << buffer << endl;
                cout << "Add to List - " << buffer << endl;

                FileTimeToSystemTime(&FindFileData.ftCreationTime,&sysTime);
                FileTimeToSystemTime(&FindFileData.ftLastWriteTime,&fLocTime);
                cout << FindFileData.cFileName << setw(2) << " " << FindFileData.nFileSizeLow << setw(4) << sysTime.wDay<<"."<<sysTime.wMonth<<"."<<sysTime.wYear
                        << setw(2) << " " << fLocTime.wDay<<"."<<fLocTime.wMonth<<"."<<fLocTime.wYear <<endl;
            }
        }
    while(FindNextFile(hFind, &FindFileData));

    FindClose(hFind);
   }
}
