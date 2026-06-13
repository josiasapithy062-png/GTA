#include "map.h"
MapZone zones[]={
    {"Liberty City",USA,0,0,5000,5000,CITY_ZONE,1},
    {"Desert USA",USA,3000,0,2000,1000,DESERT,1},
    {"Ocean USA",USA,0,-2000,5000,2000,OCEAN,1},
    {"Elyria City",ELYRIA,6000,0,4000,4000,CITY_ZONE,0},
    {"Foret Elyria",ELYRIA,8000,1500,1000,800,FOREST,0},
    {"Ocean Elyria",ELYRIA,6000,-2000,4000,2000,OCEAN,0},
};
int total_zones=6;
void load_zone(int i){zones[i].is_loaded=1;}
void unload_zone(int i){zones[i].is_loaded=0;}
