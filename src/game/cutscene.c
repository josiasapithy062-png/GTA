// Cinematiques
#include "cutscene.h"
Cutscene cutscenes[] = {
    {"Intro Josias",     1, 30, 0},
    {"Arrivee Elyria",   2, 45, 0},
    {"Coup d Etat",      3, 60, 0},
    {"Braquage Siecle",  4, 90, 0},
    {"Fin du Jeu",       5, 120,0},
};
int total_cutscenes = 5;
void play_cutscene(int index) { cutscenes[index].is_played = 1; }
void skip_cutscene(int index) { cutscenes[index].is_played = 1; }
