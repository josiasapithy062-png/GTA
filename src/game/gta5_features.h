// ELYRIA STORIES - Header GTA5 features
#ifndef GTA5_FEATURES_H
#define GTA5_FEATURES_H

typedef enum {
    SKYDIVE, BASEJUMP, SURF, DIVING,
    BMX, CYCLING, TENNIS, GOLF,
    DARTS, ARMWREST, YOGA, TRIATHLON
} SportType;

typedef enum {
    STRIPCLUB, TATTOO, BARBER, CLOTHING,
    GYM, CINEMA, BAR, RESTAURANT,
    CASINO, BOWLING, SHOOTING, RACING
} ActivityType;

typedef enum {
    TOP, BOTTOM, SHOES, ACCESSORY
} ClothingType;

typedef enum {
    EASY, MEDIUM, HARD, VERY_HARD, EXTREME
} Difficulty;

typedef struct {
    char name[32];
    int is_unlocked;
} CustomOption;

typedef struct {
    char name[32];
    ClothingType type;
    int price;
    int is_available;
} ClothingItem;

typedef struct {
    char name[32];
    SportType type;
    int is_available;
} ExtremeSport;

typedef struct {
    char name[32];
    ActivityType type;
    int is_available;
} SpecialActivity;

typedef struct {
    char name[64];
    int players_needed;
    int reward;
    Difficulty difficulty;
    int completed;
    int setup_missions;
} Heist;

extern Heist heists[];
extern int total_heists;

void start_heist(int index);
void complete_heist(int index);
void buy_clothing(ClothingItem* item);
void change_hairstyle(int index);
void add_tattoo(int index);
void play_activity(int index);

#endif
