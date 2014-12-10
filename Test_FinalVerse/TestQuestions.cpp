#include "TestQuestions.h"

TestQuestions::TestQuestions()
{
}

void TestQuestions::setStartValue()
{
    m_count1 = 0;
    m_count2 = 0;
    m_RightAnswer = 0;
    m_signQustion = "";
}

void TestQuestions::setOperation()
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    int count = rand() % 3 + 1;

    switch (count)
    {
         case 1:
         {
            m_signQustion = "+";
            m_RightAnswer = m_count1 + m_count2;
            break;
         }
         case 2:
         {
            m_signQustion = "-";
            m_RightAnswer = m_count1 - m_count2;
            break;
         }
         case 3:
         {
            m_signQustion = "*";
            m_RightAnswer = m_count1 * m_count2;
            break;
         }
         default:
         ;
    }
}

void TestQuestions::generateQuestion(int id)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    m_count1 = qrand() % ((9 + 1) - 2) + 2;
    m_count2 = qrand() % ((9 + 1) - 2) + 2;
    setOperation();

    TestDB obj_DB;

    while ((obj_DB.CheckDublicate(m_count1,m_count2,m_signQustion)) || (m_RightAnswer < 1))
    {
        m_count1 = qrand() % ((9 + 1) - 2) + 2;
        m_count2 = qrand() % ((9 + 1) - 2) + 2;
        setOperation();        
    }

    obj_DB.InsertValue(id,m_count1,m_count2,m_signQustion,m_RightAnswer);
}
