#-------------------------------------------------
#
# Project created by QtCreator 2013-01-19T14:26:35
#
#-------------------------------------------------

QT       += core gui
CONFIG += qtestlib
TARGET = SteganoTests
TEMPLATE = app


SOURCES += main.cpp \
    tst_csteganomanager.cpp \
    ../SteganoWindow.cpp \
    ../SteganoWidget.cpp \
    ../SteganoPreview.cpp \
    ../SteganoNonCheckedWidget.cpp \
    ../SteganoNonCheckedMethod.cpp \
    ../SteganoMethod.cpp \
    ../SteganoManager.cpp \
    ../SteganoExecutor.cpp \
    ../SteganoException.cpp \
    ../SteganoBitsWidget.cpp \
    ../SteganoBitsMethod.cpp \
    ../Application.cpp


HEADERS  += \
    ../SteganoWindow.h \
    ../SteganoWidget.h \
    ../SteganoTypes.h \
    ../SteganoPreview.h \
    ../SteganoNonCheckedWidget.h \
    ../SteganoNonCheckedMethod.h \
    ../SteganoMethod.h \
    ../SteganoManager.h \
    ../SteganoExecutor.h \
    ../SteganoException.h \
    ../SteganoBitsWidget.h \
    ../SteganoBitsMethod.h \
    ../BitmapHeader.h \
    ../Application.h \
    tst_csteganomanager.h

FORMS    += \
    ../zpr_stegano.ui \
    ../Steganopreview.ui
