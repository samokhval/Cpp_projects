#ifndef CDIR_HPP
#define CDIR_HPP

#include <QMap>
#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include "qexifimageheader.h"

class CDir
{
public:
    CDir(QString path){m_dirPath = path;}
    void getContentDir();
    void checkImageDublicate();
    void RemoveDublicate(QString nameFile);
    QString loadTagImage(QString nameFile);

private:
    QString m_dirPath;
    QMap<QString,QString> file_list;
};

#endif // CDIR_HPP
