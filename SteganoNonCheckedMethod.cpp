#include "SteganoNonCheckedMethod.h"
#include "BitmapHeader.h"

#include <QBitArray>
#include <QRgb>
#include <QDebug>
#include <iostream>
#include <fstream>

CSteganoNonCheckedMethod::CSteganoNonCheckedMethod(void)
{

}

CSteganoNonCheckedMethod::CSteganoNonCheckedMethod(const CSteganoNonCheckedMethod&)
{

}

CSteganoNonCheckedMethod::~CSteganoNonCheckedMethod(void)
{

}

PSteganoMethod CSteganoNonCheckedMethod::createSteganoNonCheckedMethod()
{
    return PSteganoMethod(new CSteganoNonCheckedMethod());
}

void CSteganoNonCheckedMethod::encrypt(QString ImageFilePath, QString ImageSaveFilePath, QString DataFilepath, PArgsList SteganoParameters)
{
    //SteganoParameters ignored atm
    //finds if sourcefilepath is a bitmap
    //then write header (filelength and extension) and infofilepath
        //to destfilepath.

    std::fstream fileone(ImageFilePath.toStdString().c_str(), std::fstream::in | std::fstream::binary);
    std::fstream filetwo(DataFilepath.toStdString().c_str(), std::fstream::in | std::fstream::binary);
    std::fstream filedest(ImageSaveFilePath.toStdString().c_str(), std::fstream::out | std::fstream::binary);

    //check out whether fileone is a bitmap
    //read the BMP fileheader
    BITMAPFILEHEADER h;
    fileone.read((char*)&h, static_cast<std::streamsize>(sizeof(BITMAPFILEHEADER)));
    if(!fileone)
    {
        std::cout << "header read failed!"<<std::endl;
        return;
    }
    if(h.bfType != BF_TYPE)
    {
        std::cout << "not a bitmap!"<<std::endl;
        return;
    }
    fileone.seekg (0, std::ios::beg);

    const int c_BufferSize = 1000000;
    // allocate memory for buffer
    char* buffer = new char[c_BufferSize];

    //rewrite the source file
    std::streamsize count = 0;
    do
    {
        fileone.read(buffer, c_BufferSize);
        count = fileone.gcount();
        filedest.write(buffer,count);
    }
    while(count != 0);


    //find out info file size
    filetwo.seekg (0, std::ios::end);
    int infofilesize = filetwo.tellg();
    filetwo.seekg (0, std::ios::beg);
    //qDebug()<<"infofilesize"<<infofilesize;

    //write this size to file
    filedest.write((char*)&infofilesize,sizeof(int));

    //find out extention
    char fileExtention[c_MaxExtensionLength+1];
    memset(fileExtention, 0, c_MaxExtensionLength+1);
    std::string infoFileExtension(DataFilepath.toStdString());
    size_t lastof =infoFileExtension.find_last_of(".");
    if(lastof != std::string::npos)
    {
        infoFileExtension = infoFileExtension.substr(lastof + 1);
        if(infoFileExtension.length() <= c_MaxExtensionLength)
        {
            strcpy (fileExtention,infoFileExtension.c_str());
        }
        else
        {
            //save without ext
        }
    }

    //write it to the file
    filedest.write(fileExtention,c_MaxExtensionLength);

    do
    {
        filetwo.read(buffer, c_BufferSize);
        count = filetwo.gcount();
        filedest.write(buffer,count);
    }
    while( count != 0);

    //clean up
    delete[](buffer);
}

void CSteganoNonCheckedMethod::decrypt(QString ImageFilePath, QString SaveFilepath, PArgsList SteganoParameters)
{
    std::fstream file(ImageFilePath.toStdString().c_str(), std::fstream::in | std::fstream::binary);

    if(file.is_open()) { // file opened
        BITMAPFILEHEADER h;

        //read the BMP fileheader
        file.read((char*)&h, static_cast<std::streamsize>(sizeof(BITMAPFILEHEADER)));
        if(!file)
        {
            std::cout << "header read failed!"<<std::endl;
            return;
        }
        if(h.bfType != BF_TYPE)
        {
            std::cout << "not a bitmap!"<<std::endl;
            return;
        }

        //go to area after the bitmap
         file.seekg (h.bfSize, std::ios::beg);

         int i=0;
         while(1)
         {
            //read hidden file filesize
            unsigned int filesize = 0;
            file.read((char*)&filesize, sizeof(int));
            if(!file)
            {
                if(i == 0)
                {
                    std::cout<<"no hidden info (u dun goofed)!";
                    return; //success
                }
                return;
            }

            //read file extention
            char fileExtention[c_MaxExtensionLength];
            //elementsRead = fread(fileExtention,1,c_MaxExtensionLength,file);
            file.read(fileExtention, c_MaxExtensionLength);
            if(!file)
            {
                std::cout<<"error reading extension!";
                return;
            }

            //write the data

            //compute filepath called filenamesavewithExt
            std::string filenamesavewithExt(SaveFilepath.toStdString());
            //filenamesavewithExt += ('0'+i); only one file!
            if(strlen(fileExtention)>0)
            {
                filenamesavewithExt.append(".");
            }
            filenamesavewithExt.append(fileExtention);

            //fast read - try to allocate filesize buffer
            char* buffer = new char[filesize]; //alternative - qscopedpointer, but no delete [] then, but safe for char.
            file.read(buffer,filesize);
            if(!file)
            {
                std::cout << "error reading binary file hiden"<<std::endl;
            }
            std::fstream filewrite(filenamesavewithExt.c_str(), std::fstream::out | std::fstream::binary);
            filewrite.write(buffer,filesize);
            delete [] buffer;

            ++i;
        }
    }
    else
    {
        std::cout<<"failed to load file";
    }
}

void CSteganoNonCheckedMethod::makePreview(QString imageFilePath, QString imageSaveFilePath, PByteArray data, PArgsList steganoParameters)
{

}

int CSteganoNonCheckedMethod::evaluate(PArgsList,int)
{
    return 0;
}

int CSteganoNonCheckedMethod::evaluate(PArgsList,QString)
{
    return 0;
}


PSteganoMethod CSteganoNonCheckedMethod::clone()
{
    return PSteganoMethod(new CSteganoNonCheckedMethod(*this));
}

QString CSteganoNonCheckedMethod::getName()
{
    //TEMP temporary
    return QString("NonCheckedAreaOfFiles");
}
