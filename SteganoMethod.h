#pragma once
#include <QSharedPointer>
#include <QImage>

typedef QSharedPointer<QByteArray> PByteArray;
typedef QList<QVariant> ArgsList;
typedef QSharedPointer<ArgsList> PArgsList;
typedef QSharedPointer<QImage> PImage;

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
    virtual void encrypt(QString, QString, PByteArray, PArgsList) = 0;
    //! Decryption method.
    /*!
      \param filepath to image to retrieve data from
      \param retrieved data
      \param argument list alternating method behaviour
    */
    virtual void decrypt(QString, PByteArray, PArgsList) = 0;
    virtual void makePreview(QString, QString, PByteArray, PArgsList) = 0;
    //! Evaluates number of possible bytes to be hidden in given amount of pixels
    /*!
        \param argument list alternating method behaviour
        \param pixel count
     */
    virtual int evaluate(PArgsList,int);
    //! Evaluates number of possible bytes to be hidden in given file
    /*!
        \param argument list alternating method behaviour
        \param filepath
     */
    virtual int evaluate(PArgsList,QString);
signals:
    void previewFinished(PImage);
    void encryptFinished(void);
    void decryptFinished(void);
    void progressChanged(int);
};

