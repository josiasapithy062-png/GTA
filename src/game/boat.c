// Navigation bateaux et mer
#include "boat.h"
BoatState boat = {0};
void start_boat() { boat.engine_on = 1; }
void accelerate_boat(float speed) { boat.speed += speed; }
void steer_boat(float angle) { boat.direction = angle; }
void anchor_boat() { boat.speed = 0; boat.is_anchored = 1; }
void dive_from_boat() { boat.engine_on = 0; }
void boat_collision(int damage) { boat.hull_health -= damage; }
void repair_boat() { boat.hull_health = 100; }
