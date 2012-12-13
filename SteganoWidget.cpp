#include "SteganoWidget.h"

CSteganoWidget::CSteganoWidget(QWidget *parent) :
    QWidget(parent)
{
}

CSteganoWidget::CSteganoWidget(const CSteganoWidget&)
{

}

bool CSteganoWidget::allowPropositions()
{
    return false;
}
