#pragma once

#include "SteganoWidget.h"
#include <QCheckBox>

/**
 * @brief Widget for CSteganoNonCheckedMethod class
 */
class CSteganoNonCheckedWidget :
    public CSteganoWidget
{
public:
    CSteganoNonCheckedWidget(void);
    CSteganoNonCheckedWidget(const CSteganoNonCheckedWidget&);
    virtual ~CSteganoNonCheckedWidget(void);
    static QSharedPointer<CSteganoWidget> createSteganoNonCheckedWidget();
    virtual PArgsList getArgsList();
    virtual void setArgsList(PArgsList);
    virtual QSharedPointer<CSteganoWidget> clone();
private:

};
