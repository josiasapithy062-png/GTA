// Checkpoints et respawn
#include "checkpoint.h"
Checkpoint checkpoints[] = {
    {"Debut USA",        USA,    0.0f,    0.0f,    1},
    {"Port USA",         USA,    800.0f, -1200.0f, 1},
    {"Frontiere",        USA,    4800.0f, 0.0f,    1},
    {"Debut Elyria",     ELYRIA, 6000.0f, 0.0f,    1},
    {"Arsenal",          ELYRIA, 7000.0f, 2000.0f, 1},
    {"Palais",           ELYRIA, 6200.0f, 1500.0f, 1},
};
int total_checkpoints = 6;
int last_checkpoint = 0;
void save_checkpoint(int index) { last_checkpoint = index; }
void respawn_at_checkpoint() { }
