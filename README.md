# AshLoggerExtensions

This project is a project to extend ash logger, the project 
implements new `AshLoggerPassages`.

## What is in it?
Here is a list of a the few new `AshLoggerPassages`.

|Name|Description|Dependencies|
|----|-----------|------------|
|SimpleConsoleOutExtension| Just outputs to std::cout |  |
|SimpleFileOutExtension| Just outputs to a specified file with std::filesystem::path | |
| SimpleLokiExtension | Uses the [Grafana Loki Api (Push log entries to Loki) ](https://grafana.com/docs/loki/latest/api/#push-log-entries-to-loki) | [IXWebSocket](https://github.com/machinezone/IXWebSocket.git), [JSON](https://github.com/nlohmann/json.git) |

## How to use it?
- First of clone the [Ash](https://github.com/PatchByte/Ash) project.
- Add various required SubModules such as [fmt](https://github.com/fmtlib/fmt), etc..
- Just enable the options
- And here you go

## Configurable Variables

|Name|Description|Values|
|----|-----------|------|
|ASH_LOGGER_EXTENSIONS_ENABLE|Choose to enable this project.|  ON / OFF |
|ASH_LOGGER_EXTENSIONS_ENABLE_DEVELOPMENT_ENVIRONMENT|Choose to enable this projects development environment (Should only used by myself.) | ON / OFF |
|ASH_LOGGER_EXTENSIONS_ENABLE_SAMPLES|Choose to enable samples for this project.| ON / OFF |

## Got any samples?
Sure, [here](https://github.com/PatchByte/AshLoggerExtensions/tree/main/AshLoggerExtensionSamples/source/samples)