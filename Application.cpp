#include "Application.h"
#include "SteganoManager.h"
#include "SteganoException.h"
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
    try
    {
        //test whether image filepath is not empty
        QString ImageFilepath = m_Window.getEncryptImageFilepath();
        if(ImageFilepath.length() == 0)
            throw CSteganoException("Image Filepath is not specified!");
        QString SaveFilepath = m_Window.getSaveFilepath();
        if(SaveFilepath.length() == 0)
            throw CSteganoException("'Save to' filepath is not specified!");
        if(SaveFilepath == ImageFilepath)
            throw CSteganoException("'Save to' filepath equals 'Input image' filepath: choose a different filepath for output!");
        bool IsDataToSaveAFile = m_Window.getEncryptDataSource();
        if(IsDataToSaveAFile)
        {
            m_Window.changeUIblocking(true);
            m_Executor.encryptFile(m_ChoosenMethodId,ImageFilepath,SaveFilepath, m_Window.getEncryptFileToHide(), m_Window.getArgsListFromWidget());
         }
        else
        {
            m_Window.changeUIblocking(true);
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
        m_Window.changeUIblocking(true);
        m_Executor.decryptToFile(m_ChoosenMethodId, m_Window.getDecryptImageFilepath(), m_Window.getDecryptFileToHide(), m_Window.getArgsListFromWidget());
    }
    else
    {
        m_Window.changeUIblocking(true);
        m_Executor.decryptToText(m_ChoosenMethodId, m_Window.getDecryptImageFilepath(), m_Window.getArgsListFromWidget());
    }
}
void CApplication::onProposeButtonClicked()
{
     try
    {
        //test whether image filepath is not empty
        QString ImageFilepath = m_Window.getEncryptImageFilepath();
        if(ImageFilepath.length() == 0)
            throw CSteganoException("Image Filepath is not specified!");

        PByteArray Data;
        bool IsDataToSaveAFile = m_Window.getEncryptDataSource();
        if(IsDataToSaveAFile)
        {
            m_Window.changeUIblocking(true);
            m_Executor.proposeWithFile(m_ChoosenMethodId,ImageFilepath, m_Window.getEncryptFileToHide(), m_Window.getArgsListFromWidget());
         }
        else
        {
            m_Window.changeUIblocking(true);
            m_Executor.proposeWithText(m_ChoosenMethodId,ImageFilepath, m_Window.getTextToHide(), m_Window.getArgsListFromWidget());

        }
    }
    catch(CSteganoException& Exception)
    {
        m_Window.showMessageBox(Exception.getMessage(),QMessageBox::Warning);
    }
   
}
void CApplication::onPreviewButtonClicked()
{
    try
    {
        //test whether image filepath is not empty
        QString ImageFilepath = m_Window.getEncryptImageFilepath();
        if(ImageFilepath.length() == 0)
            throw CSteganoException("Image Filepath is not specified!");

        bool IsDataToSaveAFile = m_Window.getEncryptDataSource();
        if(IsDataToSaveAFile)
        {
            m_Window.changeUIblocking(true);
            m_Executor.makePreviewWithFile(m_ChoosenMethodId,ImageFilepath,m_Window.getEncryptFileToHide(), m_Window.getArgsListFromWidget());
         }
        else
        {
            m_Window.changeUIblocking(true);
            m_Executor.makePreviewWithText(m_ChoosenMethodId,ImageFilepath, m_Window.getTextToHide(), m_Window.getArgsListFromWidget());
        }
    }
    catch(CSteganoException& Exception)
    {
        m_Window.showMessageBox(Exception.getMessage(),QMessageBox::Warning);
    }
}

void CApplication::onSteganoMethodChoosen(int id)
{
    m_ChoosenMethodId = id;
    PSteganoWidget pStegenoWidget = CSteganoManager::getInstance().produceSteganoWidget(id);
    m_Window.setWidget(pStegenoWidget);
    m_Window.changeProposeButtonVisibility(pStegenoWidget->isPropositionsAllowed());
}
void CApplication::configureWindow()
{
    PMethodList pMethodList = CSteganoManager::getInstance().getSteganoMethodList();

    // set method list to inform the user what the possibilities are
    m_Window.setStegonoMethodsList(pMethodList);

    // get widget from SteganoManager and set widget related to the first method on the method list
    PSteganoWidget pStegenoWidget = CSteganoManager::getInstance().produceSteganoWidget(pMethodList->first().first);
    m_Window.setWidget(pStegenoWidget);
    m_Window.changeProposeButtonVisibility(pStegenoWidget->isPropositionsAllowed());
    
    connect(&m_Window,SIGNAL(steganoMethodChoosen(int)),this,SLOT(onSteganoMethodChoosen(int)));
    connect(&m_Window,SIGNAL(encryptButtonClicked()),this,SLOT(onEncryptButtonClicked()));
    connect(&m_Window,SIGNAL(decryptButtonClicked()),this,SLOT(onDecryptButtonClicked()));
    connect(&m_Window,SIGNAL(openFileEncryptButtonClicked()), this, SLOT(onOpenFileEncryptButtonClicked()));
    connect(&m_Window,SIGNAL(openFileDecryptButtonClicked()), this, SLOT(onOpenFileDecryptButtonClicked()));
    connect(&m_Window,SIGNAL(saveFileEncryptButtonClicked()), this, SLOT(onSaveFileEncryptButtonClicked()));
    connect(&m_Window,SIGNAL(proposeButtonClicked()),this, SLOT(onProposeButtonClicked()));
    connect(&m_Window,SIGNAL(previewButtonClicked()),this, SLOT(onPreviewButtonClicked()));
    m_Window.show();
}

void CApplication::configureExecutor()
{
    connect(&m_Executor,SIGNAL(encryptFinished(bool)),this,SLOT(onEncryptFinished(bool)));
    connect(&m_Executor,SIGNAL(decryptFinished(bool)),this,SLOT(onDecryptFinished(bool)));
    connect(&m_Executor,SIGNAL(proposed(PArgsList)),this,SLOT(onProposed(PArgsList)));
    connect(&m_Executor,SIGNAL(progressChanged(int)),&m_Window,SLOT(updateProgress(int)));
    connect(&m_Executor,SIGNAL(previewFinished(PImage)),&m_Window,SLOT(displayPreview(PImage)));
    connect(&m_Executor,SIGNAL(decryptFinished(bool,QString)),this,SLOT(onDecryptFinished(bool,QString)));
    connect(&m_Executor,SIGNAL(errorOccurred(QString)),this,SLOT(onErrorOccurred(QString)));
}

void CApplication::onEncryptFinished(bool IsSuccess)
{
    m_Window.changeUIblocking(false);
    const int c_MaxProgress = 100;
    m_Window.updateProgress(c_MaxProgress);
    if(IsSuccess)
    {
        m_Window.showMessageBox(QString("Encryption: Success"),QMessageBox::Information);
    }
    else
    {
         m_Window.showMessageBox(QString("Encryption: Failure"),QMessageBox::Critical);
    }
}

void CApplication::onDecryptFinished(bool IsSuccess)
{
    m_Window.changeUIblocking(false);
    const int c_MaxProgress = 100;
    m_Window.updateProgress(c_MaxProgress);
    if(IsSuccess)
    {
        m_Window.showMessageBox(QString("Decryption: Success"),QMessageBox::Information);
    }
    else
    {
         m_Window.showMessageBox(QString("Decryption: Failure"),QMessageBox::Critical);
    }
}


void CApplication::onDecryptFinished(bool IsSuccess, QString DecryptedData)
{
    m_Window.changeUIblocking(false);
    const int c_MaxProgress = 100;
    m_Window.updateProgress(c_MaxProgress);
    if(IsSuccess)
    {
        m_Window.showResultsInTextArea(DecryptedData);
        m_Window.showMessageBox(QString("Decryption: Success"),QMessageBox::Information);
    }
    else
    {
         m_Window.showMessageBox(QString("Decryption: Failure"),QMessageBox::Critical);
    }
}

void CApplication::onErrorOccurred(QString Text)
{
    m_Window.showMessageBox(QString("Error Occurred: "+ Text),QMessageBox::Critical);
}

void CApplication::onProposed(PArgsList pArgs)
{
    m_Window.setWidgetArgs(pArgs);
}

void CApplication::onOpenFileEncryptButtonClicked()
{
    m_Window.showOpenFileEncryptDialog(CSteganoManager::getInstance().getSupportedTypesToEncrypt(m_ChoosenMethodId));
}

void CApplication::onOpenFileDecryptButtonClicked()
{
    QString decryptFiletypes = CSteganoManager::getInstance().getSupportedTypesToDecrypt(m_ChoosenMethodId);
    if(decryptFiletypes.size() == 0)
    {
        decryptFiletypes = CSteganoManager::getInstance().getSupportedTypesToEncrypt(m_ChoosenMethodId);
    }
    m_Window.showOpenFileDecryptDialog(decryptFiletypes);
}

void CApplication::onSaveFileEncryptButtonClicked()
{
    QString decryptFiletypes = CSteganoManager::getInstance().getSupportedTypesToDecrypt(m_ChoosenMethodId);
    if(decryptFiletypes.size() == 0)
    {
        decryptFiletypes = m_Window.getEncryptImageFilepath();
        if(decryptFiletypes.size() == 0)
        {
            m_Window.showMessageBox(QString("Specify image file first."),QMessageBox::Information);
            return;
        }
        std::string fileextenstion = decryptFiletypes.toStdString();
        fileextenstion = fileextenstion.substr(fileextenstion.find_last_of(".") + 1);
        decryptFiletypes = QString("Image Files (*.").append(QString::fromStdString(fileextenstion).append(")"));
    }
    m_Window.showSaveFileEncryptDialog(decryptFiletypes);
}
