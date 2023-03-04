cmake_minimum_required(VERSION 3.21.0 FATAL_ERROR) # .ixx and .cppm support

project("CPP-Concurrency-in-Action" 
    LANGUAGES CXX
    VERSION 1.0.0)
add_compile_definitions(ALBEDO_LAUNCHER_VERSION="${PROJECT_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Explicitly require the standard
set(CMAKE_CXX_EXTENSIONS OFF) # Vendor-specific Extensions

file(GLOB ALL_HEADER_FILES "*.h")
file(GLOB ALL_SOURCE_FILES "*.cc")

add_executable(${PROJECT_NAME} ${ALL_HEADER_FILES} ${ALL_SOURCE_FILES})