#pragma once
#include <exception>
#include <QString>

class CSteganoException :
    public std::exception
{
public:
    CSteganoException(void);
    CSteganoException(const char* Message):m_message(Message){}
    virtual QString getMessage();
    virtual ~CSteganoException(void) throw();
private:
    QString m_message;
};

