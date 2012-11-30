#include "Application.h"
#include "SteganoManager.h"
#include "SteganoException.h"
#include <QDebug>
#include <QMessageBox>

CApplication::CApplication(int & argc, char ** argv):
    QApplication(argc,argv),
    m_ChoosenMethodId(0)
{
    configureWindow();
    configureExecutor();
}

void CApplication::onEncryptButtonClicked()
{
    //TEMP: generate test ByteArray

    PByteArray ByteArray(new QByteArray());
    for(int i=0;i<50;++i)
    {
        ByteArray->push_back(static_cast<char>(i));
    }

    try
    {
        //test whether image filepath is not empty
        if(m_ImageFilepath.length() == 0)
            throw CSteganoException("Image Filepath is not specified!");
        if(m_SaveFilepath.length() == 0)
            throw CSteganoException("'Save to' filepath is not specified!");
        //TODO: data pusta ewentualnie
        m_Executor.encrypt(m_ChoosenMethodId,m_ImageFilepath,m_SaveFilepath, ByteArray,m_Window.getArgsListFromWidget());
    }
    catch(CSteganoException& Exception)
    {
        m_Window.showMessageBox(Exception.getMessage(),QMessageBox::Warning);
    }

}

void CApplication::onDecryptButtonClicked()
{

}

void CApplication::onPreviewButtonClicked()
{

}

void CApplication::onSteganoMethodChoosen(int id)
{
    m_ChoosenMethodId = id;
    qDebug()<<"stegano method choosen: " << id;
    PSteganoWidget pStegenoWidget = CSteganoManager::getInstance().produceSteganoWidget(id);
    m_Window.setWidget(pStegenoWidget);
}

void CApplication::onImageFilepathChanged(QString Filepath)
{
    m_ImageFilepath = Filepath;
}

void CApplication::onSaveFilepathChanged(QString Filepath)
{
    m_SaveFilepath = Filepath;
}

void CApplication::onTextToHideChanged(QString)
{

}

void CApplication::onFileToHideChanged(QString)
{

}

void CApplication::configureWindow()
{
    PMethodList pMethodList = CSteganoManager::getInstance().getSteganoMethodList();

    // set method list to inform the user what the possibilities are
    m_Window.setStegonoMethodsList(pMethodList);

    // get widget from SteganoManager and set widget related to the first method on the method list
    PSteganoWidget pStegenoWidget = CSteganoManager::getInstance().produceSteganoWidget(pMethodList->first().first);
    m_Window.setWidget(pStegenoWidget);

    connect(&m_Window,SIGNAL(steganoMethodChoosen(int)),this,SLOT(onSteganoMethodChoosen(int)));
    connect(&m_Window,SIGNAL(encryptButtonClicked()),this,SLOT(onEncryptButtonClicked()));
    connect(&m_Window,SIGNAL(imageFilepathChanged(QString)),this,SLOT(onImageFilepathChanged(QString)));
    connect(&m_Window,SIGNAL(saveFilepathChanged(QString)),this,SLOT(onSaveFilepathChanged(QString)));

    m_Window.show();
}

void CApplication::configureExecutor()
{
    connect(&m_Executor,SIGNAL(encryptFinished(bool)),this,SLOT(onEncryptFinished(bool)));
    connect(&m_Executor,SIGNAL(decryptFinished(bool)),this,SLOT(onDecryptFinished(bool)));
    connect(&m_Executor,SIGNAL(progressChanged(int)),&m_Window,SLOT(updateProgress(int)));
    connect(&m_Executor,SIGNAL(previewFinished(PImage)),&m_Window,SLOT(displayPreview(PImage)));
}

void CApplication::onEncryptFinished(bool IsSuccess)
{
    if(IsSuccess)
    {
        m_Window.showMessageBox(QString("Encryption: Success"),QMessageBox::Information);
    }
    else
    {
         m_Window.showMessageBox(QString("Encryption: Fefefefe EPIK FEJL"),QMessageBox::Critical);
    }
}

void CApplication::onDecryptFinished(bool IsSuccess)
{
    if(IsSuccess)
    {
        m_Window.showMessageBox(QString("Decryption: Success"),QMessageBox::Information);
    }
    else
    {
         m_Window.showMessageBox(QString("Decryption: Fefefefe EPIK FEJL"),QMessageBox::Critical);
    }
}
