cmake_minimum_required(VERSION 3.10)
project(CalcolatriceTest)

set(CMAKE_CXX_STANDARD 17)
# Sorgenti
add_library(calcolatrice calc.cpp)

# Test
add_executable(test_calcolatrice test_calc.cpp)
target_link_libraries(test_calcolatrice calcolatrice GTest::GTest GTest::Main)


# Aggiungi Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_test(NAME CalcolatriceTests COMMAND test_calcolatrice)
