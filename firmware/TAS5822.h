#ifndef TAS5822_H
#define TAS5822_H

namespace TAS5822Initializer
{

/**
 * @brief Initializes the TAS5822 amplifier.
 *
 * Applies the configuration exported from PurePath Console
 * by writing the required register sequence to the TAS5822
 * through the configured communication interface.
 *
 * @return true if the TAS5822 configuration was applied successfully;
 *         false if an error occurred during initialization.
 */
bool initialize();

} // namespace TAS5822Initializer

#endif // TAS5822_H