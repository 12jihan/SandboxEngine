cmake_minimum_required(VERSION 3.0.0)
project(Sandbox VERSION 0.1.0)

file(COPY src/resources DESTINATION ${CMAKE_BINARY_DIR}) 
file(COPY src/shaders DESTINATION ${CMAKE_BINARY_DIR}) 


file(GLOB HEADER_FILES
    headers/**/*.h
    headers/*.h
)

file(GLOB ALL_CLASSES
    src/*.c
    src/*.cpp
)

add_executable(${PROJECT_NAME} 
    ${ALL_CLASSES}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
