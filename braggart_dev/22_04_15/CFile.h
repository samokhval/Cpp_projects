#include "IFileParser.h"

#include <windows.h>
#include <iomanip>


#ifndef CFILE_H
#define CFILE_H

using namespace std;

class CFile : public IFileParser
{
public:
    CFile(string path):IFileParser(path){}
    void FindFile(string name);
    void setPath(string dir);
    void viewDirContent();
    void AddItem(IFileParser *pItem);
};

#endif // CFILE_H
