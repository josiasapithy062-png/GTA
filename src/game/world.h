// ELYRIA STORIES - Header monde
#ifndef WORLD_H
#define WORLD_H

typedef enum {
    USA,
    ELYRIA
} CountryID;

typedef enum {
    CITY,
    VILLAGE,
    ROAD,
    BORDER,
    MILITARY
} ZoneType;

typedef struct {
    char name[32];
    char capital[32];
    int has_border;
    float border_x;
    float border_y;
} Country;

typedef struct {
    char name[32];
    CountryID country;
    float pos_x;
    float pos_y;
    ZoneType type;
    int is_loaded;
} Zone;

extern Country countries[2];
extern Zone zones[];
extern int current_country;
extern int current_zone;

void check_border_crossing(float player_x);
void trigger_border_control();
void load_zone(int zone_index);

#endif
