
#include "SteganoTypes.h"
#include "SteganoBitsMethod.h"
#include <QBitArray>
#include <QRgb>
#include <QDebug>
#include <QFile>
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
PVectorInt CSteganoBitsMethod::generateEncryptMask(unsigned int maskPixel)
{
    unsigned int shifter = 0x1;
    PVectorInt pmaskVector(new QVector<unsigned int>());
    //mask generator
    while( shifter != 0x01000000 )  
    {
        if( shifter & maskPixel)
        {
            pmaskVector->push_back(shifter);
        }
        shifter<<=1;
    }
    return pmaskVector;
}
PBitArray CSteganoBitsMethod::prepareEncryptData(QString DataFilePath)
{
    //data length generation - 1 byte in stream is MSB 
    QFile file( DataFilePath );
    
    if (!file.open(QIODevice::ReadOnly))
         ;//TODO nie powinno byc bugow

    QByteArray  Data(file.readAll());
    

    unsigned int dataLength = Data.length(); //data length
    qDebug()<<"dlugosc danych: "<<dataLength;
    unsigned int mask = 0x000000FF;
    for(int k = 3; k>=0; k--)
    {
        Data.push_front( static_cast<char>( ( dataLength>>(k*8) ) & mask ) );
    }
    
    dataLength = Data.length(); //data length + sizeof(data length)
    unsigned int dataBitLength = dataLength*8;
    //generator danych
    PBitArray pdata(new QBitArray(dataBitLength));
    for(int i = 0;i < Data.size();++i)
        for(int j=0;j<8;j++)
            pdata->setBit(i*8+j,Data.at(i)&(1<<j));
    qDebug()<<"data.size() => "<<pdata->size();
    return pdata;
}
void CSteganoBitsMethod::encrypt(QString ImageFilePath, QString ImageSaveFilePath, QString DataFilePath, PArgsList SteganoParameters)
{
    unsigned int dataBitLength;
    QImage image;
    image.load(ImageFilePath);
    if(image.width() < 4)
        ;//TODO

    unsigned int maskPixel = SteganoParameters->takeAt(0).toUInt();
    
    PVectorInt pmaskVector = generateEncryptMask(maskPixel); //generating help mask for encrypting
    qDebug()<<"maskVector.size() => "<<pmaskVector->size();
    
    
    PBitArray pdata = prepareEncryptData(DataFilePath);
    dataBitLength = pdata->size();
    

    unsigned int dataCounter = 0; 
    bool loopShouldFinishFlag = 0;
    for( int i = 0;i < image.height();i++)
    {
        for( int j = 0;j < image.width();j++)
        {
            QRgb pixel = image.pixel(j,i);
            for(int k = 0;k < pmaskVector->size();k++)
            {
                if(pdata->testBit(dataCounter++) )
                {//1
                    //qDebug()<<"wpisano: 1"; 
                    pixel |=((*pmaskVector)[k]); // set bit in pixel on proper position
                }
                else
                {//0
                    //qDebug()<<"wpisano: 0";
                    pixel &=~((*pmaskVector)[k]);
                }
                if(dataCounter >= dataBitLength) //coming out of loop
                {
                    loopShouldFinishFlag = true;
                    qDebug()<<"(i,j) => "<<i<<","<<j;
                    break;
                }
            }
            image.setPixel(j,i,pixel);
            if( loopShouldFinishFlag ) //if we got the end of Data length
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
unsigned int CSteganoBitsMethod::getDataLength(PImage pimage,PVectorInt pmaskVector)
{
    unsigned int length = 0;
    unsigned int bitLength = 4*8;
    int bitCounter = 0;
    
    qDebug()<<"mask size: "<<pmaskVector->size();
    for( int i = 0;i < pimage->height();i++)
    {
        for( int j = 0;j < pimage->width();j++)
        {
            QRgb pixel = pimage->pixel(j,i);
            for(int k = 0;k < pmaskVector->size();k++)
            {
                
                if( pixel & (*pmaskVector)[k] )
                {
                    //qDebug()<<"wstawiam: 1";
                    length |= (1<<bitCounter);
                }else
                {
                    //qDebug()<<"wstawiam: 0";
                    length &= ~(1<<bitCounter);
                }
                bitCounter++;
            }
            if( bitCounter >= bitLength )
            {
                length &= 0x00FFFFFF;
                qDebug()<<"Data length: "<<length;
                return length;
            }
            
        }
    }
    return 0;

}

void CSteganoBitsMethod::decrypt(QString ImageFilePath, QString DataFilepath, PArgsList SteganoParameters)
{
    PByteArray Data( new QByteArray() );

    unsigned int dataBitLength;
    PImage pimage(new QImage);
    pimage->load(ImageFilePath);
    unsigned int maskPixel = SteganoParameters->takeAt(0).toUInt();
    
    PVectorInt pmaskVector = generateEncryptMask(maskPixel); //generating help mask for encrypting
    
    
    //odczyt dlugosci danych
    int length = getDataLength( pimage, pmaskVector);
    
    QFile file(DataFilepath);
    if (!file.open(QIODevice::WriteOnly))
         ;//TODO nie powinno byc bugow

    unsigned short shifter = 0x0001;
    unsigned short carriageReturn = 0x0100;
    char byte = 0;
    unsigned int dataCounter = 0; 
    bool loopShouldFinishFlag = 0;

    for( int i = 0;i < pimage->height();i++)
    {
        for( int j = 0;j < pimage->width();j++)
        {
            QRgb pixel = pimage->pixel(j,i);
            for(int k = 0;k < pmaskVector->size();k++)
            {
                if( pixel & (*pmaskVector)[k] )
                {
                    //qDebug()<<"wstawiam: 1";
                    byte |= (shifter);
                }else
                {
                    //qDebug()<<"wstawiam: 0";
                    byte &= ~(shifter);
                }
                shifter<<=1;
                
                if(shifter == carriageReturn)
                {
                    shifter = 0x0001;

                    if(dataCounter++>=4)
                    {
                        file.write(&byte,1);
                        byte = 0;
                    }

                    if(dataCounter >= length+4)
                        return;
                }
            }
            
        }
    }
    
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
