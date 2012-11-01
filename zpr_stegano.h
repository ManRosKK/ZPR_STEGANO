b#ifndef ZPR_STEGANO_H
#define ZPR_STEGANO_H

#include <QtGui/QMainWindow>
#include "ui_zpr_stegano.h"

class ZPR_STEGANO : public QMainWindow
{
	Q_OBJECT

public:
	ZPR_STEGANO(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ZPR_STEGANO();

private:
	Ui::ZPR_STEGANOClass ui;
};

#endif // ZPR_STEGANO_H
