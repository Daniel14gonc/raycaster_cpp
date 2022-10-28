cmake_minimum_required(VERSION 3.22.1)

project(Raycaster)

add_executable(ray src/main.cpp)

add_subdirectory(
    raycaster_lib
)

add_subdirectory(
    src/glad
)

target_include_directories(ray
  PUBLIC src/glad
)

target_link_directories(ray
  PRIVATE external/glfw/src
  PRIVATE src/glad
)

target_link_libraries(
    ray raycaster_lib
    glad
    glfw
    GL
)