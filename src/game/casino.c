// ELYRIA STORIES - Casino Elyria
#include "casino.h"
CasinoGame games[] = {
    {"Poker Texas",      POKER,      500,   100000, 1},
    {"Blackjack",        BLACKJACK,  100,   50000,  1},
    {"Roulette",         ROULETTE,   50,    25000,  1},
    {"Machine a Sous",   SLOTS,      10,    10000,  1},
    {"Baccarat",         BACCARAT,   1000,  200000, 1},
    {"Craps",            CRAPS,      200,   75000,  1},
    {"Video Poker",      VIDEO_POKER,50,    20000,  1},
};
int total_games = 7;
CasinoState casino = {0};
void enter_casino() { casino.is_inside = 1; casino.chips = 0; }
void buy_chips(int amount) { casino.chips += amount; }
void cash_out() { casino.is_inside = 0; }
int play_slots(int bet) { int result = bet * (rand() % 10); casino.chips += result - bet; return result; }
int play_blackjack(int bet) { int result = rand() % 2 ? bet * 2 : 0; casino.chips += result - bet; return result; }
int play_roulette(int bet, int number) { int result = rand() % 37 == number ? bet * 36 : 0; casino.chips += result - bet; return result; }
void poker_round(int bet) { casino.chips -= bet; }
