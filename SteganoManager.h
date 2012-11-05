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
    void registerSteganoMethod(createFunc,QWidget,QString);
private:
    CSteganoManager(void);
};

