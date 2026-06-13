// ELYRIA STORIES - Header armes
#ifndef WEAPONS_H
#define WEAPONS_H

typedef enum {
    MELEE,
    PISTOL,
    SHOTGUN,
    SMG,
    RIFLE,
    SNIPER,
    HEAVY
} WeaponType;

typedef struct {
    char name[32];
    WeaponType type;
    int damage;
    int fire_rate;
    int ammo;
    int is_owned;
} Weapon;

extern Weapon weapons[];
extern int total_weapons;

void pickup_weapon(int index);
void fire_weapon(int index);
void reload_weapon(int index, int ammo);

#endif
