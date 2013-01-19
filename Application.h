#pragma once
#include "SteganoWindow.h"
#include "SteganoExecutor.h"
#include <QApplication>
/**
 * @brief Main class of the program
 *
 * Is owner of all other objects. Handles all CSteganoWindow events
 * and proceses them using CSteganoManager and CSteganoExecutor.
 * Connects to signals from CSteganoExecutor to get results from calling CSteganoMethod.
 */
class CApplication : public QApplication
{
    Q_OBJECT
public:
    explicit CApplication(int & argc, char ** argv);
signals:

public slots:
    /**
     * @brief Implements response to clicking "Encrypt" button.
     */
    void onEncryptButtonClicked();

    /**
     * @brief Implements response to clicking "Decrypt" button.
     */
    void onDecryptButtonClicked();

    /**
     * @brief Implements response to clicking "Propose" button.
     */
    void onProposeButtonClicked();
    /**
     * @brief Implements response to clicking "Preview" button.
     */
    void onPreviewButtonClicked();

    /**
     * @brief Implements response to choosing SteganoMethod in UI
     * @param Id choosed method's id
     */
    void onSteganoMethodChoosen(int Id);

    /**
     * @brief onEncryptFinished
     * @param IsSuccess whether encryption method succeded or not
     */
    void onEncryptFinished(bool IsSuccess);

    /**
     * @brief onDecryptFinished
     * @param IsSuccess whether decryption method succeded or not
     */
    void onDecryptFinished(bool IsSuccess);

    /**
     * @brief onDecryptFinished
     * @param IsSuccess  whether decryption method succeded or not
     * @param DecryptedData Text data to be displayed
     */
    void onDecryptFinished(bool IsSuccess, QString DecryptedData);

    /**
     * @brief Constains error message which should be displayed to the user
     * @param message message content
     */
    void onErrorOccurred(QString message);

    /**
     * @brief Contains a list of arguments which should be passed to displayed widget
     * @param args list of arguments
     */
    void onProposed(PArgsList args);

    /**
     * @brief Implements response to clicking "open file button" when user wants to encrypt data
     */
    void onOpenFileEncryptButtonClicked();

    /**
     * @brief Implements response to clicking "open file button" when user wants to decrypt data
     */
    void onOpenFileDecryptButtonClicked();

    /**
     * @brief Implements response to clicking "save file button" when user wants to encrypt data
     */
    void onSaveFileEncryptButtonClicked();

private:
    /**
     * @brief Inits communication with window.
     *
     * Connects required signals and slots, adds widget to be displayed, adds list of methods.
     */
    void configureWindow();

    /**
     * @brief Inits communication with executor: connects required signals and slots
     */
    void configureExecutor();

    CSteganoWindow m_Window;
    CSteganoExecutor m_Executor;
    PByteArray m_DecryptedData;
    bool m_WasDataToSaveAFile;
    int m_ChoosenMethodId;
};
