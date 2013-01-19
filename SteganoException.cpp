#include "SteganoException.h"


CSteganoException::CSteganoException(void)
{
}

CSteganoException::~CSteganoException(void) throw()
{
}

QString CSteganoException::getMessage()
{
    return QString(m_message);
}
