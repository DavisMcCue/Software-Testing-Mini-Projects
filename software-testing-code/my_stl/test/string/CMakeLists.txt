#add_executable(test_concat test_concat.cpp)
#target_link_libraries(test_concat my_stl_static)
# Use target create by add_executable
#add_test(NAME test_concat COMMAND $<TARGET_FILE:test_concat>)
#set_target_properties(test_concat PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_unit_test(test_str_concat test_concat.cpp)
add_unit_test(test_str_ctor_char test_ctor_char.cpp)
add_unit_test(test_str_ctor_charArray test_ctor_charArray.cpp)
add_unit_test(test_str_ctor_copy test_ctor_copy.cpp)
add_unit_test(test_str_ctor_default test_ctor_default.cpp)
add_unit_test(test_str_equal test_equal.cpp)
add_unit_test(test_str_find_char test_find_char.cpp)
add_unit_test(test_str_find_string test_find_string.cpp)
add_unit_test(test_str_greaterThan test_greaterThan.cpp)
# this fails
add_unit_test(test_str_input test_input.cpp)
add_unit_test(test_str_len_cap test_len_cap.cpp)
add_unit_test(test_str_lessThan test_lessThan.cpp)
add_unit_test(test_str_split test_split.cpp)
add_unit_test(test_str_subscript test_subscript.cpp)
add_unit_test(test_str_substring test_substring.cpp)
add_unit_test(test_str_swap_assign test_swap_assign.cpp)
