#include "SteganoManager.h"
#include "SteganoException.h"
#include "SteganoBitsMethod.h"
#include "SteganoBitsWidget.h"

CSteganoManager::CSteganoManager(void)
{
    registerSteganoMethod(PSteganoMethod(new CSteganoBitsMethod()),
                          PSteganoWidget(new CSteganoBitsWidget()));
    registerSteganoMethod(PSteganoMethod(new CSteganoBitsMethod()),
                          PSteganoWidget(new CSteganoBitsWidget()));
}

CSteganoManager::~CSteganoManager(void)
{
}

CSteganoManager& CSteganoManager::getInstance()
{
    static CSteganoManager instance;
    return instance;
}

int CSteganoManager::registerSteganoMethod(PSteganoMethod pMethodObject, PSteganoWidget pWidgetObject)
{
    m_steganoProducts.push_back( std::pair<PSteganoMethod, PSteganoWidget>(pMethodObject->clone(), pWidgetObject->clone()));
    return m_counter++;
}

PMethodList CSteganoManager::getSteganoMethodList()
{
    PMethodList list(new QList< std::pair<int,QString> >());

    for( int i = 0; i < m_counter; i++ )
        list->push_back( std::pair<int,QString>( i, m_steganoProducts[i].first->getName()) );
    return list;
}

PSteganoMethod CSteganoManager::produceSteganoMethod( int id )
{
    if( id >= m_counter)
        throw CSteganoException("Method not registered");
    return m_steganoProducts[id].first->clone();
}

PSteganoWidget CSteganoManager::produceSteganoWidget( int id )
{
    if( id >= m_counter)
        throw CSteganoException("Widget not registered");
    return m_steganoProducts[id].second->clone();
}

int CSteganoManager::m_counter = 0;
