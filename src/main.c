// ELYRIA STORIES - Main PSP FINAL
#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspctrl.h>
#include <math.h>
#include "engine/graphics.h"
#include "engine/controls.h"
#include "engine/physics.h"
#include "engine/renderer.h"
#include "engine/models.h"
#include "engine/textures.h"
#include "engine/hud.h"
#include "game/characters.h"
#include "game/vehicles.h"
#include "game/world.h"
#include "game/missions.h"
#include "game/weapons.h"
#include "game/police.h"
#include "game/economy.h"
#include "game/weather.h"
#include "game/savegame.h"
#include "game/cheats.h"
#include "game/combat.h"
#include "game/driving.h"
#include "game/flying.h"

PSP_MODULE_INFO("ELYRIA STORIES", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

static int exitCallback(int arg1, int arg2, void* common) {
    sceKernelExitGame(); return 0;
}
static int callbackThread(SceSize args, void* argp) {
    int cbid = sceKernelCreateCallback("Exit", exitCallback, NULL);
    sceKernelRegisterExitCallback(cbid);
    sceKernelSleepThreadCB(); return 0;
}
static void setupCallbacks() {
    int thid = sceKernelCreateThread("cb_thread", callbackThread, 0x11, 0xFA0, 0, 0);
    if(thid >= 0) sceKernelStartThread(thid, 0, 0);
}

// Etat global du jeu
GameState game_state = {
    .player_x = 0.0f,
    .player_y = 0.0f,
    .player_z = 0.0f,
    .hour = 12
};

float player_angle = 0.0f;
float move_speed = 0.1f;

int main(void) {
    setupCallbacks();
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

    // Init graphique
    graphics_init();

    // Nouveau jeu
    new_game();

    // Boucle principale
    while(1) {
        // Lire controles
        controls_update();

        // Mouvement joueur
        if(controls.analog_y < -20)
            game_state.player_z += move_speed * cosf(player_angle);
        if(controls.analog_y > 20)
            game_state.player_z -= move_speed * cosf(player_angle);
        if(controls.analog_x < -20)
            player_angle -= 0.05f;
        if(controls.analog_x > 20)
            player_angle += 0.05f;

        // Courir avec R1
        move_speed = controls.r1 ? 0.3f : 0.1f;

        // Sauter avec Croix
        if(controls.cross) jump(5.0f);

        // Changer personnage L1
        static int l1_prev = 0;
        if(controls.l1 && !l1_prev) {
            int current = 0;
            for(int i=0;i<4;i++) if(characters[i].is_active) current=i;
            switch_character((current+1)%4);
        }
        l1_prev = controls.l1;

        // Mettre a jour physique
        physics_update(0.016f);
        game_state.player_y = player_body.y;

        // Mettre a jour heure
        update_time(0.016f);
        game_state.hour = weather.hour;

        // Camera
        update_camera(
            game_state.player_x,
            game_state.player_y,
            game_state.player_z,
            player_angle
        );

        // Verifier frontiere
        check_border_crossing(game_state.player_x);

        // Rendu
        render_frame(&game_state);

        // HUD
        Character* player = get_active_character();
        draw_health_bar(player->health);
        draw_armor_bar(player->armor);
        draw_money(economy.cash);
        draw_wanted_stars(police.wanted_level);
        draw_time(weather.hour, weather.minute);
    }

    graphics_term();
    return 0;
}
