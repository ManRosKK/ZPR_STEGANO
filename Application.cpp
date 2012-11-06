#include "Application.h"

CApplication::CApplication(int & argc, char ** argv):
    QApplication(argc,argv)
{
    //TODO: finishme: connect signal and slots to executor and window
    m_Window.show();
}
