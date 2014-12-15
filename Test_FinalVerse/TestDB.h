#ifndef TESTDB_H
#define TESTDB_H

#include <TestQuestions.h>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include "qDebug"

typedef int tID;
typedef int tCount;
typedef int tAnswer;
typedef QString tSign;

class TestDB
{
public:
    TestDB();
    void CreateTable();
    void InsertValue(tID id, tCount count1, tCount count2, tSign sign, tAnswer RightAnswer);
    bool CheckDublicate(tCount count1,tCount count2, tSign sign);
    void SetUserData(tID id, tAnswer user_answer);
    QString GetQuestion(tID id);
};

#endif // TESTDB_H
