// Notifications et messages ecran
#include "notification.h"
Notification notifications[10];
int notif_count = 0;
void show_notification(char* text, int duration) {
    if(notif_count < 10) {
        notifications[notif_count].duration = duration;
        notif_count++;
    }
}
void show_money_earned(int amount) { }
void show_mission_start(char* name) { }
void show_mission_complete(char* name, int reward) { }
void show_mission_failed(char* name) { }
void show_wanted_level(int stars) { }
void clear_notifications() { notif_count = 0; }
