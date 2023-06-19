#include "FileOutSample.h"
#include "BaseLoggerSetup.h"

#include <fmt/format.h>

#include <AshLogger/AshLogger.h>
#include <AshLoggerExtensions/SimpleFileOutExtension.h>

std::string FileOutSample::GetUsage(int argc, char* argv[])
{
    return fmt::format("{} FileOutSample [FILENAME] [APPEND | TRUNCATE]", argv[0]);
}

ash::AshResult FileOutSample::Do(int argc, char* argv[])
{
    if(argc < 4)
    {
        return ash::AshResult(false, this->GetUsage(argc, argv));
    }

    ash::AshLogger* simpleLogger = BaseLoggerSetup::SetupBasicLogger("LokiSample");
    bool Truncate = (std::string(argv[3]) == "TRUNCATE"); 

    simpleLogger->AddLoggerPassage(new ash::passages::SimpleFileOutExtension(argv[2], Truncate));
    simpleLogger->Log(LOGGER_INFO, "Hello {}", "World");
    simpleLogger->Log(LOGGER_WARNING, "{} is the {}?", "Where", "World");
    simpleLogger->Log(LOGGER_ERROR, "Good Bye {}!", "World");

    delete simpleLogger;
    return ash::AshResult(true, "Done.");
}