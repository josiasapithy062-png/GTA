// ELYRIA STORIES - Header audio
#ifndef AUDIO_H
#define AUDIO_H

#define MAX_SONGS 10

typedef enum {
    FUNK,
    HIP_HOP,
    RNB,
    ROCK,
    JAZZ,
    POP
} MusicGenre;

typedef enum {
    TENSE,
    ACTION,
    STEALTH,
    VICTORY,
    FAIL
} MissionMood;

typedef struct {
    char name[32];
    MusicGenre genre;
    int volume;
    int is_playing;
    char songs[MAX_SONGS][64];
    int total_songs;
} RadioStation;

extern RadioStation stations[];
extern int total_stations;
extern int current_station;

void change_station(int index);
void volume_up();
void volume_down();
void play_mission_music(MissionMood mood);

#endif
