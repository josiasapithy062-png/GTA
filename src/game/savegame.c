// ELYRIA STORIES - Systeme de sauvegarde

#include "savegame.h"

// Donnees de sauvegarde
SaveData save_data = {
    .slot = 1,
    .version = 1,
    .playtime = 0,
    .missions_completed = 0,
    .current_character = 0,
    .current_country = 0,
    .cash = 5000,
    .bank = 0,
    .wanted_level = 0,
    .properties_owned = 0,
    .total_kills = 0,
    .total_arrests = 0,
    .distance_traveled = 0,
    .cars_stolen = 0,
    .heists_completed = 0
};

// Sauvegarder la partie
void save_game(int slot) {
    save_data.slot = slot;
    // Ecrire dans fichier PSP
}

// Charger la partie
void load_game(int slot) {
    save_data.slot = slot;
    // Lire depuis fichier PSP
}

// Nouveau jeu
void new_game() {
    save_data.cash = 5000;
    save_data.missions_completed = 0;
    save_data.current_character = 0;
    save_data.current_country = 0;
}

// Effacer sauvegarde
void delete_save(int slot) {
    save_data.slot = -1;
}
