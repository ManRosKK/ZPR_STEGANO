#pragma once
#include "SteganoMethod.h"

class CSteganoNonCheckedMethod : public CSteganoMethod
{
public:
    CSteganoNonCheckedMethod(void);
    CSteganoNonCheckedMethod(const CSteganoNonCheckedMethod&);
    virtual ~CSteganoNonCheckedMethod(void);
    static QSharedPointer<CSteganoMethod> createSteganoNonCheckedMethod();

    virtual void encrypt(QString, QString, QString, PArgsList);
    virtual void decrypt(QString, QString, PArgsList);
    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList);
    virtual QSharedPointer<CSteganoMethod> clone();
    virtual QString getName();
    virtual QString getSupportedTypesToEncrypt();
    virtual QString getSupportedTypesToDecrypt();
private:
    void findEndOfImage(std::fstream& fileone);
    int findHiddenData(std::fstream& fileone);

    static const unsigned int c_MaxExtensionLength = 16;
    static const int c_BufferSize = 1000000;
    char buffer[c_BufferSize];
    static const int c_FooterLength = 8;
    static const char *footer;

};


