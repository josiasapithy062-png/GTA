// ELYRIA STORIES - Header braquage du siecle
#ifndef HEIST_CENTURY_H
#define HEIST_CENTURY_H

typedef struct {
    int phase;
    char name[64];
    char description[128];
    char character[32];
    int reward;
    int completed;
} HeistCenturyPhase;

extern HeistCenturyPhase phases[];
extern int total_heist_phases;
extern int current_heist_phase;
extern int heist_success;
extern int heist_total_reward;

void start_heist_phase(int phase);
void complete_heist_phase(int phase);
void heist_failed();
int get_heist_progress();

#endif
