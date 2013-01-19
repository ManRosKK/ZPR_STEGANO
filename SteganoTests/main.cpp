#include <QtGui/QApplication>
#include <QTest>
#include "tst_csteganomanager.h"
int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    char* mockUp2="";
    int mockUp1=0;
    CApplication a(mockUp1,&mockUp2);
    /*******************************************************************/
    //    CStegano Test Case
    /*******************************************************************/
    tst_CSteganoManager* p_tst_CSteganoManager = new tst_CSteganoManager();
    QTest::qExec(p_tst_CSteganoManager);
    delete p_tst_CSteganoManager;


    return 0;// a.exec();
}
