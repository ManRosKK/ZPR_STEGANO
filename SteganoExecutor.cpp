#include "SteganoExecutor.h"
#include "SteganoManager.h"
#include <fstream>
#include <iostream>
#include <QFile>
#include <QtConcurrentRun>
#include <QMessageBox>

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
    if(!tmpnam(TempFilepath))
    {
        qDebug()<<"Tmp filepath cannot be generated";
        return;
    }
    QFile file(TempFilepath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out <<Data;
    file.close();

    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::encrypt, ImageFilepath, SaveFilepath, QString(TempFilepath), pArgsList);
}

void CSteganoExecutor::proposeWithText(int Id,QString ImageFilepath, QString Data, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }
    unsigned int length = Data.length();
    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::makeProposition, ImageFilepath, length, pArgsList);
}

void CSteganoExecutor::proposeWithFile(int Id,QString ImageFilepath, QString DataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }
    unsigned int size = 0;
    QFile file(DataFilepath);
    if(file.open(QIODevice::ReadOnly))
    {
        size = file.size();
    }else
        emit errorOccurred("File error- does not exist");
    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::makeProposition, ImageFilepath, size, pArgsList);
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
    if(!tmpnam(TempFilepath))
    {
        emit errorOccurred("Tmp filepath cannot be generated");
        return;
    }
    m_DecryptToFile = false;

    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::decrypt, ImageFilepath, QString(TempFilepath), pArgsList);


}
void CSteganoExecutor::makePreviewWithFile(int Id,QString ImageFilepath, QString DataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }

    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::makePreview, ImageFilepath, DataFilepath, pArgsList);

}
void CSteganoExecutor::makePreviewWithText(int Id,QString ImageFilepath, QString Data, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
        connectSignalsAndSlotsToMethod();
    }
    if(!tmpnam(TempFilepath))
    {
        emit errorOccurred("Tmp filepath cannot be generated");
        return;
    }

    QFile file(TempFilepath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream out(&file);
    out <<Data;
    file.close();

    QtConcurrent::run(m_pSteganoMethod.data(), &CSteganoMethod::makePreview, ImageFilepath, QString(TempFilepath), pArgsList);
}
void CSteganoExecutor::connectSignalsAndSlotsToMethod()
{
    qRegisterMetaType<PArgsList>("PArgsList");
    qRegisterMetaType<PImage>("PImage");

    connect(m_pSteganoMethod.data(),SIGNAL(proposeFinished(PArgsList)),this,SLOT(onProposed(PArgsList)),Qt::QueuedConnection);
    connect(m_pSteganoMethod.data(),SIGNAL(encryptFinished(bool)),this,SLOT(onEncryptFinished(bool)),Qt::QueuedConnection);
    connect(m_pSteganoMethod.data(),SIGNAL(decryptFinished(bool)),this,SLOT(onDecryptFinished(bool)),Qt::QueuedConnection);
    connect(m_pSteganoMethod.data(),SIGNAL(previewFinished(PImage)), this,SIGNAL(previewFinished(PImage)),Qt::QueuedConnection);
    connect(m_pSteganoMethod.data(),SIGNAL(progressChanged(int)), this,SIGNAL(progressChanged(int)));
    connect(m_pSteganoMethod.data(),SIGNAL(errorOccurred(QString)), this,SIGNAL(errorOccurred(QString)));
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

void CSteganoExecutor::onProposed(PArgsList pArgsList)
{
    emit proposed(pArgsList);
}
