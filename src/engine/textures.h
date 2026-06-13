#ifndef TEXTURES_H
#define TEXTURES_H
#include <pspgu.h>
typedef enum {
    ROAD_TEX, GRASS_TEX, SAND_TEX, WATER_TEX, DIRT_TEX,
    CONCRETE_TEX, SNOW_TEX, BRICK_TEX, GLASS_TEX, METAL_TEX,
    WOOD_TEX, MARBLE_TEX, CAR_RED, CAR_BLUE, CAR_BLACK,
    CAR_WHITE, CAR_GOLD, SKIN_LIGHT, SKIN_DARK, CLOTH_BLACK,
    CLOTH_WHITE, CLOTH_RED, LEAF_TEX, TRUNK_TEX, FLOWER_TEX
} TextureType;
typedef struct { char name[32]; unsigned int color; TextureType type; } TextureColor;
extern TextureColor colors[];
extern int total_colors;
void apply_texture(TextureType type);
unsigned int get_sky_color(int hour);
unsigned int get_water_color(int frame);
#endif
