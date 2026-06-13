#ifndef SPECIAL_ABILITIES_H
#define SPECIAL_ABILITIES_H
typedef enum { JOSIAS_ABILITY, FRANCK_ABILITY, MIKAEL_ABILITY, TREV_ABILITY } AbilityOwner;
typedef struct { char name[32]; AbilityOwner owner; int cooldown; int is_active; char description[64]; } SpecialAbility;
extern SpecialAbility abilities[];
extern int total_abilities;
void activate_ability(int index);
void update_cooldowns();
#endif
