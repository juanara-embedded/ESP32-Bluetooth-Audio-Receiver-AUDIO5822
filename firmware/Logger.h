#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>

namespace Logger
{
    /**
     * @brief Initializes the serial port used by the logger.
     */
    void begin();

    /**
     * @brief Prints an informational message.
     *
     * @param message Message to print.
     */
    void info(const String& message);

    /**
     * @brief Prints a success message.
     *
     * @param message Message to print.
     */
    void success(const String& message);

    /**
     * @brief Prints a warning message.
     *
     * @param message Message to print.
     */
    void warning(const String& message);

    /**
     * @brief Prints an error message.
     *
     * @param message Message to print.
     */
    void error(const String& message);
}

#endif // LOGGER_H