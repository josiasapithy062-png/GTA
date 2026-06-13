// ELYRIA STORIES - Boutiques vetements et coiffeur
#include "clothing_shop.h"
Shop shops[] = {
    {"Binco USA",        CLOTHING_SHOP, USA,    300.0f,  400.0f,  1},
    {"Suburban USA",     CLOTHING_SHOP, USA,    400.0f,  300.0f,  1},
    {"Ponsonbys USA",    LUXURY_SHOP,   USA,    600.0f,  200.0f,  1},
    {"Binco Elyria",     CLOTHING_SHOP, ELYRIA, 6100.0f, 400.0f,  1},
    {"Luxury Elyria",    LUXURY_SHOP,   ELYRIA, 6500.0f, 600.0f,  1},
    {"Coiffeur USA",     BARBER_SHOP,   USA,    350.0f,  250.0f,  1},
    {"Coiffeur Elyria",  BARBER_SHOP,   ELYRIA, 6200.0f, 300.0f,  1},
    {"Tatoueur USA",     TATTOO_SHOP,   USA,    450.0f,  350.0f,  1},
    {"Tatoueur Elyria",  TATTOO_SHOP,   ELYRIA, 6300.0f, 400.0f,  1},
    {"Shoe Shop USA",    SHOE_SHOP,     USA,    500.0f,  300.0f,  1},
    {"Shoe Shop Elyria", SHOE_SHOP,     ELYRIA, 6400.0f, 500.0f,  1},
};
int total_shops = 11;
void enter_shop(int index) { shops[index].is_open = 1; }
void buy_item(int shop_index, int item_index, int price) { }
void change_hairstyle_shop(int style) { }
void add_tattoo_shop(int tattoo) { }
