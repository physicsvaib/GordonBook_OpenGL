cmake_minimum_required(VERSION 3.10.0)
project(Gordon VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Gordon
    main.cpp
    glad/glad.c
    src/reader.cpp   # use the .cpp implementation, not the .h
)

target_include_directories(Gordon PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/glad
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Gordon PRIVATE glfw OpenGL::GL)

# Optional: group shader files in IDEs (not compiled, just shown in project tree)
file(GLOB SHADERS "Shaders/*.glsl")
source_group("Shaders" FILES ${SHADERS})

# Optional: copy shaders into build directory so runtime paths work
file(COPY Shaders DESTINATION ${CMAKE_BINARY_DIR})
