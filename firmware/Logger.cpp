#include "Logger.h"
#include "Config.h"

namespace Logger
{

/**
 * @brief Initializes the serial interface used by the logger.
 *
 * The baud rate is obtained from the global project configuration
 * defined in Config::SERIAL_BAUDRATE.
 */
void begin()
{
    Serial.begin(Config::SERIAL_BAUDRATE);
}

/**
 * @brief Prints an informational log message.
 *
 * Used for general runtime information that does not indicate
 * an error or warning condition.
 *
 * @param message Message to print.
 */
void info(const String& message)
{
    Serial.print("[INFO] ");
    Serial.println(message);
}

/**
 * @brief Prints a success log message.
 *
 * Used to indicate that an operation or initialization completed
 * successfully.
 *
 * @param message Message to print.
 */
void success(const String& message)
{
    Serial.print("[SUCCESS] ");
    Serial.println(message);
}

/**
 * @brief Prints a warning log message.
 *
 * Used to report an abnormal or potentially problematic condition
 * that does not prevent the system from continuing operation.
 *
 * @param message Message to print.
 */
void warning(const String& message)
{
    Serial.print("[WARNING] ");
    Serial.println(message);
}

/**
 * @brief Prints an error log message.
 *
 * Used to report a failure or critical condition detected during
 * system operation.
 *
 * @param message Message to print.
 */
void error(const String& message)
{
    Serial.print("[ERROR] ");
    Serial.println(message);
}

}