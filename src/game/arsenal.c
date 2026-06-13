// ELYRIA STORIES - Arsenal National d Elyria

#include "arsenal.h"

// Armes de l arsenal national
ArsenalWeapon arsenal_weapons[] = {
    // Armes legeres
    {"Fusil d Assaut M16",    RIFLE,    85,  2500, 50000,  0},
    {"AK47 Militaire",        RIFLE,    90,  2000, 45000,  0},
    {"Sniper Barrett",        SNIPER,   999, 500,  200000, 0},
    {"Mitrailleuse M249",     MACHINE,  70,  5000, 150000, 0},

    // Armes lourdes
    {"Minigun M134",          MINIGUN,  150, 9999, 500000, 0},
    {"Minigun Dual",          MINIGUN,  200, 9999, 800000, 0},
    {"Lance Roquettes RPG7",  RPG,      800, 10,   300000, 0},
    {"Lance Missiles Stinger",MISSILE,  2000,5,    600000, 0},

    // Explosifs
    {"C4 Militaire",          EXPLOSIVE,2000,20,   100000, 0},
    {"Grenade Thermobarique", EXPLOSIVE,3000,10,   150000, 0},
    {"Mine Antichar",         EXPLOSIVE,5000,15,   200000, 0},
    {"Bombe a Fragmentation", EXPLOSIVE,4000,8,    250000, 0},

    // Vehicules militaires
    {"Tank Abrams M1A2",      TANK_W,   0,   1,    2000000,0},
    {"Helicopter Apache",     HELI_W,   0,   1,    3000000,0},
    {"Avion de Chasse F16",   PLANE_W,  0,   1,    5000000,0},
    {"APC Blindee",           APC_W,    0,   1,    1000000,0},
};

int total_arsenal_weapons = 16;

// Etat de l arsenal
ArsenalState arsenal = {
    .is_infiltrated = 0,
    .guards_count = 50,
    .alert_level = 0,
    .weapons_stolen = 0
};

// Infiltrer l arsenal
void infiltrate_arsenal() {
    arsenal.is_infiltrated = 1;
    arsenal.alert_level = 0;
}

// Voler une arme
int steal_arsenal_weapon(int index) {
    if (arsenal.is_infiltrated) {
        arsenal_weapons[index].is_stolen = 1;
        arsenal.weapons_stolen++;
        arsenal.alert_level += 20;
        return 1;
    }
    return 0;
}

// Declencher alarme
void trigger_arsenal_alarm() {
    arsenal.alert_level = 100;
    // Envoie 50 soldats
    // Police 5 etoiles
    // Helicopteres militaires
}

// Detruire batiment arsenal
void destroy_arsenal_building() {
    // Utilise explosifs ou minigun
    // Batiment s effondre
    // Cree explosion massive
}
