cmake_minimum_required(VERSION 3.5)
project(EEngine)
set (CMAKE_CXX_STANDARD 11)

find_package(OpenGL REQUIRED)

add_subdirectory(glew-2.1.0/build/cmake)
add_subdirectory(glfw-3.2.1/)

include_directories(glew-2.1.0/include)
include_directories(glfw-3.2.1/include)


include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS})


set(SOURCE_FILES main.cpp)

message(WARNING "${GLFW_LIBRARIES}")

add_executable(EEngine ${SOURCE_FILES})

target_link_libraries(EEngine glfw ${GLFW_LIBRARIES})

target_link_libraries(EEngine glfw ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES})

