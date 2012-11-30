#include "zpr_stegano.h"
#include <QFileDialog>
#include <QtGlobal>
#include <QDebug>
#include <QMessageBox>

ZPR_STEGANO::ZPR_STEGANO(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
    ui.encryptButton->setText("Encrypt!");
    ui.decryptButton->setText("Decrypt!");
    ui.openFileButton->setText("Open File");
    ui.saveFileButton->setText("Save File to..");
    ui.progressBar->setMinimum(0);
    ui.progressBar->setMaximum(100);
    ui.progressBar->setValue(20);

    connect(ui.encryptButton, SIGNAL(clicked()), this, SIGNAL(encryptButtonClicked()));
    connect(ui.decryptButton, SIGNAL(clicked()), this, SIGNAL(decryptButtonClicked()));
    connect(ui.openFileButton, SIGNAL(clicked()), this, SLOT(openFileButtonClicked()));
    connect(ui.saveFileButton, SIGNAL(clicked()), this, SLOT(saveFileButtonClicked()));
    connect(ui.comboBox,SIGNAL(activated(int)),this,SIGNAL(steganoMethodChoosen(int)));
}

ZPR_STEGANO::~ZPR_STEGANO()
{

}
void ZPR_STEGANO::setWidget(PSteganoWidget pWidget)
{
    //remove all widgets
    QLayoutItem *pItem;
    while ((pItem = ui.methodWidgetLayout->takeAt(0)) != 0);

    m_pMethodWidget = pWidget;
    m_pMethodWidget->setParent(ui.centralWidget);
    ui.methodWidgetLayout->addWidget(m_pMethodWidget.data());
}

PArgsList ZPR_STEGANO::getArgsListFromWidget()
{
    return m_pMethodWidget->getArgsList();
}

void ZPR_STEGANO::setStegonoMethodsList(PMethodList pMethodList)
{
    std::pair<int,QString> i;
    foreach(i, *pMethodList)
    {
        ui.comboBox->addItem(i.second,i.first);
    }
}


void ZPR_STEGANO::updateProgress(int Value)
{
    ui.progressBar->setValue(Value);
}

void ZPR_STEGANO::onEncryptFinished(void)
{

}

void ZPR_STEGANO::onDecryptFinished(void)
{

}

void ZPR_STEGANO::displayPreview(PImage)
{

}

void ZPR_STEGANO::showMessageBox(QString Message, QMessageBox::Icon MessageBoxIcon)
{
    QMessageBox MsgBox(this);
    //set messagebox proporties
    MsgBox.setText(Message);
    MsgBox.setIcon(MessageBoxIcon);
    MsgBox.setWindowTitle("     \n");
    //disable icon on title bar of the message box
    MsgBox.setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint);

    MsgBox.exec();
}

void ZPR_STEGANO::saveFileButtonClicked()
{
    QString FileName = QFileDialog::getSaveFileName(this,
        tr("Save Image to..."), QString(), tr("Image Files (*.png *.jpg *.bmp)"));

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        ui.saveFilepathLabel->setText(FileName);
        emit saveFilepathChanged(FileName);
    }
}

void ZPR_STEGANO::openFileButtonClicked()
{
    QString FileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QString(), tr("Image Files (*.png *.jpg *.bmp)"));

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        ui.openFileLabel->setText(FileName);
        emit imageFilepathChanged(FileName);
    }
}

