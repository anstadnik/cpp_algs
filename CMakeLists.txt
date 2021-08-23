# Cmake params
cmake_minimum_required(VERSION 3.9)

# CPP params
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -Wall -Wextra -pedantic -Werror")

# Set c++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
	# string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fno-omit-frame-pointer -fsanitize=address")
	# string(APPEND CMAKE_LINKER_FLAGS_DEBUG " -fno-omit-frame-pointer -fsanitize=address")
	# add_link_options(-fsanitize=address)

	# string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=undefined")
	# string(APPEND CMAKE_LINKER_FLAGS_DEBUG " -fsanitize=undefined")
	# add_link_options(-fsanitize=undefined)

	# string(APPEND CMAKE_CXX_FLAGS_DEBUG " -ftime-trace")
endif()

# Define project
project(algs LANGUAGES CXX
    VERSION 1.0.0
    DESCRIPTION "Set of algorithms implemented in C++."
)

# List subfolders
add_subdirectory(3rd_party)
add_subdirectory(io)
add_subdirectory(math)
add_subdirectory(helpers)
add_subdirectory(str)
add_subdirectory(leetcode_helpers)

# Create a single library
add_library(${PROJECT_NAME} INTERFACE)

target_link_libraries(${PROJECT_NAME} INTERFACE 3rd_party io math helpers str leetcode_helpers)

# Where to search for includes
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# Use openmp if found
# option(USE_OPENMP "flag to use OpenMP for multithreading" ON)
# if(USE_OPENMP)
#     find_package(OpenMP 3.0 COMPONENTS CXX)
#     if (OpenMP_CXX_FOUND)
#         message(STATUS "Building with OpenMP Multithreading.")
#     else()
#         message(STATUS "No OpenMP found, no multithreading.")
#     endif()
# endif()

# Colored output
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
   add_compile_options (-fdiagnostics-color=always)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
   add_compile_options (-fcolor-diagnostics)
endif ()

#############
#  Doxygen  #
#############

cmake_policy(SET CMP0054 NEW)
cmake_policy(SET CMP0057 NEW)
find_package(Doxygen OPTIONAL_COMPONENTS dot dia)
if(DOXYGEN_FOUND)
    set(DOXYGEN_GENERATE_MAN NO)
    set(DOXYGEN_USE_MATHJAX YES)
    set(DOXYGEN_GENERATE_HTML YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_INLINE_SOURCES YES)
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set(DOXYGEN_EXTRACT_PRIVATE YES)
    set(DOXYGEN_GENERATE_TREEVIEW YES)
    set(DOXYGEN_STRIP_CODE_COMMENTS NO)
    set(DOXYGEN_EXT_LINKS_IN_WINDOW YES)
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
    set(DOXYGEN_EXCLUDE_PATTERNS */build/*)
    set(DOXYGEN_ENABLE_PREPROCESSING YES)
    set(DOXYGEN_CLANG_ASSISTED_PARSING YES)
    set(DOXYGEN_FILE_PATTERNS *.cpp *.h *.hpp *.md)
    set(DOXYGEN_MATHJAX_EXTENSIONS  TeX/AMSmath TeX/AMSsymbols)
    set(DOXYGEN_TAGFILES "doc/cppreference-doxygen-web.tag.xml=http://en.cppreference.com/w/")
    set(DOXYGEN_MATHJAX_RELPATH "https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML")
    if(Doxygen_dot_FOUND)
        set(DOXYGEN_HAVE_DOT YES)
        set(DOXYGEN_CALL_GRAPH YES)
        set(DOXYGEN_INTERACTIVE_SVG YES)
        set(DOXYGEN_DOT_IMAGE_FORMAT "svg")
    endif()
    if(OPENMP_FOUND)
        set(DOXYGEN_PREDEFINED "_OPENMP=1")
    endif()
    if(GLUT_FOUND)
        set(DOXYGEN_PREDEFINED ${DOXYGEN_PREDEFINED} "GLUT_FOUND=1")
    endif()

    doxygen_add_docs(
        doc
        ${PROJECT_SOURCE_DIR}
        COMMENT "Generate documentation"
    )
endif()
