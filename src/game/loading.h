#ifndef LOADING_H
#define LOADING_H
typedef struct { int is_loading; int progress; char zone_name[32]; } LoadingScreen;
typedef struct { char text[128]; } LoadingTip;
extern LoadingScreen loading;
extern LoadingTip tips[];
extern int total_tips;
void show_loading_screen(char* zone_name);
void update_loading(int progress);
void hide_loading_screen();
void show_random_tip();
#endif
