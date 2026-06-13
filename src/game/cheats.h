// ELYRIA STORIES - Header codes de triche
#ifndef CHEATS_H
#define CHEATS_H

#include <string.h>

typedef enum {
    MONEY,
    HEALTH,
    ARMOR,
    ALL_WEAPONS,
    MINIGUN,
    TANK,
    HELICOPTER,
    PLANE,
    NO_WANTED,
    MAX_WANTED,
    SPEED_CAR,
    INVINCIBLE,
    LOW_GRAVITY,
    EXPLOSIONS,
    ALL_PROPS,
    ALL_CHARS
} CheatEffect;

typedef struct {
    char code[32];
    CheatEffect effect;
    char description[64];
} Cheat;

extern Cheat cheats[];
extern int total_cheats;

void activate_cheat(char* code);
void apply_cheat(CheatEffect effect);

#endif
