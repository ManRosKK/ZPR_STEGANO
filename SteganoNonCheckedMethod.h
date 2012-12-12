#pragma once
#include "SteganoMethod.h"

class CSteganoNonCheckedMethod : public CSteganoMethod
{
public:
    CSteganoNonCheckedMethod(void);
    CSteganoNonCheckedMethod(const CSteganoNonCheckedMethod&);
    virtual ~CSteganoNonCheckedMethod(void);
    static PSteganoMethod createSteganoNonCheckedMethod();

    virtual void encrypt(QString, QString, QString, PArgsList);
    virtual void decrypt(QString, QString, PArgsList);
    virtual void makePreview(QString, QString, PByteArray, PArgsList);
    virtual int evaluate(PArgsList,int);
    virtual int evaluate(PArgsList,QString);
    virtual PSteganoMethod clone();
    virtual QString getName();
private:
    static const unsigned int c_MaxExtensionLength = 16;
};


