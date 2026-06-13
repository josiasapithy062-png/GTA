// ELYRIA STORIES - Systeme parachute

#include "parachute.h"

// Etat du parachute
ParachuteState parachute = {
    .is_owned = 0,
    .is_deployed = 0,
    .altitude = 0.0f,
    .fall_speed = 0.0f,
    .landing_x = 0.0f,
    .landing_y = 0.0f
};

// Ramasser parachute
void pickup_parachute() {
    parachute.is_owned = 1;
}

// Deployer parachute
void deploy_parachute() {
    if (parachute.is_owned && !parachute.is_deployed) {
        if (parachute.altitude > 50.0f) {
            parachute.is_deployed = 1;
            parachute.fall_speed = 5.0f;
        }
    }
}

// Mettre a jour chute
void update_parachute(float delta_time) {
    if (parachute.is_deployed) {
        // Descente lente avec parachute
        parachute.altitude -= parachute.fall_speed * delta_time;
        parachute.fall_speed = 5.0f;

        // Atterrissage
        if (parachute.altitude <= 0.0f) {
            land_parachute();
        }
    } else {
        // Chute libre sans parachute
        parachute.fall_speed += 9.8f * delta_time;
        parachute.altitude -= parachute.fall_speed * delta_time;

        // Mort si touche le sol sans parachute
        if (parachute.altitude <= 0.0f) {
            parachute_death();
        }
    }
}

// Atterrissage reussi
void land_parachute() {
    parachute.is_deployed = 0;
    parachute.fall_speed = 0.0f;
    parachute.altitude = 0.0f;
}

// Mort sans parachute
void parachute_death() {
    // Le joueur meurt
    // Respawn au dernier checkpoint
}

// Diriger le parachute
void steer_parachute(float dir_x, float dir_y) {
    if (parachute.is_deployed) {
        parachute.landing_x += dir_x * 2.0f;
        parachute.landing_y += dir_y * 2.0f;
    }
}
