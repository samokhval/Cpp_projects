#include "IFileParser.h"
#include "CFile.h"
#include <list>
#include <iomanip>
#include <algorithm>

#ifndef CDIRECTORY_H
#define CDIRECTORY_H

using namespace std;

class CDirectory : public IFileParser
{
    string m_Path;
public:
    CDirectory(string path):IFileParser(path){}
    void FindFile(string name);
    void setPath(string dir);
    void viewDirContent();
    void listInfo();
    void AddItem(IFileParser *pItem);
    IFileParser *getItem(int i);

protected:
    list<IFileParser*> ListObjs;
};

#endif // CDIRECTORY_H
