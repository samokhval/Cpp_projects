#ifndef SCANNER_H
#define SCANNER_H

#include <QDir>
#include <QDirIterator>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QTextCodec>
#include <QMap>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

#include "CUI.h"
#include "CFile.h"

using namespace std;

const QString INPUT_FILENAME = QString::fromUtf8(PRO_FILE_PWD)+"/base.in";
const QString OUTPUT_FILENAME = QString::fromUtf8(PRO_FILE_PWD)+"/result.out";

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
    void setUISize(int width,int height);
    int getCountFiles();
    void saveToFile(QString inputString);    
    ~Scanner();
private:
    CUI *pUI;
    CFile *pFile;
    QString mFilePath;
    int countFiles;
    QMap<QString,QString> mList;
};

#endif // SCANNER_H
