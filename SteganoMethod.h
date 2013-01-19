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
      \param data to be hidden (eventually filepath)
      \param argument list alternating method behaviour
    */
    virtual void encrypt(QString ImageFilepath, QString SaveFilepath, QString DataFilepath, PArgsList pArgsList) = 0;

    //! Decryption method.
    /*!
      \param filepath to image to retrieve data from
      \param retrieved data
      \param argument list alternating method behaviour
    */
    virtual void decrypt(QString ImageFilepath, QString SaveFilepath, PArgsList pArgsList) = 0;

    //! Hides the data and returns QImage using a signal previewFinished(PImage).
    /*!
      \param filepath to image to hide data in
      \param filepath to save image with hidden data
      \param data to be hidden
      \param argument list alternating method behaviour
    */
    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList) = 0 ;

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

    //! Propose params of encryption.
    /*!
      \param filepath to image to hide data in
      \param filepath to save image with hidden data
      \param data to be hidden
      \param argument list alternating method behaviour
    */
    virtual void makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList);
    //virtual PArgsList suggestArgs(QString ImageFilepath, int ByteCount) = 0;

    virtual PSteganoMethod clone() = 0;
    virtual QString getName() = 0;
    virtual QString getSupportedTypesToEncrypt() = 0;
    virtual QString getSupportedTypesToDecrypt() = 0;

signals:
    void previewFinished(PImage);
    void encryptFinished(bool);
    void decryptFinished(bool);
    void progressChanged(int);
    void proposeFinished(PArgsList pArgsList);
    void errorOccurred(QString);
protected:
};



