// Natation et plongee
#include "swimming.h"
SwimState swim = {0};
void start_swimming() { swim.is_swimming = 1; }
void swim_forward(float speed) { swim.speed = speed; }
void dive_underwater() { swim.is_diving = 1; swim.depth += 1.0f; }
void surface() { swim.is_diving = 0; swim.depth = 0.0f; }
void drown() { swim.oxygen = 0; }
void refill_oxygen() { swim.oxygen = 100; }
