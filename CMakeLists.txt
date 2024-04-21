cmake_minimum_required(VERSION 3.11.0)
project(TestProject VERSION 1.0)

add_subdirectory(lib)
add_executable(${PROJECT_NAME})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
        src/TestGame.h
        src/TestGame.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Horatio)

# Probably not the correct way to do this
file(COPY ${CMAKE_CURRENT_SORUCE_DIR}res DESTINATION ${CMAKE_CURRENT_BINARY_DIR})