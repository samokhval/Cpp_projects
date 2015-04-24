#include "CCommandLine.hpp"

CCommandLine::CCommandLine()
{

}

void CCommandLine::setCmdLine(char *path)
{
    strcpy(m_cmdLine,path);

    char InputLine[];

    //CDirectory objDir(m_cmdLine);
    //p = &dir_obj;
    //IParser *p = new CDirectory(m_cmdLine);

    cout << m_cmdLine;

    do
    {
        gets(InputLine);

        if (!(strcmp(InputLine,"find")))
        {
            cout << "find file" << endl;
            cout << m_cmdLine;
        }
        else if (!(strcmp(InputLine,"cd")))
        {
            cout << "change directory" << endl;
            cout << m_cmdLine;
        }
        else if ((!(strcmp(InputLine,"exit"))) || (!(strcmp(InputLine,"quit"))))
        {
            cout << "Press any key for exit!" << endl;
        }
        else
        {
            cout << "Wrong command!" << endl;
            cout << m_cmdLine;
        }

    }
    while ((strcmp(InputLine,"exit")) && (strcmp(InputLine,"quit")));

    exit(0);

}
