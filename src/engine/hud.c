// ELYRIA STORIES - HUD et mini-map

#include "hud.h"

// Etat du HUD
HUDState hud = {
    .show_minimap = 1,
    .show_health = 1,
    .show_armor = 1,
    .show_money = 1,
    .show_wanted = 1,
    .show_weapon = 1,
    .show_phone = 1,
    .minimap_zoom = 1.0f
};

// Dessiner barre de vie
void draw_health_bar(int health) {
    // Position : bas gauche ecran PSP
    // Largeur selon health / 100
    // Couleur rouge
}

// Dessiner barre armure
void draw_armor_bar(int armor) {
    // Position : sous barre vie
    // Couleur bleu
}

// Dessiner argent
void draw_money(int cash) {
    // Position : haut droit
    // Couleur verte
}

// Dessiner etoiles police
void draw_wanted_stars(int level) {
    // 5 etoiles max
    // Etoiles pleines = actives
    // Position : haut droit sous argent
}

// Dessiner arme actuelle
void draw_current_weapon(int weapon_index) {
    // Icone arme + munitions
    // Position : bas droit
}

// Dessiner mini-map
void draw_minimap(float player_x, float player_y) {
    // Cercle en bas gauche
    // Point blanc = joueur
    // Points rouges = ennemis
    // Points bleus = police
    // Points jaunes = missions
    // Points verts = alliés
}

// Dessiner nom zone
void draw_zone_name(char* zone_name) {
    // Bas au centre
    // Disparait apres 3 secondes
}

// Dessiner heure
void draw_time(int hour, int minute) {
    // Haut gauche
}

// Dessiner notifications
void draw_notification(char* text) {
    // Haut droit
    // Disparait apres 5 secondes
}

// Dessiner personnage actif
void draw_active_character(char* name) {
    // Bas droit
    // Photo + nom personnage
}
