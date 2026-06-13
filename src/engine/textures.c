// ELYRIA STORIES - Textures et couleurs
#include "textures.h"

// Couleurs principales du jeu
TextureColor colors[] = {
    // Sols
    {"Asphalte",      0xFF333333, ROAD_TEX},
    {"Herbe",         0xFF228B22, GRASS_TEX},
    {"Sable plage",   0xFFFFD700, SAND_TEX},
    {"Eau mer",       0xFF006994, WATER_TEX},
    {"Terre",         0xFF8B4513, DIRT_TEX},
    {"Beton",         0xFF888888, CONCRETE_TEX},
    {"Neige",         0xFFFFFFFF, SNOW_TEX},
    // Batiments
    {"Mur brique",    0xFFCC6633, BRICK_TEX},
    {"Verre",         0xFF88CCFF, GLASS_TEX},
    {"Metal",         0xFF999999, METAL_TEX},
    {"Bois",          0xFF8B6914, WOOD_TEX},
    {"Marbre",        0xFFEEEEDD, MARBLE_TEX},
    // Vehicules
    {"Rouge voiture", 0xFFFF0000, CAR_RED},
    {"Bleu voiture",  0xFF0000FF, CAR_BLUE},
    {"Noir voiture",  0xFF111111, CAR_BLACK},
    {"Blanc voiture", 0xFFFFFFFF, CAR_WHITE},
    {"Or voiture",    0xFFFFD700, CAR_GOLD},
    // Personnages
    {"Peau claire",   0xFFFFBF80, SKIN_LIGHT},
    {"Peau foncee",   0xFF8B4513, SKIN_DARK},
    {"Vetement noir", 0xFF111111, CLOTH_BLACK},
    {"Vetement blanc",0xFFFFFFFF, CLOTH_WHITE},
    {"Vetement rouge",0xFFFF0000, CLOTH_RED},
    // Nature
    {"Feuilles",      0xFF228B22, LEAF_TEX},
    {"Tronc",         0xFF8B4513, TRUNK_TEX},
    {"Fleur",         0xFFFF69B4, FLOWER_TEX},
};

int total_colors = 25;

// Appliquer texture
void apply_texture(TextureType type) {
    for(int i = 0; i < total_colors; i++) {
        if(colors[i].type == type) {
            sceGuColor(colors[i].color);
            return;
        }
    }
}

// Ciel selon heure
unsigned int get_sky_color(int hour) {
    if(hour >= 6  && hour < 9)  return 0xFFFFB347;
    if(hour >= 9  && hour < 18) return 0xFF87CEEB;
    if(hour >= 18 && hour < 21) return 0xFFFF6B35;
    return 0xFF0A0A2A;
}

// Eau animee
unsigned int get_water_color(int frame) {
    int wave = frame % 60;
    if(wave < 30) return 0xFF006994;
    return 0xFF0077AA;
}
