#include "CTable.h"

CTable::CTable()
{
    //Open a temporary database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open())
        cout << "Cannot open the database" << endl;

    //Create a table
    QSqlQuery query;
    QString queryStr;
    queryStr = "create table port_history (event_date varchar(20), "
               "name_port varchar(5), received_info varchar(150))";
    if (!query.exec(queryStr))
        cout << "Cannot create a table" << endl;
}

bool CTable::InsertToBase(QString strEvent, QString namePort, QString receivedInfo)
{
    QSqlQuery query;
    QString strQuery = QString("INSERT INTO port_history (event_date, name_port, received_info) VALUES ('%1', '%2', '%3');").arg(strEvent).arg(namePort).arg(receivedInfo);
    if (!query.exec(strQuery))
    {
       return false;
    }
    else
       return true;
}

list<QString> CTable::getInfo()
{
    list<QString> tmpInfo;
    QSqlQuery query;
    QString str_select = QString("SELECT event_date, name_port, received_info FROM port_history ORDER BY name_port;");
    QString summaryInfo;
    query.exec(str_select);
    QSqlRecord rec = query.record();
    while (query.next())
    {
        summaryInfo = QString("%1 %2 %3").arg(query.value(0).toString()).arg(query.value(1).toString()).arg(query.value(2).toString());
        tmpInfo.push_back(summaryInfo);
    }
    return tmpInfo;
}
