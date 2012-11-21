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

    //! Decryption method.
    /*!
      \param filepath to image to retrieve data from
      \param retrieved data
      \param argument list alternating method behaviour
    */
    virtual void decrypt(QString, PByteArray, PArgsList);
    
    virtual void makePreview(QString, QString, PByteArray, PArgsList);
};

