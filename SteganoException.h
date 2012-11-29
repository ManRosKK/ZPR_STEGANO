#pragma once
#include <exception>
#include <QString>

class CSteganoException :
    public std::exception
{
public:
    CSteganoException(void);
    CSteganoException(const char* message):m_message(message){}
    virtual QString getMessage();
    virtual ~CSteganoException(void) throw();
private:
    QString m_message;
};

