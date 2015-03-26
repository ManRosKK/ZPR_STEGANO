#include "Application.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    CApplication a(argc, argv);
	return a.exec();
}
