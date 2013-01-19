#pragma once
#include <exception>
#include <QString>

/**
 * @brief The CSteganoException class
 *
 * Represents exceptions specific for the application.
 */
class CSteganoException :
    public std::exception
{
public:
    /**
     * @brief Default constructor
     */
    CSteganoException(void);

    /**
     * @brief CSteganoException Allows to pass a message.
     * @param Message message contents
     */
    CSteganoException(const char* Message):m_message(Message){}

    /**
     * @brief Retrieves message from exception
     * @return message contents
     */
    virtual QString getMessage();

    /**
     * @brief Destructor.
     */
    virtual ~CSteganoException(void) throw();
private:
    QString m_message;
};

