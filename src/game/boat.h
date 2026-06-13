#ifndef BOAT_H
#define BOAT_H
typedef struct { float speed; float direction; int engine_on; int is_anchored; int hull_health; float depth; } BoatState;
extern BoatState boat;
void start_boat(); void accelerate_boat(float speed); void steer_boat(float angle);
void anchor_boat(); void dive_from_boat(); void boat_collision(int damage); void repair_boat();
#endif
