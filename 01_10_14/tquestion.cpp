#include "tquestion.h"
#include "dialog.h"
#include "tdatabase.h"

int tQuestion::getAnswer()
{
  Dialog d;
  int answer = d.getLineEdit();
  return answer;
}

void tQuestion::getNextQuestion()
{
    tDataBase base;
    Dialog dlg;

    count++;

    int ct = count;

    if (count > max)
    {
        dlg.setDisable();
    }
    else
    {
        if ((count!=1) && (count < max+1))
        {QTime time = QTime::currentTime();
            qsrand((uint)time.msec());

            int count1 = qrand() % ((9 + 1) - 2) + 2;
            int count2 = qrand() % ((9 + 1) - 2) + 2;

            while (base.CheckDublicate(count1,count2))
            {
                count1 = qrand() % ((9 + 1) - 2) + 2;
                count2 = qrand() % ((9 + 1) - 2) + 2;
            }

            dlg.RepaintForm(ct,count1,count2);
         }
    }
}



int tQuestion::getQuestionsNumber(){return max;}

void tQuestion::getDetailedReport()
{
      qDebug() << "Будет проиведен детальный отчёт по ответам пользователей";
}


