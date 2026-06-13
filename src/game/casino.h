#ifndef CASINO_H
#define CASINO_H
#include <stdlib.h>
typedef enum { POKER, BLACKJACK, ROULETTE, SLOTS, BACCARAT, CRAPS, VIDEO_POKER } GameType;
typedef struct { char name[32]; GameType type; int min_bet; int max_bet; int is_available; } CasinoGame;
typedef struct { int is_inside; int chips; int total_won; int total_lost; } CasinoState;
extern CasinoGame games[];
extern CasinoState casino;
extern int total_games;
void enter_casino();
void buy_chips(int amount);
void cash_out();
int play_slots(int bet);
int play_blackjack(int bet);
int play_roulette(int bet, int number);
void poker_round(int bet);
#endif
