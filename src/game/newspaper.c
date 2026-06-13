// Journal et actualites du jeu
#include "newspaper.h"
NewsArticle articles[] = {
    {"Crime en hausse a Liberty City",    1, 0},
    {"Mystérieux braquage a la banque",   2, 0},
    {"Tensions a la frontiere Elyria",    3, 0},
    {"L arsenal national sous alerte",    4, 0},
    {"Coup d etat a Elyria",              5, 0},
    {"Nouveau president pour Elyria",     6, 0},
};
int total_articles = 6;
void unlock_article(int index) { articles[index].is_unlocked = 1; }
void read_newspaper() { }
void update_news(int mission_id) { unlock_article(mission_id - 1); }
