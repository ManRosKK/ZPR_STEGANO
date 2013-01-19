#pragma once
#include <QObject>
#include <QString>
#include "SteganoTypes.h"
#include <cstdio>
#include "SteganoWidgetMethodPointers.h"

/**
 * @brief The executor class.
 *
 * Used to launch method's encryption and decryption functions asynchronously
 * while keeping UI responsive. Proxies access to CSteganoWidgets allowing
 * user to provide data in text or file format.
 * Forwards signals from currently executed method by emitting own signals.
 * Uses CSteganoManager singleton to create CSteganoMethods.
 */
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
    void proposeWithText(int Id,QString ImageFilepath, QString Data, PArgsList pArgsList);
    void proposeWithFile(int Id,QString ImageFilepath, QString DataFilepath, PArgsList pArgsList);
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
    void errorOccurred(QString);
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
