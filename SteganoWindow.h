#pragma once
#include <QtGui/QMainWindow>
#include "ui_zpr_stegano.h"
#include "SteganoWidget.h"
#include "SteganoTypes.h"
#include <QMessageBox>

typedef QList<QVariant> ArgsList;
typedef QSharedPointer<QImage> PImage;

class CSteganoWindow : public QMainWindow
{
	Q_OBJECT

public:
    CSteganoWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~CSteganoWindow();
    void setWidget(QSharedPointer<CSteganoWidget>);
    PArgsList getArgsListFromWidget();
    void setArgsListForWidget(PArgsList);
    QString getTextToHide();
    QString getImageFilepath();
    QString getSaveFilepath();
    QString getEncryptFileToHide();
    QString getDecryptFileToHide();
    bool getEncryptDataSource();
    bool getDecryptDataSource();
    void changeProposeButtonVisibility(bool);
    void showResultsInTextArea(QString DecryptedData);
    void setWidgetArgs(PArgsList);
    // comment stub
    // Method should set active the first element on the list
    void setStegonoMethodsList(PMethodList);
signals:
    void steganoMethodChoosen(int id);
    void encryptButtonClicked();
    void decryptButtonClicked();
    void previewButtonClicked();
    void proposeButtonClicked();
    void imageFilepathChanged();
    void saveFilepathChanged();
    void fileToHideChanged();
    void dataSourceChanged();
    void openFileButtonClicked();

public slots:
    void updateProgress(int);
    void onEncryptFinished(void);
    void onDecryptFinished(void);
    void displayPreview(PImage);
    void showMessageBox(QString Message, QMessageBox::Icon MessageBoxIcon);
    void changeUIblocking(bool);
    void showOpenFileDialog(QString);

private:
	Ui::ZPR_STEGANOClass ui;
    PSteganoWidget m_pMethodWidget;

    QString m_FileToHideEncryptFilepath;
    QString m_FileToHideDecryptFilepath;
    QString m_ImageFilepath;
    QString m_SaveFilepath;
    bool m_IsFileRadioEncryptChoosen;
    bool m_IsFileRadioDecryptChoosen;
    void hideProposeButton();
    void showProposeButton();

private slots:
    void saveFileButtonClicked();
    void onEncryptRadioChecked(bool);
    void onDecryptRadioChecked(bool);
    void onEncryptDataOpenFile();
    void onDecryptDataOpenFile();
    
};
