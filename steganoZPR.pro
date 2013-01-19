#-------------------------------------------------
#
# Project created by QtCreator 2013-01-16T00:05:29
#
#-------------------------------------------------

QT       += core gui

TARGET = steganoZPR
TEMPLATE = app


SOURCES += \
    SteganoWindow.cpp \
    SteganoWidget.cpp \
    SteganoPreview.cpp \
    SteganoNonCheckedWidget.cpp \
    SteganoNonCheckedMethod.cpp \
    SteganoMethod.cpp \
    SteganoManager.cpp \
    SteganoExecutor.cpp \
    SteganoException.cpp \
    SteganoBitsWidget.cpp \
    SteganoBitsMethod.cpp \
    main.cpp \
    Application.cpp


HEADERS  += \
    SteganoWindow.h \
    SteganoWidget.h \
    SteganoTypes.h \
    SteganoPreview.h \
    SteganoNonCheckedWidget.h \
    SteganoNonCheckedMethod.h \
    SteganoMethod.h \
    SteganoManager.h \
    SteganoExecutor.h \
    SteganoException.h \
    SteganoBitsWidget.h \
    SteganoBitsMethod.h \
    BitmapHeader.h \
    Application.h


FORMS += \
    zpr_stegano.ui \
    Steganopreview.ui


OTHER_FILES +=

RESOURCES +=
