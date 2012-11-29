#pragma once
#include <QSharedPointer>
#include <QImage>
#include "SteganoTypes.h"

class CSteganoMethod: public QObject
{
    Q_OBJECT
public:
    CSteganoMethod(void);
    virtual ~CSteganoMethod(void);
    //! Encryption method.
    /*!
      \param filepath to image to hide data in
      \param filepath to save image with hidden data
      \param data to be hidden
      \param argument list alternating method behaviour
    */
    virtual void encrypt(QString ImageFilepath, QString SaveFilepath, PByteArray pData, PArgsList pArgsList) = 0;

    //! Decryption method.
    /*!
      \param filepath to image to retrieve data from
      \param retrieved data
      \param argument list alternating method behaviour
    */
    virtual void decrypt(QString ImageFilepath, PByteArray pData, PArgsList pArgsList) = 0;

    //! Hides the data and returns QImage using a signal previewFinished(PImage).
    /*!
      \param filepath to image to hide data in
      \param filepath to save image with hidden data
      \param data to be hidden
      \param argument list alternating method behaviour
    */
    virtual void makePreview(QString ImageFilepath, QString SaveFilepath, PByteArray pData, PArgsList pArgsList) = 0 ;

    //! Evaluates number of possible bytes to be hidden in given amount of pixels
    /*!
        \param argument list alternating method behaviour
        \param pixel count
     */
    virtual int evaluate(PArgsList,int) = 0;

    //! Evaluates number of possible bytes to be hidden in given file
    /*!
        \param argument list alternating method behaviour
        \param filepath
     */
    virtual int evaluate(PArgsList,QString) = 0;

signals:
    void previewFinished(PImage);
    void encryptFinished(void);
    void decryptFinished(void);
    void progressChanged(int);
protected:
};

