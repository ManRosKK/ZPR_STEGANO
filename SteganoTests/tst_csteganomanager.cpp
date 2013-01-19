#include "SteganoManager.h"
#include "Application.h"
#include "tst_csteganomanager.h"
#include <QTest>
#include "SteganoTypes.h"
#include "SteganoMethod.h"
#include "SteganoWidget.h"

class CSteganoTestMethod :
    public CSteganoMethod
{
    Q_OBJECT
public:
    CSteganoTestMethod(void)
    {

    }

    CSteganoTestMethod(const CSteganoBitsMethod&)
    {

    }

    virtual ~CSteganoBitsMethod(void)
    {

    }

    static PSteganoMethod createSteganoMethod()
    {

    }

    virtual void encrypt(QString, QString, QString, PArgsList)
    {

    }

    virtual void decrypt(QString, QString, PArgsList)
    {

    }

    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList)
    {

    }

    virtual void makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList)
    {

    }

    virtual int evaluate(PArgsList,int)
    {

    }

    virtual int evaluate(PArgsList,QString)
    {

    }

    virtual PSteganoMethod clone()
    {

    }

    virtual QString getName()
    {
        return QString("test");
    }

    virtual QString getSupportedTypesToEncrypt()
    {

    }

    virtual QString getSupportedTypesToDecrypt()
    {

    }

private:
};


tst_CSteganoManager::tst_CSteganoManager(QObject *parent) :
    QObject(parent)
{
}

void tst_CSteganoManager::testCase1()
{

    CSteganoManager* object = &CSteganoManager::getInstance();
    QVERIFY(object!=NULL);
    object->registerSteganoMethod(new )
}
