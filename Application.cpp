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

    try
    {
        //test whether image filepath is not empty
        QString ImageFilepath = m_Window.getImageFilepath();
        if(ImageFilepath.length() == 0)
            throw CSteganoException("Image Filepath is not specified!");
        QString SaveFilepath = m_Window.getSaveFilepath();
        if(SaveFilepath.length() == 0)
            throw CSteganoException("'Save to' filepath is not specified!");
        //TODO: data pusta ewentualnie
        PByteArray Data;
        bool IsDataToSaveAFile = m_Window.getEncryptDataSource();
        if(IsDataToSaveAFile)
        {
            qDebug()<<"saving a file" << m_Window.getEncryptFileToHide();
            m_Executor.encryptFile(m_ChoosenMethodId,ImageFilepath,SaveFilepath, m_Window.getEncryptFileToHide(), m_Window.getArgsListFromWidget());
         }
        else
        {
            qDebug()<<"saving a text" << m_Window.getTextToHide();
            m_Executor.encryptText(m_ChoosenMethodId,ImageFilepath,SaveFilepath, m_Window.getTextToHide(), m_Window.getArgsListFromWidget());

        }
    }
    catch(CSteganoException& Exception)
    {
        m_Window.showMessageBox(Exception.getMessage(),QMessageBox::Warning);
    }

}

void CApplication::onDecryptButtonClicked()
{

    bool IsDataToSaveAFile = m_Window.getDecryptDataSource();
    if(IsDataToSaveAFile)
    {
        qDebug()<<"saving to file" << m_Window.getDecryptFileToHide();
        m_Executor.decryptToFile(m_ChoosenMethodId, m_Window.getImageFilepath(), m_Window.getDecryptFileToHide(), m_Window.getArgsListFromWidget());
    }
    else
    {
        qDebug()<<"saving to textbox";
        m_Executor.decryptToText(m_ChoosenMethodId, m_Window.getImageFilepath(), m_Window.getArgsListFromWidget());
    }
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
    connect(&m_Window,SIGNAL(decryptButtonClicked()),this,SLOT(onDecryptButtonClicked()));
    //connect(&m_Window,SIGNAL(dataSourceChanged(bool)),this,SLOT(onDataSourceChanged(bool)));
    //connect(&m_Window,SIGNAL(imageFilepathChanged()),this,SLOT(onImageFilepathChanged()));
    //connect(&m_Window,SIGNAL(saveFilepathChanged()),this,SLOT(onSaveFilepathChanged()));

    m_Window.show();
}

void CApplication::configureExecutor()
{
    connect(&m_Executor,SIGNAL(encryptFinished(bool)),this,SLOT(onEncryptFinished(bool)));
    connect(&m_Executor,SIGNAL(decryptFinished(bool)),this,SLOT(onDecryptFinished(bool)));
    connect(&m_Executor,SIGNAL(progressChanged(int)),&m_Window,SLOT(updateProgress(int)));
    connect(&m_Executor,SIGNAL(previewFinished(PImage)),&m_Window,SLOT(displayPreview(PImage)));
    connect(&m_Executor,SIGNAL(decryptFinished(bool,QString)),this,SLOT(onDecryptFinished(bool,QString)));
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


void CApplication::onDecryptFinished(bool IsSuccess, QString DecryptedData)
{
    if(IsSuccess)
    {
        m_Window.showResultsInTextArea(DecryptedData);
        m_Window.showMessageBox(QString("Decryption: Success"),QMessageBox::Information);
    }
    else
    {
         m_Window.showMessageBox(QString("Decryption: Fefefefe EPIK FEJL"),QMessageBox::Critical);
    }
}

