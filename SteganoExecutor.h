#pragma once
#include <QObject>

typedef QSharedPointer<CSteganoMethod> PSteganoMethod;

class CSteganoExecutor : public QObject
{
    Q_OBJECT
public:
    explicit CSteganoExecutor(QObject *parent = 0);
    
signals:
    
public slots:
    
private:
    int m_LastMethodId;
    PSteganoMethod m_pSteganoMethod;
};
