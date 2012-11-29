#include "zpr_stegano.h"
#include <QFileDialog>

ZPR_STEGANO::ZPR_STEGANO(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
    ui.encryptButton->setText("Encrypt!");
    ui.decryptButton->setText("Decrypt!");
    ui.openFileButton->setText("Open File");
    ui.saveFileButton->setText("Save File to..");

    connect(ui.encryptButton,SIGNAL(clicked()),this,SIGNAL(encryptButtonClicked()));
    connect(ui.decryptButton,SIGNAL(clicked()),this,SIGNAL(decryptButtonClicked()));
    connect(ui.openFileButton,SIGNAL(clicked()),this,SLOT(openFileButtonClicked()));
    connect(ui.saveFileButton,SIGNAL(clicked()),this,SLOT(saveFileButtonClicked()));
}

ZPR_STEGANO::~ZPR_STEGANO()
{

}

void ZPR_STEGANO::updateProgress(int)
{

}

void ZPR_STEGANO::onEncryptFinished(void)
{

}

void ZPR_STEGANO::onDecryptFinished(void)
{

}

void ZPR_STEGANO::displayPreview(PImage)
{

}

void ZPR_STEGANO::saveFileButtonClicked()
{
    QString FileName = QFileDialog::getSaveFileName(this,
        tr("Save Image to..."), QString(), tr("Image Files (*.png *.jpg *.bmp)"));
    emit saveFilepathChanged(FileName);
}

void ZPR_STEGANO::openFileButtonClicked()
{
    QString FileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QString(), tr("Image Files (*.png *.jpg *.bmp)"));
    emit imageFilepathChanged(FileName);
}
