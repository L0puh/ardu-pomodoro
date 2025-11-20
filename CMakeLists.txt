cmake_minimum_required(VERSION 3.31)
project(ardu-pomodoro)

cmake_policy(SET CMP0072 NEW)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs)

set(IMGUI_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui)
set(IMGUI_LIB imgui)
set(GLFW_LIB glfw)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/gui-settings/src/**/*.cpp
)
add_executable(ardu-pomodoro ${SOURCES})

target_link_libraries(ardu-pomodoro PRIVATE
   ${IMGUI_LIB}
   ${GLFW_LIB}
   OpenGL::GL
   nlohmann_json::nlohmann_json
)
target_include_directories( ardu-pomodoro PRIVATE
   gui-settings/include
   include
   ${IMGUI_INCLUDE_DIR}
)
