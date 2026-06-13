#ifndef UNDERGROUND_H
#define UNDERGROUND_H
typedef enum { WEAPONS_BM, DRUGS_BM, PAPERS_BM, VEHICLES_BM, INFO_BM, EXPLO_BM } BlackMarketType;
typedef struct { char name[32]; BlackMarketType type; int country; float pos_x; float pos_y; int is_available; } BlackMarket;
extern BlackMarket black_market[];
extern int total_black_markets;
void access_black_market(int index);
void buy_illegal_item(int market, int item, int price);
void sell_stolen_car(int vehicle_index);
void launder_money(int amount);
#endif
