// ELYRIA STORIES - Equipement complet pour braquages

#include "heist_equipment.h"

// =============================
// ARMES DE BRAQUAGE
// =============================
HeistWeapon heist_weapons[] = {
    // Armes discretes
    {"Pistolet Silencieux",   SILENCED,  50,   1,   500,   2000,  0},
    {"SMG Silencieux",        SILENCED,  80,   1,   2000,  8000,  0},
    {"Sniper Silencieux",     SILENCED,  300,  1,   500,   15000, 0},

    // Armes lourdes braquage
    {"Shotgun Tactique",      ASSAULT,   150,  1,   300,   5000,  0},
    {"AK47 Modifie",          ASSAULT,   90,   1,   2000,  10000, 0},
    {"M4 Carbine",            ASSAULT,   85,   1,   2500,  12000, 0},
    {"Mitrailleuse Lourde",   ASSAULT,   100,  1,   5000,  20000, 0},

    // Armes explosives
    {"Grenade Fumigene",      EXPLOSIVE, 0,    1,   10,    500,   0},
    {"Grenade Aveuglante",    EXPLOSIVE, 0,    1,   10,    800,   0},
    {"C4 Explosif",           EXPLOSIVE, 1000, 1,   5,     5000,  0},
    {"RPG Antichar",          EXPLOSIVE, 800,  1,   3,     25000, 0},
    {"Mine Antipersonnel",    EXPLOSIVE, 500,  1,   10,    3000,  0},

    // Armes speciales
    {"Pistolet Electrochoc",  SPECIAL,   0,    1,   20,    2000,  0},
    {"Gaz Paralysant",        SPECIAL,   0,    1,   5,     3000,  0},
    {"Bombe EMP",             SPECIAL,   0,    1,   2,     10000, 0},
};

// =============================
// EQUIPEMENT TECHNIQUE
// =============================
HeistTool heist_tools[] = {
    // Effraction
    {"Chalumeau",             BREACH,    5000,  0, "Coupe coffre fort"},
    {"Perceuse Electrique",   BREACH,    3000,  0, "Perce murs et portes"},
    {"Pied de biche",         BREACH,    200,   0, "Force portes simples"},
    {"Explosif Porte",        BREACH,    8000,  0, "Detruit portes blindees"},
    {"Crochet Serrure",       BREACH,    500,   0, "Crochete serrures"},
    {"Coupe Fil",             BREACH,    300,   0, "Coupe alarmes"},

    // Informatique
    {"Laptop Hacker",         TECH,      15000, 0, "Hack systemes securite"},
    {"Brouilleur Signal",     TECH,      10000, 0, "Bloque communications"},
    {"Scanner Empreintes",    TECH,      8000,  0, "Clone empreintes"},
    {"Faux Badge",            TECH,      2000,  0, "Accede zones securisees"},
    {"Camera Espion",         TECH,      3000,  0, "Surveille a distance"},
    {"Detecteur Metal",       TECH,      1500,  0, "Trouve coffres caches"},

    // Transport
    {"Sac Argent Grand",      TRANSPORT, 500,   0, "Transporte 500k cash"},
    {"Valise Blindee",        TRANSPORT, 2000,  0, "Transporte bijoux"},
    {"Chariot Coffre",        TRANSPORT, 1000,  0, "Deplace coffres lourds"},
    {"Sac a Dos Tactique",    TRANSPORT, 800,   0, "Transporte armes extra"},

    // Protection
    {"Gilet Pare Balles",     PROTECTION,5000,  0, "Reduit degats balles"},
    {"Casque Tactique",       PROTECTION,2000,  0, "Protege tete"},
    {"Bouclier Tactique",     PROTECTION,8000,  0, "Bloque balles"},
    {"Masque Gaz",            PROTECTION,1500,  0, "Protege gaz"},

    // Deguisements
    {"Masque Cagoule",        DISGUISE,  200,   0, "Cache visage basique"},
    {"Uniforme Police",       DISGUISE,  0,     0, "Se deguise en policier"},
    {"Uniforme Militaire",    DISGUISE,  0,     0, "Se deguise en soldat"},
    {"Costume Technicien",    DISGUISE,  500,   0, "Se deguise en technicien"},
    {"Tenue Serveur",         DISGUISE,  300,   0, "Se deguise en serveur"},
    {"Masque Clown",          DISGUISE,  100,   0, "Masque intimidant"},
    {"Masque Presidente",     DISGUISE,  150,   0, "Masque du president"},

    // Vehicules braquage
    {"Van Noir",              VEHICLE,   50000, 0, "Transport discret"},
    {"Camion Blindé",         VEHICLE,   200000,0, "Blindage complet"},
    {"Helicoptere Fuite",     VEHICLE,   500000,0, "Fuite par les airs"},
    {"Bateau Rapide Fuite",   VEHICLE,   300000,0, "Fuite par la mer"},
    {"Moto Fuite",            VEHICLE,   80000, 0, "Fuite rapide en ville"},
};

// =============================
// ROLES DANS UN BRAQUAGE
// =============================
HeistRole roles[] = {
    {"Chef de Braquage",   LEADER,   "Coordonne toute l equipe"},
    {"Tireur Elite",       SHOOTER,  "Neutralise les gardes"},
    {"Hackeur",            HACKER,   "Desactive la securite"},
    {"Conducteur",         DRIVER,   "Gere les vehicules de fuite"},
    {"Artificier",         BOMBER,   "Gere les explosifs"},
    {"Infiltrateur",       STEALTH,  "Entre sans se faire voir"},
};

int total_heist_weapons = 14;
int total_heist_tools = 31;
int total_roles = 6;

// Acheter equipement
int buy_heist_tool(int index, int cash) {
    if (cash >= heist_tools[index].price) {
        heist_tools[index].is_owned = 1;
        return 1;
    }
    return 0;
}

// Acheter arme braquage
int buy_heist_weapon(int index, int cash) {
    if (cash >= heist_weapons[index].price) {
        heist_weapons[index].is_owned = 1;
        return 1;
    }
    return 0;
}

// Assigner role
void assign_role(int character_index, int role_index) {
    roles[role_index].assigned_character = character_index;
}

// Verifier equipement complet
int check_heist_ready(int heist_index) {
    // Verifier si tous les outils necessaires sont la
    return 1;
}
