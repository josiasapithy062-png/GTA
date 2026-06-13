// ELYRIA STORIES - Header vehicules complet
#ifndef VEHICLES_H
#define VEHICLES_H

typedef enum {
    CAR,
    MOTORCYCLE,
    PLANE,
    HELICOPTER,
    BOAT,
    TANK
} VehicleType;

typedef struct {
    char name[32];
    VehicleType type;
    float max_speed;
    float acceleration;
    float handling;
    int is_occupied;
} Vehicle;

extern Vehicle vehicles[];
extern int current_vehicle;

void enter_vehicle(int index);
void exit_vehicle();
void steal_vehicle(int index);

#endif
