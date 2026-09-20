#include "TAS5822.h"

#include "Config.h"
#include "I2CManager.h"
#include "Logger.h"
#include "TAS5822Registers.h"

namespace TAS5822Initializer
{

/**
 * @brief Initializes the TAS5822 amplifier.
 *
 * Iterates through the configuration sequence exported from
 * PurePath Console and applies each entry to the TAS5822 through I2C.
 *
 * The configuration sequence may contain:
 * - Normal register writes.
 * - Delay commands.
 * - Burst write commands.
 *
 * Initialization stops immediately if an I2C operation fails.
 *
 * @return true if the complete configuration sequence was applied
 *         successfully; false if any I2C operation failed.
 */
bool initialize()
{
    Logger::info("Initializing TAS5822...");

    for (size_t i = 0; i < TAS5822::RegisterCount; ++i)
    {
        const TAS5822::Register& reg = TAS5822::Registers[i];

        switch (reg.command)
        {
            case TAS5822::CFG_META_DELAY:
            {
                /**
                 * @brief Executes a delay specified by the configuration.
                 *
                 * The parameter represents the delay duration in
                 * milliseconds.
                 */
                delay(reg.param);

                break;
            }

            case TAS5822::CFG_META_BURST:
            {
                /**
                 * @brief Writes a block of configuration data through I2C.
                 *
                 * The entries following the burst command are treated
                 * as raw data and transmitted as a single I2C operation.
                 */
                if (!I2CManager::writeRaw(
                        Config::TAS5822_I2C_ADDRESS,
                        reinterpret_cast<const uint8_t*>(
                            &TAS5822::Registers[i + 1]),
                        reg.param))
                {
                    Logger::error("Failed to write burst.");

                    return false;
                }

                i += reg.param / sizeof(TAS5822::Register);

                break;
            }

            default:
            {
                /**
                 * @brief Writes a single TAS5822 register.
                 *
                 * Normal configuration entries use the offset and value
                 * fields of the Register structure.
                 */
                if (!I2CManager::writeRegister(
                        Config::TAS5822_I2C_ADDRESS,
                        reg.offset,
                        reg.value))
                {
                    Logger::error("Failed to write register.");

                    return false;
                }

                break;
            }
        }
    }

    Logger::success("TAS5822 initialized.");

    return true;
}

} // namespace TAS5822Initializer