// ELYRIA STORIES - Moteur graphique PSP

#include "graphics.h"

// Buffer de rendu
static unsigned int __attribute__((aligned(16))) disp_list[262144];

// Initialiser le rendu
void graphics_init() {
    sceGuInit();
    sceGuStart(GU_DIRECT, disp_list);
    sceGuDrawBuffer(GU_PSM_8888, (void*)0, BUF_WIDTH);
    sceGuDispBuffer(SCR_WIDTH, SCR_HEIGHT, (void*)0x88000, BUF_WIDTH);
    sceGuDepthBuffer((void*)0x110000, BUF_WIDTH);
    sceGuOffset(2048-(SCR_WIDTH/2), 2048-(SCR_HEIGHT/2));
    sceGuViewport(2048, 2048, SCR_WIDTH, SCR_HEIGHT);
    sceGuDepthRange(65535, 0);
    sceGuScissor(0, 0, SCR_WIDTH, SCR_HEIGHT);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuEnable(GU_DEPTH_TEST);
    sceGuEnable(GU_CULL_FACE);
    sceGuEnable(GU_TEXTURE_2D);
    sceGuEnable(GU_BLEND);
    sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA,
                   GU_ONE_MINUS_SRC_ALPHA, 0, 0);
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
}

// Debut de frame
void graphics_begin_frame() {
    sceGuStart(GU_DIRECT, disp_list);
    sceGuClearColor(0xFF87CEEB); // Ciel bleu Elyria
    sceGuClearDepth(0);
    sceGuClear(GU_COLOR_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);
}

// Fin de frame
void graphics_end_frame() {
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}

// Dessiner le sol
void draw_ground(float x, float y, float size, unsigned int color) {
    Vertex* vertices = sceGuGetMemory(2 * sizeof(Vertex));
    vertices[0].x = x;
    vertices[0].y = 0;
    vertices[0].z = y;
    vertices[0].color = color;
    vertices[1].x = x + size;
    vertices[1].y = 0;
    vertices[1].z = y + size;
    vertices[1].color = color;
    sceGumDrawArray(GU_SPRITES,
        GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,
        2, 0, vertices);
}

// Dessiner un cube simple
void draw_cube(float x, float y, float z,
               float size, unsigned int color) {
    // Dessine batiment ou objet cubique
}

// Dessiner la route
void draw_road(float x, float y,
               float width, float length) {
    unsigned int road_color = 0xFF333333;
    draw_ground(x, y, width, road_color);
}

// Dessiner le ciel
void draw_sky(TimeOfDay time) {
    switch(time) {
        case MORNING:
            sceGuClearColor(0xFFFFB347);
            break;
        case DAY:
            sceGuClearColor(0xFF87CEEB);
            break;
        case EVENING:
            sceGuClearColor(0xFFFF6B35);
            break;
        case NIGHT:
            sceGuClearColor(0xFF0A0A2A);
            break;
    }
}

// Dessiner la mer
void draw_sea(float x, float y, float size) {
    unsigned int sea_color = 0xFF006994;
    draw_ground(x, y, size, sea_color);
}

// Terminer le rendu
void graphics_term() {
    sceGuTerm();
}
