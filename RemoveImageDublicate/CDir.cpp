#include "CDir.hpp"

void CDir::getContentDir()
{
    QDir dir(m_dirPath);
    QStringList jpgs = dir.entryList(QStringList() << "*.jpg" << "*.jpeg", QDir::Files, QDir::Type | QDir::Name);

    if (jpgs.size() != 0)
    {
        foreach (QString file, jpgs)
        {
            file_list[file] = loadTagImage(file);
        }
        checkImageDublicate();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("The directory does not contain files JPG!");
        msgBox.exec();
    }
}

QString CDir::loadTagImage(QString nameFile)
{
    QString path_image = m_dirPath+"/"+nameFile;

    QExifImageHeader header;

    header.loadFromJpeg(path_image);

    QExifValue value=header.value(QExifImageHeader::DateTimeOriginal);
    return value.toString();
}

void CDir::checkImageDublicate()
{
    static int count;
    QString result;
    QStringList list = file_list.values();

    qSort(list.begin(), list.end());

    for(int i=0; i < list.size(); i++)
    {
        if  ((list.value(i) == list.value(i+1)) && (list.value(i) != ""))
        {
            QString file_dublicate = file_list.key(list.value(i+1));
            count++;
            RemoveDublicate(file_dublicate);
            list.clear();
            checkImageDublicate();
        }
        else if (list.value(i) == "")
        {
        }
        else
        {
            result = "Search completed! " + QString::number(count) + " found a duplicate!";
            QMessageBox msgBox;
            msgBox.setText(result);
            msgBox.exec();
        }
    }
}

void CDir::RemoveDublicate(QString nameFile)
{

    file_list.remove(nameFile);
    QFile bak(m_dirPath);
    QDir itdir;
    itdir.mkdir(m_dirPath+"\\copy");
    bak.rename(m_dirPath+"\\"+nameFile, m_dirPath+"\\copy\\"+nameFile);
}
