#pragma once
#include <exception>
#include <QString>
class CSteganoException :
    public std::exception
{
    QString m_message;
public:
    CSteganoException(void);
    CSteganoException(const char* message):m_message(message){}
    virtual ~CSteganoException(void);
};

