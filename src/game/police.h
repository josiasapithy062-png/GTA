// ELYRIA STORIES - Header police
#ifndef POLICE_H
#define POLICE_H

typedef enum {
    NO_RESPONSE,
    COPS_CHASE,
    SWAT_DEPLOY,
    ARMY_DEPLOY
} PoliceResponse;

typedef struct {
    int wanted_level;
    int pursuit_active;
    int bribe_cost;
    int time_to_lose;
} PoliceState;

extern PoliceState police;

void add_wanted_level(int amount);
void reduce_wanted_level(int amount);
void pay_bribe();
void lose_police();
PoliceResponse get_police_response();

#endif
