// ELYRIA STORIES - Codes de triche

#include "cheats.h"
#include "economy.h"
#include "weapons.h"
#include "police.h"
#include "characters.h"

// Liste des codes de triche
Cheat cheats[] = {
    {"RICHEMAN",   MONEY,     "Obtenir 1 million"},
    {"IRONMAN",    ARMOR,     "Armure complete"},
    {"DOCTORVIE",  HEALTH,    "Vie complete"},
    {"ARSENAL",    ALL_WEAPONS,"Toutes les armes"},
    {"MINIFORCE",  MINIGUN,   "Obtenir minigun"},
    {"TANKMAN",    TANK,      "Faire apparaitre tank"},
    {"FLYBIRD",    HELICOPTER,"Faire apparaitre helicoptere"},
    {"PLANEMAN",   PLANE,     "Faire apparaitre avion"},
    {"NOPOLICE",   NO_WANTED, "Supprimer etoiles police"},
    {"MAXWANTED",  MAX_WANTED,"5 etoiles police"},
    {"FASTCAR",    SPEED_CAR, "Voitures super rapides"},
    {"SUPERMAN",   INVINCIBLE,"Invincible"},
    {"MOONWALK",   LOW_GRAVITY,"Gravite reduite"},
    {"RAINFIRE",   EXPLOSIONS,"Balles explosives"},
    {"ELYRIAKING", ALL_PROPS, "Toutes les proprietes"},
    {"GANGSTER",   ALL_CHARS, "Debloquer tous personnages"},
};

int total_cheats = 16;

// Activer un code
void activate_cheat(char* code) {
    for (int i = 0; i < total_cheats; i++) {
        if (strcmp(cheats[i].code, code) == 0) {
            apply_cheat(cheats[i].effect);
            return;
        }
    }
}

// Appliquer l effet du code
void apply_cheat(CheatEffect effect) {
    Character* player = get_active_character();

    switch(effect) {
        case MONEY:
            add_cash(1000000);
            break;
        case HEALTH:
            player->health = 100;
            break;
        case ARMOR:
            player->armor = 100;
            break;
        case ALL_WEAPONS:
            for(int i = 0; i < total_weapons; i++)
                pickup_weapon(i);
            break;
        case MINIGUN:
            pickup_weapon(14);
            reload_weapon(14, 9999);
            break;
        case NO_WANTED:
            lose_police();
            break;
        case MAX_WANTED:
            add_wanted_level(5);
            break;
        case INVINCIBLE:
            player->health = 9999;
            player->armor = 9999;
            break;
        case ALL_PROPS:
            for(int i = 0; i < total_properties; i++)
                properties[i].is_owned = 1;
            break;
        case ALL_CHARS:
            for(int i = 0; i < 4; i++)
                characters[i].is_active = 1;
            break;
        default:
            break;
    }
}
