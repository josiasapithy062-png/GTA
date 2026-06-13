// ELYRIA STORIES - Lavage de voiture

#include "carwash.h"

// Stations de lavage
CarWash carwashes[] = {
    {"Wash & Shine USA",    USA,    500.0f,  300.0f,  1},
    {"Clean King USA",      USA,    1200.0f, 200.0f,  1},
    {"Elyria Car Wash",     ELYRIA, 6100.0f, 400.0f,  1},
    {"Luxury Auto Wash",    ELYRIA, 6500.0f, 900.0f,  1},
    {"Port Car Wash",       USA,    900.0f,  -1200.0f,1},
};

int total_carwashes = 5;

// Laver voiture
void wash_car(int carwash_index, int vehicle_index) {
    if (carwashes[carwash_index].is_open) {
        // Voiture devient propre
        // Reduit niveau recherche de 1 etoile
        // Cout selon type lavage
    }
}

// Types de lavage
void basic_wash(int vehicle_index) {
    // Lavage basique - 50$
    // Enleve saleté
}

void premium_wash(int vehicle_index) {
    // Lavage premium - 200$
    // Enleve saleté + sang + traces
    // Reduit 1 etoile police
}

void luxury_wash(int vehicle_index) {
    // Lavage luxe - 500$
    // Voiture comme neuve
    // Reduit 2 etoiles police
    // Change couleur voiture
}
