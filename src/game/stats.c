// ELYRIA STORIES - Statistiques du joueur

#include "stats.h"

// Stats globales
GameStats stats = {
    .total_kills = 0,
    .total_deaths = 0,
    .total_arrests = 0,
    .cars_stolen = 0,
    .cars_destroyed = 0,
    .boats_stolen = 0,
    .planes_stolen = 0,
    .heists_completed = 0,
    .missions_completed = 0,
    .missions_failed = 0,
    .distance_on_foot = 0,
    .distance_by_car = 0,
    .distance_by_boat = 0,
    .distance_by_plane = 0,
    .total_money_earned = 0,
    .total_money_spent = 0,
    .properties_bought = 0,
    .wanted_stars_earned = 0,
    .police_evaded = 0,
    .bullets_fired = 0,
    .accuracy = 0,
    .playtime_minutes = 0
};

// Mettre a jour stats
void update_kill_stats() {
    stats.total_kills++;
}

void update_death_stats() {
    stats.total_deaths++;
}

void update_car_stolen() {
    stats.cars_stolen++;
}

void update_mission_complete() {
    stats.missions_completed++;
}

void update_mission_failed() {
    stats.missions_failed++;
}

void update_money_earned(int amount) {
    stats.total_money_earned += amount;
}

void update_money_spent(int amount) {
    stats.total_money_spent += amount;
}

// Calculer precision tir
void calculate_accuracy(int hits, int shots) {
    if (shots > 0)
        stats.accuracy = (hits * 100) / shots;
}

// Afficher stats
void print_stats() {
    // Affiche toutes les stats a l ecran
}
