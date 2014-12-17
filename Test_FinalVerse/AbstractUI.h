#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#include <QtGlobal>

/// смысл названия этого файла для меня не понятен
/// читаем MVC
class AbstractUI
{
public:
    virtual int getMaxQuestion()= 0;
    virtual int getRightAnswer()= 0;
    virtual QString getSignQuestion()= 0;
    virtual int getCount1()= 0;
    virtual int getCount2()= 0;
};

#endif // ABSTRACTUI_H
