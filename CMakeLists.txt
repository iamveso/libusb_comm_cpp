cmake_minimum_required(VERSION 3.13)
project(lib_comm_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(lib_comm_cpp main.cpp openaccessory.cpp)

target_include_directories(lib_comm_cpp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(lib_comm_cpp
        /usr/lib/arm-linux-gnueabihf/libusb-1.0.so
        )