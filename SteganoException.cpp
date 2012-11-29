#include "SteganoException.h"


CSteganoException::CSteganoException(void)
{
}

CSteganoException::~CSteganoException(void) throw()
{
}

QString CSteganoException::getMessage()
{
    return m_message;
}
