#pragma once
#include <QtGui/QMainWindow>
#include "ui_zpr_stegano.h"
#include "SteganoWidget.h"
#include "SteganoTypes.h"
#include <QMessageBox>

typedef QList<QVariant> ArgsList;
typedef QSharedPointer<QImage> PImage;

class ZPR_STEGANO : public QMainWindow
{
	Q_OBJECT

public:
	ZPR_STEGANO(QWidget *parent = 0, Qt::WFlags flags = 0);
	~ZPR_STEGANO();
    void setWidget(QSharedPointer<CSteganoWidget>);
    PArgsList getArgsListFromWidget();
    QString getTextToHide();
    QString getImageFilepath();
    QString getSaveFilepath();
    QString getEncryptFileToHide();
    QString getDecryptFileToHide();
    bool getEncryptDataSource();
    bool getDecryptDataSource();
    void showResultsInTextArea(PByteArray DecryptedData);

    // comment stub
    // Method should set active the first element on the list
    void setStegonoMethodsList(PMethodList);
signals:
    void steganoMethodChoosen(int id);
    void encryptButtonClicked();
    void decryptButtonClicked();
    void previewButtonClicked();
    void imageFilepathChanged();
    void saveFilepathChanged();
    void fileToHideChanged();
    void dataSourceChanged();

public slots:
    void updateProgress(int);
    void onEncryptFinished(void);
    void onDecryptFinished(void);
    void displayPreview(PImage);
    void showMessageBox(QString Message, QMessageBox::Icon MessageBoxIcon);

private:
	Ui::ZPR_STEGANOClass ui;
    PSteganoWidget m_pMethodWidget;

    QString m_FileToHideEncryptFilepath;
    QString m_FileToHideDecryptFilepath;
    QString m_ImageFilepath;
    QString m_SaveFilepath;
    bool m_IsFileRadioEncryptChoosen;
    bool m_IsFileRadioDecryptChoosen;

private slots:
    void openFileButtonClicked();
    void saveFileButtonClicked();
    void onEncryptRadioChecked(bool);
    void onDecryptRadioChecked(bool);
    void onEncryptDataOpenFile();
    void onDecryptDataOpenFile();
};
