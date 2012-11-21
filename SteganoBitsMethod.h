#pragma once
#include "SteganoMethod.h"

class CSteganoBitsMethod :
    public CSteganoMethod
{
    Q_OBJECT
public:
    CSteganoBitsMethod(void);
    virtual ~CSteganoBitsMethod(void);
    virtual void encrypt(QString, QString, PByteArray, PArgsList);
    virtual void decrypt(QString, PByteArray, PArgsList);
    virtual void makePreview(QString, QString, PByteArray, PArgsList);
    virtual int evaluate(PArgsList,int);
    virtual int evaluate(PArgsList,QString);
};

