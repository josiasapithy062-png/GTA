#ifndef NEWSPAPER_H
#define NEWSPAPER_H
typedef struct { char headline[64]; int mission_trigger; int is_unlocked; } NewsArticle;
extern NewsArticle articles[];
extern int total_articles;
void unlock_article(int index);
void read_newspaper();
void update_news(int mission_id);
#endif
