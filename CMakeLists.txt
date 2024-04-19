cmake_minimum_required(VERSION 3.11.0)
project(Horatio VERSION 1.0)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS Source/*.cpp Source/*.h)

find_package(OpenGL REQUIRED)
if(NOT TARGET OpenGL::GL)
  message(FATAL_ERROR "OpenGL library not found")
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL)
