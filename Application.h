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
    
private:
    ZPR_STEGANO m_Window;
    CSteganoExecutor m_Executor;
};
