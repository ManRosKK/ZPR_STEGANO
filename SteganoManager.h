#pragma once
#include <QSharedPointer>
#include <QImage>
#include <QWidget>
#include "SteganoMethod.h"
#include "SteganoWidget.h"

class CSteganoManager: public QObject
{
	Q_OBJECT
public:
    typedef QSharedPointer<CSteganoMethod> (*createMethodFunc)(void);
    typedef QSharedPointer<CSteganoWidget> (*createWidgetFunc)(void);
	virtual ~CSteganoManager(void);
    QSharedPointer<CSteganoMethod> produceSteganoMethod(int id);
    QSharedPointer<CSteganoWidget> produceSteganoWidget(int id);
    void registerSteganoMethod(createMethodFunc, createWidgetFunc, QString);
    static QSharedPointer<CSteganoManager> getInstance();
private:
    static int m_counter;
    CSteganoManager(void);
};

