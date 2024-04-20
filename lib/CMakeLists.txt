cmake_minimum_required(VERSION 3.11.0)
project(Horatio VERSION 1.0)

find_package(glfw3 REQUIRED)
if(NOT TARGET glfw)
  message(FATAL_ERROR "GLFW library not found")
endif()

find_package(GLEW REQUIRED)
if(NOT TARGET GLEW::GLEW)
  message(FATAL_ERROR "GLEW library not found")
endif()

find_package(OpenGL REQUIRED)
if(NOT TARGET OpenGL::GL)
  message(FATAL_ERROR "OpenGL library not found")
endif()

add_library(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/Window.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        # where the library itself will look for its internal headers
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        # where top-level project will look for the library's public headers
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        # where external projects will look for the library's public headers
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE 
        glfw
        GLEW::GLEW
        OpenGL::GL
)