#include "SteganoBitsMethod.h"
#include <QBitArray>
CSteganoBitsMethod::CSteganoBitsMethod(void)
{

}

CSteganoBitsMethod::~CSteganoBitsMethod(void)
{

}

PSteganoMethod CSteganoBitsMethod::createSteganoBitsMethod()
{
    return PSteganoMethod(new CSteganoBitsMethod());
}

void CSteganoBitsMethod::encrypt(QString ImageFilePath, QString ImageSaveFilePath, PByteArray Data, PArgsList SteganoParameters)
{
    QImage image;
    image.load(ImageFilePath);
    QBitArray Array = SteganoParameters->takeAt(0).toBitArray();
    image.save(ImageSaveFilePath);
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
