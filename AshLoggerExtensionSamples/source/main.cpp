#include "main.h"
#include "BaseSample.h"

#include "samples/ConsoleOutSample.h"
#include "samples/FileOutSample.h"
#include "samples/LokiSample.h"

#include <iostream>
#include <map>
#include <cstring>
#include <ostream>
#include <fmt/format.h>

static std::map<std::string, AshBaseSample*> smAshLoggerExtensionSamplesRegistered = {
    #if ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI
    { "LokiSample", new LokiSample() },
    #endif
    { "ConsoleOutSample", new ConsoleOutSample() },
    { "FileOutSample", new FileOutSample() }
};

int main(int argc, char* argv[])
{
    if(argc >= 2)
    {
        if(strcmp(argv[1], "--help") == 0)
        {
            std::cout << fmt::format("Need Help: `{} --help`", argv[0]) << std::endl;
            std::cout << fmt::format("Run Sample: `{} [SAMPLE NAME] ARGUMENTS...", argv[0]) << std::endl;
            std::cout << std::endl;
            std::cout << "Samples list: " << std::endl;
            
            for(auto currentSample : smAshLoggerExtensionSamplesRegistered)
            {
                std::cout << fmt::format("- {}\n - Usage: {}", currentSample.first, currentSample.second->GetUsage(argc, argv)) << std::endl;
            }

            return 0;
        }
        else if(smAshLoggerExtensionSamplesRegistered.count(argv[1]) > 0)
        {
            AshBaseSample* sample = smAshLoggerExtensionSamplesRegistered.at(argv[1]);
            ash::AshResult result = sample->Do(argc, argv);

            if(result.GetMessage().length() > 0)
            {
                std::ostream& outputStream = (result.WasSuccessful() ? std::cout : std::cerr); 
                outputStream << fmt::format("{}: {}", (result.WasSuccessful() ? "Okay" : "Error"), result.GetMessage()) << std::endl;
            }

            return result.WasSuccessful() ? 0 : -1;
        }
    }
    else
    {
        std::cerr << "You need to deliver arguments to specify which sample should be run." << std::endl;
        std::cerr << fmt::format("You can just run the command or add the argument `{} --help`.", argv[0]) << std::endl;
        return -1;
    }

    return 0;
}