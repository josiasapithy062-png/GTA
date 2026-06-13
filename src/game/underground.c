// Marche noir et activites illegales
#include "underground.h"
BlackMarket black_market[] = {
    {"Armes illegales",    WEAPONS_BM,  USA,    800.0f,  600.0f,  1},
    {"Drogues",            DRUGS_BM,    USA,    900.0f,  700.0f,  1},
    {"Faux papiers",       PAPERS_BM,   ELYRIA, 6400.0f, 800.0f,  1},
    {"Vehicules voles",    VEHICLES_BM, ELYRIA, 6600.0f, 900.0f,  1},
    {"Informations",       INFO_BM,     USA,    700.0f,  500.0f,  1},
    {"Explosifs",          EXPLO_BM,    ELYRIA, 7200.0f, 1000.0f, 1},
};
int total_black_markets = 6;
void access_black_market(int index) { }
void buy_illegal_item(int market, int item, int price) { }
void sell_stolen_car(int vehicle_index) { }
void launder_money(int amount) { }
