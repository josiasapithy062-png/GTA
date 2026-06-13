// ELYRIA STORIES - Header physique
#ifndef PHYSICS_H
#define PHYSICS_H

typedef struct {
    float x, y, z;
    float vel_x, vel_y, vel_z;
    float mass;
    int on_ground;
    int in_water;
    int in_vehicle;
} PhysicsBody;

extern PhysicsBody player_body;

void physics_update(float delta_time);
void apply_force(float fx, float fy, float fz);
void jump(float force);
int check_wall_collision(float x, float z);
int check_vehicle_collision(float x, float z);
void swim(float dir_x, float dir_z);
void dive(float depth);

#endif
