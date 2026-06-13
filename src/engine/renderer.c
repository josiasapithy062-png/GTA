// ELYRIA STORIES - Moteur rendu principal
#include "renderer.h"

// Camera
Camera camera = {
    .x = 0.0f, .y = 5.0f, .z = -10.0f,
    .angle_x = 0.0f, .angle_y = 0.0f,
    .fov = 75.0f, .near = 0.1f, .far = 1000.0f
};

// Mettre a jour camera derriere joueur
void update_camera(float px, float py, float pz, float angle) {
    camera.x = px - 8.0f * sinf(angle);
    camera.y = py + 5.0f;
    camera.z = pz - 8.0f * cosf(angle);
    camera.angle_y = angle;
}

// Appliquer camera
void apply_camera() {
    sceGumMatrixMode(GU_PROJECTION);
    sceGumLoadIdentity();
    sceGumPerspective(camera.fov, 16.0f/9.0f, camera.near, camera.far);
    sceGumMatrixMode(GU_VIEW);
    sceGumLoadIdentity();
    ScePspFVector3 pos = {-camera.x, -camera.y, -camera.z};
    sceGumTranslate(&pos);
    sceGumRotateY(camera.angle_y);
    sceGumMatrixMode(GU_MODEL);
    sceGumLoadIdentity();
}

// Render frame complet
void render_frame(GameState* state) {
    sceGuStart(GU_DIRECT, disp_list);
    // Ciel
    unsigned int sky = get_sky_color(state->hour);
    sceGuClearColor(sky);
    sceGuClearDepth(0);
    sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);
    apply_camera();
    // Sol
    draw_ground(0.0f, 0.0f, 1000.0f, 0xFF228B22);
    // Routes
    draw_road(0.0f, 0.0f, 10.0f, 200.0f);
    // Batiments
    for(int i = 0; i < 5; i++)
        draw_building(i*15.0f, 0.0f, 20.0f);
    // Arbres
    for(int i = 0; i < 10; i++)
        draw_tree(i*8.0f - 40.0f, 0.0f, 15.0f);
    // Joueur
    draw_player(state->player_x, state->player_y, state->player_z);
    // Voitures
    for(int i = 0; i < 3; i++)
        draw_car(i*10.0f, 0.0f, 0.0f);
    sceGuFinish();
    sceGuSync(0, 0);
    sceDisplayWaitVblankStart();
    sceGuSwapBuffers();
}
