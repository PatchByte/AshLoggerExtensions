#include "LokiSample.h"
#include <fmt/format.h>

#include <AshLogger/AshLogger.h>
#include <AshLoggerExtensions/SimpleLokiExtension.h>

#define LOGGER_INFO 0x1
#define LOGGER_WARNING 0x2
#define LOGGER_ERROR 0x3

std::string LokiSample::GetUsage(int argc, char* argv[])
{
    return fmt::format("{} LokiSample [HOSTNAME] [PORT]", argv[0]);
}

ash::AshResult LokiSample::Do(int argc, char* argv[])
{
    if(argc < 4)
    {
        return ash::AshResult(false, this->GetUsage(argc, argv));
    }

    ash::AshLogger* simpleLogger = new ash::AshLogger("LokiSampleLogger", ash::AshLoggerTagInitializer({
        ash::AshLoggerTag(LOGGER_INFO, "Info"),
        ash::AshLoggerTag(LOGGER_WARNING, "Warning"),
        ash::AshLoggerTag(LOGGER_ERROR, "Error")
    }));

    simpleLogger->AddLoggerPassage(new ash::SimpleLokiExtension(argv[2], std::stoi(argv[3])));
    simpleLogger->Log(LOGGER_INFO, "Hello {}", "World");
    simpleLogger->Log(LOGGER_WARNING, "{} is the {}?", "Where", "World");
    simpleLogger->Log(LOGGER_ERROR, "Good Bye {}!", "World");

    delete simpleLogger;
    simpleLogger = nullptr;

    return ash::AshResult(true, "Done.");
}