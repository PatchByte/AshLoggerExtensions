project("AshLoggerExtensions")

file(GLOB ASHLOGGEREXTENSIONS_HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/AshLoggerExtensions/*.h)
file(GLOB ASHLOGGEREXTENSIONS_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp)

include_directories(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(${PROJECT_NAME} STATIC  ${ASHLOGGEREXTENSIONS_HEADER_FILES}
                                    ${ASHLOGGEREXTENSIONS_SOURCE_FILES}
)

add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_20)

# @todo do AshLogger options to enable certain parts
target_link_libraries(${PROJECT_NAME} PUBLIC Ash::Ash AshLogger::AshLogger fmt::fmt)

if(ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI)
    target_link_libraries(${PROJECT_NAME} PUBLIC nlohmann_json::nlohmann_json ixwebsocket::ixwebsocket)
endif(ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI)

if(ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI=1)
endif(ASH_LOGGER_EXTENSIONS_ENABLE_GRAFANA_LOKI)