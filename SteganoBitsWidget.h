#pragma once
#include "SteganoWidget.h"
#include <QCheckBox>

/**
 * @brief Widget for CSteganoBitsMethod class
 */
class CSteganoBitsWidget :
    public CSteganoWidget
{
public:
    CSteganoBitsWidget(void);
    CSteganoBitsWidget(const CSteganoBitsWidget&);
    virtual ~CSteganoBitsWidget(void);
    /**
     * @brief Creates instance of SteganoBitsWidget
     * @return Shared pointer of SteganoBitsWidget instance
     */
    static QSharedPointer<CSteganoWidget> createSteganoBitsWidget();
    virtual PArgsList getArgsList();
    virtual void setArgsList(PArgsList);
    virtual QSharedPointer<CSteganoWidget> clone();
    virtual bool isPropositionsAllowed();
private:
    void configureUI();
    static const int c_BitsDepth = 24;
    QCheckBox* m_CheckBox[c_BitsDepth];
};

