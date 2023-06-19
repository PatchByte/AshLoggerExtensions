project("AshLoggerExtensionSamples")

file(GLOB ASH_TEST_SOURCE_FILES
    "source/*.*"
    "source/*/*.*"
    "source/*/*/*.*"
)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/source/)

add_executable(${PROJECT_NAME} ${ASH_TEST_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} Ash::Ash AshLogger::AshLogger fmt::fmt AshLoggerExtensions::AshLoggerExtensions)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

if(ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI=1)
endif(ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI)