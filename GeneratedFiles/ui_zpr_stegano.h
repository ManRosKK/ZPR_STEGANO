/********************************************************************************
** Form generated from reading UI file 'zpr_stegano.ui'
**
** Created: Tue 11. Dec 22:26:17 2012
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
    QVBoxLayout *EncryptLayout;
    QLabel *label_2;
    QPushButton *saveFileEncryptButton;
    QLabel *saveFileEncryptLabel;
    QRadioButton *fileRadioEncrypt;
    QPushButton *openDataFileEncryptButton;
    QLabel *openDataFileEncryptLabel;
    QRadioButton *textRadioEncrypt;
    QTextEdit *textEditEncrypt;
    QPushButton *encryptButton;
    QVBoxLayout *DecryptLayout;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_4;
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
        ZPR_STEGANOClass->resize(617, 702);
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
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        EncryptLayout = new QVBoxLayout();
        EncryptLayout->setSpacing(6);
        EncryptLayout->setObjectName(QString::fromUtf8("EncryptLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        EncryptLayout->addWidget(label_2);

        saveFileEncryptButton = new QPushButton(centralWidget);
        saveFileEncryptButton->setObjectName(QString::fromUtf8("saveFileEncryptButton"));

        EncryptLayout->addWidget(saveFileEncryptButton);

        saveFileEncryptLabel = new QLabel(centralWidget);
        saveFileEncryptLabel->setObjectName(QString::fromUtf8("saveFileEncryptLabel"));
        saveFileEncryptLabel->setMaximumSize(QSize(16777215, 20));

        EncryptLayout->addWidget(saveFileEncryptLabel);

        fileRadioEncrypt = new QRadioButton(centralWidget);
        fileRadioEncrypt->setObjectName(QString::fromUtf8("fileRadioEncrypt"));

        EncryptLayout->addWidget(fileRadioEncrypt);

        openDataFileEncryptButton = new QPushButton(centralWidget);
        openDataFileEncryptButton->setObjectName(QString::fromUtf8("openDataFileEncryptButton"));

        EncryptLayout->addWidget(openDataFileEncryptButton);

        openDataFileEncryptLabel = new QLabel(centralWidget);
        openDataFileEncryptLabel->setObjectName(QString::fromUtf8("openDataFileEncryptLabel"));
        openDataFileEncryptLabel->setMaximumSize(QSize(16777215, 20));

        EncryptLayout->addWidget(openDataFileEncryptLabel);

        textRadioEncrypt = new QRadioButton(centralWidget);
        textRadioEncrypt->setObjectName(QString::fromUtf8("textRadioEncrypt"));

        EncryptLayout->addWidget(textRadioEncrypt);

        textEditEncrypt = new QTextEdit(centralWidget);
        textEditEncrypt->setObjectName(QString::fromUtf8("textEditEncrypt"));
        textEditEncrypt->setMaximumSize(QSize(16777215, 60));

        EncryptLayout->addWidget(textEditEncrypt);

        encryptButton = new QPushButton(centralWidget);
        encryptButton->setObjectName(QString::fromUtf8("encryptButton"));

        EncryptLayout->addWidget(encryptButton);


        horizontalLayout->addLayout(EncryptLayout);

        DecryptLayout = new QVBoxLayout();
        DecryptLayout->setSpacing(6);
        DecryptLayout->setObjectName(QString::fromUtf8("DecryptLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        DecryptLayout->addWidget(label_3);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        DecryptLayout->addWidget(label);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        DecryptLayout->addWidget(label_4);

        fileRadioDecrypt = new QRadioButton(centralWidget);
        fileRadioDecrypt->setObjectName(QString::fromUtf8("fileRadioDecrypt"));

        DecryptLayout->addWidget(fileRadioDecrypt);

        openDataFileDecryptButton = new QPushButton(centralWidget);
        openDataFileDecryptButton->setObjectName(QString::fromUtf8("openDataFileDecryptButton"));

        DecryptLayout->addWidget(openDataFileDecryptButton);

        openDataFileDecryptLabel = new QLabel(centralWidget);
        openDataFileDecryptLabel->setObjectName(QString::fromUtf8("openDataFileDecryptLabel"));
        openDataFileDecryptLabel->setMaximumSize(QSize(16777215, 20));

        DecryptLayout->addWidget(openDataFileDecryptLabel);

        textRadioDecrypt = new QRadioButton(centralWidget);
        textRadioDecrypt->setObjectName(QString::fromUtf8("textRadioDecrypt"));

        DecryptLayout->addWidget(textRadioDecrypt);

        textEditDecrypt = new QTextEdit(centralWidget);
        textEditDecrypt->setObjectName(QString::fromUtf8("textEditDecrypt"));
        textEditDecrypt->setMaximumSize(QSize(16777215, 60));

        DecryptLayout->addWidget(textEditDecrypt);

        decryptButton = new QPushButton(centralWidget);
        decryptButton->setObjectName(QString::fromUtf8("decryptButton"));

        DecryptLayout->addWidget(decryptButton);


        horizontalLayout->addLayout(DecryptLayout);


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
        openFileButton->setText(QApplication::translate("ZPR_STEGANOClass", "openFile", 0, QApplication::UnicodeUTF8));
        openFileLabel->setText(QApplication::translate("ZPR_STEGANOClass", "choosenFile", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ZPR_STEGANOClass", "ENCRYPT", 0, QApplication::UnicodeUTF8));
        saveFileEncryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "saveEncrypt", 0, QApplication::UnicodeUTF8));
        saveFileEncryptLabel->setText(QApplication::translate("ZPR_STEGANOClass", "filepath to save encryption", 0, QApplication::UnicodeUTF8));
        fileRadioEncrypt->setText(QApplication::translate("ZPR_STEGANOClass", "useFilepathBelow", 0, QApplication::UnicodeUTF8));
        openDataFileEncryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "openFileToEncryption", 0, QApplication::UnicodeUTF8));
        openDataFileEncryptLabel->setText(QApplication::translate("ZPR_STEGANOClass", "filepath to save encryption", 0, QApplication::UnicodeUTF8));
        textRadioEncrypt->setText(QApplication::translate("ZPR_STEGANOClass", "Use TextBox", 0, QApplication::UnicodeUTF8));
        encryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "encrypt", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ZPR_STEGANOClass", "DECRYPT", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_4->setText(QString());
        fileRadioDecrypt->setText(QApplication::translate("ZPR_STEGANOClass", "useFilepathBelow", 0, QApplication::UnicodeUTF8));
        openDataFileDecryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "openFileToDecryption", 0, QApplication::UnicodeUTF8));
        openDataFileDecryptLabel->setText(QApplication::translate("ZPR_STEGANOClass", "filepath to save decryption", 0, QApplication::UnicodeUTF8));
        textRadioDecrypt->setText(QApplication::translate("ZPR_STEGANOClass", "Use TextBox", 0, QApplication::UnicodeUTF8));
        decryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "decrypt", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZPR_STEGANOClass: public Ui_ZPR_STEGANOClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZPR_STEGANO_H
