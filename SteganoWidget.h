#pragma once
#include <QWidget>
#include "SteganoTypes.h"

/**
 * @brief Class which allows user to edit method's parameters using QT GUI.
 *
 * The widget is bound with the method on registration in CSteganoManager
 * @see CSteganoManager::registerSteganoMethod
 */
class CSteganoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CSteganoWidget(QWidget *parent = 0);
    CSteganoWidget(const CSteganoWidget&);
    virtual PArgsList getArgsList() = 0;
    virtual void setArgsList(PArgsList) = 0;
    /**
     * @brief Clone pattern.
     * @return Shared pointer to a cloned object
     */
    virtual QSharedPointer<CSteganoWidget> clone() = 0;
    virtual bool isPropositionsAllowed();
signals:
    
public slots:
    
};
