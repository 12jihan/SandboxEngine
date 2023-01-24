cmake_minimum_required(VERSION 3.0.0)

project(Sandbox VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

# Copy appropriate files over to the binary directory:
file(COPY 
    src/resources 
    DESTINATION 
    ${CMAKE_BINARY_DIR}
) 
file(COPY 
    src/shaders 
    DESTINATION 
    ${CMAKE_BINARY_DIR}
) 

# Includes from different libraries:
file(GLOB INC_SRC
    external/glfw/include
    external/glad/include
    external/stb/include
    external/glm
    # external/assimp/include
)

# Variable for all the header files used:
file(GLOB HEADER_FILES
    headers/*.h
)
# Variable for all the classes used:
file(GLOB ALL_CLASSES
    src/*.c
    src/*.cpp
)
# Show me all Headers and Classes in project:
message("All available headers: \n" ${HEADER_FILES})
message("All available classes: \n" ${ALL_CLASSES})

# All classes to include in the executable:
add_executable(${PROJECT_NAME} 
    ${ALL_CLASSES}
)

# libraries and include files to add to project:
target_include_directories(${PROJECT_NAME} 
    PUBLIC ${INC_SRC}
)
target_link_libraries(${PROJECT_NAME} 
    glfw
    ${CMAKE_DL_LIBS}
)