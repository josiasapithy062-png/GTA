// ELYRIA STORIES - Systeme economie

#include "economy.h"

// Etat financier du joueur
PlayerEconomy economy = {
    .cash = 5000,
    .bank = 0,
    .total_earned = 0,
    .properties_owned = 0
};

// Liste des proprietes
Property properties[] = {
    // Garages
    {"Garage Liberty City",   GARAGE,   50000,  500,  USA,    0},
    {"Garage Elyria",         GARAGE,   60000,  600,  ELYRIA, 0},
    {"Mega Garage",           GARAGE,   150000, 1500, ELYRIA, 0},

    // Planques
    {"Planque USA",           SAFEHOUSE,30000,  0,    USA,    0},
    {"Planque Elyria",        SAFEHOUSE,40000,  0,    ELYRIA, 0},
    {"Manoir Elyria",         SAFEHOUSE,500000, 0,    ELYRIA, 0},

    // Entreprises
    {"Club Nightlife USA",    BUSINESS, 200000, 5000, USA,    0},
    {"Club Nightlife Elyria", BUSINESS, 250000, 6000, ELYRIA, 0},
    {"Coiffeur Liberty",      BUSINESS, 80000,  2000, USA,    0},
    {"Coiffeur Elyria",       BUSINESS, 90000,  2500, ELYRIA, 0},
    {"Boutique Fringues USA", BUSINESS, 100000, 3000, USA,    0},
    {"Boutique Fringues Ely", BUSINESS, 120000, 3500, ELYRIA, 0},

    // Militaire
    {"Arsenal Prive",         MILITARY, 1000000,10000,ELYRIA, 0},
};

int total_properties = 13;

// Ajouter de l argent
void add_cash(int amount) {
    economy.cash += amount;
    economy.total_earned += amount;
}

// Depenser de l argent
int spend_cash(int amount) {
    if (economy.cash >= amount) {
        economy.cash -= amount;
        return 1;
    }
    return 0;
}

// Acheter une propriete
int buy_property(int index) {
    if (spend_cash(properties[index].price)) {
        properties[index].is_owned = 1;
        economy.properties_owned++;
        return 1;
    }
    return 0;
}

// Deposer a la banque
void deposit_bank(int amount) {
    if (economy.cash >= amount) {
        economy.cash -= amount;
        economy.bank += amount;
    }
}

// Retirer de la banque
void withdraw_bank(int amount) {
    if (economy.bank >= amount) {
        economy.bank -= amount;
        economy.cash += amount;
    }
}
