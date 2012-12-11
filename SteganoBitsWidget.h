#pragma once
#include "SteganoWidget.h"
#include <QCheckBox>

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
    void configureUI();
private:
    static const int c_BitsDepth = 24;
    QCheckBox* m_CheckBox[c_BitsDepth];
};

