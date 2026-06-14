cmake_minimum_required(VERSION 3.5)
project(ELYRIA C)
set(PSPDEV /usr/local/pspdev)
add_executable(ELYRIA src/main.c)
target_link_libraries(ELYRIA
    pspdisplay pspgu pspgum
    pspge pspkernel pspctrl m)
create_pbp_file(
    TARGET ELYRIA
    TITLE "ELYRIA STORIES"
    BUILD_PRX 1)
