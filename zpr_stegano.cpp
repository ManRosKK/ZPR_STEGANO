#include "zpr_stegano.h"
#include <QFileDialog>
#include <QtGlobal>
#include <QDebug>
#include <QMessageBox>

ZPR_STEGANO::ZPR_STEGANO(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags),
      m_IsFileRadioEncryptChoosen(false),
      m_IsFileRadioDecryptChoosen(false)
{
	ui.setupUi(this);
    ui.encryptButton->setText("Encrypt!");
    ui.decryptButton->setText("Decrypt!");
    ui.openFileButton->setText("Open File");
    ui.saveFileEncryptButton->setText("Save File to..");
    ui.progressBar->setMinimum(0);
    ui.progressBar->setMaximum(100);
    ui.progressBar->setValue(85);

    connect(ui.encryptButton, SIGNAL(clicked()), this, SIGNAL(encryptButtonClicked()));
    connect(ui.decryptButton, SIGNAL(clicked()), this, SIGNAL(decryptButtonClicked()));
    connect(ui.openFileButton, SIGNAL(clicked()), this, SLOT(openFileButtonClicked()));
    connect(ui.saveFileEncryptButton, SIGNAL(clicked()), this, SLOT(saveFileButtonClicked()));
    connect(ui.openDataFileEncryptButton, SIGNAL(clicked()),this,SLOT(onEncryptDataOpenFile()));
    connect(ui.openDataFileDecryptButton, SIGNAL(clicked()),this,SLOT(onDecryptDataOpenFile()));
    connect(ui.comboBox,SIGNAL(activated(int)),this,SIGNAL(steganoMethodChoosen(int)));
    connect(ui.fileRadioEncrypt,SIGNAL(toggled(bool)),this,SLOT(onEncryptRadioChecked(bool)));
    connect(ui.fileRadioDecrypt,SIGNAL(toggled(bool)),this,SLOT(onDecryptRadioChecked(bool)));
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

QString ZPR_STEGANO::getImageFilepath()
{
    return m_ImageFilepath;
}

QString ZPR_STEGANO::getSaveFilepath()
{
    return m_SaveFilepath;
}

QString ZPR_STEGANO::getEncryptFileToHide()
{
    return m_FileToHideEncryptFilepath;
}

QString ZPR_STEGANO::getDecryptFileToHide()
{
    return m_FileToHideDecryptFilepath;
}

bool ZPR_STEGANO::getEncryptDataSource()
{
    return m_IsFileRadioDecryptChoosen;
}

bool ZPR_STEGANO::getDecryptDataSource()
{
    return m_IsFileRadioDecryptChoosen;
}

QString ZPR_STEGANO::getTextToHide()
{
    return ui.textEditEncrypt->document()->toPlainText();
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
        m_SaveFilepath = FileName;
        ui.saveFileEncryptLabel->setText(FileName);
        emit saveFilepathChanged();
    }
}

void ZPR_STEGANO::openFileButtonClicked()
{
    QString FileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QString(), tr("Image Files (*.png *.jpg *.bmp)"));

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_ImageFilepath = FileName;
        ui.openFileLabel->setText(FileName);
        emit imageFilepathChanged();
    }
}

void ZPR_STEGANO::onEncryptRadioChecked(bool IsFileChecked)
{
    qDebug()<<"radio chcked";
    m_IsFileRadioEncryptChoosen = IsFileChecked;
}

void ZPR_STEGANO::onDecryptRadioChecked(bool IsFileChecked)
{
    m_IsFileRadioDecryptChoosen = IsFileChecked;
}

void ZPR_STEGANO::onEncryptDataOpenFile()
{
    QString FileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), QString());

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_FileToHideEncryptFilepath = FileName; //same atm \/
        ui.openDataFileEncryptLabel->setText(FileName);
        //emit imageFilepathChanged();
    }
}

void ZPR_STEGANO::onDecryptDataOpenFile()
{
    QString FileName = QFileDialog::getSaveFileName(this,
        tr("Save data to"), QString());
    qDebug()<<"asdasd "<<FileName;
    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_FileToHideDecryptFilepath = FileName; //same atm /\
        ui.openDataFileDecryptLabel->setText(FileName);
        //emit imageFilepathChanged();
    }
}

void ZPR_STEGANO::showResultsInTextArea(PByteArray DecryptedData)
{
    QString string(*DecryptedData);
    string.append("");
    ui.textEditDecrypt->setDocument(new QTextDocument(string,this));
}
