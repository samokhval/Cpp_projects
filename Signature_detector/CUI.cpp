#include "CUI.h"
#include "ui_CUI.h"

CUI::CUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CUI)
{
    ui->setupUi(this);
    connect(this,SIGNAL(signalToPB()),this,SLOT(setValueProgressBar()),Qt::AutoConnection);
}

CUI::~CUI()
{
    delete ui;
    delete pScanner;
}

void CUI::getRefScanner(Scanner *refScanner)
{
    pScanner = refScanner;
}

void CUI::on_buttonChangeDir_clicked()
{   
    QString rootPath;
    rootPath = QFileDialog::getExistingDirectory(this, tr("Select Directory"),"",QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks);
    ui->selectPath->setText(rootPath);
    pScanner->setFilePath(ui->selectPath->text());
}

void CUI::setValueProgressBar()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
    ui->progressBar->repaint();
}

void CUI::on_buttonStart_clicked()
{
    pScanner->setCountFiles(ui->selectPath->text());
    ui->progressBar->setRange(0,pScanner->getCountFiles());
    ui->progressBar->setMaximum(pScanner->getCountFiles());
    std::thread t(&Scanner::viewDirContent,pScanner);
    t.detach();
}

void CUI::on_buttonClose_clicked()
{
    close();
}

void CUI::setLabelText(QString nameFile)
{
    ui->label_2->setText(nameFile);
}
