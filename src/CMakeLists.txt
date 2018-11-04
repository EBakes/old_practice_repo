cmake_minimum_required(VERSION 3.5)

project(EEngine)

set (CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_executable(EEngine ${SOURCE_FILES})

find_package(OpenGL REQUIRED)
find_package ( GLEW REQUIRED)

target_link_libraries(EEngine glfw ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR})

add_subdirectory(glfw-3.2.1/)

include_directories(glfw-3.2.1/include)
