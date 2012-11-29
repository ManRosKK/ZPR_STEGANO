#include "SteganoBitsMethod.h"


CSteganoBitsMethod::CSteganoBitsMethod(void)
{

}


CSteganoBitsMethod::~CSteganoBitsMethod(void)
{

}

void CSteganoBitsMethod::encrypt(QString imageFilePath, QString imageSaveFilePath, PByteArray data, PArgsList steganoParameters)
{
    QImage image;
    image.load( imageFilePath );
    image.save( imageSaveFilePath );
}

void CSteganoBitsMethod::decrypt(QString imageFilePath, PByteArray data, PArgsList steganoParameters)
{

}

void CSteganoBitsMethod::makePreview(QString imageFilePath, QString imageSaveFilePath, PByteArray data, PArgsList steganoParameters)
{

}

int CSteganoBitsMethod::evaluate(PArgsList,int)
{
    return 0;
}

int CSteganoBitsMethod::evaluate(PArgsList,QString)
{
    return 0;
}
