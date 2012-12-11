#include "SteganoBitsMethod.h"
#include <QBitArray>
#include <QRgb>
#include <QDebug>
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

void CSteganoBitsMethod::encrypt(QString ImageFilePath, QString ImageSaveFilePath, PByteArray Data, bool IsDataFilepath, PArgsList SteganoParameters)
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
    
    qDebug()<<"maskVector.size() => "<<maskVector.size();
    
    unsigned int dataLength = Data->length();
    //generacja opisu dlugosci danych - pierwszy bajt w Data będzie najbardziej znaczący
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
    qDebug()<<"data.size() => "<<data.size();
    

    unsigned int dataCounter = 0; 
    bool loopShouldFinishFlag = 0;
    for( int i = 0;i < image.height();i++)
    {
        for( int j = 0;j < image.width();j++)
        {
            QRgb pixel = image.pixel(j,i);
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
                    loopShouldFinishFlag = true;
                    qDebug()<<"(i,j) => "<<i<<","<<j;
                    break;
                }
            }
            image.setPixel(j,i,pixel);
            if( loopShouldFinishFlag )
            {
                i = image.height();
                j = image.width();
            }
        }
    }
    if(dataCounter < dataBitLength )
    {
         //blad
        qDebug()<<"ERRRRRRRRRRRORRRRRR: "<<dataCounter;
    }
    image.save(ImageSaveFilePath);
}

void CSteganoBitsMethod::decrypt(QString imageFilePath, PByteArray data, bool IsDataFilepath, PArgsList steganoParameters)
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
    //TEMP temporary
    return QString("Koczo");
}
