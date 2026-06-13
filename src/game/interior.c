// ELYRIA STORIES - Interieurs batiments
#include "interior.h"
Interior interiors[] = {
    {"Appartement Josias",  APARTMENT, USA,    1, 0},
    {"Manoir Mikael",       MANSION,   USA,    1, 0},
    {"Planque Trev",        HIDEOUT,   USA,    1, 0},
    {"Banque Centrale",     BANK,      USA,    1, 0},
    {"Strip Club USA",      CLUB,      USA,    1, 0},
    {"Coiffeur USA",        SHOP,      USA,    1, 0},
    {"Boutique Fringues",   SHOP,      USA,    1, 0},
    {"Palais Presidential", PALACE,    ELYRIA, 1, 0},
    {"Arsenal National",    MILITARY,  ELYRIA, 1, 0},
    {"Strip Club Elyria",   CLUB,      ELYRIA, 1, 0},
    {"Casino Elyria",       CASINO,    ELYRIA, 1, 0},
    {"Hopital Elyria",      HOSPITAL,  ELYRIA, 1, 0},
    {"Commissariat USA",    POLICE,    USA,    1, 0},
    {"Salle de Sport",      GYM,       USA,    1, 0},
    {"Restaurant Luxe",     RESTAURANT,ELYRIA, 1, 0},
};
int total_interiors = 15;
void enter_interior(int index) { interiors[index].is_loaded = 1; }
void exit_interior(int index) { interiors[index].is_loaded = 0; }
