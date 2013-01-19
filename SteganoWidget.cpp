#include "SteganoWidget.h"

CSteganoWidget::CSteganoWidget(QWidget *parent) :
    QWidget(parent)
{
}

CSteganoWidget::CSteganoWidget(const CSteganoWidget& sw):
    QWidget(sw.parentWidget())
{

}

bool CSteganoWidget::isPropositionsAllowed()
{
    return false;
}
