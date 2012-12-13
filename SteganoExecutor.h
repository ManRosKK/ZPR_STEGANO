#pragma once
#include <QObject>
#include <QString>
#include "SteganoTypes.h"
#include <cstdio>

class CSteganoExecutor : public QObject
{
    Q_OBJECT
public:
    explicit CSteganoExecutor( QObject *parent = 0 );
    PMethodList getSteganoMethodList();
    void encryptFile(int Id,QString ImageFilepath, QString SaveFilepath, QString DataFilepath, PArgsList pArgsList);
    void encryptText(int Id,QString ImageFilepath, QString SaveFilepath, QString Data, PArgsList pArgsList);
    void decryptToFile(int Id,QString ImageFilepath, QString DataFilepath, PArgsList pArgsList);
    void decryptToText(int Id,QString ImageFilepath, PArgsList pArgsList);
    void makePreview(int Id, QString ImageFilepath, PByteArray pData, PArgsList pArgsList);
signals:
    void previewFinished(PImage);
    void encryptFinished(bool); ///< bool: whether it succeded or not
    void decryptFinished(bool);
    void decryptFinished(bool,QString);
    void progressChanged(int);
public slots:

private:
    int m_LastMethodId;
    PSteganoMethod m_pSteganoMethod;
    char TempFilepath[L_tmpnam];
};
