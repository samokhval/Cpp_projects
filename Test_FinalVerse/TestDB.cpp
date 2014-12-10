#include "TestDB.h"

TestDB::TestDB()
{
}

void TestDB::CreateTable()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open())
    {
       qDebug() << "Невозможно открыть временную базу";
    }

    // Создаем таблицу
    QSqlQuery query;
    QString str = "CREATE TABLE questions ( "
    "id INTEGER AUTO_INCREMENT, "
    "user_name VARCHAR(20), "
    "question VARCHAR(15), "
    "right_answer INT(10), "
    "user_answer INT(10), "
    "result VARCHAR(1), "
    "PRIMARY KEY(`id`)"
    ");";

    if (!query.exec(str))
    {
       qDebug() << "Невозможно создать таблицу";
    }
}

//проверка значений на дублирование
bool TestDB::CheckDublicate(int count1,int count2, QString sign)
{
    QSqlQuery query;
    bool dublicate = false;

    //QSqlDatabase db;
    //db.setDatabaseName(":memory:");

    QString strS1 = QString(" %1 %2 %3 ").arg(count1).arg(sign).arg(count2);
    QString strS2 = QString(" %1 %2 %3 ").arg(count2).arg(sign).arg(count1);

    QString str_select = QString("SELECT question FROM questions WHERE question = '%1' OR question = '%2'").arg(strS1).arg(strS2);

    query.exec(str_select);

    QSqlRecord rec = query.record();

    while (query.next())
    {
        QString str_question = query.value(0).toString();

        if (strS1 == str_question)
        {
            dublicate = true;
        }
    }
    return dublicate;
}

//Передача результата для вывода в таблицу
void TestDB::GetBasesData()
{
    QSqlQuery query;
    TestQuestions obj_Q;
    TestUI obj_UI;
    UITableWidget obj_Table;

    int right = 0;
    int wrong = 0;

    QString Result;

    if (!query.exec("SELECT * FROM questions;"))
    {
        qDebug() << "Невозможно выполнить запрос";
        return;
    }

    QSqlRecord rec = query.record();

    while (query.next())
    {
        int nID = query.value(rec.indexOf("id")).toInt();
        QString StrQuestion = query.value(rec.indexOf("question")).toString();
        int IntRight_answer = query.value(rec.indexOf("right_answer")).toInt();
        int IntUser_answer = query.value(rec.indexOf("user_answer")).toInt();

        if ( IntUser_answer == IntRight_answer) {right++; Result = "+";}
        else {wrong++;  Result = "-";}
        qDebug() << nID << " " << StrQuestion << " = " << IntUser_answer << " " << Result;
        obj_Table.setTableItem(nID,StrQuestion,IntRight_answer,IntUser_answer,Result);
    }
    qDebug() << QString("%1 %2 %3 %4 %5 %6 %7").arg("Из ").arg(obj_Q.getMaxQuestion()).arg(" вопросов, вы ответили правильно на ").arg(right).arg(" и на ").arg(wrong).arg("неверно!");
    //ui->label_5->setText(QString("%1 %2 %3 %4 %5 %6 %7").arg("Из ").arg(max).arg(" вопросов, вы ответили правильно на ").arg(right).arg(" и на ").arg(wrong).arg("неверно!"));
    //ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    //ui->tableWidget->setVisible(true);
    //ui->pushButton_2->setVisible(false);
    //repaint();
}

void TestDB::InsertValue(int id, int count1, int count2, QString sign, int RightAnswer)
{
    QSqlQuery query;

    QString str_question = QString(" %1 %2 %3 ").arg(count1).arg(sign).arg(count2);

    query.prepare("INSERT INTO questions (id, question, right_answer) "
    "VALUES(:id, :question, :right_answer);");
    query.bindValue(":id", id);
    query.bindValue(":question", str_question);
    query.bindValue(":right_answer", RightAnswer);

    if (!query.exec())
    {
        qDebug() << "Невозможно вставить запись!";
    }

}

QString TestDB::GetQuestion(int id)
{

    QSqlQuery query;

    QString str_select = QString("SELECT user_name, id, question, right_answer FROM questions WHERE id = %1").arg(id);

    query.exec(str_select);

    QSqlRecord rec = query.record();

    while (query.next())
    {
        return query.value(2).toString();
    }
}

void TestDB::SetUserData(int id, int user_answer)
{
    QSqlQuery query;

    QString str_update = QString("UPDATE questions SET user_answer = %1 WHERE id = %2").arg(user_answer).arg(id);

    if (!query.exec(str_update))
    {
        qDebug() << "невозможно обновить запись таблицы";
    }
}
