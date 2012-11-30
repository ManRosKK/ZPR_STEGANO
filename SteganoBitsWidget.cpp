#include "SteganoBitsWidget.h"
#include <QLayout>
#include <QLabel>
#include <QBitArray>
CSteganoBitsWidget::CSteganoBitsWidget(void)
{
    QVBoxLayout *VerticalLayout = new QVBoxLayout(this);
    QLabel* Label = new QLabel(this);
    Label->setText(QString::fromLocal8Bit("Koczo rz¹dzi: "));
    VerticalLayout->addWidget(Label);
    setLayout(VerticalLayout);
}

CSteganoBitsWidget::~CSteganoBitsWidget(void)
{
}

PSteganoWidget CSteganoBitsWidget::createSteganoBitsWidget()
{
    return PSteganoWidget(new CSteganoBitsWidget());
}

PArgsList CSteganoBitsWidget::getArgsList()
{

    PArgsList pArgsList(new ArgsList());
    QBitArray Array(24);
    Array.fill(true,0,16);
    pArgsList->append(Array);
    return pArgsList;
}
