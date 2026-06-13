// ELYRIA STORIES - Mission Coup d Etat
// La mission principale du jeu

#include "coup_detat.h"

// Phases du coup d etat
CoupPhase coup_phases[] = {
    {
        .phase = 1,
        .name = "Recrutement des Allies",
        .description = "Recrute 5 personnages cles dans Elyria",
        .character = "Josias",
        .reward = 30000,
        .completed = 0
    },
    {
        .phase = 2,
        .name = "Controle des Medias",
        .description = "Prends le controle de la television nationale",
        .character = "Mikael",
        .reward = 40000,
        .completed = 0
    },
    {
        .phase = 3,
        .name = "Neutraliser la Garde",
        .description = "Elimine la garde presidentielle",
        .character = "Trev",
        .reward = 50000,
        .completed = 0
    },
    {
        .phase = 4,
        .name = "Siege du Parlement",
        .description = "Prends le controle du parlement d Elyria",
        .character = "Josias",
        .reward = 75000,
        .completed = 0
    },
    {
        .phase = 5,
        .name = "Arrestation du President",
        .description = "Capture le president en place",
        .character = "Franck",
        .reward = 100000,
        .completed = 0
    },
    {
        .phase = 6,
        .name = "Installation au Pouvoir",
        .description = "Installe notre homme a la presidence",
        .character = "Josias",
        .reward = 250000,
        .completed = 0
    },
};

int total_coup_phases = 6;
int current_coup_phase = 0;
int coup_success = 0;

// Demarrer phase
void start_coup_phase(int phase) {
    current_coup_phase = phase;
    coup_phases[phase].completed = 0;
}

// Completer phase
void complete_coup_phase(int phase) {
    coup_phases[phase].completed = 1;
    current_coup_phase++;

    // Verifier si coup reussi
    if (current_coup_phase >= total_coup_phases) {
        coup_success = 1;
        // Fin du jeu - Notre homme au pouvoir !
    }
}

// Verifier progression
int get_coup_progress() {
    int completed = 0;
    for (int i = 0; i < total_coup_phases; i++) {
        if (coup_phases[i].completed) completed++;
    }
    return (completed * 100) / total_coup_phases;
}
