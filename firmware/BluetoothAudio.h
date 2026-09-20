#ifndef BLUETOOTHAUDIO_H
#define BLUETOOTHAUDIO_H

#include <Arduino.h>

namespace BluetoothAudio
{

/**
 * @brief Initializes the Bluetooth A2DP audio sink.
 *
 * Configures the Bluetooth audio subsystem to receive
 * A2DP audio data and provide it to the system audio pipeline.
 *
 * @return true if the Bluetooth audio subsystem was initialized
 *         successfully; false otherwise.
 */
bool begin();

} // namespace BluetoothAudio

#endif // BLUETOOTHAUDIO_H