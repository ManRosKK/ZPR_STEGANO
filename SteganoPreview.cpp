#include "SteganoPreview.h"
#include "ui_Steganopreview.h"

CSteganoPreview::CSteganoPreview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSteganoPreview)
{
    ui->setupUi(this);
}

CSteganoPreview::~CSteganoPreview()
{
    delete ui;
}

void CSteganoPreview::SetImage(QImage& Image)
{
    //*pImage;
   // pWindowsImage = pImage;
    ui->label->setPixmap(QPixmap::fromImage(Image));
}
