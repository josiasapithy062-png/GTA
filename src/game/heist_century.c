// ELYRIA STORIES - Le Braquage du Siecle

#include "heist_century.h"

// Phases du braquage du siecle
HeistCenturyPhase phases[] = {
    {
        .phase = 1,
        .name = "Reconnaissance",
        .description = "Surveille la banque centrale pendant 3 jours",
        .character = "Mikael",
        .reward = 20000,
        .completed = 0
    },
    {
        .phase = 2,
        .name = "Recrutement Equipe",
        .description = "Recrute hackeur, tireur, conducteur",
        .character = "Josias",
        .reward = 15000,
        .completed = 0
    },
    {
        .phase = 3,
        .name = "Vol du Materiel",
        .description = "Vole chalumeau et explosifs",
        .character = "Trev",
        .reward = 25000,
        .completed = 0
    },
    {
        .phase = 4,
        .name = "Hack du Systeme",
        .description = "Desactive alarmes et cameras",
        .character = "Mikael",
        .reward = 30000,
        .completed = 0
    },
    {
        .phase = 5,
        .name = "Infiltration",
        .description = "Entre dans la banque en deguisement",
        .character = "Franck",
        .reward = 35000,
        .completed = 0
    },
    {
        .phase = 6,
        .name = "Percee du Coffre",
        .description = "Perce le mega coffre avec chalumeau",
        .character = "Trev",
        .reward = 50000,
        .completed = 0
    },
    {
        .phase = 7,
        .name = "Fuite Epique",
        .description = "Fuis avec 2 millions par helicoptere",
        .character = "Josias",
        .reward = 200000,
        .completed = 0
    },
};

int total_heist_phases = 7;
int current_heist_phase = 0;
int heist_success = 0;
int heist_total_reward = 375000;

// Demarrer phase braquage
void start_heist_phase(int phase) {
    current_heist_phase = phase;
}

// Completer phase
void complete_heist_phase(int phase) {
    phases[phase].completed = 1;
    current_heist_phase++;

    if (current_heist_phase >= total_heist_phases) {
        heist_success = 1;
        // Braquage reussi !
        // Ajouter 2 millions au joueur
    }
}

// Echec braquage
void heist_failed() {
    heist_success = 0;
    current_heist_phase = 0;
    // Recommencer depuis debut
}

// Progression
int get_heist_progress() {
    int done = 0;
    for (int i = 0; i < total_heist_phases; i++) {
        if (phases[i].completed) done++;
    }
    return (done * 100) / total_heist_phases;
}
