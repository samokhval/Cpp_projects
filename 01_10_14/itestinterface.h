#ifndef ITESTINTERFACE_H
#define ITESTINTERFACE_H

//#include "tquestion.h"

class ITestInterface
{

public:

    virtual void getNextQuestion() = 0;
    virtual int getAnswer() = 0;
    virtual int getQuestionsNumber() = 0;
    //virtual int getCurrentQuestionNumber(int i) = 0;
    virtual void getDetailedReport() = 0;
    virtual void getTestResult() = 0;

};

#endif // ITESTINTERFACE_H
