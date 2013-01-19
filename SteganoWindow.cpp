#include "SteganoWindow.h"
#include <QFileDialog>
#include <QtGlobal>
#include <QDebug>
#include <QMessageBox>
#include "SteganoPreview.h"
CSteganoWindow::CSteganoWindow(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags),
      m_IsFileRadioEncryptChoosen(false),
      m_IsFileRadioDecryptChoosen(false)
{
	ui.setupUi(this);
    ui.encryptButton->setText("Encrypt!");
    ui.decryptButton->setText("Decrypt!");
    ui.progressBar->setMinimum(0);
    ui.progressBar->setMaximum(100);
    ui.progressBar->setValue(100);
    ui.progressBar->hide();

    ui.openFileEncryptLabel->setText(QString());
    ui.openFileDecryptLabel->setText(QString());
    ui.saveFileEncryptLabel->setText(QString());
    ui.openDataFileDecryptLabel->setText(QString());
    ui.openDataFileEncryptLabel->setText(QString());

    QButtonGroup* ButtonGroupEncrypt = new QButtonGroup(this);
    ButtonGroupEncrypt->addButton(ui.textRadioEncrypt);
    ButtonGroupEncrypt->addButton(ui.fileRadioEncrypt);

    QButtonGroup* ButtonGroupDecrypt = new QButtonGroup(this);
    ButtonGroupDecrypt->addButton(ui.textRadioDecrypt);
    ButtonGroupDecrypt->addButton(ui.fileRadioDecrypt);

    ui.textRadioDecrypt->setChecked(true);
    ui.textRadioEncrypt->setChecked(true);

    connect(ui.encryptButton, SIGNAL(clicked()), this, SIGNAL(encryptButtonClicked()));
    connect(ui.decryptButton, SIGNAL(clicked()), this, SIGNAL(decryptButtonClicked()));
    connect(ui.openFileEncryptButton, SIGNAL(clicked()), this, SIGNAL(openFileEncryptButtonClicked()));
    connect(ui.openFileDecryptButton, SIGNAL(clicked()), this, SIGNAL(openFileDecryptButtonClicked()));
    connect(ui.saveFileEncryptButton, SIGNAL(clicked()), this, SIGNAL(saveFileEncryptButtonClicked()));
    connect(ui.proposeButton, SIGNAL(clicked()), this, SIGNAL(proposeButtonClicked()));
    connect(ui.previewButton, SIGNAL(clicked()), this, SIGNAL(previewButtonClicked()));
    connect(ui.openDataFileEncryptButton, SIGNAL(clicked()), this, SLOT(onEncryptDataOpenFile()));
    connect(ui.openDataFileDecryptButton, SIGNAL(clicked()), this, SLOT(onDecryptDataOpenFile()));
    connect(ui.comboBox, SIGNAL(activated(int)), this, SLOT(onComboBoxActivated(int)));
    connect(ui.fileRadioEncrypt, SIGNAL(toggled(bool)), this, SLOT(onEncryptRadioChecked(bool)));
    connect(ui.fileRadioDecrypt, SIGNAL(toggled(bool)), this, SLOT(onDecryptRadioChecked(bool)));
}

CSteganoWindow::~CSteganoWindow()
{
    //empty body
}

void CSteganoWindow::setWidget(PSteganoWidget pWidget)
{
    //remove all widgets
    QLayoutItem *pItem;
    while ((pItem = ui.methodWidgetLayout->takeAt(0)) != 0);

    m_pMethodWidget = pWidget;
    m_pMethodWidget->setParent(ui.centralWidget);
    ui.methodWidgetLayout->addWidget(m_pMethodWidget.data());
}

PArgsList CSteganoWindow::getArgsListFromWidget()
{
    return m_pMethodWidget->getArgsList();
}

void CSteganoWindow::setStegonoMethodsList(PMethodList pMethodList)
{
    std::pair<int,QString> i;
    foreach(i, *pMethodList)
    {
        ui.comboBox->addItem(i.second,i.first);
    }
}

QString CSteganoWindow::getEncryptImageFilepath()
{
    return m_EncryptImageFilepath;
}

QString CSteganoWindow::getDecryptImageFilepath()
{
    return m_DecryptImageFilepath;
}

QString CSteganoWindow::getSaveFilepath()
{
    return m_SaveFilepath;
}

QString CSteganoWindow::getEncryptFileToHide()
{
    return m_FileToHideEncryptFilepath;
}

QString CSteganoWindow::getDecryptFileToHide()
{
    return m_FileToHideDecryptFilepath;
}

bool CSteganoWindow::getEncryptDataSource()
{
    return m_IsFileRadioEncryptChoosen;
}

bool CSteganoWindow::getDecryptDataSource()
{
    return m_IsFileRadioDecryptChoosen;
}

QString CSteganoWindow::getTextToHide()
{
    return ui.textEditEncrypt->document()->toPlainText();
}

void CSteganoWindow::setWidgetArgs(PArgsList pArgs)
{
    changeUIblocking(false);
    m_pMethodWidget->setArgsList(pArgs);
}

void CSteganoWindow::updateProgress(int Value)
{
    ui.progressBar->setValue(Value);
    if(Value >= 100)
    {
        ui.progressBar->hide();
    }
    else
    {
        ui.progressBar->show();
    }
}

void CSteganoWindow::onEncryptFinished(void)
{

}

void CSteganoWindow::onDecryptFinished(void)
{

}

void CSteganoWindow::displayPreview(PImage pImage)
{
    changeUIblocking(false);
    if(!pImage.isNull())
    {
        CSteganoPreview* preview =(new CSteganoPreview(this));
        //pPreview->setParent(this);
        preview->setWindowTitle("Preview");

        preview->SetImage(*pImage);
        preview->exec();

        delete preview;
    }
    ui.progressBar->setValue(100);
}

void CSteganoWindow::showMessageBox(QString Message, QMessageBox::Icon MessageBoxIcon)
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

void CSteganoWindow::showOpenFileEncryptDialog(QString SupportedTypes)
{
    QString FileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QString(), SupportedTypes);

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_EncryptImageFilepath = FileName;
        m_SaveFilepath = QString();
        ui.saveFileEncryptLabel->setText(QString());
        ui.openFileEncryptLabel->setText(FileName);
    }
}

void CSteganoWindow::showOpenFileDecryptDialog(QString SupportedTypes)
{
    QString FileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), QString(), SupportedTypes);

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_DecryptImageFilepath = FileName;
        ui.openFileDecryptLabel->setText(FileName);
    }
}

void CSteganoWindow::showSaveFileEncryptDialog(QString SupportedTypes)
{
    QString FileName = QFileDialog::getSaveFileName(this,
        tr("Save Image to..."), QString(), SupportedTypes);

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_SaveFilepath = FileName;
        ui.saveFileEncryptLabel->setText(FileName);
    }
}

void CSteganoWindow::onEncryptRadioChecked(bool IsFileChecked)
{
    m_IsFileRadioEncryptChoosen = IsFileChecked;
}

void CSteganoWindow::onDecryptRadioChecked(bool IsFileChecked)
{
    m_IsFileRadioDecryptChoosen = IsFileChecked;
}

void CSteganoWindow::onEncryptDataOpenFile()
{
    QString FileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), QString());

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_FileToHideEncryptFilepath = FileName;
        ui.openDataFileEncryptLabel->setText(FileName);
        ui.fileRadioEncrypt->setChecked(true);
    }
}

void CSteganoWindow::onDecryptDataOpenFile()
{
    QString FileName = QFileDialog::getSaveFileName(this,
        tr("Save data to..."), QString());

    //check whether QFileDialog returned a valid filename
    if(FileName.length() != 0)
    {
        m_FileToHideDecryptFilepath = FileName;
        ui.openDataFileDecryptLabel->setText(FileName);
        ui.fileRadioDecrypt->setChecked(true);
    }
}
void CSteganoWindow::changeProposeButtonVisibility(bool status)
{
    if(status) 
        showProposeButton();
    else
        hideProposeButton();

}
void  CSteganoWindow::hideProposeButton()
{
    ui.proposeButton->hide();
}
void CSteganoWindow::showProposeButton()
{
    ui.proposeButton->show();
}
void CSteganoWindow::showResultsInTextArea(QString DecryptedData)
{
    ui.textEditDecrypt->setDocument(new QTextDocument(DecryptedData,this));
}

void CSteganoWindow::changeUIblocking(bool ShouldBeBlocked)
{
    bool ShouldBeEnabled = !ShouldBeBlocked;
    ui.comboBox->setEnabled(ShouldBeEnabled);
    ui.encryptButton->setEnabled(ShouldBeEnabled);
    ui.decryptButton->setEnabled(ShouldBeEnabled);
    ui.openFileEncryptButton->setEnabled(ShouldBeEnabled);
    ui.openFileDecryptButton->setEnabled(ShouldBeEnabled);
    ui.saveFileEncryptButton->setEnabled(ShouldBeEnabled);
    ui.openDataFileEncryptButton->setEnabled(ShouldBeEnabled);
    ui.openDataFileDecryptButton->setEnabled(ShouldBeEnabled);
    ui.proposeButton->setEnabled(ShouldBeEnabled);
}

void CSteganoWindow::onComboBoxActivated(int Id)
{
    m_EncryptImageFilepath = QString();
    m_DecryptImageFilepath = QString();
    ui.openFileEncryptLabel->setText(QString());
    ui.openFileDecryptLabel->setText(QString());

    m_SaveFilepath = QString();
    ui.saveFileEncryptLabel->setText(QString());

    emit steganoMethodChoosen(Id);
}

