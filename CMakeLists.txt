cmake_minimum_required(VERSION 3.24)
project(rl_particle VERSION 0.1)

set(CMAKE_BUILD_TYPE RELEASE)
set(OpenGL_GL_PREFERENCE GLVND)

add_subdirectory(vendors)
add_subdirectory(particle)
