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
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(5);

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
  TestDB obj_DB;
  UITableWidget obj_Table;

  setSizeUI(400,486);
  obj_DB.GetBasesData();

  obj_Table.testInsert();
  obj_Table.repaint();

  repaint();

}

void UITableWidget::testInsert()
{
    ui->tableWidget->insertRow(0);
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("Item1"));
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

void UITableWidget::setTableItem(int id, QString question, int RightAnswer, int UserAnswer, QString result)
{

    ui->tableWidget->insertRow(id-1);
    ui->tableWidget->setItem(id-1,1,new QTableWidgetItem(QString(question)));


    QTableWidgetItem *newItem1 = new QTableWidgetItem(QString::number(id));
    //QTableWidgetItem *newItem2 = new QTableWidgetItem(QString(question));
    //QTableWidgetItem *newItem2 = new QTableWidgetItem("wewee");
    QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(RightAnswer));
    QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::number(UserAnswer));
    QTableWidgetItem *newItem5 = new QTableWidgetItem(QString(result));

    ui->tableWidget->setItem(id-1,0,newItem1);
    //ui->tableWidget->setItem(id-1,1,newItem2);
    ui->tableWidget->setItem(id-1,2,newItem3);
    ui->tableWidget->setItem(id-1,3,newItem4);
    ui->tableWidget->setItem(id-1,4,newItem5);

    QTableWidgetItem *pCell = new QTableWidgetItem;
    pCell->setText("LaVe");
    ui->tableWidget->setItem(0, 1, pCell);

}

void TestUI::on_pushButton_3_clicked()
{
    exit(0);
}
