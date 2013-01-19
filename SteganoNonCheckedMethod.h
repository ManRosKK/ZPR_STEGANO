#pragma once
#include "SteganoMethod.h"

/**
 * @brief A SteganoMethod which hides data after real content end of a file.
 *
 * It takes an empty list of arguments.
 */
class CSteganoNonCheckedMethod : public CSteganoMethod
{
public:
    CSteganoNonCheckedMethod(void);
    CSteganoNonCheckedMethod(const CSteganoNonCheckedMethod&);
    virtual ~CSteganoNonCheckedMethod(void);
    /**
     * @brief Creates instance of SteganoNonCheckedMethod
     * @return Shared pointer to SteganoNonCheckedMethod instance
     */
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


