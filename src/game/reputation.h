// ELYRIA STORIES - Header reputation
#ifndef REPUTATION_H
#define REPUTATION_H

typedef struct {
    char character[32];
    int street_cred;
    int police_notoriety;
    int gang_respect;
    int political_power;
    int wealth_status;
    int total_kills;
    int missions_done;
} Reputation;

extern Reputation reputations[4];

void add_street_cred(int char_index, int amount);
void add_police_notoriety(int char_index, int amount);
void add_gang_respect(int char_index, int amount);
void add_political_power(int char_index, int amount);
char* get_reputation_title(int char_index);

#endif
