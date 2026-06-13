// ELYRIA STORIES - Header equipement braquage
#ifndef HEIST_EQUIPMENT_H
#define HEIST_EQUIPMENT_H

typedef enum {
    SILENCED,
    ASSAULT,
    EXPLOSIVE,
    SPECIAL
} HeistWeaponType;

typedef enum {
    BREACH,
    TECH,
    TRANSPORT,
    PROTECTION,
    DISGUISE,
    VEHICLE
} HeistToolType;

typedef enum {
    LEADER,
    SHOOTER,
    HACKER,
    DRIVER,
    BOMBER,
    STEALTH
} RoleType;

typedef struct {
    char name[32];
    HeistWeaponType type;
    int damage;
    int is_silenced;
    int ammo;
    int price;
    int is_owned;
} HeistWeapon;

typedef struct {
    char name[32];
    HeistToolType type;
    int price;
    int is_owned;
    char description[64];
} HeistTool;

typedef struct {
    char name[32];
    RoleType type;
    char description[64];
    int assigned_character;
} HeistRole;

extern HeistWeapon heist_weapons[];
extern HeistTool heist_tools[];
extern HeistRole roles[];
extern int total_heist_weapons;
extern int total_heist_tools;
extern int total_roles;

int buy_heist_tool(int index, int cash);
int buy_heist_weapon(int index, int cash);
void assign_role(int character_index, int role_index);
int check_heist_ready(int heist_index);

#endif
