// ELYRIA STORIES - Systeme des armes

#include "weapons.h"

// Liste des armes
Weapon weapons[] = {
    // Corps a corps
    {"Poings",        MELEE,  0,    0,   999, 1},
    {"Couteau",       MELEE,  0,    25,  999, 0},
    {"Batte",         MELEE,  0,    40,  999, 0},

    // Pistolets
    {"Pistolet",      PISTOL, 35,   18,  500, 0},
    {"Pistolet 50",   PISTOL, 80,   7,   350, 0},

    // Fusils
    {"Shotgun",       SHOTGUN,120,  8,   200, 0},
    {"Shotgun Lourd", SHOTGUN,200,  6,   150, 0},

    // Mitraillettes
    {"Micro SMG",     SMG,    28,   35,  1500,0},
    {"SMG",           SMG,    45,   30,  1200,0},

    // Fusils assault
    {"AK47",          RIFLE,  65,   30,  1800,0},
    {"M16",           RIFLE,  55,   45,  2000,0},

    // Sniper
    {"Sniper",        SNIPER, 200,  1,   500, 0},
    {"Sniper Lourd",  SNIPER, 999,  1,   300, 0},

    // Armes lourdes
    {"RPG",           HEAVY,  500,  1,   50,  0},
    {"Minigun",       HEAVY,  150,  999, 9999,0},
    {"Grenade",       HEAVY,  300,  1,   20,  0},
    {"Molotov",       HEAVY,  200,  1,   15,  0},
};

int total_weapons = 17;

// Ramasser une arme
void pickup_weapon(int index) {
    weapons[index].is_owned = 1;
}

// Tirer
void fire_weapon(int index) {
    if (weapons[index].ammo > 0) {
        weapons[index].ammo--;
    }
}

// Recharger
void reload_weapon(int index, int ammo) {
    weapons[index].ammo += ammo;
}
