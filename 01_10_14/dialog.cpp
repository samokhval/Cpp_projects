#include "dialog.h"
#include "tquestion.h"
#include "tdatabase.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(showResult()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(StartTest()));
    connect(ui->lineEdit,SIGNAL(returnPressed()),this ,SLOT(GenerateQuestion()));

    ui->lineEdit->setValidator(new QIntValidator(0, 81, this));
    ui->lineEdit->setAlignment(Qt::AlignHCenter);
    ui->pushButton_2->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->tableWidget->setVisible(false);

    setGeometry(QRect(200,200,424,129));
    setMinimumSize(424,129);
    setMaximumSize(424,129);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::StartTest()
{
 ui->pushButton->setVisible(false);
 ui->lineEdit->setEnabled(true);
 ui->lineEdit->setCursorPosition(0);
 ui->lineEdit->setAlignment(Qt::AlignHCenter);
 setEnable();
}

int Dialog::getLineEdit()
{
   return QString(ui->lineEdit->displayText()).toInt();
}

void Dialog::on_pushButton_3_clicked()
{
    close();
}

void Dialog::RepaintForm(int count, int count1, int count2)
{
    Dialog dlg;
    qDebug() << "Получили count = " << count << " count2 = " << count1<< " count2 = " << count2;
    QString sText = QString(" %1 %2 %3 ").arg(count1).arg("*").arg(count2);
    qDebug() << "Текст для вывода в метку: " << sText;
    ui->label_2->setText(sText);
    qDebug() << "Текст метки " << ui->label_2->text();
    ui->label->setText(QString(" %1 %2 %3 %4").arg("Вопрос ").arg(count).arg(" из ").arg(max));
    dlg.repaint();
    qDebug() << "Сейчас должна быть прорисовка";
}

void Dialog::setEnable()
{
    ui->lineEdit->setEnabled(true);

    ITestInterface *pQuestion;
    pQuestion = new tQuestion();
    pQuestion->getNextQuestion();

}

void Dialog::setDisable()
{
   ui->pushButton_2->setEnabled(true);
   ui->lineEdit->setEnabled(false);
}
void Dialog::setSize(int i, int j, int x, int z)
{
    setGeometry(QRect(i,j,x,z));
    setMinimumSize(x,z);
    setMaximumSize(x,z);
    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(4);
}

void Dialog::setItem(QString first, QString second, int three, int four,int step)
{
    setSize(200,200,424,469);

    QTableWidgetItem *newItem1 = new QTableWidgetItem(QString(first));
    QTableWidgetItem *newItem2 = new QTableWidgetItem(QString(second));
    QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(three));
    QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::number(four));

    ui->tableWidget->setItem(step,0,newItem2);
    ui->tableWidget->setItem(step,1,newItem3);
    ui->tableWidget->setItem(step,2,newItem4);
    ui->tableWidget->setItem(step,3,newItem1);
}

void Dialog::GetResult(QString result)
{
    qDebug() << result;
    ui->label_5->setText(result);
    ui->tableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
    ui->tableWidget->setVisible(true);
    ui->pushButton_2->setVisible(false);
    repaint();
}

void Dialog::showResult()
{
    tDataBase base;
    base.getTestResult();
}

void Dialog::GenerateQuestion()
{
  ui->lineEdit->clear();
  ITestInterface *pQuestion;
  pQuestion = new tQuestion(1);
  pQuestion->getNextQuestion();
}
