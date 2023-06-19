#pragma once
#include "BaseSample.h"
#if ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI

class LokiSample : public AshBaseSample
{
public:
    ASH_BASE_SAMPLE_IMPLEMENT();
};
#endif