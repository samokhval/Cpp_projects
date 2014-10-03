#ifndef TDATABASE_H
#define TDATABASE_H

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QTableWidgetItem>
#include <QSqlRecord>

class tDataBase
{
    QSqlDatabase mSqlDatabase;
    QSqlQuery query;
    int right;
    int wrong;
    bool dublicate;
    QString CharResult;
    QString TextResult;
    QString StrQuestion;
    int IntRight_answer;
    int IntUser_answer;
    int nID;
    int step;

public:
    tDataBase();
    //~tDataBase();
    void InsertValue(int i, QString StrIn, int count, int answer, QString result, QString text_result);
    bool CheckDublicate(int count1, int count2);

signals:

public slots:
    void getTestResult();
};

#endif // TDATABASE_H
