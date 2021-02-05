# Cmake params
cmake_minimum_required(VERSION 3.9)

# CPP params
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

# Set c++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_STATIC_LINKER_FLAGS "-Wl,--export-all-symbols")

# Define project
project(algs LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "Set of algorithms implemented in C++."
)

# List subfolders
add_subdirectory(3rd_party)
add_subdirectory(io)
add_subdirectory(math)

# Create a single library
add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE 3rd_party io math)

# Where to search for includes
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Use openmp if found
option(USE_OPENMP "flag to use OpenMP for multithreading" ON)
if(USE_OPENMP)
    find_package(OpenMP 3.0 COMPONENTS CXX)
    if (OpenMP_CXX_FOUND)
        message(STATUS "Building with OpenMP Multithreading.")
    else()
        message(STATUS "No OpenMP found, no multithreading.")
    endif()
endif()
