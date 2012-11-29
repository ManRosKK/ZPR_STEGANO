#pragma once
#include <QtGui/QMainWindow>
#include "ui_zpr_stegano.h"
#include "SteganoWidget.h"

typedef QList<QVariant> ArgsList;
typedef QSharedPointer<QImage> PImage;

class ZPR_STEGANO : public QMainWindow
{
	Q_OBJECT

public:
	ZPR_STEGANO(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ZPR_STEGANO();
    void setWidget(QSharedPointer<CSteganoWidget>);
    ArgsList getArgsListFromWidget();

signals:
    void steganoMethodChoosen(int id);
    void encryptButtonClicked();
    void decryptButtonClicked();
    void previewButtonClicked();
    void imageFilepathChanged(QString);
    void saveFilepathChanged(QString);
    void textToHideChanged(QString);
    void fileToHideChanged(QString);
public slots:
    void updateProgress(int);
    void onEncryptFinished(void);
    void onDecryptFinished(void);
    void displayPreview(PImage);

private:
	Ui::ZPR_STEGANOClass ui;
    QSharedPointer<CSteganoWidget> m_MethodWidget;
private slots:
    void openFileButtonClicked();
    void saveFileButtonClicked();
};
