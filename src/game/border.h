#ifndef BORDER_H
#define BORDER_H
typedef struct { int is_at_border; int inspection_started; int papers_shown; int crossing_allowed; int has_crossed; int is_wanted; } BorderState;
typedef struct { char name[32]; int country; float pos_x; float pos_y; int is_active; int is_bribed; } BorderGuard;
extern BorderState border;
extern BorderGuard guards[];
extern int total_guards;
void approach_border();
void show_papers();
void bribe_border_guard(int amount);
void sneak_through_border();
void cross_border();
#endif
