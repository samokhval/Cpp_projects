#include "CTextLine.h"

CTextLine::CTextLine()
{
}

void CTextLine::setText(QString text)
{
    //p->setLabelText(text);
    Ui::CUI::label_2->setText(text);
}
