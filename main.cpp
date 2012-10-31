#include "zpr_stegano.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ZPR_STEGANO w;
	w.show();
	return a.exec();
}
