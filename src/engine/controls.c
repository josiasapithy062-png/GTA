// ELYRIA STORIES - Controles PSP

#include "controls.h"

// Etat des boutons
ControlState controls = {0};

// Lire les controles
void controls_update() {
    SceCtrlData pad;
    sceCtrlReadBufferPositive(&pad, 1);

    // Boutons
    controls.cross     = pad.Buttons & PSP_CTRL_CROSS;
    controls.circle    = pad.Buttons & PSP_CTRL_CIRCLE;
    controls.square    = pad.Buttons & PSP_CTRL_SQUARE;
    controls.triangle  = pad.Buttons & PSP_CTRL_TRIANGLE;
    controls.l1        = pad.Buttons & PSP_CTRL_LTRIGGER;
    controls.r1        = pad.Buttons & PSP_CTRL_RTRIGGER;
    controls.start     = pad.Buttons & PSP_CTRL_START;
    controls.select    = pad.Buttons & PSP_CTRL_SELECT;
    controls.up        = pad.Buttons & PSP_CTRL_UP;
    controls.down      = pad.Buttons & PSP_CTRL_DOWN;
    controls.left      = pad.Buttons & PSP_CTRL_LEFT;
    controls.right     = pad.Buttons & PSP_CTRL_RIGHT;

    // Joystick analogique
    controls.analog_x  = pad.Lx - 128;
    controls.analog_y  = pad.Ly - 128;
}

// Actions joueur a pied
void handle_on_foot_controls() {
    // Joystick = marcher/courir
    if (controls.analog_x != 0 || controls.analog_y != 0) {
        float speed = 0.1f;
        if (controls.r1) speed = 0.2f; // Courir
        apply_force(
            controls.analog_x * speed,
            0,
            controls.analog_y * speed
        );
    }

    // Croix = sauter
    if (controls.cross) jump(5.0f);

    // Carre = frapper
    if (controls.square) {
        // Combat corps a corps
    }

    // Rond = entrer vehicule
    if (controls.circle) {
        // Entrer dans vehicule proche
    }

    // Triangle = viser
    if (controls.triangle) {
        // Mode visee
    }

    // L1 = changer personnage
    if (controls.l1) {
        // Switch personnage
    }

    // R1 = tirer
    if (controls.r1) {
        // Tirer arme
    }

    // Select = telephone
    if (controls.select) {
        // Ouvrir telephone
    }

    // Start = pause
    if (controls.start) {
        // Menu pause
    }
}

// Actions en vehicule
void handle_vehicle_controls() {
    // Joystick = direction
    // Croix = accelerer
    // Carre = freiner
    // Rond = sortir vehicule
    // Triangle = klaxon
    // L1 = regarder derriere
    // R1 = tirer depuis vehicule
}

// Actions en avion
void handle_plane_controls() {
    // Joystick = direction vol
    // Croix = accelerer moteur
    // Carre = ralentir moteur
    // L1 = piquer
    // R1 = cabrer
    // Triangle = atterrir
}

// Actions en bateau
void handle_boat_controls() {
    // Joystick = direction
    // Croix = accelerer
    // Carre = freiner
    // Triangle = plonger
}
