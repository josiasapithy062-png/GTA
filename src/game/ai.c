// ELYRIA STORIES - IA ennemis et PNJ
#include "ai.h"
AIState ai_states[] = {
    {IDLE,    0.0f, 0.0f, 0, 0},
    {PATROL,  0.0f, 0.0f, 0, 0},
    {CHASE,   0.0f, 0.0f, 0, 0},
    {ATTACK,  0.0f, 0.0f, 0, 0},
    {FLEE,    0.0f, 0.0f, 0, 0},
    {COVER,   0.0f, 0.0f, 0, 0},
};
void ai_update(int npc_index, float player_x, float player_y) {
    float dx = player_x - ai_states[npc_index].pos_x;
    float dy = player_y - ai_states[npc_index].pos_y;
    float dist = dx*dx + dy*dy;
    if (dist < 100.0f) ai_states[npc_index].state = ATTACK;
    else if (dist < 500.0f) ai_states[npc_index].state = CHASE;
    else ai_states[npc_index].state = PATROL;
}
void ai_patrol(int index) { ai_states[index].state = PATROL; }
void ai_attack(int index) { ai_states[index].state = ATTACK; ai_states[index].is_shooting = 1; }
void ai_flee(int index) { ai_states[index].state = FLEE; }
void ai_take_cover(int index) { ai_states[index].state = COVER; }
