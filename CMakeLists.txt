cmake_minimum_required(VERSION 3.11.0)
project(TestProject VERSION 1.0)

add_subdirectory(lib)
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE Horatio)
