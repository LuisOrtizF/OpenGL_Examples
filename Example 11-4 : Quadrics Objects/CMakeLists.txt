cmake_minimum_required(VERSION 2.8)
project(quadric)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

add_executable(quadric main.c)

target_link_libraries(quadric ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )