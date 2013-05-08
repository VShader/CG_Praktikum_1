cmake_minimum_required(VERSION 2.8)
project("OpenGL_QT_aGentleIntroduction")
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGl REQUIRED)
find_package(OpenGL REQUIRED)
include(${QT_USE_FILE})
#set(QT_USE_QTOPENGL TRUE)
ADD_DEFINITIONS(${QT_DEFINITIONS})




file(GLOB proSOURCES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB proHEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB proUIS ${CMAKE_CURRENT_SOURCE_DIR}/*.ui)

QT4_WRAP_UI(UISrcs ${proUIS})
QT4_WRAP_CPP(MOCSrcs ${proHEADERS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} )
add_executable(${PROJECT_NAME} ${proSOURCES}  ${proHEADERS} ${proUIS} ${UISrcs} ${MOCSrcs})
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES} ${OPENGL_LIBRARIES})
