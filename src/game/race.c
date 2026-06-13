// Courses de rue
#include "race.h"
Race races[] = {
    {"Circuit Liberty",   CAR_RACE,   USA,    3,  5000,  1},
    {"Moto Drag USA",     MOTO_RACE,  USA,    2,  3000,  1},
    {"Elyria Grand Prix", CAR_RACE,   ELYRIA, 5,  10000, 1},
    {"Boat Race Port",    BOAT_RACE,  USA,    4,  8000,  1},
    {"Air Race Elyria",   PLANE_RACE, ELYRIA, 3,  15000, 1},
};
int total_races = 5;
void start_race(int index) { }
void finish_race(int index, int position) { }
void win_race_reward(int index) { }
