// ELYRIA STORIES - Header economie
#ifndef ECONOMY_H
#define ECONOMY_H

typedef enum {
    GARAGE,
    SAFEHOUSE,
    BUSINESS,
    MILITARY
} PropertyType;

typedef struct {
    char name[32];
    PropertyType type;
    int price;
    int daily_income;
    int country;
    int is_owned;
} Property;

typedef struct {
    int cash;
    int bank;
    int total_earned;
    int properties_owned;
} PlayerEconomy;

extern PlayerEconomy economy;
extern Property properties[];
extern int total_properties;

void add_cash(int amount);
int spend_cash(int amount);
int buy_property(int index);
void deposit_bank(int amount);
void withdraw_bank(int amount);

#endif
