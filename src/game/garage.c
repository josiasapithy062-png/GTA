// Garages et vehicules stockes
#include "garage.h"
Garage garages[] = {
    {"Garage Josias USA",   USA,    500.0f,  200.0f,  10, 0, 0},
    {"Garage Franck USA",   USA,    1000.0f, 300.0f,  8,  0, 0},
    {"Mega Garage Elyria",  ELYRIA, 6300.0f, 200.0f,  20, 0, 0},
    {"Garage Trev",         ELYRIA, 7500.0f, 500.0f,  15, 0, 0},
    {"Garage Port USA",     USA,    900.0f, -1100.0f, 12, 0, 0},
};
int total_garages = 5;
void buy_garage(int index, int price) { garages[index].is_owned = 1; }
void store_vehicle(int garage, int vehicle) { garages[garage].stored_vehicles++; }
void retrieve_vehicle(int garage, int vehicle) { garages[garage].stored_vehicles--; }
void repair_in_garage(int garage) { }
void customize_vehicle(int garage, int vehicle) { }
