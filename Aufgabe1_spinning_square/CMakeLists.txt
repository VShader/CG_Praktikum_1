project("Aufgabe1_spinning_square")
set(CMAKE_BUILD_TYPE Debug)

find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIR})
link_directories(${GLUT_LIBRARY_DIR})
add_definitions(${GLUT_DEFINITION})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)

find_package(OpenGL REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})# ${OPENGL_INCLUDE_DIRS})

file(GLOB_RECURSE proSOURCES *.cpp)
file(GLOB_RECURSE proHEADERS *.h)

add_executable(${PROJECT_NAME} ${proSOURCES} ${proHEADERS})
target_link_libraries(${PROJECT_NAME} ${GLUT_LIBRARY} ${OPENGL_LIBRARIES})
