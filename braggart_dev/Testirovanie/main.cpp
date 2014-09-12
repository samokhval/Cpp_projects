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

//проверка значений на дублирование
bool Dialog::CheckDublicate()
{
    QString strS1 = QString(" %1 %2 %3 ").arg(count1).arg("*").arg(count2);
    QString strS2 = QString(" %1 %2 %3 ").arg(count2).arg("*").arg(count1);

    QSqlQuery query;
    bool dublicate;

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

void Dialog::ChangeAnswer()
{
    QString result,text_result;

    ui->lineEdit->setCursorPosition(0);
    ui->lineEdit->setAlignment(Qt::AlignVCenter);

    int answer = QString(ui->lineEdit->displayText()).toInt();

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

    QString strIn = ui->label_2->text();

    InsertValue(count, strIn, count1*count2, answer, result, text_result);

    ui->lineEdit->clear();
    count++;

    if (count > max)
    {
        ui->pushButton_2->setEnabled(true);
        ui->lineEdit->setEnabled(false);
    }

    {
        if ((count!=1) && (count < max+1))
        {QTime time = QTime::currentTime();
            qsrand((uint)time.msec());

            count1 = qrand() % ((9 + 1) - 2) + 2;
            count2 = qrand() % ((9 + 1) - 2) + 2;

            while (CheckDublicate())
            {
                count1 = qrand() % ((9 + 1) - 2) + 2;
                count2 = qrand() % ((9 + 1) - 2) + 2;
            }

            ui->label_2->setText(QString(" %1 %2 %3 ").arg(count1).arg("*").arg(count2));
            ui->label->setText(QString(" %1 %2 %3 %4").arg("Вопрос ").arg(count).arg(" из ").arg(max));
            repaint();
         }
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

//Вывод результата на экран
void Dialog::GetDataBase()
{
    right = right - 4;
    QSqlQuery query;

    setGeometry(QRect(200,200,424,469));
    setMinimumSize(424,469);
    setMaximumSize(424,469);

    if (!query.exec("SELECT * FROM questions;")) {
    qDebug() << "Невозможно выполнить запрос — exiting";
    return;
    }
    int nID;
    int step = 0;
    QSqlRecord rec = query.record();
    QString StrQuestion;
    int IntRight_answer;
    int IntUser_answer;
    QString CharResult;
    QString TextResult;
    ui->tableWidget->setRowCount(max);
    ui->tableWidget->setColumnCount(4);
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

    QTableWidgetItem *newItem1 = new QTableWidgetItem(QString(CharResult));
    QTableWidgetItem *newItem2 = new QTableWidgetItem(QString(StrQuestion));
    QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(IntRight_answer));
    QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::number(IntUser_answer));

    ui->tableWidget->setItem(step,0,newItem2);
    ui->tableWidget->setItem(step,1,newItem3);
    ui->tableWidget->setItem(step,2,newItem4);
    ui->tableWidget->setItem(step,3,newItem1);

    step++;
    }

    ui->label_5->setText(QString("%1 %2 %3 %4 %5 %6 %7").arg("Из ").arg(max).arg(" вопросов, вы ответили правильно на ").arg(right).arg(" и на ").arg(wrong).arg("неверно!"));
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableWidget->setVisible(true);
    ui->pushButton_2->setVisible(false);
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

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    w.count1 = w.randInt(2,9);
    w.count2 = w.randInt(2,9);

    w.ui->lineEdit->setCursorPosition(0);
    w.ui->lineEdit->setEnabled(true);
    w.ui->label_2->setText(QString(" %1 %2 %3 ").arg(w.count1).arg("*").arg(w.count2));
    w.ui->label->setText(QString(" %1 %2 %3 %4").arg("Вопрос ").arg(w.count).arg(" из ").arg(w.max));
    w.repaint();

    w.setGeometry(QRect(200,200,424,129));
    w.setMaximumSize(424,129);
    w.show();

    return a.exec();
}
