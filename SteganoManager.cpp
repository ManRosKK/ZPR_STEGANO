#include "SteganoManager.h"


CSteganoManager::CSteganoManager(void)
{
}


CSteganoManager::~CSteganoManager(void)
{
}

CSteganoManager& CSteganoManager::getInstance()
{
    static CSteganoManager instance;
    return instance;
}


int CSteganoManager::m_counter = 0;
