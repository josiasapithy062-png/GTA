// ELYRIA STORIES - Sequence d intro
#include "intro.h"
IntroScene intro_scenes[] = {
    {"Noir total",              3,  0},
    {"Logo ELYRIA STORIES",     4,  0},
    {"Vue aerienne USA",        5,  0},
    {"Josias arrive en ville",  6,  0},
    {"Presentation Franck",     4,  0},
    {"Presentation Mikael",     4,  0},
    {"Presentation Trev",       4,  0},
    {"Le plan se met en place", 8,  0},
    {"Debut du jeu",            3,  0},
};
int total_scenes = 9;
int current_scene = 0;
int intro_complete = 0;
void play_intro() {
    current_scene = 0;
    intro_complete = 0;
}
void next_scene() {
    current_scene++;
    if(current_scene >= total_scenes) {
        intro_complete = 1;
        current_scene = 0;
    }
}
void skip_intro() {
    intro_complete = 1;
    current_scene = 0;
}
