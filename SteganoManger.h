#pragma once
#include <qobject.h>
#include <QSharedPointer>
#include <QImage>
#include "SteganoMethod.h"
;
class CSteganoManger: public QObject
{
	Q_OBJECT
public:
    typedef QSharedPointer<CSteganoMethod> (*createFunc)(void);
	CSteganoManger(void);
	virtual ~CSteganoManger(void);
    QSharedPointer<CSteganoMethod> produceSteganoMethod(int id);
	void registerSteganoMethod(createFunc);
};

