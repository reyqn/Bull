#include <Bull/Core/Exception.hpp>

namespace Bull
{
    /*! \brief Constructor
     *
     * \param message The message of the exception
     * \param level The log error level
     *
     */
    Exception::Exception(const String& message, Log::Level level) :
        m_message(message),
        m_level(level)
    {
        m_when = Date::now();
    }

    /*! \brief Save the exception into the log
     *
     */
    void Exception::log()
    {
        String entry;

        entry += "Uncaught exception: \n";
        entry += "\tType: "     + getName()  + "\n";
        entry += "\tFunction: " + m_function + "\n";
        entry += "\tDate: "     + String::number(m_when.year) + "/" + String::number(m_when.month)  + "/" + String::number(m_when.day)                + "\n";
        entry += "\tAt: "       + String::number(m_when.hour) + ":" + String::number(m_when.minute) + ":" + String::number(m_when.second.asSeconds()) + "\n";

        Log::get()->log(entry, m_level);
    }
}
