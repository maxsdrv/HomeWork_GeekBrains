cmake_minimum_required(VERSION 3.17)
project(TTT)

set(CMAKE_CXX_STANDARD 17)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

set(data_SHADOW icon.png fon.png)

add_executable(TTT main.cpp)

target_link_libraries(TTT sfml-graphics )