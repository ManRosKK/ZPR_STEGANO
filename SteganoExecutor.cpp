#include "SteganoExecutor.h"
#include "SteganoManager.h"
#include <QDebug>

CSteganoExecutor::CSteganoExecutor(QObject *parent) :
    QObject(parent),
    m_LastMethodId(-1) //FIXME: magic constant
{
}

void CSteganoExecutor::encrypt(int Id,QString ImageFilepath, QString SaveFilepath, PByteArray pData, bool IsDataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
    }
    m_pSteganoMethod->encrypt(ImageFilepath, SaveFilepath, pData, IsDataFilepath, pArgsList);

    emit encryptFinished(true);
}


void CSteganoExecutor::decrypt(int Id,QString ImageFilepath, PByteArray pData, bool IsDataFilepath, PArgsList pArgsList)
{
    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
    }
    m_pSteganoMethod->decrypt(ImageFilepath, pData, IsDataFilepath, pArgsList);
    emit decryptFinished(true);
}
