// Editeur de carte interne
#include "map_editor.h"
Building buildings[] = {
    {"Banque Centrale",  BANK_B,    USA,    200.0f,  100.0f,  50.0f, 100},
    {"Hotel Liberty",    HOTEL,     USA,    400.0f,  200.0f,  80.0f, 100},
    {"Commissariat",     POLICE_B,  USA,    100.0f,  100.0f,  30.0f, 100},
    {"Hopital USA",      HOSPITAL_B,USA,    300.0f,  300.0f,  40.0f, 100},
    {"Palais Elyria",    PALACE_B,  ELYRIA, 6200.0f, 1500.0f, 100.0f,100},
    {"Arsenal Elyria",   ARSENAL_B, ELYRIA, 7000.0f, 2000.0f, 80.0f, 100},
    {"Tour Elyria",      TOWER,     ELYRIA, 6000.0f, 0.0f,    150.0f,100},
    {"Casino Elyria",    CASINO_B,  ELYRIA, 6500.0f, 500.0f,  60.0f, 100},
};
int total_buildings = 8;
void damage_building(int index, int damage) {
    buildings[index].health -= damage;
    if(buildings[index].health <= 0) destroy_building(index);
}
void destroy_building(int index) { buildings[index].health = 0; }
void repair_building(int index) { buildings[index].health = 100; }
