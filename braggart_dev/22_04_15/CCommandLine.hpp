#include "CDirectory.h"
#include <iostream>

#ifndef CCOMMANDLINE_HPP
#define CCOMMANDLINE_HPP

using namespace std;

class CCommandLine
{
    char m_cmdLine;

public:
    CCommandLine();
    void setCmdLine(char *path);
    string getCmdLine(){return 0;}

private:
    IFileParser *p;
};

#endif // CCOMMANDLINE_HPP
