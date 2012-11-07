#pragma once
#include <QSharedPointer>
#include <QImage>
#include "SteganoTypes.h"

class CSteganoMethod: public QObject
{
    Q_OBJECT
public:
    CSteganoMethod(void);
    //! Encryption method.
    /*!
      \param filepath to image to hide data in
      \param filepath to save image with hidden data
      \param data to be hidden
      \param argument list alternating method behaviour
    */
    virtual void encrypt(QString, QString, PByteArray, PArgsList) = 0;
    //! Decryption method.
    /*!
      \param filepath to image to retrieve data from
      \param retrieved data
      \param argument list alternating method behaviour
    */
    virtual void decrypt(QString, PByteArray, PArgsList) = 0;
    virtual void makePreview(QString, QString, PByteArray, PArgsList) = 0;
    virtual ~CSteganoMethod(void);
signals:
    void previewFinished(PImage);
    void encryptFinished(void);
    void decryptFinished(void);
    void progressChanged(int);
};

