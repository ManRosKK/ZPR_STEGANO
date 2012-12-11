#include "SteganoNonCheckedWidget.h"

#include <QLayout>
#include <QLabel>
#include <QBitArray>
#include <QDebug>
#include <QCheckBox>

CSteganoNonCheckedWidget::CSteganoNonCheckedWidget(void)
{

}

CSteganoNonCheckedWidget::CSteganoNonCheckedWidget(const CSteganoNonCheckedWidget&)
{

}

CSteganoNonCheckedWidget::~CSteganoNonCheckedWidget(void)
{
}

PSteganoWidget CSteganoNonCheckedWidget::createSteganoNonCheckedWidget()
{
    return PSteganoWidget(new CSteganoNonCheckedWidget());
}

PArgsList CSteganoNonCheckedWidget::getArgsList()
{
    PArgsList pArgsList(new ArgsList());
    return pArgsList;
}

PSteganoWidget CSteganoNonCheckedWidget::clone()
{
    return PSteganoWidget(new CSteganoNonCheckedWidget(*this));
}

