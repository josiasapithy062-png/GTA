// ELYRIA STORIES - Header gangs
#ifndef GANGS_H
#define GANGS_H

#include "world.h"

typedef struct {
    char name[32];
    int country;
    unsigned int color;
    float territory_x;
    float territory_y;
    int members;
    int respect;
    int is_ally;
    int is_enemy;
} Gang;

extern Gang gangs[];
extern int total_gangs;

void join_gang(int index);
void declare_war(int index);
void earn_gang_respect(int index, int amount);
void conquer_territory(int gang_index, float x, float y);

#endif
