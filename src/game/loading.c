// Ecran de chargement PSP
#include "loading.h"
LoadingScreen loading = {0};
LoadingTip tips[] = {
    {"Utilise L1 pour changer de personnage"},
    {"La frontiere est gardee, sois discret"},
    {"L arsenal a les meilleures armes"},
    {"Lave ta voiture pour reduire les etoiles"},
    {"Le casino peut te rendre riche"},
    {"Utilise le parachute depuis les avions"},
    {"Chaque personnage a sa specialite"},
    {"Le braquage du siecle necessite 4 joueurs"},
    {"Elyria est le pays principal du jeu"},
    {"Le coup d etat change la fin du jeu"},
};
int total_tips = 10;
void show_loading_screen(char* zone_name) { loading.is_loading = 1; loading.progress = 0; }
void update_loading(int progress) { loading.progress = progress; if(progress >= 100) loading.is_loading = 0; }
void hide_loading_screen() { loading.is_loading = 0; }
void show_random_tip() { }
