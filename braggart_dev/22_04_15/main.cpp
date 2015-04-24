#include <iostream>
#include <CDirectory.h>
#include <windows.h>

using namespace std;

int main()
{
    char cmdline[MAX_PATH];
    GetCurrentDirectoryA(sizeof(cmdline),cmdline);
    strcat(cmdline,"\\");
    cout << cmdline;

    CDirectory *pcmdPath = new CDirectory(cmdline);
    string cmdLine;

    do
    {
        getline(cin,cmdLine);

        if ((cmdLine == "quit"))
        {
            cout << "Please press any key for quit!";

        }
        else if ((cmdLine.substr(0,2) == "cd") && (cmdLine.substr(2,1) == " "))
        {
            pcmdPath->setPath(cmdLine.substr(3,cmdLine.length()-1));
        }
        else if (cmdLine == "find")
        {
             cout << "start find!" << endl;
        }
        else if (cmdLine == "list")
        {
             pcmdPath->listInfo();
        }

        else
        {
            cout << "Wrong command!!! Entered a new command or 'quit' for exit" << endl;
        }
    }
      while (cmdLine != "quit");

    delete pcmdPath;

    return 0;
}

