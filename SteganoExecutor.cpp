#include "SteganoExecutor.h"
#include "SteganoManager.h"
#include <QDebug>
#include <fstream>
#include <iostream>
#include <QFile>
#include <QtConcurrentRun>


CSteganoExecutor::CSteganoExecutor(QObject *parent) :
    QObject(parent),
    m_LastMethodId(CSteganoManager::c_InvalidIdNumber)
{
}

void CSteganoExecutor::encryptFile(int Id,QString ImageFilepath, QString SaveFilepath, QString DataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }
    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::encrypt, ImageFilepath, SaveFilepath, DataFilepath, pArgsList);
}

void CSteganoExecutor::encryptText(int Id,QString ImageFilepath, QString SaveFilepath, QString Data, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }
    tmpnam(TempFilepath);
    QFile file(TempFilepath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out <<Data;
    file.close();

    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::encrypt, ImageFilepath, SaveFilepath, QString(TempFilepath), pArgsList);
}

void CSteganoExecutor::decryptToFile(int Id, QString ImageFilepath, QString DataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }
    m_DecryptToFile = true;
    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::decrypt, ImageFilepath, DataFilepath, pArgsList);
}

void CSteganoExecutor::decryptToText(int Id, QString ImageFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }

    // ask method save file to temporary location and load it to string
    tmpnam(TempFilepath);
    m_DecryptToFile = false;
    //m_pSteganoMethod->decrypt(ImageFilepath, QString(TempFilepath), pArgsList);

    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::decrypt, ImageFilepath, QString(TempFilepath), pArgsList);

    /*std::ifstream TempFile(TempFilepath, std::ios::in | std::ios::binary);
    if(!TempFile)
    {
        qDebug()<<"!good";
    }
    std::string DecryptedData;

    TempFile.seekg(0, std::ios::end);
    DecryptedData.resize(TempFile.tellg());
    TempFile.seekg(0, std::ios::beg);
    TempFile.read(&DecryptedData[0], DecryptedData.size());
    TempFile.close();*/

}

void CSteganoExecutor::connectSignalsAndSlotsToMethod()
{
    connect(m_pSteganoMethod.data(),SIGNAL(encryptFinished(bool)),this,SLOT(onEncryptFinished(bool)),Qt::QueuedConnection);
    connect(m_pSteganoMethod.data(),SIGNAL(decryptFinished(bool)),this,SLOT(onDecryptFinished(bool)),Qt::QueuedConnection);
    connect(m_pSteganoMethod.data(),SIGNAL(progressChanged(int)), this,SIGNAL(progressChanged(int)));
}

void CSteganoExecutor::onDecryptFinished(bool success)
{
    if(success)
    {
        if(!m_DecryptToFile)
        {
            QFile file(TempFilepath);
            QByteArray decryptedString;
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
            decryptedString = file.readAll();
            file.close();
            emit decryptFinished(true,QString(decryptedString));
        }
        else
        {
            emit decryptFinished(true);
        }
    }
    else
    {
        emit decryptFinished(false);
    }
}

void CSteganoExecutor::onEncryptFinished(bool success)
{
    emit encryptFinished(success);
}

