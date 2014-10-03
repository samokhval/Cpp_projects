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
    int numb, count;
    bool dublicate;

public:
    void getNextQuestion();
    int getAnswer();
    void setQuestion();
    int getQuestionsNumber();
//    int getCurrentQuestionNumber();
    void getDetailedReport();

signals:

public slots:

};

#endif // TQUESTION_H