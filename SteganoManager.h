#pragma once
#include <QSharedPointer>
#include <QImage>
#include <QWidget>
#include "SteganoTypes.h"
#include "SteganoMethod.h"
#include "SteganoWidget.h"
#include "SteganoWidgetMethodPointers.h"

/**
 * @brief Singleton class used to create SteganoWidgets and SteganoMethods.
 *
 * Implements Factory pattern.
 *
 */
class CSteganoManager: public QObject
{
	Q_OBJECT
public:
    virtual ~CSteganoManager(void);
    /**
     * @brief Singleton pattern: returns instance of CSteganoManager
     * @return instance of CSteganoManager
     */
    static CSteganoManager& getInstance(void);

    /**
     * @brief Returns list of available IDs and method names to recognize methods
     * @return Shared pointer to list of methods containing pairs of method names and ID
     */
    PMethodList getSteganoMethodList(void);

    /**
     * @brief Produces SteganoMethod
     * @param Id Id of SteganoMethod to be produced
     * @return Shared pointer to produced CSteganoMethod
     * @see getSteganoMethodList
     */
    PSteganoMethod produceSteganoMethod(int Id);
    /**
     * @brief Produces SteganoMethod
     * @param Id Id of SteganoWidget to be produced
     * @return Shared pointer to produced CSteganoWidget
     * @see getSteganoMethodList
     */
    PSteganoWidget produceSteganoWidget(int Id);

    /**
     * @brief getSupportedTypesToEncrypt
     * @param Id
     * @return Supported input types for a method in Qt format
     */
    QString getSupportedTypesToEncrypt(int Id);

    /**
     * @brief getSupportedTypesToDecrypt
     * @param Id
     * @return Supported output types for a method in Qt format
     */
    QString getSupportedTypesToDecrypt(int Id);

    /**
     * @brief Registers new pair of SteganoMethod and SteganoWidget
     * @param pSteganoMethod Shared pointer to CSteganoMethod
     * @param pSteganoWidget Shared pointer to CSteganoWidget
     * @return registered method ID
     */
    int registerSteganoMethod(PSteganoMethod pSteganoMethod, PSteganoWidget pSteganoWidget);
    static const int c_InvalidIdNumber = -1;
private:
    Q_DISABLE_COPY(CSteganoManager)
    /**
     * @brief Private constructor to disable creation of second copy of CSteganoManager
     */
    CSteganoManager(void);

    static int m_counter; /* allows to set unique ID for each method */
    QVector< std::pair<PSteganoMethod, PSteganoWidget> > m_steganoProducts;
};

