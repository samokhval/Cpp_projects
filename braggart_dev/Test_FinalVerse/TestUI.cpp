#include "TestUI.h"
#include "ui_TestUI.h"

TestUI::TestUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestUI)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(ButtonPress()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(ResultTest()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),this ,SLOT(GetAnswer()));

    connect(this,SIGNAL(sendSignal(QString)),this,SLOT(setText(QString)));
    connect(this,SIGNAL(sendSignalPB(int)),ui->progressBar,SLOT(setValue(int)));
    connect(this,SIGNAL(sendSignalPB2(int)),ui->progressBar,SLOT(setMaximum(int)));

    ui->lineEdit->setValidator(new QIntValidator(-100, 100, this));
    ui->lineEdit->setAlignment(Qt::AlignHCenter);
    ui->lineEdit->setCursorPosition(0);
    ui->progressBar->setVisible(false);
    ui->label_2->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->pushButton_2->setEnabled(false);

    m_StateTest = 1;
    m_UserAnswer = 0;
}

TestUI::~TestUI()
{
    delete ui;
}

void TestUI::setSizeUI(int width, int height)
{
    setGeometry(QRect(200,200,width,height));
    setMinimumSize(width,height);
    setMaximumSize(width,height);
    repaint();
}

void TestUI::ButtonPress()
{
    TestQuestions obj_Q;
    TestDB obj_DB;

    if (ui->lineEdit_2->text().isEmpty())
    {
       QMessageBox msgBox;
       msgBox.addButton(QMessageBox::Ok);
       msgBox.setText("Вы не ввели своё имя!");
       msgBox.setWindowTitle("Ошибка");
       msgBox.exec();
    }
    else
    {
        ui->pushButton->setVisible(false);
        ui->lineEdit_2->setVisible(false);
        ui->label_2->setVisible(true);
        ui->lineEdit->setVisible(true);
        ui->lineEdit->setCursorPosition(0);
        ui->progressBar->setVisible(true);

        ui->label->setText("Тестирование началось");

        //Считывание имени пользователя
        m_UserName = ui->lineEdit_2->text();

        //Установка максимального количества вопросов
        emit sendSignalPB2(obj_Q.getMaxQuestion());

        //Установка позиции ProgressBar
        setValuePB(m_StateTest-1);

        //Генерация вопроса и изменение формы
        emit sendSignal(obj_DB.GetQuestion(m_StateTest));

     }
}

void TestUI::setText(QString s)
{
    ui->label_2->setText(s);
}

void TestUI::ResultTest()
{
  setSizeUI(400,486);

  TestDB obj_DB;
  QSqlQuery query;
  TestQuestions obj_Q;

  int right = 0;
  int wrong = 0;

  ui->tableWidget->setRowCount(obj_Q.getMaxQuestion());
  ui->tableWidget->setColumnCount(4);

  QString Result;

  if (!query.exec("SELECT * FROM questions;"))
  {
      qDebug() << "Невозможно выполнить запрос";
      return;
  }

  QSqlRecord rec = query.record();

  while (query.next())
  {
      int nID = query.value(rec.indexOf("id")).toInt();
      QString StrQuestion = query.value(rec.indexOf("question")).toString();
      int IntRight_answer = query.value(rec.indexOf("right_answer")).toInt();
      int IntUser_answer = query.value(rec.indexOf("user_answer")).toInt();

      if ( IntUser_answer == IntRight_answer) {right++; Result = "+";}
      else {wrong++;  Result = "-";}
      qDebug() << nID << " " << StrQuestion << " = " << IntUser_answer << " " << Result;

      QTableWidgetItem *newItem1 = new QTableWidgetItem(QString(StrQuestion));
      QTableWidgetItem *newItem2 = new QTableWidgetItem(QString::number(IntRight_answer));
      QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(IntUser_answer));
      QTableWidgetItem *newItem4 = new QTableWidgetItem(QString(Result));

      ui->tableWidget->setItem(nID-1,0,newItem1);
      ui->tableWidget->setItem(nID-1,1,newItem2);
      ui->tableWidget->setItem(nID-1,2,newItem3);
      ui->tableWidget->setItem(nID-1,3,newItem4);

      ui->tableWidget->repaint();

  }
  qDebug() << QString("%1 %2 %3 %4 %5 %6 %7").arg("Из ").arg(obj_Q.getMaxQuestion()).arg(" вопросов, вы ответили правильно на ").arg(right).arg(" и на ").arg(wrong).arg("неверно!");
  //ui->label_5->setText(QString("%1 %2 %3 %4 %5 %6 %7").arg("Из ").arg(max).arg(" вопросов, вы ответили правильно на ").arg(right).arg(" и на ").arg(wrong).arg("неверно!"));
  ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
  repaint();

}

void TestUI::GetAnswer()
{
   TestDB obj_DB;

   //Считывание ответа пользователя
   m_UserAnswer = QString(ui->lineEdit->displayText()).toInt();

   obj_DB.SetUserData(m_StateTest, m_UserAnswer);

   ui->lineEdit->clear();

   m_StateTest++;

   //Установка позиции ProgressBar
   setValuePB(m_StateTest-1);

   if (m_StateTest < 11)
   {
       //Генерация вопроса
       emit sendSignal(obj_DB.GetQuestion(m_StateTest));

   }
   else
   {
       ui->label_2->setVisible(false);
       ui->lineEdit->setVisible(false);
       ui->label->setText("Тестирование завершено");
       ui->pushButton_2->setEnabled(true);
       repaint();
   }
}

void TestUI::setValuePB(int i)
{
    emit sendSignalPB(i);
}

void TestUI::on_pushButton_3_clicked()
{
    exit(0);
}
