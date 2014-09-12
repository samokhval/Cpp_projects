#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:    
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    Ui::Dialog *ui;

    const int max = 10; //количество вопросов в тесте
    int count = 1; //начальное значение счётчика
    int right, wrong = 0;//переменные подсчёта правильный и неправильных ответов
    int count1,count2;//переменные для хранения множителей

    void CreateTable(); //создание таблицы
    bool CheckDublicate();//проверка дублирования вопросов
    void InsertValue(int, QString, int, int, QString, QString);
    int randInt(int, int);

private:

public slots:
    void GetDataBase();
    void ChangeAnswer();

private slots:
    void on_pushButton_3_clicked();
};

#endif // DIALOG_H
