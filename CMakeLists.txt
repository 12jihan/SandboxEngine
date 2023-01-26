cmake_minimum_required(VERSION 3.0.0)
project(Sandbox VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
message("CMAKE CURRENT DIR LIST:\n\t" ${CMAKE_CURRENT_LIST_DIR})
# set(IMGUI_PATH ${CMAKE_CURRENT_LIST_DIR}/external/imgui)
# message(" ")
# message("---------------------------------------------")
# message(" ")
# message("IMGUI CURRENT PATH\n\t" ${IMGUI_PATH})
# message(" ")
# message("---------------------------------------------")
# message(" ")
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

#includes all of Dear ImGui:
# file(GLOB IMGUI_SRCS
#     # CPP files:
#     ${IMGUI_PATH}/*.cpp
#     ${IMGUI_PATH}/backends/*.cpp
#     # Header files:
#     ${IMGUI_PATH}/*.h
#     ${IMGUI_PATH}/backends/*.h
# )
# message("IMGUI srcs list:\n\t" ${IMGUI_SRCS})
# message(" ")
# message("---------------------------------------------")
# message(" ")
# Includes from different libraries:
file(GLOB INC_SRC
    external/glfw/include
    external/glad/include
    external/stb/include
    external/glm
    # external/assimp/include
)
set(list
${INC_SRC})

# Variable for all the header files used:
file(GLOB HEADER_FILES
    src/headers/*.h
)
# Variable for all the classes used:
file(GLOB ALL_CLASSES
    src/*.c
    src/*.cpp
)
add_subdirectory(external/glfw)
# Show me all Headers and Classes in project:
message("All available headers: \n" ${HEADER_FILES})
message(" ")
message("---------------------------------------------")
message(" ")
message("All available classes: \n" ${ALL_CLASSES})
message(" ")
message("---------------------------------------------")
message(" ")
message("All available includes: \n" ${list})
foreach(X IN LISTS ${list})
    message("Lib: ${X}")
endforeach()

message(" ")
message("---------------------------------------------")
message(" ")
# All classes to include in the executable:
add_executable(${PROJECT_NAME} 
    ${ALL_CLASSES}
)

#ImGui specific stuff:
# add_library("imgui" STATIC ${IMGUI_SRCS})
# target_include_directories("imgui" PUBLIC ${IMGUI_PATH})
# target_link_libraries("imgui")

# libraries and include files to add to project:
target_include_directories(${PROJECT_NAME} 
    PUBLIC ${INC_SRC}
)
target_link_libraries(${PROJECT_NAME} 
    PRIVATE glfw
    ${CMAKE_DL_LIBS}
)