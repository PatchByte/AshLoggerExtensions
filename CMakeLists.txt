cmake_minimum_required(VERSION 3.24)
project("AshLoggerExtensions-build")

option(ASH_LOGGER_EXTENSIONS_ENABLE "Enable AshLogger extensions." OFF)
option(ASH_LOGGER_EXTENSIONS_ENABLE_DEVELOPMENT_ENVIRONMENT "Enables a few specific tweaks to be able to develope AshLoggerExtensions" OFF)
option(ASH_LOGGER_EXTENSIONS_ENABLE_SAMPLES "Enable a few AshLoggerExtension samples." OFF)
option(ASH_LOGGER_EXTENSIONS_ENABLE_USAGE_OF_EXTERNAL_VENDORS "Enable the usages of external vendors." OFF)

# Configurable vendor variables
option(ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI "Enable the Grafana Loki extension." OFF)

if(ASH_LOGGER_EXTENSIONS_ENABLE)
    if(ASH_LOGGER_EXTENSIONS_ENABLE_DEVELOPMENT_ENVIRONMENT)
        set(CMAKE_CXX_VERSION 23)
        
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
    endif(ASH_LOGGER_EXTENSIONS_ENABLE_DEVELOPMENT_ENVIRONMENT)

    if(NOT ASH_LOGGER_EXTENSIONS_ENABLE_USAGE_OF_EXTERNAL_VENDORS)
        add_subdirectory("AshLoggerExtensionVendors")
    endif(NOT ASH_LOGGER_EXTENSIONS_ENABLE_USAGE_OF_EXTERNAL_VENDORS)

    add_subdirectory("AshLoggerExtensions")

    if(ASH_LOGGER_EXTENSIONS_ENABLE_SAMPLES)
        add_subdirectory("AshLoggerExtensionSamples")
    endif(ASH_LOGGER_EXTENSIONS_ENABLE_SAMPLES)
endif(ASH_LOGGER_EXTENSIONS_ENABLE)