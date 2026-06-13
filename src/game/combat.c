// ELYRIA STORIES - Systeme de combat complet

#include "combat.h"

// Etat du combat
CombatState combat = {
    .is_fighting = 0,
    .is_aiming = 0,
    .is_cover = 0,
    .combo_count = 0,
    .last_hit_time = 0
};

// Coups corps a corps
MeleeMove moves[] = {
    {"Coup de poing droit",  20,  1, 0},
    {"Coup de poing gauche", 20,  1, 0},
    {"Coup de pied",         35,  1, 0},
    {"Uppercut",             50,  2, 0},
    {"Coup de coude",        40,  1, 0},
    {"Coup de genou",        45,  1, 0},
    {"Headbutt",             60,  2, 0},
    {"Combo 3 coups",        90,  3, 0},
    {"Coup fatal",           150, 5, 0},
    {"Etranglement",         200, 4, 0},
};

int total_moves = 10;

// Frapper ennemi
void melee_attack(int move_index, int target_index) {
    if (!combat.is_fighting) return;
    combat.combo_count++;
    // Appliquer degats a la cible
}

// Viser
void aim_weapon(float target_x, float target_y) {
    combat.is_aiming = 1;
    combat.aim_x = target_x;
    combat.aim_y = target_y;
}

// Tirer
void shoot(int weapon_index) {
    if (!combat.is_aiming) return;
    // Reduire munitions
    // Calculer trajectoire
    // Appliquer degats
}

// Se mettre a couvert
void take_cover(float wall_x, float wall_y) {
    combat.is_cover = 1;
    combat.cover_x = wall_x;
    combat.cover_y = wall_y;
}

// Sortir du couvert
void leave_cover() {
    combat.is_cover = 0;
}

// Roulade d evitement
void dodge_roll(float dir_x, float dir_y) {
    // Joueur roule dans direction
    // Invincible pendant 0.5 sec
}

// Execution
void execute_enemy(int target_index) {
    // Animation execution
    // Ennemi mort instantanement
    // Augmente street

cat > /workspaces/GTA/src/game/combat.c << 'EOF'
// ELYRIA STORIES - Systeme de combat complet

#include "combat.h"

// Etat du combat
CombatState combat = {
    .is_fighting = 0,
    .is_aiming = 0,
    .is_cover = 0,
    .combo_count = 0,
    .last_hit_time = 0
};

// Coups corps a corps
MeleeMove moves[] = {
    {"Coup de poing droit",  20,  1, 0},
    {"Coup de poing gauche", 20,  1, 0},
    {"Coup de pied",         35,  1, 0},
    {"Uppercut",             50,  2, 0},
    {"Coup de coude",        40,  1, 0},
    {"Coup de genou",        45,  1, 0},
    {"Headbutt",             60,  2, 0},
    {"Combo 3 coups",        90,  3, 0},
    {"Coup fatal",           150, 5, 0},
    {"Etranglement",         200, 4, 0},
};

int total_moves = 10;

// Frapper ennemi
void melee_attack(int move_index, int target_index) {
    if (!combat.is_fighting) return;
    combat.combo_count++;
    // Appliquer degats a la cible
}

// Viser
void aim_weapon(float target_x, float target_y) {
    combat.is_aiming = 1;
    combat.aim_x = target_x;
    combat.aim_y = target_y;
}

// Tirer
void shoot(int weapon_index) {
    if (!combat.is_aiming) return;
    // Reduire munitions
    // Calculer trajectoire
    // Appliquer degats
}

// Se mettre a couvert
void take_cover(float wall_x, float wall_y) {
    combat.is_cover = 1;
    combat.cover_x = wall_x;
    combat.cover_y = wall_y;
}

// Sortir du couvert
void leave_cover() {
    combat.is_cover = 0;
}

// Roulade d evitement
void dodge_roll(float dir_x, float dir_y) {
    // Joueur roule dans direction
    // Invincible pendant 0.5 sec
}

// Execution
void execute_enemy(int target_index) {
    // Animation execution
    // Ennemi mort instantanement
    // Augmente street cred
}

// Tir depuis vehicule
void drive_by_shoot(int weapon_index,
                    float dir_x, float dir_y) {
    // Tir en conduisant
    // Moins precis
}
