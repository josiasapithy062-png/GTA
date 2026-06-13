// ELYRIA STORIES - Header PNJ et animaux
#ifndef NPCS_H
#define NPCS_H

typedef enum {
    CIVILIAN,
    POLICE,
    GANG,
    MILITARY,
    BORDER,
    SERVICE
} NPCType;

typedef enum {
    DOG,
    CAT,
    BIRD,
    DEER,
    FOX,
    SNAKE,
    CROC,
    FISH
} AnimalType;

typedef struct {
    char name[32];
    NPCType type;
    int country;
    float pos_x;
    float pos_y;
    int health;
    int is_alive;
    int is_hostile;
    int is_talking;
} NPC;

typedef struct {
    char name[32];
    AnimalType type;
    int country;
    float pos_x;
    float pos_y;
    int health;
    int is_alive;
    int is_hostile;
} Animal;

extern NPC npcs[];
extern Animal animals[];
extern int total_npcs;
extern int total_animals;

void talk_to_npc(int index);
void npc_attack(int index);
void animal_attack(int animal_index);
void npc_die(int index);

#endif
