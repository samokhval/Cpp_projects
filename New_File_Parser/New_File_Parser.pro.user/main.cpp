#include <QCoreApplication>
#include "CFileOperations.hpp"
#include <QDebug>
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char cmdline[MAX_PATH];
    string inputLine;
    IFileOperations *pFileOperations;


    GetCurrentDirectoryA(sizeof(cmdline),cmdline);
    strcat(cmdline,"\\");
    cout << cmdline;

    do
    {
        getline(cin,inputLine);

        if ((inputLine == "quit"))
        {
            cout << "Please press any key for quit!";
            return 0;
        }
        else if ((inputLine.substr(0,2) == "cd") && (inputLine.substr(2,1) == " "))
        {
            QString newPath = QString::fromStdString(inputLine.substr(3,inputLine.length()-1));
            if(SetCurrentDirectory(newPath.toStdString().c_str()))
            {

                pFileOperations = new CFileOperations();
                pFileOperations->setPath(newPath);
                pFileOperations->viewDirectoryContent();
                cout << newPath.toStdString() + "\\";
            }
            else
            {
                cout << "Path not found!" << endl;
                cout << cmdline;
            }
        }
        else if (inputLine == "find")
        {
             cout << "start find!" << endl;
        }
        else if (inputLine == "list")
        {
             cout << "list" << endl;
        }

        else
        {
            cout << "Wrong command!!! Entered a new command or 'quit' for exit" << endl;
        }
    }
      while (inputLine != "quit");

    delete pFileOperations;
    return a.exec();
}
