cmake_minimum_required(VERSION 3.5)
project(EEngine)
set (CMAKE_CXX_STANDARD 11)

include_directories(glfw-3.2.1/include)

add_subdirectory(glfw-3.2.1/)


find_package(OpenGL REQUIRED)

set(GLEW_INCLUDE_DIR, "/glew-2.1.0/include/")
set(GLEW_LIBRARY, "/glew-2.1.0/lib/")

find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()



include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLFW_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIR})


set(SOURCE_FILES main.cpp)

message(WARNING "${GLFW_LIBRARIES}")

add_executable(EEngine ${SOURCE_FILES})

target_link_libraries(EEngine glfw ${GLFW_LIBRARIES})

target_link_libraries(EEngine glfw ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})

