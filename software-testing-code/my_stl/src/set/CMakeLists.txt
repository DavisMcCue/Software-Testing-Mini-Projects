file(GLOB SET_HEADERS *.hpp)
file(GLOB SET_SOURCE  *.cpp)

add_library(set OBJECT ${SET_HEADERS} ${SET_SOURCE})

install(FILES ${SET_HEADERS} DESTINATION include)
