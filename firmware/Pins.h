#ifndef PINS_H
#define PINS_H

#include <Arduino.h>

namespace Pins
{
    /*
     * I2C pins
     */

    // I2C data line connected to the TAS5822.
    constexpr uint8_t I2C_SDA = 18;

    // I2C clock line connected to the TAS5822.
    constexpr uint8_t I2C_SCL = 19;


    /*
     * I2S pins
     */

    // I2S bit clock.
    constexpr uint8_t I2S_BCLK = 26;

    // I2S word select / left-right clock.
    constexpr uint8_t I2S_LRCK = 25;

    // I2S audio data output.
    constexpr uint8_t I2S_DOUT = 22;
}

#endif // PINS_H