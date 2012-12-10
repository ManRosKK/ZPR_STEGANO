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

void CSteganoNonCheckedMethod::encrypt(QString ImageFilePath, QString ImageSaveFilePath, PByteArray Data, bool IsDataFilepath, PArgsList SteganoParameters)
{
    //SteganoParameters ignored atm

}

void CSteganoNonCheckedMethod::decrypt(QString ImageFilePath, PByteArray Data, bool IsDataFilepath, PArgsList SteganoParameters)
{
    std::fstream file(ImageFilePath.toAscii().data(), std::fstream::in | std::fstream::binary);

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
        std::cout << "[Header read test] {File to hide in}.size is: "<<h.bfSize<<std::endl;
        //go to area after the bitmap

         file.seekg (h.bfSize, std::ios::beg);

         int i=0;
         while(1)
         {
            //read hidden file filesize
            unsigned int filesize = -1;
            file.read((char*)&filesize, static_cast<std::streamsize>(sizeof(unsigned int)));
            if(!file)
            {
                if(i == 0)
                {
                    std::cout<<"no hidden info (u dun goofed)!";
                    return; //success
                }
                return;//
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
            std::cout<<"file ext: "<<fileExtention<<"\n";

            if(IsDataFilepath)
            {
                //compute filepath called filenamesavewithExt
                std::string filenamesavewithExt(QString(*Data).toStdString());
                filenamesavewithExt += ('0'+i);
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
            }
            else
            {
                //fast read - try to allocate filesize buffer
                char* buffer = new char[filesize]; //alternative - qscopedpointer, but no delete [] then, but safe for char.
                file.read(buffer,filesize);
                if(!file)
                {
                    std::cout << "error reading binary file hiden"<<std::endl;
                }
                Data->clear();
                Data->append(" "); //hack - deep copy is performed only if Data is not empty
                Data->prepend(QByteArray::fromRawData(buffer, filesize)); //WARNING: not safe!!
                //std::fstream filewrite(filenamesavewithExt.c_str(), std::fstream::out | std::fstream::binary);
                //filewrite.write(buffer,filesize);
                delete [] buffer;
            }

            ++i;
        }
    }
    else
    {
        std::cout<<"failed load file";
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
