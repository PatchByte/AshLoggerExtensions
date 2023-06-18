#pragma once
#include <iostream>
#include <AshLogger/AshLogger.h>

#define LOGGER_INFO 0x1
#define LOGGER_WARNING 0x2
#define LOGGER_ERROR 0x3

class BaseLoggerSetup
{
public:
    static ash::AshLogger* SetupBasicLogger(std::string LoggerName);
};