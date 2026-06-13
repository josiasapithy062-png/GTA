#ifndef RADIO_H
#define RADIO_H
typedef struct { char name[32]; char station[32]; char catchphrase[64]; } DJHost;
typedef struct { char text[128]; } RadioAd;
extern DJHost djs[];
extern RadioAd ads[];
extern int current_dj;
void next_station();
void prev_station();
void mute_radio();
void play_ad();
#endif
