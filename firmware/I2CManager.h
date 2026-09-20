#ifndef I2CMANAGER_H
#define I2CMANAGER_H

#include <Arduino.h>

namespace I2CManager
{
    /**
     * @brief Initializes the I2C bus.
     *
     * @return true if initialization was successful.
     */
    bool begin();


    /**
     * @brief Writes a single byte to a device register.
     *
     * @param deviceAddress I2C device address.
     * @param registerAddress Register address.
     * @param value Value to write.
     *
     * @return true if the write was successful.
     */
    bool writeRegister(
        uint8_t deviceAddress,
        uint8_t registerAddress,
        uint8_t value
    );


    /**
     * @brief Writes multiple bytes starting at a device register.
     *
     * @param deviceAddress I2C device address.
     * @param registerAddress Starting register address.
     * @param data Pointer to the data buffer.
     * @param length Number of bytes to write.
     *
     * @return true if the write was successful.
     */
    bool writeData(
        uint8_t deviceAddress,
        uint8_t registerAddress,
        const uint8_t* data,
        size_t length
    );


    /**
     * @brief Reads a single byte from a device register.
     *
     * @param deviceAddress I2C device address.
     * @param registerAddress Register address.
     * @param value Reference where the read value will be stored.
     *
     * @return true if the read was successful.
     */
    bool readRegister(
        uint8_t deviceAddress,
        uint8_t registerAddress,
        uint8_t& value
    );


    /**
     * @brief Writes raw data directly to an I2C device.
     *
     * @param deviceAddress I2C device address.
     * @param data Pointer to the data buffer.
     * @param length Number of bytes to write.
     *
     * @return true if the write was successful.
     */
    bool writeRaw(
        uint8_t deviceAddress,
        const uint8_t* data,
        size_t length
    );
}

#endif // I2CMANAGER_H