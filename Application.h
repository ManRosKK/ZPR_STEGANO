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
    void onSteganoMethodChoosen(int Id);
    void onImageFilepathChanged(QString Filepath);
    void onSaveFilepathChanged(QString Filepath);
    void onTextToHideChanged(QString Filepath);
    void onFileToHideChanged(QString Filepath);
    void onEncryptFinished(bool IsSuccess);
    void onDecryptFinished(bool IsSuccess);
private:
    void configureWindow();
    void configureExecutor();

    ZPR_STEGANO m_Window;
    CSteganoExecutor m_Executor;

    QString m_ImageFilepath;
    QString m_SaveFilepath;
    int m_ChoosenMethodId;
};
