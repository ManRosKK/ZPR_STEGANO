#include "SteganoBitsMethod.h"
#include <QBitArray>
#include <QRgb>
CSteganoBitsMethod::CSteganoBitsMethod(void)
{

}

CSteganoBitsMethod::CSteganoBitsMethod(const CSteganoBitsMethod&)
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
    unsigned int maskPixel = SteganoParameters->takeAt(0).toUInt();
    unsigned int shifter = 0x1;
    //genrator maski
    QVector<unsigned int> maskVector;
    while( shifter != 0x01000000 )  
    {
        if( shifter & maskPixel)
        {
            maskVector.push_back(shifter);
        }
        shifter<<=1;
    }
    
    
    
    unsigned int dataLength = Data->length();
    //generacja zpisu dlugosci danych
    unsigned int mask = 0x000000FF;
    for(int k = 0;k<4;k++)
    {
        Data->push_front( static_cast<char>( ( dataLength>>(k*8) ) & mask ) );
    }
    
    dataLength = Data->length();
    unsigned int dataBitLength = dataLength*8;
    //generator danych
    QBitArray data(dataBitLength);
    for(int i = 0;i < Data->size();++i)
        for(int j=0;j<8;j++)
            data.setBit(i*8+j,Data->at(i)&(1<<j));

    

    unsigned int dataCounter = 0; 
    for( int i = 0;i < image.height();i++)
    {
        for( int j = 0;j < image.width();j++)
        {
            QRgb pixel = image.pixel(i,j);
            for(int k = 0;k < maskVector.size();k++)
            {
                if(data.testBit(dataCounter++) )
                {
                    pixel |=(maskVector[k]); // set bit in pixel on proper position
                }
                else
                {
                    pixel &=~(maskVector[k]);
                }
                if(dataCounter >= dataBitLength) //coming out of loop
                {
                    k = maskVector.size();
                    i = image.height();
                    j = image.width();
                }
            }
            image.setPixel(i,j,pixel);
        }
    }
    if(dataCounter < dataBitLength )
    {
         //blad
    }
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


inline void CSteganoBitsMethod::modifyPixel(QRgb& pixel, QVector<unsigned int> mask, QBitArray data)
{
    
}

PSteganoMethod CSteganoBitsMethod::clone()
{
    return PSteganoMethod(new CSteganoBitsMethod(*this));
}

QString CSteganoBitsMethod::getName()
{
    //temporary
    return QString("Koczo");
}
