#ifndef FLYING_H
#define FLYING_H
typedef struct { float altitude; float speed; float thrust; float pitch; float roll; float yaw; float fuel; int is_flying; int is_landing; int engine_on; } FlyingState;
extern FlyingState flying;
void start_engine(); void takeoff_plane(); void takeoff_helicopter(); void thrust_up(); void thrust_down(); void pitch_up(); void pitch_down(); void land(); void plane_crash();
#endif
