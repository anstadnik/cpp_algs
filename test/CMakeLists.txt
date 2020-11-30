cmake_minimum_required(VERSION 3.9)












# If necessary, use the RELATIVE flag, otherwise each source file may be listed
# with full pathname. RELATIVE may makes it easier to extract an executable name
# automatically.
file( GLOB FILE_NAMES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp )

foreach( filename ${FILE_NAMES} )
    # I used a simple string replace, to cut off .cpp.
    # string( REPLACE ".cpp" "" testname ${testsourcefile} )
    # add_executable( ${testname} ${testsourcefile} )
	get_filename_component( filename_comp ${filename} NAME_WE )
	add_executable( ${filename_comp} ${filename} )

    # set_target_properties(${testname} PROPERTIES
    #     LINKER_LANGUAGE CXX
    #     CXX_STANDARD 14)
    # if(OpenMP_CXX_FOUND)
    #     target_link_libraries(${testname} OpenMP::OpenMP_CXX)
    # endif()
    # install(TARGETS ${testname} DESTINATION "bin/sorting")

endforeach( filename ${FILE_NAMES} )
