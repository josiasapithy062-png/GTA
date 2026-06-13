// ELYRIA STORIES - Header arsenal national
#ifndef ARSENAL_H
#define ARSENAL_H

typedef enum {
    RIFLE,
    SNIPER,
    MACHINE,
    MINIGUN,
    RPG,
    MISSILE,
    EXPLOSIVE,
    TANK_W,
    HELI_W,
    PLANE_W,
    APC_W
} ArsenalWeaponType;

typedef struct {
    char name[64];
    ArsenalWeaponType type;
    int damage;
    int ammo;
    int price;
    int is_stolen;
} ArsenalWeapon;

typedef struct {
    int is_infiltrated;
    int guards_count;
    int alert_level;
    int weapons_stolen;
} ArsenalState;

extern ArsenalWeapon arsenal_weapons[];
extern ArsenalState arsenal;
extern int total_arsenal_weapons;

void infiltrate_arsenal();
int steal_arsenal_weapon(int index);
void trigger_arsenal_alarm();
void destroy_arsenal_building();

#endif
