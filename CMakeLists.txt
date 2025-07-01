cmake_minimum_required(VERSION 3.20)
project(CollatzConjectureScripts VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)
FetchContent_Declare(
    matplotplusplus
    GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus
    GIT_TAG a672f65216db529db0d5619d8b98c53524b63b93 # Commit on Jun 20, 2025
)
FetchContent_GetProperties(matplotplusplus)
if(NOT matplotplusplus_POPULATED)
    FetchContent_Populate(matplotplusplus)
    add_subdirectory(${matplotplusplus_SOURCE_DIR} ${matplotplusplus_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(CollatzConjectureScripts main.cpp ReusableFunctions.cpp)
set_property(TARGET CollatzConjectureScripts PROPERTY CXX_STANDARD 20)
target_link_libraries(CollatzConjectureScripts PUBLIC matplot)


