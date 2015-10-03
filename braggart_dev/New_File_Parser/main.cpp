#include <QCoreApplication>
#include "CFileOperations.hpp"
#include <QDebug>
#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    char cmdline[MAX_PATH];
    string inputLine;
    IFileOperations *pOperation;
    QString tmp_path;

    GetCurrentDirectoryA(sizeof(cmdline),cmdline);
    strcat(cmdline,"\\");
    cout << cmdline;
    tmp_path = cmdline;

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
                pOperation = new CFileOperations();
                pOperation->setPath(newPath);
                tmp_path = newPath;
            }
            else
            {
                cout << "Path not found!" << endl;
                cout << tmp_path.toStdString() << "\\";
            }
        }
        else if ((inputLine.substr(0,4) == "find") && (inputLine.substr(4,1) == " "))
        {
            QString fileMask = QString::fromStdString(inputLine.substr(5,inputLine.length()-1));
            pOperation->findFile(fileMask);
            cout << tmp_path.toStdString() << "\\";
        }
        else
        {
            cout << "Wrong command!!! Entered a new command or 'quit' for exit" << endl;
            cout << tmp_path.toStdString();
        }
    }
      while (inputLine != "quit");

    delete pOperation;


    return a.exec();
}
