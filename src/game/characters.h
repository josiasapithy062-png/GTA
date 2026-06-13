// ELYRIA STORIES - Header personnages
#ifndef CHARACTERS_H
#define CHARACTERS_H

typedef struct {
    char name[32];
    int health;
    int armor;
    float speed;
    int endurance;
    int piloting;
    int shooting;
    int strength;
    int is_active;
} Character;

extern Character characters[4];

void switch_character(int index);
Character* get_active_character();

#endif
