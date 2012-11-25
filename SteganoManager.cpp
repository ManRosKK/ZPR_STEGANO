#include "SteganoManager.h"
#include "SteganoException.h"

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

int CSteganoManager::registerSteganoMethod(PCreateMethodFunc methodCreator, PCreateWidgetFunc widgetCreator, QString name)
{
    if ( m_steganoNames.contains( name ) ) 
        throw CSteganoException("Method already exists");

    m_steganoNames.push_back(name);
    m_steganoProducts.push_back( std::pair< PCreateMethodFunc, PCreateWidgetFunc> (methodCreator,widgetCreator) );

    return m_counter++;
}
PMethodList CSteganoManager::getSteganoMethodList()
{
    PMethodList list( &QList< std::pair<int,QString> >()  );

    for( int i = 0; i < m_counter; i++ )
        list->push_back( std::pair<int,QString>( i, m_steganoNames[i]) );

    return list;
}
int CSteganoManager::m_counter = 0;
