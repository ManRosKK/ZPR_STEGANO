#include "SteganoExecutor.h"
#include "SteganoManager.h"
CSteganoExecutor::CSteganoExecutor(QObject *parent) :
    QObject(parent)
{
}

void CSteganoExecutor::encrypt(int Id,QString ImageFilepath, QString SaveFilepath, PByteArray pData, PArgsList pArgsList)
{

    if( Id != m_LastMethodId)
    {
        m_pSteganoMethod = CSteganoManager::getInstance().produceSteganoMethod(Id);
        m_LastMethodId = Id;
    }
    m_pSteganoMethod->encrypt(ImageFilepath, SaveFilepath, pData, pArgsList);
    emit encryptFinished(true);
}
