#include "Version.h"

#include "Logger.h"

namespace Version
{
    void print()
    {
        Logger::info("========================================");

        Logger::info(PROJECT_NAME);
        Logger::info(PROJECT_DESCRIPTION);

        Logger::info("");

        Logger::info("Author:");
        Logger::info(PROJECT_AUTHOR);

        Logger::info("License:");
        Logger::info(PROJECT_LICENSE);

        Logger::info("");

        Logger::info("Firmware Version:");
        Logger::info(
            String(MAJOR) + "." +
            String(MINOR) + "." +
            String(PATCH));

        Logger::info("========================================");
    }
}