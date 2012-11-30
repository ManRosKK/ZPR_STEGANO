#include "SteganoBitsWidget.h"
#include <QLayout>
#include <QLabel>
#include <QBitArray>
#include <QDebug>
#include <QCheckBox>

CSteganoBitsWidget::CSteganoBitsWidget(void)
{
    configureUI();
}

CSteganoBitsWidget::CSteganoBitsWidget(const CSteganoBitsWidget&)
{
    configureUI();
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
    unsigned int mask = 0;
    for(int i=0;i<c_BitsDepth;++i)
    {
        if(m_CheckBox[i]->isChecked())
        {
            mask |= (1 << (c_BitsDepth-i-1));
        }
    }
    pArgsList->append(mask);
    qDebug()<<"the mask is: RGB =>"<< ((mask>>16)&0xFF) << ((mask>>8)&0xFF) << (mask&0xFF);
    return pArgsList;
}

PSteganoWidget CSteganoBitsWidget::clone()
{
    return PSteganoWidget(new CSteganoBitsWidget(*this));
}

void CSteganoBitsWidget::configureUI()
{
    QVBoxLayout *VerticalLayout = new QVBoxLayout(this);

    QLabel* Label = new QLabel();
    Label->setText(QString::fromLocal8Bit("Set desired RGB bits to hide data in there: "));
    QLabel* RedLabel = new QLabel();
    RedLabel->setText(QString::fromLocal8Bit("Red: "));
    QLabel* GreenLabel = new QLabel();
    GreenLabel->setText(QString::fromLocal8Bit("Green: "));
    QLabel* BlueLabel = new QLabel();
    BlueLabel->setText(QString::fromLocal8Bit("Blue: "));

    QHBoxLayout* HorizontalLayoutRed = new QHBoxLayout();
    QHBoxLayout* HorizontalLayoutGreen = new QHBoxLayout();
    QHBoxLayout* HorizontalLayoutBlue = new QHBoxLayout();

    for(int i=0;i<c_BitsDepth;++i)
    {
        m_CheckBox[i] = new QCheckBox();
    }
    const int c_BitsDepthPerChannel = 8;
    for(int i=0;i<c_BitsDepthPerChannel;++i)
    {
        HorizontalLayoutRed->addWidget(m_CheckBox[i]);
        HorizontalLayoutGreen->addWidget(m_CheckBox[c_BitsDepthPerChannel + i]);
        HorizontalLayoutBlue->addWidget(m_CheckBox[2*c_BitsDepthPerChannel + i]);
    }

    // add elements to the main layout
    VerticalLayout->addWidget(Label);
    VerticalLayout->addWidget(RedLabel);
    VerticalLayout->addLayout(HorizontalLayoutRed);
    VerticalLayout->addWidget(GreenLabel);
    VerticalLayout->addLayout(HorizontalLayoutGreen);
    VerticalLayout->addWidget(BlueLabel);
    VerticalLayout->addLayout(HorizontalLayoutBlue);
}
