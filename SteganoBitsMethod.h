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
    virtual void makePreview(QString, QString, PByteArray, PArgsList);
    virtual int evaluate(PArgsList,int);
    virtual int evaluate(PArgsList,QString);
    virtual PSteganoMethod clone();
    virtual QString getName();
private:
    inline void modifyPixel(QRgb& pixel, QVector<unsigned int> mask, QBitArray data);
    PVectorInt generateEncryptMask(unsigned int maskPixel);
    PBitArray prepareEncryptData(QString DataFilePath);
    unsigned int getDataLength(PImage pimage,PVectorInt pmaskVector );
};

