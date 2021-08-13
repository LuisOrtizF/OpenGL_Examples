cmake_minimum_required(VERSION 2.8)

project(bezsurf)
add_executable(bezsurf main.c)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(bezsurf ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
