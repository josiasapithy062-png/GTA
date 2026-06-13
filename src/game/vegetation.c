// ELYRIA STORIES - Arbres et vegetation

#include "vegetation.h"

// Types d arbres et plantes
Tree trees[] = {
    // USA - Liberty City
    {"Chene",         OAK,    8.0f,  5.0f,  USA,    0.0f,    500.0f,  1},
    {"Palmier",       PALM,   10.0f, 3.0f,  USA,    200.0f,  -1200.0f,1},
    {"Palmier Plage", PALM,   12.0f, 4.0f,  USA,    600.0f,  -1500.0f,1},
    {"Sapin",         PINE,   15.0f, 6.0f,  USA,    1000.0f, 2000.0f, 1},
    {"Buisson",       BUSH,   2.0f,  3.0f,  USA,    300.0f,  300.0f,  1},
    {"Herbe Haute",   GRASS,  1.0f,  2.0f,  USA,    400.0f,  400.0f,  1},
    {"Eucalyptus",    OAK,    9.0f,  4.0f,  USA,    2000.0f, 1000.0f, 1},
    {"Cactus",        CACTUS, 3.0f,  2.0f,  USA,    3000.0f, 500.0f,  1},
    {"Cactus Desert", CACTUS, 4.0f,  2.5f,  USA,    3500.0f, 600.0f,  1},

    // Bord de mer USA
    {"Cocotier",      PALM,   11.0f, 3.5f,  USA,    700.0f,  -1600.0f,1},
    {"Mangrove",      OAK,    7.0f,  6.0f,  USA,    800.0f,  -1800.0f,1},

    // ELYRIA - Ville
    {"Palmier Elyria",PALM,   10.0f, 3.0f,  ELYRIA, 6000.0f, 0.0f,   0},
    {"Chene Elyria",  OAK,    9.0f,  5.0f,  ELYRIA, 6500.0f, 800.0f, 0},
    {"Sapin Elyria",  PINE,   14.0f, 6.0f,  ELYRIA, 8000.0f, 1000.0f,0},
    {"Buisson Ely",   BUSH,   2.0f,  3.0f,  ELYRIA, 6200.0f, 500.0f, 0},

    // Bord de mer ELYRIA
    {"Cocotier Ely",  PALM,   11.0f, 3.5f,  ELYRIA, 6200.0f,-1500.0f,0},
    {"Mangrove Ely",  OAK,    7.0f,  6.0f,  ELYRIA, 6500.0f,-1800.0f,0},
    {"Bambou",        PINE,   8.0f,  2.0f,  ELYRIA, 7000.0f, 1500.0f,0},

    // Zone militaire ELYRIA
    {"Sapin Militaire",PINE,  16.0f, 7.0f,  ELYRIA, 7000.0f, 2000.0f,0},
    {"Chene Arsenal", OAK,    10.0f, 5.0f,  ELYRIA, 7500.0f, 2500.0f,0},

    // Village ELYRIA
    {"Arbre Fruitier",OAK,    6.0f,  4.0f,  ELYRIA, 8000.0f,-1000.0f,0},
    {"Bananier",      PALM,   8.0f,  3.0f,  ELYRIA, 8500.0f,-500.0f, 0},
};

int total_trees = 22;

// Charger les arbres d une zone
void load_trees(int country) {
    for (int i = 0; i < total_trees; i++) {
        if (trees[i].country == country) {
            trees[i].is_loaded = 1;
        }
    }
}

// Collision avec arbre
int check_tree_collision(float x, float y, float radius) {
    for (int i = 0; i < total_trees; i++) {
        if (!trees[i].is_loaded) continue;
        float dx = x - trees[i].pos_x;
        float dy = y - trees[i].pos_y;
        float dist = dx*dx + dy*dy;
        if (dist < (radius + trees[i].radius) * 
                   (radius + trees[i].radius)) {
            return i;
        }
    }
    return -1;
}

// Arbre peut etre detruit
void destroy_tree(int index) {
    trees[index].is_loaded = 0;
}
