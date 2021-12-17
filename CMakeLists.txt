cmake_minimum_required(VERSION 3.12)

project(game)

add_subdirectory(deps/glfw)
add_subdirectory(deps/glew/build/cmake)
add_subdirectory(deps/glm)

add_executable(game)

file(
    GLOB SHADERS_SRC
    shaders/*.glsl
)
file(GLOB SRC_FILES    #TODOS OS ARQUIVOS FONTE
    resources/*.cpp
    resources/*.h
    
)
target_sources(game 
    PRIVATE

    ${SHADERS_SRC}
    ${SRC_FILES}
    MainBehaviour.cpp
)

target_include_directories(game PRIVATE 
    deps/glfw/include
    deps/glew/include
    deps/glm/glm
    resources
    shaders
)

target_link_libraries(game PRIVATE 
    glm
    glfw
    glew
    opengl32
)

add_custom_command(TARGET game POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_SOURCE_DIR}/build/bin/Debug/glew32d.dll" "${CMAKE_SOURCE_DIR}/build/Debug/glew32d.dll"
                COMMAND ${CMAKE_COMMAND} -E create_symlink "${CMAKE_SOURCE_DIR}/shaders" "${CMAKE_BINARY_DIR}/Debug/shaders"
				)