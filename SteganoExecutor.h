#pragma once
#include <QObject>
#include <QString>
#include "SteganoTypes.h"

class CSteganoExecutor : public QObject
{
    Q_OBJECT
public:
    explicit CSteganoExecutor( QObject *parent = 0 );
    PMethodList getSteganoMethodList();
    void encrypt(int Id,QString ImageFilepath, QString SaveFilepath, PByteArray pData, PArgsList pArgsList);
    void decrypt(int Id,QString ImageFilepath, PByteArray pData, PArgsList pArgsList);
    void makePreview(int,QString, QString, PByteArray, PArgsList);
signals:
    void previewFinished(PImage);
    void encryptFinished(bool); ///< bool: whether it succeded or not
    void decryptFinished(bool);
    void progressChanged(int);
public slots:

private:
    int m_LastMethodId;
    PSteganoMethod m_pSteganoMethod;
};
