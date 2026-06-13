// ELYRIA STORIES - Systeme de reputation

#include "reputation.h"

// Reputation de chaque personnage
Reputation reputations[4] = {
    // Josias
    {
        .character = "Josias",
        .street_cred = 0,
        .police_notoriety = 0,
        .gang_respect = 0,
        .political_power = 0,
        .wealth_status = 0,
        .total_kills = 0,
        .missions_done = 0
    },
    // Franck
    {
        .character = "Franck",
        .street_cred = 50,
        .police_notoriety = 30,
        .gang_respect = 60,
        .political_power = 0,
        .wealth_status = 20,
        .total_kills = 0,
        .missions_done = 0
    },
    // Mikael
    {
        .character = "Mikael",
        .street_cred = 30,
        .police_notoriety = 20,
        .gang_respect = 40,
        .political_power = 50,
        .wealth_status = 80,
        .total_kills = 0,
        .missions_done = 0
    },
    // Trev
    {
        .character = "Trev",
        .street_cred = 90,
        .police_notoriety = 90,
        .gang_respect = 80,
        .political_power = 0,
        .wealth_status = 30,
        .total_kills = 0,
        .missions_done = 0
    }
};

// Ajouter reputation
void add_street_cred(int char_index, int amount) {
    reputations[char_index].street_cred += amount;
    if (reputations[char_index].street_cred > 100)
        reputations[char_index].street_cred = 100;
}

// Ajouter notoriete police
void add_police_notoriety(int char_index, int amount) {
    reputations[char_index].police_notoriety += amount;
    if (reputations[char_index].police_notoriety > 100)
        reputations[char_index].police_notoriety = 100;
}

// Ajouter respect gang
void add_gang_respect(int char_index, int amount) {
    reputations[char_index].gang_respect += amount;
    if (reputations[char_index].gang_respect > 100)
        reputations[char_index].gang_respect = 100;
}

// Ajouter pouvoir politique
void add_political_power(int char_index, int amount) {
    reputations[char_index].political_power += amount;
    if (reputations[char_index].political_power > 100)
        reputations[char_index].political_power = 100;
}

// Obtenir niveau reputation
char* get_reputation_title(int char_index) {
    int cred = reputations[char_index].street_cred;
    if (cred < 10)  return "Inconnu";
    if (cred < 25)  return "Petit Malfrat";
    if (cred < 50)  return "Gangster";
    if (cred < 75)  return "Capo";
    if (cred < 90)  return "Boss";
    return "Legende des Rues";
}
