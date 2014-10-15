#include "tdatabase.h"
#include "dialog.h"

tDataBase::tDataBase()
{
right = 4;
wrong = 0;
}

void tDataBase::CreateTable()
{
    mSqlDatabase = QSqlDatabase::addDatabase("QSQLITE");
    mSqlDatabase.setDatabaseName(":memory:");
    if (!mSqlDatabase.open())
    {
       qDebug() << "Невозможно открыть временную базу";
    }
    else
    {
       qDebug() << "Временная база  " << mSqlDatabase.databaseName() << "создана";
    }

    QSqlQuery query;
    QString str3 = QString("%1 %2").arg("USE").arg(mSqlDatabase.databaseName());
    if (query.exec(str3))
    {
        qDebug() << "Временная база установлена по умолчанию";
    }

    // Создаем таблицу
    QString str = "CREATE TABLE questions ( "
    "id INTEGER AUTO_INCREMENT, "
    "question VARCHAR(15), "
    "right_answer INT(10), "
    "user_answer INT(10), "
    "result VARCHAR(1), "
    "text_result VARCHAR(40), "
    "PRIMARY KEY(`id`)"
    ");";

    if (!query.exec(str))
    {
       qDebug() << "Невозможно создать таблицу";
    }
}

void tDataBase::InsertValue(int i, QString StrIn, int count, int answer, QString result, QString text_result)
{
    QString strF =
    "INSERT INTO questions (id, question, right_answer, user_answer, result, text_result) "
    "VALUES(%1, '%2', %3, %4, '%5', '%6');";
    QString str = strF.arg(i)
    .arg(StrIn).arg(count).arg(answer).arg(result).arg(text_result);
    if (!query.exec(str))
    {
        qDebug() << "Невозможно осуществить операцию вставки данных!";
    }
    //else
    //{
    //    qDebug() << "Данные успешно добавлены в таблицу!";
    //}
}

void tDataBase::getTestResult()
{
    Dialog d;

    right = right - 4;

    if (!query.exec("SELECT * FROM questions;"))
    {
        qDebug() << "Невозможно выполнить запрос — exiting";
        return;
    }

    QSqlRecord rec = query.record();

    while (query.next())
    {
        nID = query.value(rec.indexOf("id")).toInt();
        StrQuestion = query.value(rec.indexOf("question")).toString();
        IntRight_answer = query.value(rec.indexOf("right_answer")).toInt();
        IntUser_answer = query.value(rec.indexOf("user_answer")).toInt();
        CharResult = query.value(rec.indexOf("result")).toString();

        if (CharResult == "+")
            right++;
        else
            wrong++;

        TextResult = query.value(rec.indexOf("text_result")).toString();

        d.setItem(CharResult,StrQuestion,IntRight_answer,IntUser_answer,step);
        step++;
     }

   QString result = QString("%1 %2 %3 %4 %5 %6 %7").arg("Из ").arg(10).arg(" вопросов, вы ответили правильно на ").arg(right).arg(" и на ").arg(wrong).arg("неверно!");
   d.GetResult(result);
}

bool tDataBase::CheckDublicate(int count1, int count2)
{
    QString strS1 = QString(" %1 %2 %3 ").arg(count1).arg("*").arg(count2);
    QString strS2 = QString(" %1 %2 %3 ").arg(count2).arg("*").arg(count1);

    QSqlQuery query;
    QString str3 = QString("%1 %2").arg("USE").arg(mSqlDatabase.databaseName());
    if (query.exec(str3))
    {
        qDebug() << "Временная база установлена по умолчанию";
    }

    query.exec("SELECT * FROM questions;");

    QSqlRecord rec = query.record();

    while (query.next())
        {
            QString StrQuestion = query.value(rec.indexOf("question")).toString();
            if ((StrQuestion == strS1) || (StrQuestion == strS2))
            {
                dublicate = true;
                return dublicate;
            }
        }
        return dublicate;
}
