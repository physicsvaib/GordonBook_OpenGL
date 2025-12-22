cmake_minimum_required(VERSION 3.10.0)
project(Gordon VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Gordon main.cpp glad/glad.h glad/glad.c)

target_link_libraries(Gordon PRIVATE glfw OpenGL::GL)