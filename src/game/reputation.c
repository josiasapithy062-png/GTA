// ELYRIA STORIES - Reputation
#include "reputation.h"

Reputation reputations[4] = {
    {"Josias", 0,  0,  0,  0,  0},
    {"Franck", 50, 30, 60, 0,  20},
    {"Mikael", 30, 20, 40, 50, 80},
    {"Trev",   90, 90, 80, 0,  30}
};

void add_street_cred(int i, int amount) {
    reputations[i].street_cred += amount;
    if (reputations[i].street_cred > 100)
        reputations[i].street_cred = 100;
}
