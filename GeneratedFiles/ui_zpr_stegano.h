/********************************************************************************
** Form generated from reading UI file 'zpr_stegano.ui'
**
** Created: Thu 1. Nov 00:04:57 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ZPR_STEGANOClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ZPR_STEGANOClass)
    {
        if (ZPR_STEGANOClass->objectName().isEmpty())
            ZPR_STEGANOClass->setObjectName(QString::fromUtf8("ZPR_STEGANOClass"));
        ZPR_STEGANOClass->resize(600, 400);
        menuBar = new QMenuBar(ZPR_STEGANOClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        ZPR_STEGANOClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ZPR_STEGANOClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        ZPR_STEGANOClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ZPR_STEGANOClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
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
    } // retranslateUi

};

namespace Ui {
    class ZPR_STEGANOClass: public Ui_ZPR_STEGANOClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZPR_STEGANO_H
