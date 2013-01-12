#pragma once

#include "SteganoTypes.h"
#include "SteganoMethod.h"
class CSteganoBitsMethod :
    public CSteganoMethod
{
    Q_OBJECT
public:
    CSteganoBitsMethod(void);
    CSteganoBitsMethod(const CSteganoBitsMethod&);
    virtual ~CSteganoBitsMethod(void);
    static PSteganoMethod createSteganoBitsMethod();

    virtual void encrypt(QString, QString, QString, PArgsList);
    virtual void decrypt(QString, QString, PArgsList);
    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList);
    virtual void makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList);
    virtual int evaluate(PArgsList,int);
    virtual int evaluate(PArgsList,QString);
    virtual PSteganoMethod clone();
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

