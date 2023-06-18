set(ASH_ENABLE_LOGGER ON)
set(ASH_ENABLE_USAGE_OF_EXTERNAL_VENDORS ON)

set(USE_ZLIB OFF)

add_subdirectory("fmt")
add_subdirectory("json")
add_subdirectory("IXWebSocket")
add_subdirectory("Ash")