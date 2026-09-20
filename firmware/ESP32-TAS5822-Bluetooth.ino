
/*
 * ESP32-TAS5822-Bluetooth
 *
 * Modular Bluetooth Audio Receiver for ESP32
 * using the TAS5822 Class-D Audio Amplifier.
 *
 * Author:
 *   Juan Antonio Rodríguez Alcaraz
 *
 * Contact:
 *   Email: juanara210605@gmail.com
 *
 * Description:
 *   Bluetooth A2DP audio receiver based on the ESP32,
 *   with I2S audio output to the TAS5822 Class-D amplifier.
 *
 * Initialization sequence:
 *   1. Initialize the logger.
 *   2. Print firmware version.
 *   3. Initialize the I2C interface.
 *   4. Initialize the TAS5822 amplifier.
 *   5. Initialize Bluetooth A2DP audio.
 *
 * If a required module fails to initialize, the system
 * stops execution to prevent the audio system from
 * running in an undefined state.
 */




#include "Version.h"

#include "Logger.h"
#include "I2CManager.h"
#include "TAS5822.h"
#include "BluetoothAudio.h"

void setup()
{
    // Initialize serial logging.
    Logger::begin();

    // Display firmware and project information.
    Version::print();

    // Initialize the I2C interface used by the TAS5822.
    if (!I2CManager::begin())
    {
        while (true)
        {
        }
    }

    // Configure and initialize the TAS5822 amplifier.
    if (!TAS5822Initializer::initialize())
    {
        while (true)
        {
        }
    }

    // Initialize the Bluetooth A2DP audio receiver.
    if (!BluetoothAudio::begin())
    {
        while (true)
        {
        }
    }

    // All required modules initialized successfully.
    Logger::success("System ready.");
}

void loop()
{
}


