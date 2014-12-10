#ifndef TESTUI_H
#define TESTUI_H

#include "TestQuestions.h"
#include "TestDB.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTableWidget>

namespace Ui {
class TestUI;
class UITTableWidget;

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
    void sendSignalPB(int);
    void sendSignalPB2(int);

private slots:
    void on_pushButton_3_clicked();
};


class UITableWidget : public TestUI
{

public:

    void setTableItem(int id, QString question, int RightAnswer, int UserAnswer, QString result);
    void testInsert();
};

#endif // TESTUI_H


