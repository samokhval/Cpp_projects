#include "CUI.h"
#include "ui_CUI.h"

CUI::CUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CUI)
{
    ui->setupUi(this);
    connect(this,SIGNAL(signalToPB()),this,SLOT(setValueProgressBar()),Qt::AutoConnection);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    //table->horizontalHeaderItem(0)->setSizeHint(x,y);

}

CUI::~CUI()
{
    delete ui;
}

void CUI::getRefScanner(Scanner *refScanner)
{
    pScanner = refScanner;
}

void CUI::on_buttonChangeDir_clicked()
{   
    QString rootPath;
    rootPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"),"",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    pScanner->setFilePath(rootPath);
    pScanner->setCountFiles(rootPath);
    ui->selectPath->setText(rootPath);
    ui->progressBar->setRange(0,pScanner->getCountFiles());
    ui->progressBar->setMaximum(pScanner->getCountFiles());
    ui->progressBar->setValue(0);
    ui->progressBar->repaint();
    ui->label_2->setText("");


}

void CUI::setValueProgressBar()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
    ui->progressBar->repaint();
}

void CUI::on_buttonStart_clicked()
{
    std::thread t(&Scanner::viewDirContent,pScanner);
    t.detach();
}

void CUI::setCountRow(int c)
{
    ui->tableWidget->setRowCount(c);
}

void CUI::addNewStringToTab(QString newStr)
{
    static int count = 0;
    QTableWidgetItem *item = new QTableWidgetItem();
    item->setText(newStr);
    ui->tableWidget->setItem(count, 0, item);
    count++;
}

void CUI::on_buttonClose_clicked()
{
    close();
}

void CUI::setLabelText(QString nameFile)
{
    ui->label_2->setText(nameFile);
}

