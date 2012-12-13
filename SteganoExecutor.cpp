#include "SteganoExecutor.h"
#include "SteganoManager.h"
#include <QDebug>
#include <fstream>
#include <iostream>

CSteganoExecutor::CSteganoExecutor(QObject *parent) :
    QObject(parent),
    m_LastMethodId(-1) //FIXME: magic constant
{
}

void CSteganoExecutor::encryptFile(int Id,QString ImageFilepath, QString SaveFilepath, QString DataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
    }
    m_pSteganoMethod->encrypt(ImageFilepath, SaveFilepath, DataFilepath, pArgsList);

    emit encryptFinished(true);
}

void CSteganoExecutor::encryptText(int Id,QString ImageFilepath, QString SaveFilepath, QString Data, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
    }
    tmpnam(TempFilepath);
    // save file to temporary location and pass it to encrypt
    std::fstream TempFile(TempFilepath, std::fstream::out);
    TempFile << Data.toStdString();
    TempFile.close();

    m_pSteganoMethod->encrypt(ImageFilepath, SaveFilepath, QString(TempFilepath), pArgsList);

    emit encryptFinished(true);
}

void CSteganoExecutor::decryptToFile(int Id, QString ImageFilepath, QString DataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
    }
    m_pSteganoMethod->decrypt(ImageFilepath, DataFilepath, pArgsList);
    emit decryptFinished(true);
}

void CSteganoExecutor::decryptToText(int Id, QString ImageFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
    }

    // ask method save file to temporary location and load it to string
    tmpnam(TempFilepath);
    m_pSteganoMethod->decrypt(ImageFilepath, QString(TempFilepath), pArgsList);

    std::ifstream TempFile(TempFilepath, std::ios::in | std::ios::binary);
    if(!TempFile)
    {
        qDebug()<<"!good";
    }
    std::string DecryptedData;

    TempFile.seekg(0, std::ios::end);
    DecryptedData.resize(TempFile.tellg());
    TempFile.seekg(0, std::ios::beg);
    TempFile.read(&DecryptedData[0], DecryptedData.size());
    TempFile.close();

    emit decryptFinished(true,QString::fromStdString(DecryptedData));
}
