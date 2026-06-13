#ifndef MAP_H
#define MAP_H
typedef enum { ROAD, HIGHWAY, PARK, FOREST, DESERT, RIVER, LAKE, OCEAN, MOUNTAIN } ZoneMapType;
typedef struct { char name[32]; int country; float x,y,width,height; ZoneMapType type; int is_loaded; } MapZone;
extern MapZone map_zones[];
extern int total_map_zones;
void load_map_zone(int index);
void unload_map_zone(int index);
int get_zone_at(float x, float y);
#endif
