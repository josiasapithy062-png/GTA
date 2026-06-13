// ELYRIA STORIES - Header sauvegarde
#ifndef SAVEGAME_H
#define SAVEGAME_H

typedef struct {
    int slot;
    int version;
    int playtime;
    int missions_completed;
    int current_character;
    int current_country;
    int cash;
    int bank;
    int wanted_level;
    int properties_owned;
    int total_kills;
    int total_arrests;
    int distance_traveled;
    int cars_stolen;
    int heists_completed;
} SaveData;

extern SaveData save_data;

void save_game(int slot);
void load_game(int slot);
void new_game();
void delete_save(int slot);

#endif
