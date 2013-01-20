#pragma once
#include "SteganoMethod.h"

/**
 * @brief A SteganoMethod which hides data after real content of a file.
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
    /**
     * @brief Finds real end of image for all suported filetypes.
     *
     * Sets read iterator of file to a place after the end of image.
     * @param fileone file to find end of image in
     */
    void findEndOfImage(std::fstream& fileone);
    /**
     * @brief Finds hidden data of image for all suported filetypes.
     *
     * Sets read iterator of file to a place where hidden data starts.
     * @param fileone file to find hidden data in
     * @return hidden data length (<=0 if no data is hidden)
     */
    int findHiddenData(std::fstream& fileone);

    static const int c_BufferSize = 1000000;
    char buffer[c_BufferSize];
    static const int c_FooterLength = 8;
    static const char *footer;

};


