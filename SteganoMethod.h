#pragma once
#include <QSharedPointer>
#include <QImage>
#include "SteganoTypes.h"

/**
 * @brief Allows to hide and retrieve data using image files
 *
 * The most important base class in project. Allows user to hide data in images
 * and later retrieve the data. Each class derieving from CSteganoMethod should
 * inform of desired list of parameters needed to encrypt and decrypt data.
 */
class CSteganoMethod: public QObject
{
    Q_OBJECT

public:
    /**
     * @brief CSteganoMethod default constructor
     */
    CSteganoMethod(void);

    /**
     * @brief ~CSteganoMethod destructor
     */
    virtual ~CSteganoMethod(void);

    /**
     * @brief Encryption method.
     * @param ImageFilepath filepath to image to hide data in
     * @param SaveFilepath filepath to save image with hidden data
     * @param DataFilepath data to be hidden (eventually filepath)
     * @param pArgsList argument list alternating method behaviour
     */
    virtual void encrypt(QString ImageFilepath, QString SaveFilepath, QString DataFilepath, PArgsList pArgsList) = 0;

    /**
     * @brief Decryption method.
     * @param ImageFilepath filepath to image to retrieve data from
     * @param SaveFilepath retrieved data
     * @param pArgsList argument list alternating method behaviour
     */
    virtual void decrypt(QString ImageFilepath, QString SaveFilepath, PArgsList pArgsList) = 0;

    /**
     * @brief Hides the data and returns QImage using a signal previewFinished(PImage).
     * @param ImageFilepath filepath to image to hide data in
     * @param DataFilePath data to be hidden
     * @param pArgsList argument list alternating method behaviour
     */
    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList) = 0 ;

    /**
     * @brief Proposes params of encryption.
     * @param ImageFilepath filepath to image to hide data in
     * @param ByteCount how much data is to be hidden
     * @param pArgsList argument list alternating method behaviour
     */
    virtual void makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList);
    //virtual PArgsList suggestArgs(QString ImageFilepath, int ByteCount) = 0;

    /**
     * @brief Clone pattern.
     * @return shared pointer to cloned object
     */
    virtual QSharedPointer<CSteganoMethod> clone() = 0;
    /**
     * @brief Gets a human-friendly name to help recognizing the method
     * @return method's name
     */
    virtual QString getName() = 0;

    /**
     * @return input types which method supports in QT format
     * @see <a href="http://doc.qt.digia.com/qt/qfiledialog.html#details">QT format on qt.digia.com</a>
     */
    virtual QString getSupportedTypesToEncrypt() = 0;

    /**
     * @return output types which method supports in QT format.
     * Should return an empty string if a method can output only image in input format.
     * @see <a href="http://doc.qt.digia.com/qt/qfiledialog.html#details">QT format on qt.digia.com</a>
     */
    virtual QString getSupportedTypesToDecrypt() = 0;

signals:
    /**
     * @brief Image containing a preview for an user
     */
    void previewFinished(PImage);

    /**
     * @brief Information of finishing the encryption with encryption status
     */
    void encryptFinished(bool);

    /**
     * @brief Information of finishing the decryption with decryption status
     */
    void decryptFinished(bool);

    /**
     * @brief Contains information indicating current progress single integer ranging form 0 to 100
     */
    void progressChanged(int);

    /**
     * @brief Containts arguments which can be used with the method to hide given length of data
     * @param pArgsList Proposed arguments list
     */
    void proposeFinished(PArgsList pArgsList);

    /**
     * @brief Contains error message indicating current problem; the message should be displayed to human user
     */
    void errorOccurred(QString);
};



