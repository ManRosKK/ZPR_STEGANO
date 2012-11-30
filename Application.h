#pragma once
#include "zpr_stegano.h"
#include "SteganoExecutor.h"
#include <QApplication>

class CApplication : public QApplication
{
    Q_OBJECT
public:
    explicit CApplication(int & argc, char ** argv);
signals:

public slots:
    void onEncryptButtonClicked();
    void onDecryptButtonClicked();
    void onPreviewButtonClicked();
    void onSteganoMethodChoosen(int id);
    void onImageFilepathChanged(QString);
    void onSaveFilepathChanged(QString);
    void onTextToHideChanged(QString);
    void onFileToHideChanged(QString);
    void onEncryptFinished(bool);
    void onDecryptFinished(bool);
private:
    void configureWindow();
    void configureExecutor();

    ZPR_STEGANO m_Window;
    CSteganoExecutor m_Executor;

    QString m_ImageFilepath;
    QString m_SaveFilepath;
    int m_ChoosenMethodId;
};
