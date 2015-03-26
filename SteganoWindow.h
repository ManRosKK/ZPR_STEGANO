#pragma once
#include <QMainWindow>
#include "ui_zpr_stegano.h"
#include "SteganoWidget.h"
#include "SteganoTypes.h"
#include "SteganoWidgetMethodPointers.h"
#include <QMessageBox>

typedef QList<QVariant> ArgsList;
typedef QSharedPointer<QImage> PImage;

/**
 * @brief Main window of the program.
 *
 * Allows user to choose a SteganoMethod, provide arguments and see results.
 */
class CSteganoWindow : public QMainWindow
{
	Q_OBJECT

public:
    CSteganoWindow(QWidget *parent = 0);
    ~CSteganoWindow();
    void setWidget(QSharedPointer<CSteganoWidget>);
    PArgsList getArgsListFromWidget();
    void setArgsListForWidget(PArgsList);
    QString getTextToHide();
    QString getEncryptImageFilepath();
    QString getDecryptImageFilepath();
    QString getSaveFilepath();
    QString getEncryptFileToHide();
    QString getDecryptFileToHide();
    bool getEncryptDataSource();
    bool getDecryptDataSource();
    void changeProposeButtonVisibility(bool);
    void showResultsInTextArea(QString DecryptedData);
    void setWidgetArgs(PArgsList);
    void setStegonoMethodsList(PMethodList);
signals:
    void steganoMethodChoosen(int id);
    void encryptButtonClicked();
    void decryptButtonClicked();
    void previewButtonClicked();
    void proposeButtonClicked();
    void openFileEncryptButtonClicked();
    void openFileDecryptButtonClicked();
    void saveFileEncryptButtonClicked();

public slots:
    void updateProgress(int);
    void onEncryptFinished(void);
    void onDecryptFinished(void);
    void displayPreview(PImage);
    void showMessageBox(QString Message, QMessageBox::Icon MessageBoxIcon);
    void changeUIblocking(bool);
    void showOpenFileEncryptDialog(QString);
    void showOpenFileDecryptDialog(QString);
    void showSaveFileEncryptDialog(QString);
    void onComboBoxActivated(int Id);

private:
	Ui::ZPR_STEGANOClass ui;
    PSteganoWidget m_pMethodWidget;

    QString m_FileToHideEncryptFilepath;
    QString m_FileToHideDecryptFilepath;
    QString m_EncryptImageFilepath;
    QString m_DecryptImageFilepath;
    QString m_SaveFilepath;
    bool m_IsFileRadioEncryptChoosen;
    bool m_IsFileRadioDecryptChoosen;
    void hideProposeButton();
    void showProposeButton();

private slots:
    void onEncryptRadioChecked(bool);
    void onDecryptRadioChecked(bool);
    void onEncryptDataOpenFile();
    void onDecryptDataOpenFile();
    
};
