cmake_minimum_required(VERSION 3.16)
project(ethworks_zadanie)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googlemock/include)
include_directories(lib/googletest-master/googletest/include)
#set(SOURCE_FILES main.cpp)
add_executable(ethworks_zadanie Tests/test.cpp Tests/test.h Tests/test.cpp com/Variable.cpp com/Variable.h com/Expression.cpp com/Expression.h com/addExpression.cpp com/addExpression.h)

target_link_libraries(ethworks_zadanie gtest gtest_main)
