#ifndef MAP_H
#define MAP_H
typedef enum{CITY_ZONE,DESERT,OCEAN,FOREST,MOUNTAIN,ROAD_ZONE}ZoneType;
typedef struct{char name[32];int country;float x,y,w,h;ZoneType type;int is_loaded;}MapZone;
extern MapZone zones[];extern int total_zones;
void load_zone(int i);void unload_zone(int i);
#endif
