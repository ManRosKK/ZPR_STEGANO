#pragma once
#include <QObject>
#include <QSharedPointer>
#include "SteganoMethod.h"

typedef QSharedPointer<CSteganoMethod> PSteganoMethod;

class CSteganoExecutor : public QObject
{
    Q_OBJECT
public:
    explicit CSteganoExecutor(QObject *parent = 0);
    void encrypt(int,QString, QString, PByteArray, PArgsList);
    void decrypt(int,QString, PByteArray, PArgsList);
    void makePreview(int,QString, QString, PByteArray, PArgsList);
signals:
    void previewFinished(PImage);
    void encryptFinished(void);
    void decryptFinished(void);
    void progressChanged(int);
public slots:
    
private:
    int m_LastMethodId;
    PSteganoMethod m_pSteganoMethod;
};
