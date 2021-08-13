cmake_minimum_required(VERSION 2.8)

project(texgen)
add_executable(texgen main.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(texgen ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
