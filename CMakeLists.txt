cmake_minimum_required(VERSION 3.19)
project(Skillbox_HW_32_2 VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(json)

add_executable(Skillbox_HW_32_2 main.cpp)
target_link_libraries(Skillbox_HW_32_2 PRIVATE nlohmann_json::nlohmann_json)