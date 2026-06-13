// ELYRIA STORIES - Systeme de gangs

#include "gangs.h"

// Gangs disponibles
Gang gangs[] = {
    // USA
    {
        .name = "Los Santos Bloods",
        .country = USA,
        .color = 0xFF0000FF,
        .territory_x = 200.0f,
        .territory_y = 300.0f,
        .members = 50,
        .respect = 0,
        .is_ally = 0,
        .is_enemy = 0
    },
    {
        .name = "Liberty Crips",
        .country = USA,
        .color = 0xFFFF0000,
        .territory_x = 800.0f,
        .territory_y = 500.0f,
        .members = 45,
        .respect = 0,
        .is_ally = 0,
        .is_enemy = 0
    },
    {
        .name = "Downtown Mafia",
        .country = USA,
        .color = 0xFF000000,
        .territory_x = 400.0f,
        .territory_y = 100.0f,
        .members = 30,
        .respect = 0,
        .is_ally = 0,
        .is_enemy = 0
    },
    // ELYRIA
    {
        .name = "Elyria Kings",
        .country = ELYRIA,
        .color = 0xFF00FF00,
        .territory_x = 6200.0f,
        .territory_y = 800.0f,
        .members = 60,
        .respect = 0,
        .is_ally = 1,
        .is_enemy = 0
    },
    {
        .name = "Elyria Cartel",
        .country = ELYRIA,
        .color = 0xFFFFFF00,
        .territory_x = 6800.0f,
        .territory_y = 500.0f,
        .members = 40,
        .respect = 0,
        .is_ally = 0,
        .is_enemy = 1
    },
    {
        .name = "Garde Presidentielle",
        .country = ELYRIA,
        .color = 0xFFFFFFFF,
        .territory_x = 6200.0f,
        .territory_y = 1500.0f,
        .members = 100,
        .respect = 0,
        .is_ally = 0,
        .is_enemy = 1
    },
};

int total_gangs = 6;

// Rejoindre un gang
void join_gang(int index) {
    gangs[index].is_ally = 1;
    gangs[index].is_enemy = 0;
}

// Declarer guerre
void declare_war(int index) {
    gangs[index].is_enemy = 1;
    gangs[index].is_ally = 0;
}

// Gagner respect gang
void earn_gang_respect(int index, int amount) {
    gangs[index].respect += amount;
    if (gangs[index].respect > 100)
        gangs[index].respect = 100;
}

// Conquete territoire
void conquer_territory(int gang_index,
                       float x, float y) {
    gangs[gang_index].territory_x = x;
    gangs[gang_index].territory_y = y;
}
