#pragma once

#include "SteganoTypes.h"
#include "SteganoMethod.h"
/**
 * @brief A SteganoMethod which hides data in bits of pixel
 *
 * It's argument list should contain one integer (32bit) with
 * bits set in QRgb format (only last 24bits are significant).
 *
 * @see <a href="http://doc.qt.digia.com/qt/qcolor.html">QRgb</a>
 */
class CSteganoBitsMethod :
    public CSteganoMethod
{
    Q_OBJECT
public:
    CSteganoBitsMethod(void);
    CSteganoBitsMethod(const CSteganoBitsMethod&);
    virtual ~CSteganoBitsMethod(void);
    /**
     * @brief Creates instance of SteganoBitsMethod
     * @return Shared pointer of SteganoBitsMethod instance
     */
    static QSharedPointer<CSteganoMethod> createSteganoBitsMethod();
    virtual void encrypt(QString, QString, QString, PArgsList);
    virtual void decrypt(QString, QString, PArgsList);
    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList);
    virtual void makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList);
    virtual QSharedPointer<CSteganoMethod> clone();
    virtual QString getName();
    virtual QString getSupportedTypesToEncrypt();
    virtual QString getSupportedTypesToDecrypt();
private:
    PImage encryptWithPreview(QString ImageFilePath, QString DataFilePath, PArgsList SteganoParameters);
    inline void modifyPixel(QRgb& pixel, QVector<unsigned int> mask, QBitArray data);
    PVectorInt generateEncryptMask(unsigned int maskPixel);
    PBitArray prepareEncryptData(QString DataFilePath);
    unsigned int getDataLength(PImage pimage,PVectorInt pmaskVector );
};

