// ELYRIA STORIES - Systeme de police et etoiles

#include "police.h"

// Etat de la recherche
PoliceState police = {
    .wanted_level = 0,
    .pursuit_active = 0,
    .bribe_cost = 500,
    .time_to_lose = 60
};

// Augmenter le niveau de recherche
void add_wanted_level(int amount) {
    police.wanted_level += amount;
    if (police.wanted_level > 5)
        police.wanted_level = 5;
    if (police.wanted_level > 0)
        police.pursuit_active = 1;
}

// Reduire le niveau de recherche
void reduce_wanted_level(int amount) {
    police.wanted_level -= amount;
    if (police.wanted_level < 0)
        police.wanted_level = 0;
    if (police.wanted_level == 0)
        police.pursuit_active = 0;
}

// Payer un pot-de-vin
void pay_bribe() {
    reduce_wanted_level(1);
}

// Perdre la police
void lose_police() {
    police.wanted_level = 0;
    police.pursuit_active = 0;
}

// Obtenir la reaction selon les etoiles
PoliceResponse get_police_response() {
    switch (police.wanted_level) {
        case 1: return COPS_CHASE;
        case 2: return COPS_CHASE;
        case 3: return SWAT_DEPLOY;
        case 4: return SWAT_DEPLOY;
        case 5: return ARMY_DEPLOY;
        default: return NO_RESPONSE;
    }
}
