cmake_minimum_required(VERSION 3.5)
project(EEngine)
set (CMAKE_CXX_STANDARD 11)

include_directories(glfw-3.2.1/include)
#include_directories(glew-2.1.0/include)

add_subdirectory(glfw-3.2.1/)
#add_subdirectory(glew-2.1.0/build/cmake)	
#include_directories(glew-2.1.0/lib)

find_package(OpenGL REQUIRED)

include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIR})

set(SOURCE_FILES main.cpp)

add_executable(EEngine ${SOURCE_FILES})

#target_link_libraries(EEngine glfw ${GLFW_LIBRARIES})


find_package ( GLEW REQUIRED )
#target_link_libraries( EEngine GLEW::GLEW )

target_link_libraries(EEngine glfw ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})
