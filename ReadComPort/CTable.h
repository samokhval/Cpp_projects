#ifndef CTABLE_H
#define CTABLE_H

#include <QString>
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QVariant>
#include <list>

using namespace std;

class CTable
{
public:
    CTable();
    bool InsertToBase(QString strEvent, QString namePort, QString receivedInfo);
    list<QString> getInfo();
};

#endif // CTABLE_H
