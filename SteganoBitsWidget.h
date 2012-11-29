#pragma once
#include "steganowidget.h"
class CSteganoBitsWidget :
    public CSteganoWidget
{
public:
    CSteganoBitsWidget(void);
    virtual ~CSteganoBitsWidget(void);
    static PSteganoWidget createSteganoBitsWidget();

    virtual PArgsList getArgsList();
};

