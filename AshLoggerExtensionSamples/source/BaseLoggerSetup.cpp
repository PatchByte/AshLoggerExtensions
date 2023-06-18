#include "BaseLoggerSetup.h"
#include <fmt/format.h>

ash::AshLogger* BaseLoggerSetup::SetupBasicLogger(std::string LoggerName)
{
    ash::AshLogger* simpleLogger = new ash::AshLogger(LoggerName, ash::AshLoggerTagInitializer({
        ash::AshLoggerTag(LOGGER_INFO, "Info"),
        ash::AshLoggerTag(LOGGER_WARNING, "Warning"),
        ash::AshLoggerTag(LOGGER_ERROR, "Error")
    }));

    simpleLogger->SetPrefixFunction([LoggerName] (ash::AshLoggerTag LoggerTag, std::string LoggerFormat, fmt::format_args LoggerFormatArgs) -> std::string 
    {
        return fmt::format("[{}::{}]", LoggerName, LoggerTag.GetPrefix());
    });

    return simpleLogger;
}