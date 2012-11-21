#pragma once
#include <QObject>
class COperationResult :
    public QObject
{
    Q_OBJECT
public:
    COperationResult(void);
    virtual ~COperationResult(void);
};

