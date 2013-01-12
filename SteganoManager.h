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
    virtual ~CSteganoManager(void);
    static CSteganoManager& getInstance(void);
    PMethodList getSteganoMethodList(void);
    PSteganoMethod produceSteganoMethod(int Id);
    PSteganoWidget produceSteganoWidget(int Id);
    QString getSupportedTypesToEncrypt(int Id);
    QString getSupportedTypesToDecrypt(int Id);
    int registerSteganoMethod(PSteganoMethod, PSteganoWidget);
    static const int c_InvalidIdNumber = -1;
private:
    QVector< std::pair<PSteganoMethod, PSteganoWidget> > m_steganoProducts;
    Q_DISABLE_COPY(CSteganoManager)
    CSteganoManager(void);

    //private data
    static int m_counter;
};

