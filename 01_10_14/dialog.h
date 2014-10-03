#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void setEnable();
    void setDisable();
    void setSize(int i, int j, int x, int z);  
    int getLineEdit();
    void setItem(QString first, QString second, int three, int four, int step);
    void GetResult(QString result);
    void RepaintForm(int count, int count1, int count2);


private slots:
    void on_pushButton_3_clicked();
    void StartTest();
    void showResult();
    void GenerateQuestion();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
