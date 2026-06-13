// Succes et trophees
#include "achievements.h"
Achievement achievements[] = {
    {"Premier sang",       "Tue ton premier ennemi",          0},
    {"Chauffeur fou",      "Vole 10 voitures",                0},
    {"Millionnaire",       "Gagne 1 million",                 0},
    {"Intouchable",        "Echappe 5 etoiles police",        0},
    {"Pilote as",          "Vol 1 heure en avion",            0},
    {"Roi des mers",       "Navigue 30 minutes en bateau",    0},
    {"Braqueur legendaire","Complete le braquage du siecle",  0},
    {"Liberateur",         "Complete le coup d etat",         0},
    {"Collectionneur",     "Possede 10 voitures de luxe",     0},
    {"Globe trotter",      "Visite les 2 pays",               0},
    {"Sniper elite",       "100 tirs precis",                 0},
    {"Invincible",         "Survie 5 etoiles 10 minutes",     0},
    {"Le Boss",            "Complete toutes les missions",    0},
    {"Cameleon",           "Utilise tous les deguisements",   0},
    {"Richissime",         "Achete toutes les proprietes",    0},
};
int total_achievements = 15;
void unlock_achievement(int index) {
    if(!achievements[index].is_unlocked) {
        achievements[index].is_unlocked = 1;
    }
}
void check_achievements() {
    for(int i = 0; i < total_achievements; i++)
        if(!achievements[i].is_unlocked) { }
}
