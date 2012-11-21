#include "Application.h"

CApplication::CApplication(int & argc, char ** argv):
    QApplication(argc,argv)
{
    //TODO: finishme: connect signal and slots to executor and window
    m_Window.show();
}

void CApplication::onEncryptButtonClicked(){}
void CApplication::onDecryptButtonClicked(){}
void CApplication::onPreviewButtonClicked(){}
void CApplication::onSteganoMethodChoosen(int id){}
void CApplication::onImageFilepathChanged(QString){}
void CApplication::onSaveFilepathChanged(QString){}
void CApplication::onTextToHideChanged(QString){}
void CApplication::onFileToHideChanged(QString){}
