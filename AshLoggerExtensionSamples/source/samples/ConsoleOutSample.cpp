#include "ConsoleOutSample.h"
#include "BaseLoggerSetup.h"

#include <fmt/format.h>

#include <AshLogger/AshLogger.h>
#include <AshLoggerExtensions/SimpleConsoleOutExtension.h>

std::string ConsoleOutSample::GetUsage(int argc, char* argv[])
{
    return fmt::format("{} ConsoleOutSample", argv[0]);
}

ash::AshResult ConsoleOutSample::Do(int argc, char* argv[])
{
    ash::AshLogger* simpleLogger = BaseLoggerSetup::SetupBasicLogger("ConsoleOutSample");

    simpleLogger->AddLoggerPassage(new ash::passages::SimpleConsoleOutExtension());
    simpleLogger->Log(LOGGER_INFO, "Hello {}", "World");
    simpleLogger->Log(LOGGER_WARNING, "{} is the {}?", "Where", "World");
    simpleLogger->Log(LOGGER_ERROR, "Good Bye {}!", "World");

    delete simpleLogger;
    return ash::AshResult(true, "Done.");
}