#include "AshLoggerExtensions/SimpleFileOutExtension.h"
#include <fmt/format.h>

namespace ash::passages
{

    SimpleFileOutExtension::SimpleFileOutExtension(std::filesystem::path OutputPath, bool ClearBeforeFirstOutput)
    {
        this->outputStream = std::ofstream();
        this->outputStream.open(OutputPath, ClearBeforeFirstOutput ? std::ios::trunc : std::ios::app);
    }

    void SimpleFileOutExtension::DoPassthrough(AshLoggerTag Tag, std::string Format, fmt::format_args Args, std::string FormattedString)
    {
        if(this->GetLoggerTagFilter().DoFilter(Tag.GetShortTag()) == false) { return; }

        if(this->outputStream.bad() == false)
        {
            this->outputStream << fmt::format("{} {}", this->GetParent()->GetPrefixFunction()(Tag, Format, Args), FormattedString) << std::endl;
        }
    }

}