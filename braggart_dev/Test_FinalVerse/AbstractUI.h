#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#include <QtGlobal>

class AbstractUI
{
public:
    virtual void getNextQuestion() = 0;
    virtual void setStartValue()= 0;
    virtual void setOperation()= 0;
    virtual void generateQuestion(int id) = 0;
    virtual int getMaxQuestion()= 0;
    virtual int getRightAnswer()= 0;
    virtual QString getSignQuestion()= 0;
    virtual int getCount1()= 0;
    virtual int getCount2()= 0;
};

#endif // ABSTRACTUI_H
