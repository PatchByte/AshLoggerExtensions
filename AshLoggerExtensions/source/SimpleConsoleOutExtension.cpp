#include "AshLoggerExtensions/SimpleConsoleOutExtension.h"

namespace ash::passages
{

    void SimpleConsoleOutExtension::DoPassthrough(AshLoggerTag Tag, std::string Format, fmt::format_args Args, std::string FormattedString)
    {
        std::cout << this->GetParent()->GetPrefixFunction()(Tag, Format, Args) << " " << FormattedString << std::endl;
    }

}