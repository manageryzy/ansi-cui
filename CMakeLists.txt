message(${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_BINARY_DIR})

if(${CMAKE_CURRENT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
    message(FATAL_ERROR "do not run this. run in another directory or run make")
endif()

set (CMAKE_CXX_STANDARD 11)

add_executable(demo1_c demo1.c)
add_executable(demo1_cpp demo1.cpp)
