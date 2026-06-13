// Dialogues personnages
#include "dialogue.h"
Dialogue dialogues[] = {
    {"Josias", "On va changer Elyria pour toujours",    1, 0},
    {"Franck", "Je suis le meilleur conducteur",         1, 0},
    {"Mikael", "L argent c est le pouvoir",              1, 0},
    {"Trev",   "Je suis le plus fou de tous",            1, 0},
    {"Josias", "Elyria sera libre",                      2, 0},
    {"Douanier","Vos papiers s il vous plait",           3, 0},
    {"Boss",   "Le braquage du siecle commence",         4, 0},
    {"Josias", "Pour Elyria et sa liberte",              5, 0},
};
int total_dialogues = 8;
void play_dialogue(int index) { dialogues[index].is_played = 1; }
