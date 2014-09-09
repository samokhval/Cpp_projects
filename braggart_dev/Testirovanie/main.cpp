#include "dialog.h"
#include "ui_dialog.h"
#include <QApplication>
#include <QDebug>
#include <QtGlobal>
#include <QTime>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>

int Dialog::randInt(int low, int high)
{
    // Произвольные числа от нижней границы до верхней
    return qrand() % ((high + 1) - low) + low;
}

void Dialog::ChangeAnswer()
{
    QString result,text_result;
    int n = 1;
    answer = QString(ui->lineEdit->displayText()).toInt();
    count += n;
    qDebug() << count;
    qDebug() << ui->lineEdit->text();


    if (count1*count2 == answer)
    {
        result = "+";
        text_result = "Правильный ответ!!! Вы молодец!";
    }
    else
    {
        result = "-";
        text_result = "Вы ответили неправильно!!! Нужно еще учить!";
    }

    qDebug() << count1*count2 << " " << answer << " " <<result;
    QString strIn = ui->label_2->text();

    InsertValue(count, strIn, count1*count2, answer, result, text_result);

    //count += n;

    ui->lineEdit->clear();

    if (count == max)
    {
        ui->pushButton_2->setEnabled(true);
        ui->pushButton->setEnabled(false);
        ui->lineEdit->setEnabled(false);
    }
}


//Добавление в таблицу данных
void Dialog::InsertValue(int i, QString StrIn, int count, int answer, QString result, QString text_result)
{
    QSqlQuery query;
    QString strF =
    "INSERT INTO questions (id, question, right_answer, user_answer, result, text_result) "
    "VALUES(%1, '%2', %3, %4, '%5', '%6');";
    QString str = strF.arg(i)
    .arg(StrIn).arg(count).arg(answer).arg(result).arg(text_result);
    if (!query.exec(str))
    {
    qDebug() << "Невозможно осуществить операцию вставки данных!";
    }
}

//действия осуществляемые при нажании кнопки "Следующий"
void Dialog::next_q()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    count1 = randInt(2,9);
    count2 = randInt(2,9);


    ui->pushButton->setText("Следующий");
    ui->lineEdit->setEnabled(true);
    ui->lineEdit->setCursorPosition(0);
    ui->label_2->setText(QString(" %1 %2 %3 ").arg(count1).arg("*").arg(count2));
    ui->label->setText(QString(" %1 %2 %3 %4").arg("Вопрос ").arg(count+1).arg(" из ").arg(max));
    repaint();

}

//Создание таблицы
void Dialog::CreateTable()
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

//Вывод результата на экран
void Dialog::GetDataBase()
{
    QSqlQuery query;
    if (!query.exec("SELECT * FROM questions;")) {
    qDebug() << "Невозможно выполнить запрос — exiting";
    return;
    }

    QSqlRecord rec = query.record();
    int nID,right,wrong = 0;
    QString StrQuestion;
    int IntRight_answer;
    int IntUser_answer;
    QString CharResult;
    QString TextResult;
    while (query.next()) {
    nID = query.value(rec.indexOf("id")).toInt();
    StrQuestion = query.value(rec.indexOf("question")).toString();
    IntRight_answer = query.value(rec.indexOf("right_answer")).toInt();
    IntUser_answer = query.value(rec.indexOf("user_answer")).toInt();
    CharResult = query.value(rec.indexOf("result")).toString();
    if (CharResult == "+")
       right += 1;
    else
       wrong += 1;
    TextResult = query.value(rec.indexOf("text_result")).toString();
    qDebug() << nID << StrQuestion << "=" << IntRight_answer << ". Вы ответили:"<<IntUser_answer<<" "<<TextResult;

    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.ui->pushButton_2->setEnabled(false);
    w.ui->lineEdit->setEnabled(false);
    w.CreateTable();

    w.show();

    return a.exec();
}
