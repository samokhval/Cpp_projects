#ifndef SCANNER_H
#define SCANNER_H

#include <QDir>
#include <QDirIterator>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <ctime>

#include "CUI.h"
#include "CFile.h"

using namespace std;

const QString INPUT_FILENAME = "base.in";
const QString OUTPUT_FILENAME = "result.out";

class CUI;

class Scanner
{
public:
    Scanner();
    void loadDataBase();
    void showUI();
    void viewDirContent();
    void setFilePath(QString pathDir);
    void setCountFiles(QString pathDir);
    int getCountFiles(){return countFiles;}
    void saveToFile(QString inputString);
    ~Scanner();
private:
    CUI *pUI;
    CFile *pFile;
    QString mFilePath;
    int countFiles;
    list<QString> mListMask;
};

#endif // SCANNER_H
