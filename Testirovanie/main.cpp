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
#include <QTableWidgetItem>
#include <QTableWidget>

int Dialog::randInt(int low, int high)
{
    // Произвольные числа от нижней границы до верхней
    return qrand() % ((high + 1) - low) + low;
}

void Dialog::ChangeAnswer()
{
    QString result,text_result;
    int n = 1;
    count++;
    qDebug() << count;

    if (count!=1)
    {QTime time = QTime::currentTime();
        qsrand((uint)time.msec());
        count1 = randInt(2,9);
        count2 = randInt(2,9);}

    ui->pushButton->setHidden(true);

    ui->label_2->setText(QString(" %1 %2 %3 ").arg(count1).arg("*").arg(count2));
    ui->label->setText(QString(" %1 %2 %3 %4").arg("Вопрос ").arg(count).arg(" из ").arg(max));

    int answer = QString(ui->lineEdit->displayText()).toInt();
   qDebug() << answer;
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
    qDebug() << count;

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
    ui->pushButton->setEnabled(false);
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
    int nID,right,wrong,step = 1;
    QSqlRecord rec = query.record();
    QString StrQuestion;
    int IntRight_answer;
    int IntUser_answer;
    QString CharResult;
    QString TextResult;
    ui->tableWidget->setRowCount(max);
    ui->tableWidget->setColumnCount(5);
    while (query.next()) {

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
    ui->tableWidget->setItem(step,1,new QTableWidgetItem(nID));
    ui->tableWidget->setItem(step,2,new QTableWidgetItem(QString(StrQuestion)));
    ui->tableWidget->setItem(step,3,new QTableWidgetItem(IntRight_answer));
    ui->tableWidget->setItem(step,4,new QTableWidgetItem(IntUser_answer));
    ui->tableWidget->setItem(step,5,new QTableWidgetItem(QString(TextResult)));
    step++;
    qDebug() << step;
    qDebug() << nID << StrQuestion << "=" << IntRight_answer << ". Вы ответили:"<<IntUser_answer<<" "<<TextResult;

    }
    setGeometry(QRect(200,300,400,423));
    ui->tableWidget->setVisible(true);
    repaint();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.ui->pushButton_2->setEnabled(false);
    w.ui->lineEdit->setEnabled(false);
    w.ui->tableWidget->setVisible(false);
    w.CreateTable();
/* QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    w.count1 = w.randInt(2,9);
    w.count2 = w.randInt(2,9);

    //ui->pushButton->setText("Следующий");
    w.ui->lineEdit->setEnabled(true);
    w.ui->lineEdit->setCursorPosition(0);
    w.ui->label_2->setText(QString(" %1 %2 %3 ").arg(w.count1).arg("*").arg(w.count2));
    w.ui->label->setText(QString(" %1 %2 %3 %4").arg("Вопрос ").arg(w.count).arg(" из ").arg(w.max));
*/
    w.show();

    return a.exec();
}
