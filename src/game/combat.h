// ELYRIA STORIES - Header combat
#ifndef COMBAT_H
#define COMBAT_H

typedef struct {
    int is_fighting;
    int is_aiming;
    int is_cover;
    int combo_count;
    int last_hit_time;
    float aim_x;
    float aim_y;
    float cover_x;
    float cover_y;
} CombatState;

typedef struct {
    char name[32];
    int damage;
    int combo_required;
    int is_unlocked;
} MeleeMove;

extern CombatState combat;
extern MeleeMove moves[];
extern int total_moves;

void melee_attack(int move_index, int target_index);
void aim_weapon(float target_x, float target_y);
void shoot(int weapon_index);
void take_cover(float wall_x, float wall_y);
void leave_cover();
void dodge_roll(float dir_x, float dir_y);
void execute_enemy(int target_index);
void drive_by_shoot(int weapon_index, float dir_x, float dir_y);

#endif
