// ELYRIA STORIES - Systeme wanted avance
#include "wanted.h"
WantedSystem wanted = {0};
PoliceUnit units[] = {
    {"Policier a pied",   COP_FOOT,  1, 50,  0},
    {"Voiture de police", COP_CAR,   2, 100, 0},
    {"Moto police",       COP_MOTO,  2, 80,  0},
    {"SWAT",              SWAT,      3, 150, 0},
    {"Helicoptere",       COP_HELI,  3, 200, 0},
    {"FBI",               FBI,       4, 200, 0},
    {"Voiture FBI",       FBI_CAR,   4, 250, 0},
    {"Armee",             ARMY,      5, 300, 0},
    {"Tank",              ARMY_TANK, 5, 999, 0},
    {"Avion militaire",   ARMY_PLANE,5, 500, 0},
};
int total_units = 10;
void update_wanted(int stars) {
    wanted.level = stars;
    for(int i = 0; i < total_units; i++)
        units[i].is_deployed = (units[i].min_stars <= stars);
}
void escape_wanted() { wanted.level = 0; wanted.is_being_chased = 0; }
void bribe_police() { if(wanted.level > 0) wanted.level--; }
void call_lawyer() { wanted.level = 0; }
