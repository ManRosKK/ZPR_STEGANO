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
    void proposeWithText(int Id,QString ImageFilepath, QString SaveFilepath, QString Data, PArgsList pArgsList);
    void proposeWithFile(int Id,QString ImageFilepath, QString SaveFilepath, QString DataFilepath, PArgsList pArgsList);
    void makePreviewWithFile(int Id,QString ImageFilepath, QString DataFilepath, PArgsList pArgsList);
    void makePreviewWithText(int Id,QString ImageFilepath, QString data, PArgsList pArgsList);


    void makePreview(int Id, QString ImageFilepath, PByteArray pData, PArgsList pArgsList);
    void proposeParams(int Id,QString ImageFilepath, QString SaveFilepath, QString DataFilepath, PArgsList pArgsList);
signals:
    void proposed(PArgsList);
    void previewFinished(PImage);
    void encryptFinished(bool); ///< bool: whether it succeded or not
    void decryptFinished(bool);
    void decryptFinished(bool,QString);
    void progressChanged(int);
public slots:

private:
    void connectSignalsAndSlotsToMethod();
    int m_LastMethodId;
    PSteganoMethod m_pSteganoMethod;
    char TempFilepath[L_tmpnam];
    bool m_DecryptToFile;
private slots:
    void onEncryptFinished(bool);
    void onDecryptFinished(bool);
    void onProposed(PArgsList pArgsList);
};
