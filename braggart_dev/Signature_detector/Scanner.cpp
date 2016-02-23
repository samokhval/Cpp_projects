#include "Scanner.h"

Scanner::Scanner()
{
    pUI = new CUI;
    pUI->getRefScanner(this);
    countFiles = 0;
    loadDataBase();
}

void Scanner::loadDataBase()
{
    string new_line;
    ifstream myfile(INPUT_FILENAME.toStdString());
    if (myfile.is_open())
    {
        while ( getline (myfile,new_line))
        {
          mListMask.push_back(QString::fromStdString(new_line));
        }
        qDebug() << "Information from file is loaded successfully";
        myfile.close();
     }
     else
        qDebug() << "Unable to open inputfile " << INPUT_FILENAME;
}


void Scanner::showUI()
{
    pUI->show();
}

void Scanner::setFilePath(QString pathDir)
{
    mFilePath = pathDir;
}

void Scanner::setCountFiles(QString pathDir)
{    
    QDir dir(pathDir);
    dir.setFilter( QDir::Files | QDir::NoDotAndDotDot );
    countFiles += dir.count();
    QFileInfoList sList = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach(QFileInfo lDir, sList)
    {
       setCountFiles(lDir.absoluteFilePath());
    }    
}

void Scanner::viewDirContent()
{
    list<QString> matchingList;
    QDirIterator iterator (mFilePath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while(iterator.hasNext())
    {
        iterator.next();
        pUI->setLabelText(iterator.fileInfo().fileName());
        pUI->signalToPB();
        pFile = new CFile(iterator.fileInfo().absoluteFilePath());
        std::thread t(&CFile::scanFile,pFile,&mListMask);
        t.join();
        matchingList = pFile->getResultScan();
        for (list<QString>::iterator it = matchingList.begin(); it != matchingList.end(); ++it)
        {
            saveToFile(*it);
        }
        delete pFile;
    }
}

void Scanner::saveToFile(QString inputString)
{
    char buffer[80];
    time_t seconds = time(NULL);
    tm* timeinfo = localtime(&seconds);
    char* format = "%d %B %Y %I:%M:%S";
    strftime(buffer, 80, format, timeinfo);
    ofstream outputFile;
    outputFile.open (OUTPUT_FILENAME.toStdString(), ios::out | ios::app);
    outputFile << "Date of scanning:" << buffer << ", " << inputString.toStdString() << "\n";
    outputFile.close();
}

Scanner::~Scanner()
{
    delete pUI;    
}

