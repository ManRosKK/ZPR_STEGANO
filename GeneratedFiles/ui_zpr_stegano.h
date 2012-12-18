/********************************************************************************
** Form generated from reading UI file 'zpr_stegano.ui'
**
** Created: Tue 18. Dec 16:58:10 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZPR_STEGANO_H
#define UI_ZPR_STEGANO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZPR_STEGANOClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QPushButton *openFileButton;
    QLabel *openFileLabel;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *EncryptLayout;
    QPushButton *saveFileEncryptButton;
    QLabel *saveFileEncryptLabel;
    QGroupBox *groupBox1;
    QVBoxLayout *verticalLayout;
    QRadioButton *fileRadioEncrypt;
    QPushButton *openDataFileEncryptButton;
    QLabel *openDataFileEncryptLabel;
    QRadioButton *textRadioEncrypt;
    QTextEdit *textEditEncrypt;
    QPushButton *encryptButton;
    QGroupBox *Decrypt;
    QVBoxLayout *DecryptLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *fileRadioDecrypt;
    QPushButton *openDataFileDecryptButton;
    QLabel *openDataFileDecryptLabel;
    QRadioButton *textRadioDecrypt;
    QTextEdit *textEditDecrypt;
    QPushButton *decryptButton;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *methodWidgetLayout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ZPR_STEGANOClass)
    {
        if (ZPR_STEGANOClass->objectName().isEmpty())
            ZPR_STEGANOClass->setObjectName(QString::fromUtf8("ZPR_STEGANOClass"));
        ZPR_STEGANOClass->resize(693, 702);
        centralWidget = new QWidget(ZPR_STEGANOClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        openFileButton = new QPushButton(centralWidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        verticalLayout_2->addWidget(openFileButton);

        openFileLabel = new QLabel(centralWidget);
        openFileLabel->setObjectName(QString::fromUtf8("openFileLabel"));
        openFileLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(openFileLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(30);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        EncryptLayout = new QVBoxLayout(groupBox);
        EncryptLayout->setSpacing(6);
        EncryptLayout->setContentsMargins(11, 11, 11, 11);
        EncryptLayout->setObjectName(QString::fromUtf8("EncryptLayout"));
        saveFileEncryptButton = new QPushButton(groupBox);
        saveFileEncryptButton->setObjectName(QString::fromUtf8("saveFileEncryptButton"));

        EncryptLayout->addWidget(saveFileEncryptButton);

        saveFileEncryptLabel = new QLabel(groupBox);
        saveFileEncryptLabel->setObjectName(QString::fromUtf8("saveFileEncryptLabel"));
        saveFileEncryptLabel->setMaximumSize(QSize(16777215, 20));

        EncryptLayout->addWidget(saveFileEncryptLabel);

        groupBox1 = new QGroupBox(groupBox);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        verticalLayout = new QVBoxLayout(groupBox1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        fileRadioEncrypt = new QRadioButton(groupBox1);
        fileRadioEncrypt->setObjectName(QString::fromUtf8("fileRadioEncrypt"));

        verticalLayout->addWidget(fileRadioEncrypt);

        openDataFileEncryptButton = new QPushButton(groupBox1);
        openDataFileEncryptButton->setObjectName(QString::fromUtf8("openDataFileEncryptButton"));

        verticalLayout->addWidget(openDataFileEncryptButton);

        openDataFileEncryptLabel = new QLabel(groupBox1);
        openDataFileEncryptLabel->setObjectName(QString::fromUtf8("openDataFileEncryptLabel"));
        openDataFileEncryptLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(openDataFileEncryptLabel);

        textRadioEncrypt = new QRadioButton(groupBox1);
        textRadioEncrypt->setObjectName(QString::fromUtf8("textRadioEncrypt"));

        verticalLayout->addWidget(textRadioEncrypt);

        textEditEncrypt = new QTextEdit(groupBox1);
        textEditEncrypt->setObjectName(QString::fromUtf8("textEditEncrypt"));
        textEditEncrypt->setMaximumSize(QSize(16777215, 60));

        verticalLayout->addWidget(textEditEncrypt);


        EncryptLayout->addWidget(groupBox1);

        encryptButton = new QPushButton(groupBox);
        encryptButton->setObjectName(QString::fromUtf8("encryptButton"));

        EncryptLayout->addWidget(encryptButton);


        horizontalLayout->addWidget(groupBox);

        Decrypt = new QGroupBox(centralWidget);
        Decrypt->setObjectName(QString::fromUtf8("Decrypt"));
        DecryptLayout = new QVBoxLayout(Decrypt);
        DecryptLayout->setSpacing(6);
        DecryptLayout->setContentsMargins(11, 11, 11, 11);
        DecryptLayout->setObjectName(QString::fromUtf8("DecryptLayout"));
        groupBox_2 = new QGroupBox(Decrypt);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        fileRadioDecrypt = new QRadioButton(groupBox_2);
        fileRadioDecrypt->setObjectName(QString::fromUtf8("fileRadioDecrypt"));

        verticalLayout_3->addWidget(fileRadioDecrypt);

        openDataFileDecryptButton = new QPushButton(groupBox_2);
        openDataFileDecryptButton->setObjectName(QString::fromUtf8("openDataFileDecryptButton"));

        verticalLayout_3->addWidget(openDataFileDecryptButton);

        openDataFileDecryptLabel = new QLabel(groupBox_2);
        openDataFileDecryptLabel->setObjectName(QString::fromUtf8("openDataFileDecryptLabel"));
        openDataFileDecryptLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_3->addWidget(openDataFileDecryptLabel);

        textRadioDecrypt = new QRadioButton(groupBox_2);
        textRadioDecrypt->setObjectName(QString::fromUtf8("textRadioDecrypt"));

        verticalLayout_3->addWidget(textRadioDecrypt);

        textEditDecrypt = new QTextEdit(groupBox_2);
        textEditDecrypt->setObjectName(QString::fromUtf8("textEditDecrypt"));
        textEditDecrypt->setMaximumSize(QSize(16777215, 60));

        verticalLayout_3->addWidget(textEditDecrypt);


        DecryptLayout->addWidget(groupBox_2);

        decryptButton = new QPushButton(Decrypt);
        decryptButton->setObjectName(QString::fromUtf8("decryptButton"));

        DecryptLayout->addWidget(decryptButton);


        horizontalLayout->addWidget(Decrypt);


        verticalLayout_2->addLayout(horizontalLayout);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        methodWidgetLayout = new QVBoxLayout();
        methodWidgetLayout->setSpacing(6);
        methodWidgetLayout->setObjectName(QString::fromUtf8("methodWidgetLayout"));

        verticalLayout_2->addLayout(methodWidgetLayout);

        ZPR_STEGANOClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ZPR_STEGANOClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        ZPR_STEGANOClass->setStatusBar(statusBar);

        retranslateUi(ZPR_STEGANOClass);

        QMetaObject::connectSlotsByName(ZPR_STEGANOClass);
    } // setupUi

    void retranslateUi(QMainWindow *ZPR_STEGANOClass)
    {
        ZPR_STEGANOClass->setWindowTitle(QApplication::translate("ZPR_STEGANOClass", "ZPR_STEGANO", 0, QApplication::UnicodeUTF8));
        openFileButton->setText(QApplication::translate("ZPR_STEGANOClass", "Choose a file to encrypt or decrypt...", 0, QApplication::UnicodeUTF8));
        openFileLabel->setText(QApplication::translate("ZPR_STEGANOClass", "choosenFile", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("ZPR_STEGANOClass", "Encrypt", 0, QApplication::UnicodeUTF8));
        saveFileEncryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "Choose where to save file with hidden data", 0, QApplication::UnicodeUTF8));
        saveFileEncryptLabel->setText(QApplication::translate("ZPR_STEGANOClass", "filepath to save encryption", 0, QApplication::UnicodeUTF8));
        groupBox1->setTitle(QApplication::translate("ZPR_STEGANOClass", "Choose input data source", 0, QApplication::UnicodeUTF8));
        fileRadioEncrypt->setText(QApplication::translate("ZPR_STEGANOClass", "Take data to hide in image from file...", 0, QApplication::UnicodeUTF8));
        openDataFileEncryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "Choose a file with data to be hidden", 0, QApplication::UnicodeUTF8));
        openDataFileEncryptLabel->setText(QApplication::translate("ZPR_STEGANOClass", "Filepath with data to be hidden", 0, QApplication::UnicodeUTF8));
        textRadioEncrypt->setText(QApplication::translate("ZPR_STEGANOClass", "Use TextBox", 0, QApplication::UnicodeUTF8));
        encryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "encrypt", 0, QApplication::UnicodeUTF8));
        Decrypt->setTitle(QApplication::translate("ZPR_STEGANOClass", "Decrypt", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ZPR_STEGANOClass", "Choose output data target", 0, QApplication::UnicodeUTF8));
        fileRadioDecrypt->setText(QApplication::translate("ZPR_STEGANOClass", "Output decrypted data taken from image to file", 0, QApplication::UnicodeUTF8));
        openDataFileDecryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "Choose a file where decrypted data will be written", 0, QApplication::UnicodeUTF8));
        openDataFileDecryptLabel->setText(QApplication::translate("ZPR_STEGANOClass", "Filepath where data will be written", 0, QApplication::UnicodeUTF8));
        textRadioDecrypt->setText(QApplication::translate("ZPR_STEGANOClass", "Use TextBox", 0, QApplication::UnicodeUTF8));
        decryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "decrypt", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZPR_STEGANOClass: public Ui_ZPR_STEGANOClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZPR_STEGANO_H
