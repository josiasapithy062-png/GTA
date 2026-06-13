// ELYRIA STORIES - Carte complete du monde
#include "map.h"
MapZone map_zones[] = {
    // USA Routes principales
    {"Route 1 USA",      USA, 0,      0,     5000,  50,   ROAD,   1},
    {"Route 2 USA",      USA, 0,      1000,  5000,  50,   ROAD,   1},
    {"Autoroute USA",    USA, 0,      0,     5000,  100,  HIGHWAY,1},
    // USA Zones vertes
    {"Parc Liberty",     USA, 200,    500,   300,   300,  PARK,   1},
    {"Foret Nord",       USA, 1000,   2000,  800,   600,  FOREST, 1},
    {"Desert Ouest",     USA, 3000,   0,     2000,  1000, DESERT, 1},
    // USA Eau
    {"Riviere Liberty",  USA, 500,    0,     50,    1000, RIVER,  1},
    {"Lac Nord",         USA, 1500,   1500,  300,   300,  LAKE,   1},
    {"Ocean USA",        USA, 0,      -2000, 5000,  2000, OCEAN,  1},
    // ELYRIA Routes
    {"Route 1 Elyria",   ELYRIA,6000, 0,    4000,  50,   ROAD,   0},
    {"Autoroute Elyria", ELYRIA,6000, 0,    4000,  100,  HIGHWAY,0},
    // ELYRIA Zones
    {"Parc Elyria",      ELYRIA,6200, 500,  400,   400,  PARK,   0},
    {"Foret Elyria",     ELYRIA,8000, 1500, 1000,  800,  FOREST, 0},
    {"Montagne Elyria",  ELYRIA,9000, 2000, 1000,  1000, MOUNTAIN,0},
    // ELYRIA Eau
    {"Ocean Elyria",     ELYRIA,6000,-2000, 4000,  2000, OCEAN,  0},
    {"Fleuve Elyria",    ELYRIA,7000, 0,    50,    2000, RIVER,  0},
    {"Lac Elyria",       ELYRIA,8500, 500,  400,   400,  LAKE,   0},
};
int total_map_zones = 17;
void load_map_zone(int index) { map_zones[index].is_loaded = 1; }
void unload_map_zone(int index) { map_zones[index].is_loaded = 0; }
int get_zone_at(float x, float y) {
    for(int i=0;i<total_map_zones;i++) {
        MapZone* z = &map_zones[i];
        if(x>=z->x && x<=z->x+z->width && y>=z->y && y<=z->y+z->height)
            return i;
    }
    return -1;
}
