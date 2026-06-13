// ELYRIA STORIES - Header telephone
#ifndef PHONE_H
#define PHONE_H

typedef enum {
    ALLY,
    MISSION,
    SERVICE,
    ENEMY
} ContactType;

typedef struct {
    char name[32];
    char number[16];
    ContactType type;
    int is_unlocked;
    char voicemail[128];
} Contact;

typedef struct {
    int id;
    char sender[32];
    char text[128];
    int is_read;
    int is_important;
} Message;

extern Contact contacts[];
extern Message messages[];
extern int total_contacts;
extern int total_messages;
extern int unread_messages;

void call_contact(int index);
void send_message(int contact_index, char* text);
void read_message(int index);
void add_contact(char* name, char* number, ContactType type);
void unlock_contact(int index);

#endif
