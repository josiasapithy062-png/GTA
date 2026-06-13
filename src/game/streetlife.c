// ELYRIA STORIES - Vie de rue PNJ
#include "streetlife.h"
StreetEvent events[] = {
    {"Bagarre de rue",      FIGHT,    USA,    300.0f,  200.0f,  1},
    {"Accident voiture",    ACCIDENT, USA,    500.0f,  100.0f,  1},
    {"Vol a la tire",       ROBBERY,  USA,    200.0f,  300.0f,  1},
    {"Manifestation",       PROTEST,  ELYRIA, 6100.0f, 200.0f,  1},
    {"Marche ambulant",     MARKET,   ELYRIA, 6300.0f, 400.0f,  1},
    {"Course de rue",       RACE,     USA,    800.0f,  100.0f,  1},
    {"Fusillade gang",      SHOOTING, USA,    700.0f,  600.0f,  1},
    {"Arrestation police",  ARREST,   USA,    400.0f,  300.0f,  1},
    {"Fete de quartier",    PARTY,    ELYRIA, 6500.0f, 300.0f,  1},
    {"Incendie batiment",   FIRE,     USA,    300.0f,  500.0f,  1},
    {"Dealeur de rue",      DEAL,     USA,    600.0f,  700.0f,  1},
    {"Prostituee",          ESCORT,   USA,    500.0f,  400.0f,  1},
    {"Musicien de rue",     MUSIC,    ELYRIA, 6200.0f, 100.0f,  1},
    {"Match de foot",       SPORT,    ELYRIA, 7000.0f, 300.0f,  1},
    {"Cambriolage",         BURGLARY, USA,    400.0f,  600.0f,  1},
};
int total_events = 15;
void trigger_event(int index) { events[index].is_active = 1; }
void end_event(int index) { events[index].is_active = 0; }
void intervene_event(int index) { end_event(index); }
