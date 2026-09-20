#include "I2CManager.h"

#include <Wire.h>

#include "Pins.h"
#include "Logger.h"

namespace I2CManager
{
    /**
     * @brief Initializes the I2C bus using the configured GPIO pins.
     *
     * @return true after the I2C interface has been initialized.
     */
    bool begin()
    {
        Wire.begin(
            Pins::I2C_SDA,
            Pins::I2C_SCL
        );

        Logger::success("I2C initialized.");

        return true;
    }


    /**
     * @brief Writes a single byte to a device register.
     *
     * The transaction consists of the device address,
     * register address, and one data byte.
     *
     * @param deviceAddress I2C device address.
     * @param registerAddress Register address.
     * @param value Byte value to write.
     *
     * @return true if the I2C transaction was successful.
     */
    bool writeRegister(
        uint8_t deviceAddress,
        uint8_t registerAddress,
        uint8_t value
    )
    {
        Wire.beginTransmission(deviceAddress);

        Wire.write(registerAddress);
        Wire.write(value);

        uint8_t result = Wire.endTransmission();

        if (result != 0)
        {
            Logger::error(
                String("I2C writeRegister failed. Error code: ") + result
            );

            return false;
        }

        return true;
    }


    /**
     * @brief Writes multiple bytes starting at a device register.
     *
     * The register address is sent first, followed by the
     * contents of the provided data buffer.
     *
     * @param deviceAddress I2C device address.
     * @param registerAddress Starting register address.
     * @param data Pointer to the data buffer.
     * @param length Number of bytes to write.
     *
     * @return true if the I2C transaction was successful.
     */
    bool writeData(
        uint8_t deviceAddress,
        uint8_t registerAddress,
        const uint8_t* data,
        size_t length
    )
    {
        Wire.beginTransmission(deviceAddress);

        Wire.write(registerAddress);

        for (size_t i = 0; i < length; i++)
        {
            Wire.write(data[i]);
        }

        uint8_t result = Wire.endTransmission();

        if (result != 0)
        {
            Logger::error("I2C writeData failed.");

            return false;
        }

        return true;
    }


    /**
     * @brief Reads a single byte from a device register.
     *
     * A repeated-start transaction is used to request the
     * register value without releasing the I2C bus.
     *
     * @param deviceAddress I2C device address.
     * @param registerAddress Register address to read.
     * @param value Reference where the received byte is stored.
     *
     * @return true if the register was read successfully.
     */
    bool readRegister(
        uint8_t deviceAddress,
        uint8_t registerAddress,
        uint8_t& value
    )
    {
        Wire.beginTransmission(deviceAddress);

        Wire.write(registerAddress);

        if (Wire.endTransmission(false) != 0)
        {
            Logger::error("I2C read request failed.");

            return false;
        }

        if (Wire.requestFrom(deviceAddress, (uint8_t)1) != 1)
        {
            Logger::error("I2C read failed.");

            return false;
        }

        value = Wire.read();

        return true;
    }


    /**
     * @brief Writes raw data directly to an I2C device.
     *
     * Unlike writeRegister() and writeData(), this function
     * does not prepend a register address. The caller provides
     * the complete byte sequence to be transmitted.
     *
     * This is useful for devices that require special command
     * or configuration sequences.
     *
     * @param deviceAddress I2C device address.
     * @param data Pointer to the data buffer.
     * @param length Number of bytes to write.
     *
     * @return true if the I2C transaction was successful.
     */
    bool writeRaw(
        uint8_t deviceAddress,
        const uint8_t* data,
        size_t length
    )
    {
        Wire.beginTransmission(deviceAddress);

        for (size_t i = 0; i < length; i++)
        {
            Wire.write(data[i]);
        }

        uint8_t result = Wire.endTransmission();

        if (result != 0)
        {
            Logger::error("I2C writeRaw failed.");

            return false;
        }

        return true;
    }
}