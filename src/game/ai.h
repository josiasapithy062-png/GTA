#ifndef AI_H
#define AI_H
typedef enum { IDLE, PATROL, CHASE, ATTACK, FLEE, COVER } AIBehavior;
typedef struct { AIBehavior state; float pos_x; float pos_y; int is_shooting; int is_alerted; } AIState;
extern AIState ai_states[];
void ai_update(int npc_index, float player_x, float player_y);
void ai_patrol(int index);
void ai_attack(int index);
void ai_flee(int index);
void ai_take_cover(int index);
#endif
