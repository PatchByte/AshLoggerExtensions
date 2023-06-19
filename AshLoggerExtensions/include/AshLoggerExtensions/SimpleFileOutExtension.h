#pragma once
#include <AshLogger/AshLoggerPassage.h>
#include <AshLogger/AshLogger.h>
#include <filesystem>
#include <fstream>

namespace ash::passages
{

    class SimpleFileOutExtension : public AshLoggerDefaultPassage
    {
    public:
        SimpleFileOutExtension(std::filesystem::path OutputPath, bool ClearBeforeFirstOutput);
        ~SimpleFileOutExtension() = default;
        void DoPassthrough(AshLoggerTag Tag, std::string Format, fmt::format_args Args, std::string FormattedString);
    private:
        std::ofstream outputStream;
    };

}