#ifndef FINALE_H
#define FINALE_H
typedef enum { GOOD_ENDING, BAD_ENDING, SECRET_ENDING, NEUTRAL_ENDING } EndingType;
typedef struct { EndingType type; char name[32]; char description[64]; int is_triggered; } Ending;
typedef struct { char character[32]; char role[32]; } Credit;
extern Ending endings[];
extern Credit credits[];
extern int total_endings;
extern int total_credits;
void trigger_ending(int type);
void show_credits();
void calculate_final_score();
void unlock_new_game_plus();
#endif
