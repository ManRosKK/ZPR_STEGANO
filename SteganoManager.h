#pragma once
#include <qobject.h>
#include <QSharedPointer>
#include <QImage>
#include <qwidget.h>
#include "SteganoMethod.h"
;
class CSteganoManager: public QObject
{
	Q_OBJECT
public:
    typedef QSharedPointer<CSteganoMethod> (*createFunc)(void);
	virtual ~CSteganoManager(void);
    QSharedPointer<CSteganoMethod> produceSteganoMethod(int id);
    QSharedPointer<CSteganoWidget> produceSteganoWidget(int id);
    // powinno byc jeszcze get list ale to d³uga lista qsha<qlistt<....
    void registerSteganoMethod(createFunc, CSteganoWidget, QString);
    static QSharedPointer<CSteganoManager> getInstance();
private:
    static int m_counter = 0;
    CSteganoManager(void);
};

