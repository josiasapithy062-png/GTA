// ELYRIA STORIES - Radio et DJ
#include "radio.h"
DJHost djs[] = {
    {"DJ Smooth",    "Elyria Funk FM",    "Bienvenue sur Elyria Funk FM!"},
    {"DJ Blazer",    "Liberty Hip Hop",   "C est votre DJ Blazer en direct!"},
    {"DJ Soulful",   "Elyria RnB",        "On est sur Elyria RnB baby!"},
    {"DJ Rock",      "USA Classic Rock",  "Rock n Roll forever!"},
    {"DJ Miles",     "Elyria Jazz Lounge","Jazz et sophistication!"},
    {"DJ Pop Star",  "Liberty Pop Radio", "Le meilleur de la pop!"},
};
RadioAd ads[] = {
    {"Achetez vos armes chez Ammu-Nation!"},
    {"Pizza Stack - Livraison rapide Elyria!"},
    {"Impotent Rage - Le film de l annee!"},
    {"Garage Benny - On repare tout!"},
    {"Casino Elyria - Venez gagner gros!"},
};
int total_djs = 6;
int total_ads = 5;
int current_dj = 0;
void next_station() { current_dj = (current_dj + 1) % total_djs; }
void prev_station() { current_dj = (current_dj - 1 + total_djs) % total_djs; }
void mute_radio() { }
void play_ad() { }
