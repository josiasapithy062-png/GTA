// ELYRIA STORIES - Systeme de vol avion et helicoptere

#include "flying.h"

// Etat de vol
FlyingState flying = {
    .altitude = 0.0f,
    .speed = 0.0f,
    .pitch = 0.0f,
    .roll = 0.0f,
    .yaw = 0.0f,
    .thrust = 0.0f,
    .is_flying = 0,
    .is_landing = 0,
    .engine_on = 0,
    .fuel = 100.0f
};

// Demarrer moteur
void start_engine() {
    flying.engine_on = 1;
    flying.thrust = 0.1f;
}

// Decollage avion
void takeoff_plane() {
    if (flying.engine_on && flying.speed > 80.0f) {
        flying.is_flying = 1;
        flying.altitude += flying.thrust * 2.0f;
    }
}

// Decollage helicoptere
void takeoff_helicopter() {
    if (flying.engine_on) {
        flying.is_flying = 1;
        flying.altitude += flying.thrust * 1.5f;
    }
}

// Accelerer en vol
void thrust_up() {
    flying.thrust += 0.1f;
    if (flying.thrust > 1.0f) flying.thrust = 1.0f;
    flying.speed += flying.thrust * 10.0f;
    flying.fuel -= 0.1f;
}

// Ralentir en vol
void thrust_down() {
    flying.thrust -= 0.1f;
    if (flying.thrust < 0.0f) flying.thrust = 0.0f;
    flying.speed -= 5.0f;
    if (flying.speed < 0.0f) flying.speed = 0.0f;
}

// Piquer vers le bas
void pitch_down() {
    flying.pitch -= 5.0f;
    flying.altitude -= flying.speed * 0.1f;
}

// Cabrer vers le haut
void pitch_up() {
    flying.pitch += 5.0f;
    flying.altitude += flying.speed * 0.1f;
}

// Rouler a gauche
void roll_left() {
    flying.roll -= 5.0f;
    flying.yaw -= 2.0f;
}

// Rouler a droite
void roll_right() {
    flying.roll += 5.0f;
    flying.yaw += 2.0f;
}

// Atterrissage
void land() {
    flying.is_landing = 1;
    flying.thrust = 0.0f;
    flying.altitude -= 2.0f;
    if (flying.altitude <= 0.0f) {
        flying.altitude = 0.0f;
        flying.is_flying = 0;
        flying.is_landing = 0;
        flying.speed = 0.0f;
    }
}

// Crash
void plane_crash() {
    flying.is_flying = 0;
    flying.speed = 0.0f;
    flying.altitude = 0.0f;
    // Explosion massive
    // Joueur meurt si sans parachute
}

// Tirer missiles depuis avion
void fire_missile() {
    if (flying.is_flying) {
        // Lance missile vers cible
        // Explosion a l impact
    }
}

// Tirer depuis helicoptere
void helicopter_gun() {
    if (flying.is_flying) {
        // Mitrailleuse helicoptere
    }
}
