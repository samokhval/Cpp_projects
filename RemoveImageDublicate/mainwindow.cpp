#include "mainwindow.hpp"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(327,120);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete path_dir;
}

void MainWindow::on_pushButton_clicked()
{
    selectDir();
}

void MainWindow::on_pushButton_2_clicked()
{
       exit(0);
}

void MainWindow::selectDir()
{
    QString dir = QFileDialog::getExistingDirectory(
                this,
                tr("Choose folder"),
                "C:\\",
                QFileDialog::ShowDirsOnly | QFileDialog::DontUseNativeDialog);
    if (dir != "")
    {
        path_dir = new CDir(dir);
        path_dir->getContentDir();
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setText("The directory does not select!");
        msgBox.exec();
    }
}

