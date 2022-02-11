file(GLOB STRING_HEADERS *.hpp)
file(GLOB STRING_SOURCE  *.cpp)

# without destination goes into that directory (my_stl_build/src/string)
#add_library(string ${STRING_HEADERS} ${STRING_SOURCE})
#set_target_properties(string PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(string OBJECT ${STRING_HEADERS} ${STRING_SOURCE})
install(FILES ${STRING_HEADERS} DESTINATION include)