#include "./../SteganoManager.h"
#include "./../Application.h"
#include "tst_csteganomanager.h"
#include <QTest>
#include "./../SteganoException.h"
#include "./../SteganoTypes.h"
#include "./../SteganoMethod.h"
#include "./../SteganoWidget.h"

class CSteganoTestWidget :
    public CSteganoWidget
{
public:
    CSteganoTestWidget(void){}
    CSteganoTestWidget(const CSteganoTestWidget&){}
    virtual ~CSteganoTestWidget(void){}
    static PSteganoWidget createSteganoTestWidget(){}

    virtual PArgsList getArgsList(){}

    virtual void setArgsList(PArgsList){}

    virtual PSteganoWidget clone()
    {
        return PSteganoWidget(new CSteganoTestWidget(*this));
    }

    virtual bool isPropositionsAllowed(){return false;}

private:
};



void CSteganoTestMethod::encrypt(QString, QString, QString, PArgsList){}

void CSteganoTestMethod::decrypt(QString, QString, PArgsList){}

void CSteganoTestMethod::makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList){}

void CSteganoTestMethod::makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList){}

int CSteganoTestMethod::evaluate(PArgsList,int){return 1;}

int CSteganoTestMethod::evaluate(PArgsList,QString){return 1;}

PSteganoMethod CSteganoTestMethod::clone()
{
    return PSteganoMethod(new CSteganoTestMethod(*this));
}
QString CSteganoTestMethod::getName()
{
    return name;
}
QString CSteganoTestMethod::getSupportedTypesToEncrypt(){return QString("jpg");}
QString CSteganoTestMethod::getSupportedTypesToDecrypt(){return QString("png");}

tst_CSteganoManager::tst_CSteganoManager(QObject *parent) :
    QObject(parent)
{
}

void tst_CSteganoManager::testCase1()
{

    CSteganoManager* object = &CSteganoManager::getInstance();

    QVERIFY(object!=NULL);
    PSteganoWidget  tmp = PSteganoWidget(new CSteganoTestWidget());
    int id1 = object->registerSteganoMethod(PSteganoMethod(new CSteganoTestMethod("test1")),tmp );
    QString name = object->produceSteganoMethod(id1)->getName();

    QCOMPARE(name,QString("test1"));

    PMethodList objList2 = object->getSteganoMethodList();

    QCOMPARE(objList2->length(),(1+2) );

    QVERIFY(object->produceSteganoWidget(id1).data() != tmp.data());
    try {
        object->registerSteganoMethod(PSteganoMethod(NULL),tmp );
        QFAIL("Exception not thrown");
    }
    catch (...)
    {
    }

    try {
        object->registerSteganoMethod(PSteganoMethod(NULL),tmp );
        QFAIL("Exception not thrown");
    }
    catch (...)
    {
    }

    bool exceptionSeen = false;
    try {
        object->registerSteganoMethod(PSteganoMethod(NULL),PSteganoWidget(NULL));
    }
    catch (CSteganoException&) {
        exceptionSeen = true;
    }
    QCOMPARE(exceptionSeen, true);
    int id2 = object->registerSteganoMethod(PSteganoMethod(new CSteganoTestMethod("test2")),tmp );
    int id3 = object->registerSteganoMethod(PSteganoMethod(new CSteganoTestMethod("test3")),tmp );
    PMethodList objList = object->getSteganoMethodList();

    QCOMPARE(objList->length(),(3+2) );

    for(int i=0;i<objList->length();i++)
    {
        QCOMPARE(object->produceSteganoMethod(objList->at(0).first)->getName(),objList->at(0).second);

    }
}

void tst_CSteganoManager::testCase2()
{

    CSteganoManager* object = &CSteganoManager::getInstance();

    QVERIFY(object!=NULL);
    PSteganoWidget  tmp = PSteganoWidget(new CSteganoTestWidget());
    int id1 = object->registerSteganoMethod(PSteganoMethod(new CSteganoTestMethod("test1")),tmp );



}
