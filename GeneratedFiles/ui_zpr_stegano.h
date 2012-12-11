/********************************************************************************
** Form generated from reading UI file 'zpr_stegano.ui'
**
** Created: Wed 5. Dec 19:37:33 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZPR_STEGANOClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBox;
    QPushButton *encryptButton;
    QPushButton *decryptButton;
    QPushButton *openFileButton;
    QLabel *openFileLabel;
    QPushButton *saveFileButton;
    QLabel *saveFilepathLabel;
    QProgressBar *progressBar;
    QVBoxLayout *methodWidgetLayout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ZPR_STEGANOClass)
    {
        if (ZPR_STEGANOClass->objectName().isEmpty())
            ZPR_STEGANOClass->setObjectName(QString::fromUtf8("ZPR_STEGANOClass"));
        ZPR_STEGANOClass->resize(600, 400);
        centralWidget = new QWidget(ZPR_STEGANOClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        encryptButton = new QPushButton(centralWidget);
        encryptButton->setObjectName(QString::fromUtf8("encryptButton"));

        verticalLayout_2->addWidget(encryptButton);

        decryptButton = new QPushButton(centralWidget);
        decryptButton->setObjectName(QString::fromUtf8("decryptButton"));

        verticalLayout_2->addWidget(decryptButton);

        openFileButton = new QPushButton(centralWidget);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        verticalLayout_2->addWidget(openFileButton);

        openFileLabel = new QLabel(centralWidget);
        openFileLabel->setObjectName(QString::fromUtf8("openFileLabel"));
        openFileLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(openFileLabel);

        saveFileButton = new QPushButton(centralWidget);
        saveFileButton->setObjectName(QString::fromUtf8("saveFileButton"));

        verticalLayout_2->addWidget(saveFileButton);

        saveFilepathLabel = new QLabel(centralWidget);
        saveFilepathLabel->setObjectName(QString::fromUtf8("saveFilepathLabel"));
        saveFilepathLabel->setMaximumSize(QSize(16777215, 20));

        verticalLayout_2->addWidget(saveFilepathLabel);

        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(24);

        verticalLayout_2->addWidget(progressBar);

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
        encryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "encrypt", 0, QApplication::UnicodeUTF8));
        decryptButton->setText(QApplication::translate("ZPR_STEGANOClass", "decrypt", 0, QApplication::UnicodeUTF8));
        openFileButton->setText(QApplication::translate("ZPR_STEGANOClass", "openFile", 0, QApplication::UnicodeUTF8));
        openFileLabel->setText(QApplication::translate("ZPR_STEGANOClass", "choosenFile", 0, QApplication::UnicodeUTF8));
        saveFileButton->setText(QApplication::translate("ZPR_STEGANOClass", "save", 0, QApplication::UnicodeUTF8));
        saveFilepathLabel->setText(QApplication::translate("ZPR_STEGANOClass", "filepath to save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ZPR_STEGANOClass: public Ui_ZPR_STEGANOClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZPR_STEGANO_H
