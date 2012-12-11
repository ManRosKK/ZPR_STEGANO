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
    void encrypt(int Id,QString ImageFilepath, QString SaveFilepath, PByteArray pData, bool IsDataFilepath, PArgsList pArgsList);
    void decrypt(int Id,QString ImageFilepath, PByteArray pData, bool IsDataFilepath, PArgsList pArgsList);
    void makePreview(int Id, QString ImageFilepath, PByteArray pData, PArgsList pArgsList);
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
