// ELYRIA STORIES - Monde complet
// USA + ELYRIA - Port/Mer/Aeroport proches

#include "world.h"

// Les deux pays
Country countries[2] = {
    {"ETATS-UNIS", "Liberty City", 1, 5000.0f, 0.0f},
    {"ELYRIA",     "Elyria City",  1, 5001.0f, 0.0f}
};

// Toutes les zones de la carte
Zone zones[] = {

    // ================================
    // USA - Liberty City et environs
    // ================================
    {"Liberty City Centre",  USA, 0.0f,    0.0f,    CITY,     1},
    {"Quartier Nord",        USA, 500.0f,  800.0f,  CITY,     1},
    {"Quartier Sud",         USA, 500.0f, -800.0f,  CITY,     1},
    {"Millwood Village",     USA, 2000.0f, 1000.0f, VILLAGE,  1},

    // Port et Mer USA - proches de la ville
    {"Port Liberty",         USA, 800.0f, -1200.0f, PORT,     1},
    {"Mer des Caraïbes USA", USA, 800.0f, -2000.0f, SEA,      1},
    {"Plage Liberty",        USA, 600.0f, -1500.0f, BEACH,    1},

    // Aeroport USA - proche du port
    {"Aeroport Liberty",     USA, 1200.0f,-1300.0f, AIRPORT,  1},
    {"Piste 1",              USA, 1400.0f,-1400.0f, AIRPORT,  1},
    {"Hangar Prive",         USA, 1600.0f,-1200.0f, AIRPORT,  1},

    // Routes et autoroutes
    {"Autoroute Nord",       USA, 1000.0f, 2000.0f, ROAD,     1},
    {"Desert Highway",       USA, 3000.0f, 500.0f,  ROAD,     1},

    // Frontiere
    {"Poste Frontiere USA",  USA, 4800.0f, 0.0f,    BORDER,   1},
    {"Zone Tampon",          USA, 4900.0f, 0.0f,    BORDER,   1},

    // ================================
    // ELYRIA - Pays principal
    // ================================
    {"Elyria City Centre",   ELYRIA, 6000.0f, 0.0f,    CITY,     0},
    {"Quartier Riche",       ELYRIA, 6500.0f, 800.0f,  CITY,     0},
    {"Quartier Pauvre",      ELYRIA, 6500.0f,-800.0f,  CITY,     0},
    {"Elyria Village",       ELYRIA, 8000.0f, 1000.0f, VILLAGE,  0},
    {"Village Sud Elyria",   ELYRIA, 8000.0f,-1000.0f, VILLAGE,  0},

    // Port et Mer ELYRIA - proches de la ville
    {"Grand Port Elyria",    ELYRIA, 6200.0f,-1200.0f, PORT,     0},
    {"Mer d Elyria",         ELYRIA, 6200.0f,-2000.0f, SEA,      0},
    {"Plage Elyria",         ELYRIA, 6000.0f,-1500.0f, BEACH,    0},
    {"Dock Secret",          ELYRIA, 6800.0f,-1400.0f, PORT,     0},

    // Aeroport ELYRIA - proche du port
    {"Aeroport Elyria",      ELYRIA, 6800.0f,-1300.0f, AIRPORT,  0},
    {"Piste Militaire",      ELYRIA, 7000.0f,-1400.0f, AIRPORT,  0},
    {"Hangar Militaire",     ELYRIA, 7200.0f,-1200.0f, AIRPORT,  0},

    // Sites militaires
    {"Arsenal National",     ELYRIA, 7000.0f, 2000.0f, MILITARY, 0},
    {"Base Militaire",       ELYRIA, 7500.0f, 2500.0f, MILITARY, 0},
    {"Palais Presidential",  ELYRIA, 6200.0f, 1500.0f, MILITARY, 0},

    // Frontiere ELYRIA
    {"Poste Frontiere Ely",  ELYRIA, 5200.0f, 0.0f,    BORDER,   0},
};

int total_zones = 31;
int current_country = USA;
int current_zone = 0;

// Verifier traversee frontiere
void check_border_crossing(float player_x) {
    if (player_x >= 4800.0f && player_x <= 5200.0f) {
        trigger_border_control();
    }
    if (player_x > 5200.0f) {
        current_country = ELYRIA;
    } else {
        current_country = USA;
    }
}

// Controle douanier
void trigger_border_control() {
    // Douaniers approchent
    // Joueur doit montrer papiers
    // Si refuse : 3 etoiles police
}

// Entrer dans la mer
void enter_sea(float player_x, float player_y) {
    if (player_y < -1500.0f) {
        // Le joueur est dans la mer
        // Activer physique bateau
    }
}

// Charger zone
void load_zone(int zone_index) {
    current_zone = zone_index;
    zones[zone_index].is_loaded = 1;
}
