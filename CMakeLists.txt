cmake_minimum_required(VERSION 3.0)

project(GPU-Bugger)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../out")

if(MSVC)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "../out")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "../out")
endif()

add_subdirectory("libs/SDL")
add_executable(GPU-Bugger "src/main.cpp")

target_link_libraries(GPU-Bugger PUBLIC SDL2-static)
target_include_directories(GPU-Bugger PUBLIC "libs/SDL/include")

if(MSVC)
set_target_properties(GPU-Bugger PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "../out")
endif() 
