#pragma once
#include <AshLogger/AshLoggerPassage.h>
#include <AshLogger/AshLogger.h>

namespace ash::passages
{

    class SimpleLokiExtension : public AshLoggerDefaultPassage
    {
    public:
        inline SimpleLokiExtension(std::string LokiEndpointHostname, unsigned short LokiEndpointPort): lokiEndpointHostname(LokiEndpointHostname), lokiEndpointPort(LokiEndpointPort) {}
        ~SimpleLokiExtension() = default;

        void DoPassthrough(AshLoggerTag Tag, std::string Format, fmt::format_args Args, std::string FormattedString);
    private:
        std::string lokiEndpointHostname;
        unsigned short lokiEndpointPort;
    };

}