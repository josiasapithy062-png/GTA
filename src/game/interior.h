#ifndef INTERIOR_H
#define INTERIOR_H
typedef enum { APARTMENT, MANSION, HIDEOUT, BANK, CLUB, SHOP, PALACE, MILITARY, CASINO, HOSPITAL, POLICE, GYM, RESTAURANT } InteriorType;
typedef struct { char name[64]; InteriorType type; int country; int is_available; int is_loaded; } Interior;
extern Interior interiors[];
extern int total_interiors;
void enter_interior(int index);
void exit_interior(int index);
#endif
