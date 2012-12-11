#pragma once

#include "SteganoWidget.h"
#include <QCheckBox>

class CSteganoNonCheckedWidget :
    public CSteganoWidget
{
public:
    CSteganoNonCheckedWidget(void);
    CSteganoNonCheckedWidget(const CSteganoNonCheckedWidget&);
    virtual ~CSteganoNonCheckedWidget(void);
    static PSteganoWidget createSteganoNonCheckedWidget();
    virtual PArgsList getArgsList();
    virtual PSteganoWidget clone();
private:

};
