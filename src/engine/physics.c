// ELYRIA STORIES - Moteur physique

#include "physics.h"

// Etat physique du joueur
PhysicsBody player_body = {
    .x = 0.0f,
    .y = 0.0f,
    .z = 0.0f,
    .vel_x = 0.0f,
    .vel_y = 0.0f,
    .vel_z = 0.0f,
    .mass = 80.0f,
    .on_ground = 1,
    .in_water = 0,
    .in_vehicle = 0
};

// Gravite
#define GRAVITY -9.8f
#define FRICTION 0.85f
#define WATER_FRICTION 0.7f

// Mettre a jour physique
void physics_update(float delta_time) {
    if (!player_body.on_ground && !player_body.in_water) {
        // Gravite
        player_body.vel_y += GRAVITY * delta_time;
    }

    // Appliquer velocite
    player_body.x += player_body.vel_x * delta_time;
    player_body.y += player_body.vel_y * delta_time;
    player_body.z += player_body.vel_z * delta_time;

    // Friction
    if (player_body.in_water) {
        player_body.vel_x *= WATER_FRICTION;
        player_body.vel_z *= WATER_FRICTION;
    } else {
        player_body.vel_x *= FRICTION;
        player_body.vel_z *= FRICTION;
    }

    // Sol
    if (player_body.y <= 0.0f) {
        player_body.y = 0.0f;
        player_body.vel_y = 0.0f;
        player_body.on_ground = 1;
    }

    // Eau
    if (player_body.z < -1500.0f) {
        player_body.in_water = 1;
    }
}

// Appliquer force
void apply_force(float fx, float fy, float fz) {
    player_body.vel_x += fx / player_body.mass;
    player_body.vel_y += fy / player_body.mass;
    player_body.vel_z += fz / player_body.mass;
}

// Sauter
void jump(float force) {
    if (player_body.on_ground) {
        player_body.vel_y = force;
        player_body.on_ground = 0;
    }
}

// Collision avec mur
int check_wall_collision(float x, float z) {
    return 0;
}

// Collision avec vehicule
int check_vehicle_collision(float x, float z) {
    return 0;
}

// Nager
void swim(float dir_x, float dir_z) {
    if (player_body.in_water) {
        player_body.vel_x = dir_x * 3.0f;
        player_body.vel_z = dir_z * 3.0f;
        player_body.vel_y = 0.5f;
    }
}

// Plonger
void dive(float depth) {
    if (player_body.in_water) {
        player_body.vel_y = -depth;
    }
}
