// Frontiere et douaniers
#include "border.h"
BorderState border = {0};
BorderGuard guards[] = {
    {"Douanier Chef",   USA,    4800.0f, 50.0f,  1, 0},
    {"Douanier 1",      USA,    4820.0f, -50.0f, 1, 0},
    {"Douanier 2",      USA,    4840.0f, 100.0f, 1, 0},
    {"Douanier Elyria", ELYRIA, 5200.0f, 50.0f,  1, 0},
    {"Douanier Ely 2",  ELYRIA, 5220.0f, -50.0f, 1, 0},
};
int total_guards = 5;
void approach_border() {
    border.is_at_border = 1;
    border.inspection_started = 1;
}
void show_papers() { border.papers_shown = 1; border.crossing_allowed = 1; }
void bribe_border_guard(int amount) { border.crossing_allowed = 1; }
void sneak_through_border() { border.is_wanted = 1; }
void cross_border() {
    if(border.crossing_allowed) border.has_crossed = 1;
    else sneak_through_border();
}
