cmake_minimum_required(VERSION 3.0)
project(ELYRIA_STORIES)

set(CMAKE_C_STANDARD 99)

set(SOURCES
    src/main.c
    src/engine/graphics.c
    src/engine/physics.c
    src/engine/controls.c
    src/game/characters.c
    src/game/vehicles.c
    src/game/luxury_cars.c
    src/game/classic_cars.c
    src/game/world.c
    src/game/missions.c
    src/game/weapons.c
    src/game/police.c
    src/game/economy.c
    src/game/phone.c
    src/game/npcs.c
    src/game/vegetation.c
    src/game/audio.c
    src/game/heist_equipment.c
    src/game/gta5_features.c
    src/game/carwash.c
    src/game/cheats.c
    src/game/parachute.c
    src/game/savegame.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

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
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    TITLE "ELYRIA STORIES"
    BUILD_PRX 1
)
