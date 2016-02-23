#ifndef CTEXTLINE_H
#define CTEXTLINE_H

#include "CUI.h"
#include "ui_CUI.h"

class CTextLine: public Ui::CUI
{
                Q_OBJECT
public:
    CTextLine();
    void setText(QString text);

private:
    Ui::CUI *p;
};

#endif // CTEXTLINE_H
