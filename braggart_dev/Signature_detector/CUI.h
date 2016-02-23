#ifndef CUI_H
#define CUI_H

#include <QMainWindow>
#include <thread>
#include <QString>
#include "Scanner.h"

namespace Ui {
class CUI;
}

class Scanner;

class CUI : public QMainWindow
{
    Q_OBJECT

public:
    CUI(QWidget *parent = 0);
    void setLabelText(QString nameFile);
    void getRefScanner(Scanner *refScanner);
    ~CUI();

signals:
    void signalToPB();

private slots:
    void on_buttonChangeDir_clicked();
    void on_buttonStart_clicked();
    void setValueProgressBar();
    void on_buttonClose_clicked();

protected:
    Ui::CUI *ui;

private:
    Scanner *pScanner;
};

#endif // CUI_H
