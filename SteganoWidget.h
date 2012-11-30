#pragma once
#include <QWidget>
#include "SteganoTypes.h"


class CSteganoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CSteganoWidget(QWidget *parent = 0);
    CSteganoWidget(const CSteganoWidget&);
    virtual PArgsList getArgsList() = 0;
    virtual PSteganoWidget clone() = 0;
signals:
    
public slots:
    
};
