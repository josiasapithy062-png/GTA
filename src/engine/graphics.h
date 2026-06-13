// ELYRIA STORIES - Header graphique
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <pspgu.h>
#include <pspgum.h>
#include <pspdisplay.h>

#define BUF_WIDTH  512
#define SCR_WIDTH  480
#define SCR_HEIGHT 272

typedef enum {
    MORNING,
    DAY,
    EVENING,
    NIGHT
} TimeOfDay;

typedef struct {
    float x, y, z;
    unsigned int color;
    float u, v;
} Vertex;

void graphics_init();
void graphics_begin_frame();
void graphics_end_frame();
void draw_ground(float x, float y, float size, unsigned int color);
void draw_cube(float x, float y, float z, float size, unsigned int color);
void draw_road(float x, float y, float width, float length);
void draw_sky(TimeOfDay time);
void draw_sea(float x, float y, float size);
void graphics_term();

#endif
