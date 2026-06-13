// ELYRIA STORIES - PNJ et animaux

#include "npcs.h"

// Liste des PNJ
NPC npcs[] = {
    // USA - Liberty City
    {"Passant homme",    CIVILIAN, USA,    0.0f,   200.0f,  100, 0},
    {"Passant femme",    CIVILIAN, USA,    300.0f, 100.0f,  100, 0},
    {"Vendeur rue",      CIVILIAN, USA,    500.0f, 300.0f,  100, 0},
    {"Policier",         POLICE,   USA,    100.0f, 100.0f,  150, 0},
    {"Gangster",         GANG,     USA,    800.0f, 500.0f,  120, 0},
    {"Dealer",           GANG,     USA,    900.0f, 600.0f,  100, 0},
    {"Douanier USA",     BORDER,   USA,    4800.0f,0.0f,    200, 0},
    {"Douanier USA 2",   BORDER,   USA,    4850.0f,100.0f,  200, 0},

    // ELYRIA - Ville
    {"Citoyen Elyria",   CIVILIAN, ELYRIA, 6000.0f,200.0f,  100, 0},
    {"Femme Elyria",     CIVILIAN, ELYRIA, 6300.0f,100.0f,  100, 0},
    {"Soldat Elyria",    MILITARY, ELYRIA, 7000.0f,2000.0f, 200, 0},
    {"Soldat Arsenal",   MILITARY, ELYRIA, 7500.0f,2500.0f, 200, 0},
    {"Douanier Elyria",  BORDER,   ELYRIA, 5200.0f,0.0f,    200, 0},
    {"Politicien",       CIVILIAN, ELYRIA, 6200.0f,1500.0f, 150, 0},
    {"Chef de Gang",     GANG,     ELYRIA, 6500.0f,800.0f,  180, 0},
    {"Coiffeur",         SERVICE,  ELYRIA, 6100.0f,300.0f,  100, 0},
    {"Vendeur Fringues", SERVICE,  USA,    400.0f, 400.0f,  100, 0},
    {"Mecanicien",       SERVICE,  USA,    1200.0f,200.0f,  100, 0},
};

// Liste des animaux
Animal animals[] = {
    // Chiens
    {"Chien errant",     DOG,   USA,    200.0f,  300.0f,  50,  1},
    {"Chien de garde",   DOG,   ELYRIA, 7000.0f, 2000.0f, 80,  1},
    {"Chien policier",   DOG,   USA,    100.0f,  100.0f,  100, 1},

    // Chats
    {"Chat de rue",      CAT,   USA,    400.0f,  200.0f,  30,  1},
    {"Chat Elyria",      CAT,   ELYRIA, 6200.0f, 300.0f,  30,  1},

    // Oiseaux
    {"Pigeon",           BIRD,  USA,    0.0f,    0.0f,    10,  1},
    {"Aigle",            BIRD,  ELYRIA, 7000.0f, 1000.0f, 20,  1},
    {"Perroquet",        BIRD,  ELYRIA, 6000.0f, 500.0f,  15,  1},

    // Animaux sauvages
    {"Cerf",             DEER,  USA,    2000.0f, 1500.0f, 60,  1},
    {"Renard",           FOX,   USA,    1500.0f, 1000.0f, 40,  1},
    {"Coyote",           FOX,   USA,    3000.0f, 500.0f,  50,  1},
    {"Serpent",          SNAKE, USA,    3500.0f, 600.0f,  30,  1},
    {"Crocodile",        CROC,  ELYRIA, 6500.0f,-1800.0f, 150, 1},

    // Animaux marins
    {"Dauphin",          FISH,  USA,    800.0f,  -2000.0f,80,  1},
    {"Requin",           FISH,  ELYRIA, 6200.0f, -2000.0f,200, 1},
    {"Baleine",          FISH,  USA,    600.0f,  -2500.0f,500, 1},
};

int total_npcs = 18;
int total_animals = 16;

// Faire parler un PNJ
void talk_to_npc(int index) {
    npcs[index].is_talking = 1;
}

// PNJ attaque
void npc_attack(int index) {
    npcs[index].is_hostile = 1;
}

// Animal attaque
void animal_attack(int animal_index) {
    animals[animal_index].is_hostile = 1;
}

// PNJ meurt
void npc_die(int index) {
    npcs[index].health = 0;
    npcs[index].is_alive = 0;
}
