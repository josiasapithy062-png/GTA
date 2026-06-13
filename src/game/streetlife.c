// Vie de rue
#include "streetlife.h"
StreetEvent events[] = {
    {"Bagarre",     FIGHT,    USA,    300.0f, 200.0f, 0},
    {"Accident",    ACCIDENT, USA,    500.0f, 100.0f, 0},
    {"Vol",         ROBBERY,  USA,    200.0f, 300.0f, 0},
    {"Fusillade",   SHOOTING, USA,    700.0f, 600.0f, 0},
    {"Incendie",    FIRE,     USA,    300.0f, 500.0f, 0},
    {"Dealeur",     DEAL,     USA,    600.0f, 700.0f, 0},
    {"Fete",        PARTY,    ELYRIA, 6500.0f,300.0f, 0},
    {"Marche",      MARKET,   ELYRIA, 6300.0f,400.0f, 0},
};
int total_events = 8;
void trigger_event(int i) { events[i].is_active=1; }
void end_event(int i) { events[i].is_active=0; }
