#pragma once
#include <AshLogger/AshLoggerPassage.h>
#include <AshLogger/AshLogger.h>

namespace ash::passages
{

    class SimpleConsoleOutExtension : public AshLoggerDefaultPassage
    {
    public:
        void DoPassthrough(AshLoggerTag Tag, std::string Format, fmt::format_args Args, std::string FormattedString);
    };

}