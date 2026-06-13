// ELYRIA STORIES - Vol
#include "flying.h"
FlyingState flying = {0};
void start_engine() { flying.engine_on = 1; }
void takeoff_plane() { if(flying.engine_on && flying.speed > 80.0f) { flying.is_flying = 1; flying.altitude += 2.0f; } }
void takeoff_helicopter() { if(flying.engine_on) { flying.is_flying = 1; flying.altitude += 1.5f; } }
void thrust_up() { flying.speed += 10.0f; flying.fuel -= 0.1f; }
void thrust_down() { flying.speed -= 5.0f; if(flying.speed < 0.0f) flying.speed = 0.0f; }
void pitch_up() { flying.altitude += flying.speed * 0.1f; }
void pitch_down() { flying.altitude -= flying.speed * 0.1f; }
void land() { flying.altitude -= 2.0f; if(flying.altitude <= 0.0f) { flying.altitude = 0.0f; flying.is_flying = 0; flying.speed = 0.0f; } }
void plane_crash() { flying.is_flying = 0; flying.speed = 0.0f; flying.altitude = 0.0f; }
