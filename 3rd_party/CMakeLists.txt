file(GLOB FILE_NAMES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc)

get_filename_component(LIB_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" LIB_NAME ${LIB_NAME})

add_library(${LIB_NAME} INTERFACE)

# Needed for backward
find_library(DW_LIBRARY dw)
target_link_libraries(${LIB_NAME} INTERFACE ${DW_LIBRARY})
