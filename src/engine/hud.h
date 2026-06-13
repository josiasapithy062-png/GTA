// ELYRIA STORIES - Header HUD
#ifndef HUD_H
#define HUD_H

typedef struct {
    int show_minimap;
    int show_health;
    int show_armor;
    int show_money;
    int show_wanted;
    int show_weapon;
    int show_phone;
    float minimap_zoom;
} HUDState;

extern HUDState hud;

void draw_health_bar(int health);
void draw_armor_bar(int armor);
void draw_money(int cash);
void draw_wanted_stars(int level);
void draw_current_weapon(int weapon_index);
void draw_minimap(float player_x, float player_y);
void draw_zone_name(char* zone_name);
void draw_time(int hour, int minute);
void draw_notification(char* text);
void draw_active_character(char* name);

#endif
