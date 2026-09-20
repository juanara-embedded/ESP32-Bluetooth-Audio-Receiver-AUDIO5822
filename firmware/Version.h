#ifndef VERSION_H
#define VERSION_H

#include <Arduino.h>

namespace Version
{
    /*
     * Project information
     */

    constexpr char PROJECT_NAME[] =
        "ESP32-TAS5822-Bluetooth";

    constexpr char PROJECT_DESCRIPTION[] =
        "Modular Bluetooth Audio Receiver using the TAS5822 Class-D Audio Amplifier";

    constexpr char PROJECT_AUTHOR[] =
        "Juan Antonio Rodríguez Alcaraz";

    constexpr char PROJECT_LICENSE[] =
        "MIT";


    /*
     * Firmware version
     *
     * Version format: MAJOR.MINOR.PATCH
     */

    constexpr uint8_t MAJOR = 1;
    constexpr uint8_t MINOR = 0;
    constexpr uint8_t PATCH = 0;


    /**
     * @brief Prints project information and firmware version
     *        to the serial console.
     */
    void print();
}

#endif // VERSION_H