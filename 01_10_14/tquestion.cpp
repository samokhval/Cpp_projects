#include "tquestion.h"
#include "dialog.h"
#include "tdatabase.h"

int tQuestion::getAnswer()
{
  Dialog d;
  int answer = d.getLineEdit();
  return answer;
}

void tQuestion::InsertAnswer(int count1, int count2)
{
    tDataBase base;
    QString strIn = QString(" %1 %2 %3 ").arg(count1).arg("*").arg(count2);

    if (count1*count2 == getAnswer())
    {
        result = "+";
        text_result = "Отлично! Вы ответили правильно!";
    }
    else
    {
        result = "-";
        text_result = "Ответ неверный! Нужно еще учить";
    }

    base.InsertValue(count, strIn, count1*count2, getAnswer(), result, text_result);
}

void tQuestion::getNextQuestion()
{
    tDataBase base;
    Dialog dlg;

    if (count > max)
    {
        dlg.setDisable();
    }
    else
    {

        QTime time = QTime::currentTime();
        qsrand((uint)time.msec());

        int count1 = qrand() % ((9 + 1) - 2) + 2;
        int count2 = qrand() % ((9 + 1) - 2) + 2;

        if (count < max+1)
        {
            InsertAnswer(count1,count2);

            if (count > 1)
            {
                if (base.CheckDublicate(count1,count2))
                {
                    count1 = qrand() % ((9 + 1) - 2) + 2;
                    count2 = qrand() % ((9 + 1) - 2) + 2;
                }

            }
            qDebug() << count << " " << count1 << " " << count2;
            dlg.RepaintForm(count,count1,count2);
         }


    }
}

int tQuestion::getQuestionsNumber(){return max;}

void tQuestion::getDetailedReport()
{
      qDebug() << "Будет проиведен детальный отчёт по ответам пользователей";
}


