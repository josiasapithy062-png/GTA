// ELYRIA STORIES - Systeme des personnages
// Personnages : Josias, Franck, Mikael, Trev

#include "characters.h"

// Definition des 4 personnages
Character characters[4] = {
    {
        .name = "Josias",
        .health = 100,
        .armor = 50,
        .speed = 1.2f,
        .endurance = 100,
        .piloting = 60,
        .shooting = 70,
        .strength = 80,
        .is_active = 1
    },
    {
        .name = "Franck",
        .health = 100,
        .armor = 30,
        .speed = 1.5f,
        .endurance = 80,
        .piloting = 50,
        .shooting = 90,
        .strength = 70,
        .is_active = 0
    },
    {
        .name = "Mikael",
        .health = 100,
        .armor = 60,
        .speed = 1.0f,
        .endurance = 70,
        .piloting = 80,
        .shooting = 85,
        .strength = 75,
        .is_active = 0
    },
    {
        .name = "Trev",
        .health = 150,
        .armor = 20,
        .speed = 1.3f,
        .endurance = 90,
        .piloting = 70,
        .shooting = 95,
        .strength = 100,
        .is_active = 0
    }
};

// Changer de personnage
void switch_character(int index) {
    for (int i = 0; i < 4; i++) {
        characters[i].is_active = (i == index) ? 1 : 0;
    }
}

// Obtenir le personnage actif
Character* get_active_character() {
    for (int i = 0; i < 4; i++) {
        if (characters[i].is_active) return &characters[i];
    }
    return &characters[0];
}
