
#include "SteganoTypes.h"
#include "SteganoBitsMethod.h"
#include <QBitArray>
#include <QRgb>
#include <QDebug>
#include <QFile>
#include <QMessageBox>

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
    if(dataLength == 0)
        return PBitArray(new QBitArray(0));
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
PImage CSteganoBitsMethod::encryptWithPreview(QString ImageFilePath, QString DataFilePath, PArgsList SteganoParameters)
{
    unsigned int dataBitLength;
    PImage pImage(new QImage() );
    //QImage& image= *pImage.data();
    
    pImage->load(ImageFilePath);
 
    unsigned int maskPixel = SteganoParameters->takeAt(0).toUInt();
    
    PVectorInt pmaskVector = generateEncryptMask(maskPixel); //generating help mask for encrypting
    qDebug()<<"maskVector.size() => "<<pmaskVector->size();
    
    
    PBitArray pdata = prepareEncryptData(DataFilePath);
    dataBitLength = pdata->size();
    
    if(dataBitLength == 0)
        return pImage;

    unsigned int dataCounter = 0; 
    bool loopShouldFinishFlag = 0;
    for( int i = 0;i < pImage->height();i++)
    {
        for( int j = 0;j < pImage->width();j++)
        {
            QRgb pixel = pImage->pixel(j,i);
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
                    //qDebug()<<"(i,j) => "<<i<<","<<j;
                    break;
                }
            }
            pImage->setPixel(j,i,pixel);
            if( loopShouldFinishFlag ) //if we got the end of Data length
            {
                i = pImage->height();
                j = pImage->width();
            }
        }
        int Percentage = (dataCounter*100)/dataBitLength;
        emit progressChanged( Percentage );
    }
    if(dataCounter < dataBitLength )
    {
        //emit encryptFinished(false);

        return PImage(NULL);
    }
    return pImage;
}
void CSteganoBitsMethod::encrypt(QString ImageFilePath, QString ImageSaveFilePath, QString DataFilePath, PArgsList SteganoParameters)
{
    try
    {
        PImage pImage = encryptWithPreview(ImageFilePath,DataFilePath,SteganoParameters);

        pImage->save(ImageSaveFilePath);
        emit encryptFinished(true);
    }catch(...)
    {
        emit encryptFinished(false);
    }
    
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
    if( (length+4)*8 > (pimage->height()*pimage->width())/pmaskVector->size() )
    {
          emit decryptFinished(false);
          return;
    }
    QFile file(DataFilepath);
    if (!file.open(QIODevice::WriteOnly))
    {
          emit decryptFinished(false);
          return;
    }

    unsigned short shifter = 0x0001;
    unsigned short carriageReturn = 0x0100;
    char byte = 0;
    unsigned int dataCounter = 0; 
    bool loopShouldFinishFlag = 0;

    for( int i = 0; i < pimage->height(); i++)
    {
        for( int j = 0; j < pimage->width(); j++)
        {
            QRgb pixel = pimage->pixel(j,i);
            for(int k = 0; k < pmaskVector->size(); k++) //foreach bit in mask for one pixel
            {
                if( pixel & (*pmaskVector)[k] )
                {
                    //"insert: 1";
                    byte |= (shifter);
                }else
                {
                    //"insert: 0";
                    byte &= ~(shifter);
                }
                shifter<<=1;
                
                if(shifter == carriageReturn)
                {
                    //byte is full of 8 bits
                    //it is time to rewrite it to buffer
                    shifter = 0x0001;

                    if(dataCounter++>=4) // if we are after dataLength
                    {
                        file.write(&byte,1);
                        qDebug()<<byte<<"   "<<DataFilepath;
                       
                        byte = 0;
                    }
                    
                    if(dataCounter >= length+4) //we reached the end of data
                    {
                        file.close();
                        emit progressChanged( 100 );
                        emit decryptFinished(true);
                        return;
                    }
                }
            }
            int percentage = (dataCounter+ 4)/length;
            emit progressChanged( percentage );
        }
    }
    emit decryptFinished(false);
}
void CSteganoBitsMethod::makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList)
{
    emit proposeFinished(pArgsList);
    return;
}
void CSteganoBitsMethod::makePreview(QString ImageFilePath, QString DataFilePath, PArgsList SteganoParameters)
{
    try
    {
        qDebug()<<"STEGANOBITS::makePreview";
        PImage pImage=encryptWithPreview(ImageFilePath,DataFilePath,SteganoParameters);
        qDebug()<<ImageFilePath<<" "<<DataFilePath<<" ";
        if(pImage.data() == NULL)
            qDebug()<<"NUUUUUUUUUUUUUUUUUUUL "<<pImage.data() ;
        *pImage;
        emit previewFinished(pImage);
    }catch(...)
    {
        //emit BLAD;
    }
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

QString CSteganoBitsMethod::getSupportedTypesToEncrypt()
{
    return QString("Image Files (*.png *.jpg *.bmp)");
}

QString CSteganoBitsMethod::getSupportedTypesToDecrypt()
{
    return QString("Image Files (*.jpg *.bmp)");
}
