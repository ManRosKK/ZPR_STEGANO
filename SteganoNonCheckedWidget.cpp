#include "SteganoNonCheckedWidget.h"

#include <QLayout>
#include <QLabel>
#include <QBitArray>
#include <QDebug>
#include <QCheckBox>

CSteganoNonCheckedWidget::CSteganoNonCheckedWidget(void)
{

}

CSteganoNonCheckedWidget::CSteganoNonCheckedWidget(const CSteganoNonCheckedWidget& sncw):
    CSteganoWidget(sncw.parentWidget())
{

}

CSteganoNonCheckedWidget::~CSteganoNonCheckedWidget(void)
{
}

QSharedPointer<CSteganoWidget> CSteganoNonCheckedWidget::createSteganoNonCheckedWidget()
{
    return QSharedPointer<CSteganoWidget>(new CSteganoNonCheckedWidget());
}

PArgsList CSteganoNonCheckedWidget::getArgsList()
{
    PArgsList pArgsList(new ArgsList());
    return pArgsList;
}

void CSteganoNonCheckedWidget::setArgsList(PArgsList)
{
    //empty body
}

QSharedPointer<CSteganoWidget> CSteganoNonCheckedWidget::clone()
{
    return QSharedPointer<CSteganoWidget>(new CSteganoNonCheckedWidget(*this));
}

