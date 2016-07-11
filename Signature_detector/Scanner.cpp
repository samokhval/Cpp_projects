#include "Scanner.h"

Scanner::Scanner()
{
    pUI = new CUI;
    pUI->getRefScanner(this);
    loadDataBase();
    countFiles = 0;
}

void Scanner::loadDataBase()
{
    string new_line;
    size_t n;
    QByteArray reply8bit;
    QString replyUnicode;
    ifstream myfile(INPUT_FILENAME.toStdString());
    if (myfile.is_open())
    {
        while ( getline (myfile,new_line))
        {
          n = new_line.find(".{");
          reply8bit = QByteArray::fromHex(new_line.substr(0,n).c_str());
          replyUnicode = QString::fromUtf8(reply8bit);
          mList.insert(replyUnicode,QString::fromStdString(new_line.substr(n+2,new_line.length() - n - 3)));
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

void Scanner::setUISize(int width, int height)
{
    pUI->setFixedSize(width,height);
}

int Scanner::getCountFiles()
{
    return countFiles;
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
        std::thread t(&CFile::scanFile,pFile,&mList);
        t.join();        
        foreach (QString it, pFile->getResultScan())
        {
            matchingList.push_back(it);
        }
        delete pFile;
    }

    pUI->setLabelText("");
    pUI->setBaseSize(425,485);
    pUI->setCountRow(matchingList.size());

    for (list<QString>::iterator it = matchingList.begin(); it != matchingList.end(); ++it)
    {
        pUI->addNewStringToTab(*it);
        saveToFile(*it);
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
    mList.clear();
    delete pUI;
}

