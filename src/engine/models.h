#ifndef MODELS_H
#define MODELS_H
#include <pspgu.h>
#include <pspgum.h>
typedef struct { float x, y, z; unsigned int color; } Vertex;
extern Vertex player_model[];
extern Vertex car_model[];
extern Vertex building_model[];
extern Vertex tree_model[];
extern Vertex road_model[];
void draw_model(Vertex* model, int count, float x, float y, float z);
void draw_player(float x, float y, float z);
void draw_car(float x, float y, float z);
void draw_building(float x, float y, float z);
void draw_tree(float x, float y, float z);
void draw_road(float x, float y, float z);
#endif
