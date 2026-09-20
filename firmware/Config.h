#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>

namespace Config
{
    /*
     * Bluetooth configuration
     */

    // Bluetooth device name advertised by the ESP32.
    constexpr char BLUETOOTH_DEVICE_NAME[] = "ESP32_AUDIO";


    /*
     * TAS5822 configuration
     */

    // I2C address of the TAS5822 audio amplifier.
    constexpr uint8_t TAS5822_I2C_ADDRESS = 0x2D;


    /*
     * Serial configuration
     */

    // Baud rate used for serial communication and logging.
    constexpr uint32_t SERIAL_BAUDRATE = 115200;
}

#endif // CONFIG_H