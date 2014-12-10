#ifndef TESTDB_H
#define TESTDB_H

#include <TestQuestions.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>


#include "qDebug"

class TestDB
{
public:
    TestDB();
    void CreateTable();
    void InsertValue(int id, int count1, int count2, QString sign, int RightAnswer);
    bool CheckDublicate(int count1,int count2, QString sign);
    void GetBasesData();
    void SetUserData(int id, int user_answer);
    QString GetQuestion(int id);
};

#endif // TESTDB_H
