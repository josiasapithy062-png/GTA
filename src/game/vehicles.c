// ELYRIA STORIES - Vehicules complets

#include "vehicles.h"

Vehicle vehicles[] = {
    // Voitures
    {"Sultan",        CAR,         150.0f, 8.0f,  5.0f,  0},
    {"Infernus",      CAR,         200.0f, 10.0f, 4.0f,  0},
    {"Stockade",      CAR,         100.0f, 5.0f,  8.0f,  0},
    {"Limousine",     CAR,         130.0f, 6.0f,  5.0f,  0},
    {"Taxi",          CAR,         120.0f, 7.0f,  6.0f,  0},
    {"Police Car",    CAR,         180.0f, 9.0f,  7.0f,  0},
    {"Ambulance",     CAR,         140.0f, 7.0f,  6.0f,  0},
    {"Camion",        CAR,         90.0f,  4.0f,  9.0f,  0},

    // Motos
    {"Moto Sport",    MOTORCYCLE,  220.0f, 12.0f, 4.0f,  0},
    {"Chopper",       MOTORCYCLE,  160.0f, 8.0f,  6.0f,  0},
    {"Quad",          MOTORCYCLE,  100.0f, 6.0f,  8.0f,  0},
    {"Moto Police",   MOTORCYCLE,  200.0f, 11.0f, 5.0f,  0},

    // Avions - Aeroport pres du port
    {"Hydra",         PLANE,       400.0f, 15.0f, 3.0f,  0},
    {"Dodo",          PLANE,       300.0f, 12.0f, 4.0f,  0},
    {"Cargo",         PLANE,       250.0f, 8.0f,  5.0f,  0},
    {"Jet Prive",     PLANE,       380.0f, 14.0f, 3.5f,  0},

    // Helicopteres
    {"Maverick",      HELICOPTER,  200.0f, 8.0f,  6.0f,  0},
    {"Hunter",        HELICOPTER,  280.0f, 10.0f, 5.0f,  0},
    {"Police Heli",   HELICOPTER,  220.0f, 9.0f,  6.0f,  0},

    // Bateaux - Port et mer proches
    {"Speedboat",     BOAT,        180.0f, 10.0f, 5.0f,  0},
    {"Yacht",         BOAT,        120.0f, 5.0f,  7.0f,  0},
    {"Bateau Police", BOAT,        160.0f, 8.0f,  6.0f,  0},
    {"Hors-bord",     BOAT,        200.0f, 12.0f, 4.0f,  0},
    {"Sous-marin",    BOAT,        80.0f,  4.0f,  8.0f,  0},

    // Militaires
    {"Rhino Tank",    TANK,        80.0f,  3.0f,  15.0f, 0},
    {"APC",           TANK,        100.0f, 4.0f,  12.0f, 0},
};

int total_vehicles = 26;
int current_vehicle = -1;

void enter_vehicle(int index) {
    current_vehicle = index;
    vehicles[index].is_occupied = 1;
}

void exit_vehicle() {
    if (current_vehicle >= 0) {
        vehicles[current_vehicle].is_occupied = 0;
        current_vehicle = -1;
    }
}

void steal_vehicle(int index) {
    enter_vehicle(index);
}
