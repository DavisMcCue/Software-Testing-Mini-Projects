
add_subdirectory(set)
add_subdirectory(stack)
add_subdirectory(string)

macro(build_lib LIB_NAME LIB_TYPE)

    add_library(${LIB_NAME} ${LIB_TYPE} $<TARGET_OBJECTS:string> $<TARGET_OBJECTS:set>)
    set_target_properties(${LIB_NAME} PROPERTIES 
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
        OUTPUT_NAME my_stl)

endmacro()

#add_library(my_stl STATIC $<TARGET_OBJECTS:string> $<TARGET_OBJECTS:set>)
#set_target_properties(my_stl PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

build_lib(my_stl_static STATIC)
build_lib(my_stl_shared SHARED)

install(TARGETS my_stl_static my_stl_shared RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
