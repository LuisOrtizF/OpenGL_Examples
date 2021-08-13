cmake_minimum_required(VERSION 2.8)

project(font)
add_executable(font main.c)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(font ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
