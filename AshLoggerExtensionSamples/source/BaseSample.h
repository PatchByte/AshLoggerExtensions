#pragma once
#include <Ash/AshResult.h>
#include <iostream>

#define ASH_BASE_SAMPLE_IMPLEMENT() std::string GetUsage(int argc, char* argv[]); \
                                    ash::AshResult Do(int argc, char* argv[]);

class AshBaseSample
{
public:
    virtual ~AshBaseSample() = default;
    virtual std::string GetUsage(int argc, char* argv[]) { return ""; };
    virtual ash::AshResult Do(int argc, char* argv[]) { return ash::AshResult(false, "Called a non implemented function"); };
};