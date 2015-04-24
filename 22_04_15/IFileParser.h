#include <cstdio>
#include <string>
#include <windows.h>
#include <list>
#include <iomanip>
#include <algorithm>
#include <iostream>

#ifndef IFILEPARSER_H
#define IFILEPARSER_H

using namespace std;

class IFileParser
{
public:
    IFileParser(string path): path_(path){}
    //virtual void FindFile(string name) = 0 ;
    virtual void setPath(string dir) = 0;
    //virtual void viewDirContent() = 0;
    virtual void AddItem(IFileParser *pItem) = 0;
    virtual ~IFileParser(){}
protected:
    string path_;
};

#endif // IFILEPARSER_H
