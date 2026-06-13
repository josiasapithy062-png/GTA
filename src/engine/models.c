// ELYRIA STORIES - Modeles 3D simples PSP
#include "models.h"

// Modele personnage (forme humaine simple)
Vertex player_model[] = {
    // Tete
    {0.0f,  2.0f, 0.0f,  0xFFFFBF00},
    {0.5f,  2.5f, 0.0f,  0xFFFFBF00},
    {-0.5f, 2.5f, 0.0f,  0xFFFFBF00},
    {0.0f,  3.0f, 0.0f,  0xFFFFBF00},
    // Corps
    {0.0f,  1.0f, 0.0f,  0xFF0000FF},
    {0.5f,  2.0f, 0.0f,  0xFF0000FF},
    {-0.5f, 2.0f, 0.0f,  0xFF0000FF},
    {0.5f,  1.0f, 0.0f,  0xFF0000FF},
    {-0.5f, 1.0f, 0.0f,  0xFF0000FF},
    // Jambes
    {0.2f,  0.0f, 0.0f,  0xFF333333},
    {-0.2f, 0.0f, 0.0f,  0xFF333333},
    {0.2f,  1.0f, 0.0f,  0xFF333333},
    {-0.2f, 1.0f, 0.0f,  0xFF333333},
    // Bras
    {1.0f,  1.5f, 0.0f,  0xFFFFBF00},
    {-1.0f, 1.5f, 0.0f,  0xFFFFBF00},
    {1.0f,  2.0f, 0.0f,  0xFFFFBF00},
    {-1.0f, 2.0f, 0.0f,  0xFFFFBF00},
};

// Modele voiture simple
Vertex car_model[] = {
    // Carrosserie bas
    {-2.0f, 0.0f, -1.0f, 0xFFFF0000},
    {2.0f,  0.0f, -1.0f, 0xFFFF0000},
    {2.0f,  0.0f,  1.0f, 0xFFFF0000},
    {-2.0f, 0.0f,  1.0f, 0xFFFF0000},
    // Carrosserie haut
    {-1.5f, 1.0f, -0.8f, 0xFFCC0000},
    {1.5f,  1.0f, -0.8f, 0xFFCC0000},
    {1.5f,  1.0f,  0.8f, 0xFFCC0000},
    {-1.5f, 1.0f,  0.8f, 0xFFCC0000},
    // Pare brise
    {-1.0f, 1.5f, -0.7f, 0xFF88CCFF},
    {1.0f,  1.5f, -0.7f, 0xFF88CCFF},
    {1.0f,  1.5f,  0.7f, 0xFF88CCFF},
    {-1.0f, 1.5f,  0.7f, 0xFF88CCFF},
    // Roues
    {-1.5f, 0.0f, -1.2f, 0xFF111111},
    {1.5f,  0.0f, -1.2f, 0xFF111111},
    {1.5f,  0.0f,  1.2f, 0xFF111111},
    {-1.5f, 0.0f,  1.2f, 0xFF111111},
};

// Modele batiment simple
Vertex building_model[] = {
    // Base
    {-5.0f, 0.0f,  -5.0f, 0xFF888888},
    {5.0f,  0.0f,  -5.0f, 0xFF888888},
    {5.0f,  0.0f,   5.0f, 0xFF888888},
    {-5.0f, 0.0f,   5.0f, 0xFF888888},
    // Toit
    {-5.0f, 10.0f, -5.0f, 0xFF666666},
    {5.0f,  10.0f, -5.0f, 0xFF666666},
    {5.0f,  10.0f,  5.0f, 0xFF666666},
    {-5.0f, 10.0f,  5.0f, 0xFF666666},
    // Fenetres
    {-2.0f, 3.0f,  -5.1f, 0xFF88CCFF},
    {-1.0f, 4.0f,  -5.1f, 0xFF88CCFF},
    {1.0f,  3.0f,  -5.1f, 0xFF88CCFF},
    {2.0f,  4.0f,  -5.1f, 0xFF88CCFF},
};

// Modele arbre simple
Vertex tree_model[] = {
    // Tronc
    {-0.2f, 0.0f, 0.0f, 0xFF8B4513},
    {0.2f,  0.0f, 0.0f, 0xFF8B4513},
    {0.2f,  2.0f, 0.0f, 0xFF8B4513},
    {-0.2f, 2.0f, 0.0f, 0xFF8B4513},
    // Feuilles bas
    {-1.5f, 2.0f, 0.0f, 0xFF228B22},
    {1.5f,  2.0f, 0.0f, 0xFF228B22},
    {0.0f,  4.0f, 0.0f, 0xFF228B22},
    // Feuilles haut
    {-1.0f, 3.5f, 0.0f, 0xFF32CD32},
    {1.0f,  3.5f, 0.0f, 0xFF32CD32},
    {0.0f,  5.5f, 0.0f, 0xFF32CD32},
};

// Modele route
Vertex road_model[] = {
    {-5.0f, 0.01f, -20.0f, 0xFF333333},
    {5.0f,  0.01f, -20.0f, 0xFF333333},
    {5.0f,  0.01f,  20.0f, 0xFF333333},
    {-5.0f, 0.01f,  20.0f, 0xFF333333},
    // Lignes blanches
    {-0.2f, 0.02f, -20.0f, 0xFFFFFFFF},
    {0.2f,  0.02f, -20.0f, 0xFFFFFFFF},
    {0.2f,  0.02f,  20.0f, 0xFFFFFFFF},
    {-0.2f, 0.02f,  20.0f, 0xFFFFFFFF},
};

// Dessiner modele
void draw_model(Vertex* model, int count, float x, float y, float z) {
    sceGumPushMatrix();
    ScePspFVector3 pos = {x, y, z};
    sceGumTranslate(&pos);
    sceGumDrawArray(GU_TRIANGLE_STRIP,
        GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,
        count, 0, model);
    sceGumPopMatrix();
}

void draw_player(float x, float y, float z) {
    draw_model(player_model, 17, x, y, z);
}

void draw_car(float x, float y, float z) {
    draw_model(car_model, 16, x, y, z);
}

void draw_building(float x, float y, float z) {
    draw_model(building_model, 12, x, y, z);
}

void draw_tree(float x, float y, float z) {
    draw_model(tree_model, 10, x, y, z);
}

void draw_road(float x, float y, float z) {
    draw_model(road_model, 8, x, y, z);
}
