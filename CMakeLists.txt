cmake_minimum_required(VERSION 3.0.0)
project(Sandbox VERSION 0.1.0)

file(COPY src/resources DESTINATION ${CMAKE_BINARY_DIR}) 
file(COPY src/shaders DESTINATION ${CMAKE_BINARY_DIR}) 
file(GLOB INC_SRC
    external/glfw/include
    external/glad/include
    external/stb/include
    external/glm
    # external/assimp/include
)


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

add_subdirectory(
    external/glfw
    external/glad
)

target_include_directories(${PROJECT_NAME} 
    PUBLIC ${INC_SRC}
)

target_link_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/src
    # PUBLIC external/assimp/src
)


target_link_libraries(${PROJECT_NAME} 
    glfw
    # assimp
)