#include "LokiSample.h"
#include "BaseLoggerSetup.h"

#include <fmt/format.h>

#include <AshLogger/AshLogger.h>
#include <AshLoggerExtensions/SimpleLokiExtension.h>

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

    ash::AshLogger* simpleLogger = BaseLoggerSetup::SetupBasicLogger("LokiSample");

    simpleLogger->AddLoggerPassage(new ash::passages::SimpleLokiExtension(argv[2], std::stoi(argv[3])));
    simpleLogger->Log(LOGGER_INFO, "Hello {}", "World");
    simpleLogger->Log(LOGGER_WARNING, "{} is the {}?", "Where", "World");
    simpleLogger->Log(LOGGER_ERROR, "Good Bye {}!", "World");

    delete simpleLogger;
    return ash::AshResult(true, "Done.");
}