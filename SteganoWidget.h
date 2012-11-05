#pragma once

#include <QWidget>

typedef QList<QVariant> ArgsList;
typedef QSharedPointer<ArgsList> PArgsList;

class CSteganoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CSteganoWidget(QWidget *parent = 0);
    virtual PArgsList getArgsList() = 0;
signals:
    
public slots:
    
};
