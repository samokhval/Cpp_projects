#ifndef TESTQUESTIONS_H
#define TESTQUESTIONS_H

#include <QtGlobal>
#include <QTime>
#include <QDebug>
#include <TestUI.h>
#include <AbstractUI.h>

const int max = 10;

class TestQuestions//: public AbstractUI
{
    int m_questionID;
    int m_count1;
    int m_count2;
    QString m_signQustion;
    int m_RightAnswer;

public:
    TestQuestions();
    void setStartValue();
    void setOperation();
    void generateQuestion(int id);
    int getMaxQuestion(){return max;}
    int getRightAnswer(){return m_RightAnswer;}
    QString getSignQuestion(){return m_signQustion;}
    int getCount1(){return m_count1;}
    int getCount2(){return m_count2;}
};

#endif // TESTQUESTIONS_H
