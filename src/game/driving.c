// ELYRIA STORIES - Systeme de conduite

#include "driving.h"

// Etat de conduite
DrivingState driving = {
    .speed = 0.0f,
    .max_speed = 0.0f,
    .acceleration = 0.0f,
    .brake_force = 0.0f,
    .steering = 0.0f,
    .is_drifting = 0,
    .is_airborne = 0,
    .engine_health = 100,
    .tire_health = 100,
    .nitro = 0
};

// Accelerer
void accelerate(float force) {
    if (driving.engine_health > 0) {
        driving.speed += force * driving.acceleration;
        if (driving.speed > driving.max_speed)
            driving.speed = driving.max_speed;
    }
}

// Freiner
void brake(float force) {
    driving.speed -= force * driving.brake_force;
    if (driving.speed < 0) driving.speed = 0;
}

// Tourner
void steer(float angle) {
    driving.steering = angle;
    if (driving.speed > 100.0f)
        driving.is_drifting = 1;
    else
        driving.is_drifting = 0;
}

// Nitro boost
void activate_nitro() {
    if (driving.nitro > 0) {
        driving.speed *= 1.5f;
        driving.nitro -= 10;
    }
}

// Klaxon
void honk() {
    // Son klaxon
    // PNJ s ecartent
}

// Collision
void vehicle_collision(float impact_force) {
    driving.engine_health -= (int)(impact_force * 0.1f);
    if (driving.engine_health < 0)
        driving.engine_health = 0;
}

// Reparer vehicule
void repair_vehicle() {
    driving.engine_health = 100;
    driving.tire_health = 100;
}

// Crever pneu
void blow_tire(int tire_index) {
    driving.tire_health = 0;
    driving.max_speed *= 0.3f;
}

// Faire le plein
void refuel() {
    // Station essence
    // Cout selon vehicule
}
