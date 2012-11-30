#pragma once
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

    virtual void encrypt(QString, QString, PByteArray, PArgsList);
    virtual void decrypt(QString, PByteArray, PArgsList);
    virtual void makePreview(QString, QString, PByteArray, PArgsList);
    virtual int evaluate(PArgsList,int);
    virtual int evaluate(PArgsList,QString);
    virtual PSteganoMethod clone();
    virtual QString getName();
private:
    inline void modifyPixel(QRgb& pixel, QVector<unsigned int> mask, QBitArray data);
};

