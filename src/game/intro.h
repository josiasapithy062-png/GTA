#ifndef INTRO_H
#define INTRO_H
typedef struct { char name[64]; int duration; int is_played; } IntroScene;
extern IntroScene intro_scenes[];
extern int total_scenes;
extern int current_scene;
extern int intro_complete;
void play_intro();
void next_scene();
void skip_intro();
#endif
