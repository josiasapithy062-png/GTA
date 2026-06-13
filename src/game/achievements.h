#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H
typedef struct { char name[32]; char description[64]; int is_unlocked; } Achievement;
extern Achievement achievements[];
extern int total_achievements;
void unlock_achievement(int index);
void check_achievements();
#endif
