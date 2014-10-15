#ifndef TQUESTION_H
#define TQUESTION_H

#include <itestinterface.h>
#include <tdatabase.h>
#include <QtGlobal>
#include <QTime>
#include <QDebug>

const int max = 10;

class tQuestion : public ITestInterface
{
    bool dublicate;
    int count;
    int step;
    QString result;
    QString text_result;

public:
    tQuestion(){count=0;}
    tQuestion(int i){count=count + i;}
    void getNextQuestion();
    int getAnswer();
    void InsertAnswer(int count1, int count2);
    void setQuestion();
    int getQuestionsNumber();
    //int getCurrentQuestionNumber(int i) { step = i + 1; return step; }
    void getDetailedReport();
    void getTestResult() {}

};

#endif // TQUESTION_H
