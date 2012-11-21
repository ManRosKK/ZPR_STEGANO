#pragma once
#include <QObject>
#include <QString>
#include "SteganoTypes.h"
#include "OperationResult.h"
class CSteganoExecutor : public QObject
{
    Q_OBJECT
public:
    explicit CSteganoExecutor( QObject *parent = 0 );
    PMethodList getSteganoMethodList();
     
signals:
    void OperationFinished( POperationResult result );
public slots:
    void setImageFilePath( QString path );
    void setSteganoParam( int steganoMethod, PArgsList args );
};
