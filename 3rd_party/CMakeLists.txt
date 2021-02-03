file(GLOB FILE_NAMES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

add_subdirectory(backward-cpp)

get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" LIB_NAME ${LIB_NAME})

add_library(${LIB_NAME} STATIC ${FILE_NAMES} ${BACKWARD_ENABLE})

# Add to the top level CMakeLists.txt
# link_libraries(-ldw)
# set(CMAKE_STATIC_LINKER_FLAGS "${CMAKE_STATIC_LINKER_FLAGS} -ldw")

add_backward(${LIB_NAME})
