// ELYRIA STORIES - Systeme telephone et messagerie

#include "phone.h"

// Contacts du telephone
Contact contacts[] = {
    // Contacts Josias
    {"Franck",        "555-0101", ALLY,    0, "Yo c est Franck"},
    {"Mikael",        "555-0102", ALLY,    0, "Mikael a l appareil"},
    {"Trev",          "555-0103", ALLY,    0, "C est Trev, quoi?"},

    // Contacts missions
    {"Le Boss",       "555-0201", MISSION, 0, "J ai du boulot pour toi"},
    {"Informateur",   "555-0202", MISSION, 0, "J ai des infos importantes"},
    {"Douanier",      "555-0203", MISSION, 0, "Je peux t aider a passer"},
    {"Politicien",    "555-0204", MISSION, 0, "Nous avons un accord"},

    // Services
    {"Taxi",          "555-0301", SERVICE, 1, "Taxi a votre service"},
    {"Ambulance",     "555-0302", SERVICE, 1, "Services medicaux"},
    {"Mecanicien",    "555-0303", SERVICE, 1, "Je repare tout"},
    {"Armurier",      "555-0304", SERVICE, 0, "Armes discretes dispo"},
    {"Agent Immob",   "555-0305", SERVICE, 1, "Proprietes disponibles"},

    // Ennemis
    {"Chef de Gang",  "555-0401", ENEMY,   0, "Tu es mort"},
    {"Commissaire",   "555-0402", ENEMY,   0, "On te retrouvera"},
};

int total_contacts = 14;

// Messages recus
Message messages[] = {
    {1, "Franck",     "Yo t es ou la?",              0, 0},
    {2, "Le Boss",    "Reunion ce soir au port",      0, 0},
    {3, "Informateur","Attention la police arrive",   0, 0},
    {4, "Mikael",     "Le plan est pret",             0, 0},
    {5, "Trev",       "J ai les armes pretes",        0, 0},
    {6, "Douanier",   "La frontiere est libre a 3h",  0, 0},
    {7, "Politicien", "Rendez vous au palais demain", 0, 0},
    {8, "Armurier",   "Nouveau stock arrive au port", 0, 0},
};

int total_messages = 8;
int unread_messages = 8;

// Appeler un contact
void call_contact(int index) {
    if (contacts[index].is_unlocked) {
        // Declenche dialogue avec contact
        contacts[index].is_unlocked = 1;
    }
}

// Envoyer message
void send_message(int contact_index, char* text) {
    // Envoie message au contact
}

// Lire message
void read_message(int index) {
    if (!messages[index].is_read) {
        messages[index].is_read = 1;
        unread_messages--;
    }
}

// Ajouter contact
void add_contact(char* name, char* number, ContactType type) {
    // Ajoute nouveau contact
}

// Debloquer contact apres mission
void unlock_contact(int index) {
    contacts[index].is_unlocked = 1;
}
