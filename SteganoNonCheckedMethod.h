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
    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList);
    virtual int evaluate(PArgsList,int);
    virtual int evaluate(PArgsList,QString);
    virtual PSteganoMethod clone();
    virtual QString getName();
private:
    void findEndOfImage(std::fstream& fileone);
    int findHiddenData(std::fstream& fileone);

    static const unsigned int c_MaxExtensionLength = 16;
    static const int c_BufferSize = 1000000;
    char buffer[c_BufferSize];
    static const int c_FooterLength = 5;
    static const char *footer;

};


