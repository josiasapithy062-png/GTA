cmake_minimum_required(VERSION 3.5)
project(ELYRIA_STORIES C)
set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
    src/engine
    src/game
)

target_link_libraries(${PROJECT_NAME}
    pspdisplay
    pspgu
    pspgum
    pspge
    pspkernel
    pspaudio
    pspctrl
    psputility
    pspuser
    m
)

create_pbp_file(
    TARGET ${PROJECT_NAME}
    TITLE "ELYRIA STORIES"
    BUILD_PRX 1
)
