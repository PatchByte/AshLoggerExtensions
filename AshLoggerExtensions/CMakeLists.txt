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
target_link_libraries(${PROJECT_NAME} PUBLIC Ash::Ash fmt::fmt)