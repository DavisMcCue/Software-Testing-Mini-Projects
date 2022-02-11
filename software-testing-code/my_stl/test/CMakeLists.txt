
macro(add_unit_test TEST_NAME TEST_FILE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    # ARGN is any additional parameters ... Not needed here.
    target_link_libraries(${TEST_NAME} my_stl_static ${ARGN})
    # needed for coverage
    #target_link_libraries(${TEST_NAME} my_stl_static ${ARGN})
    add_test(NAME ${TEST_NAME} COMMAND $<TARGET_FILE:${TEST_NAME}>)
    set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
endmacro()

add_subdirectory(set)
add_subdirectory(stack)
add_subdirectory(string)
