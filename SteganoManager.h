#pragma once
#include <QSharedPointer>
#include <QImage>
#include <QWidget>
#include "SteganoTypes.h"
#include "SteganoMethod.h"
#include "SteganoWidget.h"
class CSteganoManager: public QObject
{
	Q_OBJECT
public:
    typedef QSharedPointer<CSteganoMethod> (*PCreateMethodFunc)(void);
    typedef QSharedPointer<CSteganoWidget> (*PCreateWidgetFunc)(void);
	virtual ~CSteganoManager(void);
    static CSteganoManager& getInstance();
    PMethodList getSteganoMethodList();
    PSteganoMethod produceSteganoMethod(int Id);
    PSteganoWidget produceSteganoWidget(int Id);
    int registerSteganoMethod(PCreateMethodFunc, PCreateWidgetFunc, QString);
private:
    Q_DISABLE_COPY(CSteganoManager)
    CSteganoManager(void);

    //private data
    static int m_counter;
};

