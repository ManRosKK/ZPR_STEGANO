#ifndef TST_CSTEGANOMANAGER_H
#define TST_CSTEGANOMANAGER_H

#include <QObject>
#include "./../SteganoMethod.h"
typedef QSharedPointer<CSteganoMethod> PSteganoMethod ;
class CSteganoTestMethod :
    public CSteganoMethod
{
    Q_OBJECT
public:

  CSteganoTestMethod(void){}
  CSteganoTestMethod(QString tmp){name = tmp;}
  CSteganoTestMethod(const CSteganoTestMethod& cp){this->name = cp.name;}
    virtual ~CSteganoTestMethod(void){}

  static PSteganoMethod createSteganoMethod(){return PSteganoMethod(NULL);}
    virtual void encrypt(QString, QString, QString, PArgsList);
    virtual void decrypt(QString, QString, PArgsList);
    virtual void makePreview(QString ImageFilepath,QString DataFilePath, PArgsList pArgsList);
    virtual void makeProposition(QString ImageFilepath, unsigned int ByteCount, PArgsList pArgsList);
    virtual int evaluate(PArgsList,int);
    virtual int evaluate(PArgsList,QString);
    virtual PSteganoMethod clone();
    virtual QString getName();
    virtual QString getSupportedTypesToEncrypt();
    virtual QString getSupportedTypesToDecrypt();

private:
    QString name;
};

class tst_CSteganoManager : public QObject
{
    Q_OBJECT
public:
    explicit tst_CSteganoManager(QObject *parent = 0);
    
signals:
    
private slots:
    void testCase1();  // testing register function

    void testCase2(); //  testing getSupported
};

#endif // TST_CSTEGANOMANAGER_H
