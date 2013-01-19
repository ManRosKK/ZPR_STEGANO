#ifndef STEGANOPREVIEW_H
#define STEGANOPREVIEW_H

#include <QDialog>
#include <QImage>
#include "SteganoTypes.h"
namespace Ui {
class CSteganoPreview;
}

class CSteganoPreview : public QDialog
{
    Q_OBJECT
    
public:
    explicit CSteganoPreview(QWidget *parent = 0);
    ~CSteganoPreview();
    void SetImage(QImage& Image);
private:
    Ui::CSteganoPreview *ui;
    PImage pWindowsImage;
};

#endif // STEGANOPREVIEW_H
