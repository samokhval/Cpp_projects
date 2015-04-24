#include "CDirectory.h"

using namespace std;

void CDirectory::FindFile(string name)
{

    /*
    list<IFileParser*>::iterator findIter = find(ListObjs.begin(), ListObjs.end(), name);
    if (findIter != ListObjs.end())
    {
            cout << "Found: " << *findIter << endl;
    } else
    {
            cout << "File no found!" << endl;
    }
    */
}

void CDirectory::setPath(string dir)
{
    //Checked directory path
    /*
    TCHAR buffer[MAX_PATH];
    std::wstring stemp = std::wstring(dir.begin(), dir.end());
    LPCWSTR ppp = stemp.c_str();
    SetCurrentDirectoryA(LPCSTR(ppp));

    if (GetCurrentDirectoryA(sizeof(buffer),buffer))
    {
        cout << buffer;
    }
    else
    {
        cout << "Defined path!!!" << endl;
    }
*/

    WIN32_FIND_DATA FindFileData;
    HANDLE hFind;
    SYSTEMTIME sysTime, fLocTime;

    CDirectory *pDir = new CDirectory(dir);
    pDir->AddItem(pDir);

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

            if (FindFileData.dwFileAttributes&FILE_ATTRIBUTE_DIRECTORY)
            {
                buffer = dir + "\\" + FindFileData.cFileName;
                //cout << "[" << FindFileData.cFileName << "]" << endl;
                setPath(buffer);
            }
            else
            {
                buffer = dir + "\\" + FindFileData.cFileName;
                pDir->AddItem(new CFile(buffer));
                //FileTimeToSystemTime(&FindFileData.ftCreationTime,&sysTime);
                //FileTimeToSystemTime(&FindFileData.ftLastWriteTime,&fLocTime);
                //cout << FindFileData.cFileName << setw(2) << " " << FindFileData.nFileSizeLow << setw(4) << sysTime.wDay<<"."<<sysTime.wMonth<<"."<<sysTime.wYear
                 //       << setw(2) << " " << fLocTime.wDay<<"."<<fLocTime.wMonth<<"."<<fLocTime.wYear <<endl;
            }
        }while(FindNextFile(hFind, &FindFileData));
    FindClose(hFind);
   }
    cout << dir+"\\";

}

void CDirectory::AddItem(IFileParser *pItem)
{
    ListObjs.push_back(pItem);
}

void CDirectory::listInfo()
{
    cout << "Size of list: " << ListObjs.size();

}
