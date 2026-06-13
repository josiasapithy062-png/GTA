// ELYRIA STORIES - Fin du jeu et credits
#include "finale.h"
EndingType endings[] = {
    {GOOD_ENDING,    "Liberation d Elyria",     "Josias devient hero national",      0},
    {BAD_ENDING,     "La trahison",             "Un allie trahit le groupe",          0},
    {SECRET_ENDING,  "Le vrai pouvoir",         "Josias prend tout pour lui",         0},
    {NEUTRAL_ENDING, "Equilibre fragile",       "Elyria change mais reste instable",  0},
};
int total_endings = 4;
Credits credits[] = {
    {"Josias",     "Personnage Principal"},
    {"Franck",     "Pilote de l equipe"},
    {"Mikael",     "Le cerveau"},
    {"Trev",       "La force brute"},
    {"Elyria",     "Le pays de la liberte"},
};
int total_credits = 5;
void trigger_ending(int type) { endings[type].is_triggered = 1; }
void show_credits() { }
void calculate_final_score() { }
void unlock_new_game_plus() { }
