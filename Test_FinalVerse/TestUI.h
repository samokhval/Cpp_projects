#ifndef TESTUI_H
#define TESTUI_H

#include "TestQuestions.h"
#include "TestDB.h"
#include <QDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableWidget>
#include <QIcon>

namespace Ui {
class TestUI;
}

class TestUI : public QDialog
{
    Q_OBJECT
    int m_StateTest;
    int m_UserAnswer;
    QString m_UserName;

public:
    explicit TestUI(QWidget *parent = 0);
    ~TestUI();
    void setQuestion();
    void setSizeUI(int width, int height);
    void setValuePB(int i);

protected:
    Ui::TestUI *ui;

public slots:
    void ButtonPress();
    void ResultTest();
    void GetAnswer();
    void setText(QString);

signals:
    void sendSignal(QString);
    void sendSignalPB(int); /// название методов очень говорящее
    void sendSignalPB2(int);

private slots:
    void on_pushButton_3_clicked();
};

#endif // TESTUI_H


