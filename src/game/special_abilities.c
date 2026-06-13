// Capacites speciales personnages
#include "special_abilities.h"
SpecialAbility abilities[] = {
    // Josias - Leadership
    {"Rallier allies",    JOSIAS_ABILITY, 30, 0, "Tous les allies se battent mieux"},
    {"Intimidation",      JOSIAS_ABILITY, 20, 0, "Les ennemis fuient"},
    {"Discours",          JOSIAS_ABILITY, 60, 0, "Convainc les civils"},
    // Franck - Vitesse
    {"Reflexes rapides",  FRANCK_ABILITY, 30, 0, "Ralentit le temps en voiture"},
    {"Conduite extreme",  FRANCK_ABILITY, 45, 0, "Vitesse maximale doublée"},
    {"Drift maitre",      FRANCK_ABILITY, 20, 0, "Controle parfait en drift"},
    // Mikael - Precision
    {"Visee parfaite",    MIKAEL_ABILITY, 30, 0, "Ralentit le temps en tir"},
    {"Negociateur",       MIKAEL_ABILITY, 60, 0, "Reduit cout braquage"},
    {"Planificateur",     MIKAEL_ABILITY, 90, 0, "Double recompense mission"},
    // Trev - Rage
    {"Mode berserk",      TREV_ABILITY,   45, 0, "Invincible et degats x3"},
    {"Explosion rage",    TREV_ABILITY,   30, 0, "Detruit tout autour"},
    {"Cri de guerre",     TREV_ABILITY,   20, 0, "Paralyse les ennemis"},
};
int total_abilities = 12;
void activate_ability(int index) {
    if(abilities[index].cooldown == 0) {
        abilities[index].is_active = 1;
        abilities[index].cooldown = 30;
    }
}
void update_cooldowns() {
    for(int i = 0; i < total_abilities; i++)
        if(abilities[i].cooldown > 0) abilities[i].cooldown--;
}
