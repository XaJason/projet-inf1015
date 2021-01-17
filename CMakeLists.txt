cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake")

project(Exercices)

set(ALL_FILES
    "main.cpp"
    "Arguments.hpp"
    "Arguments.cpp"
)
add_executable(${PROJECT_NAME} ${ALL_FILES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++2a -fsigned-char -Wall -Wextra -Wpedantic -Woverloaded-virtual -Wno-unknown-pragmas -Wno-enum-compare")

find_package(Boost REQUIRED COMPONENTS regex)
find_package(cppitertools CONFIG REQUIRED)
find_path(TCLAP_INCLUDE_DIRS "tclap/Arg.h")
target_include_directories(${PROJECT_NAME} PRIVATE ${TCLAP_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::boost Boost::regex cppitertools::cppitertools)
