#ifndef CSCANNER_H
#define CSCANNER_H

#include "CFile.h"

const QString INPUT_FILE = "mask.txt";

class CScanner
{
public:
    CScanner();
    void getNewFile(QString fileName);
    ~CScanner();

private:
    CFile *pFile;

};

#endif // CSCANNER_H
