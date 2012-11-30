#pragma once
#include "steganowidget.h"
class CSteganoBitsWidget :
    public CSteganoWidget
{
public:
    CSteganoBitsWidget(void);
    CSteganoBitsWidget(const CSteganoBitsWidget&);
    virtual ~CSteganoBitsWidget(void);
    static PSteganoWidget createSteganoBitsWidget();
    virtual PArgsList getArgsList();
    virtual PSteganoWidget clone();
};

