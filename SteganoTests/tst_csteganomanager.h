#ifndef TST_CSTEGANOMANAGER_H
#define TST_CSTEGANOMANAGER_H

#include <QObject>

class tst_CSteganoManager : public QObject
{
    Q_OBJECT
public:
    explicit tst_CSteganoManager(QObject *parent = 0);
    
signals:
    
private slots:
    void testCase1();
};

#endif // TST_CSTEGANOMANAGER_H
