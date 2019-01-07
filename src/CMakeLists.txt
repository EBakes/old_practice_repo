cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(EEngine CXX)

set(SOURCE_FILES main.cpp)

add_executable(EEngine ${SOURCE_FILES})

target_compile_features(EEngine PRIVATE cxx_constexpr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set_property(TARGET EEngine PROPERTY CXX_STANDARD 17)



find_package(OpenGL REQUIRED)
find_package ( GLEW REQUIRED)



target_link_libraries(EEngine glfw ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES} ${GLEW_LIBRARIES})


include_directories(
        ${OPENGL_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR})

add_subdirectory(glfw-3.2.1/)

include_directories(glfw-3.2.1/include)
