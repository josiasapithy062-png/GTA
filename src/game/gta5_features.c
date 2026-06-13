// ELYRIA STORIES - Toutes les features GTA 5

#include "gta5_features.h"

// =============================
// SPORTS EXTREMES
// =============================
ExtremeSport extreme_sports[] = {
    {"Saut en parachute",    SKYDIVE,   1},
    {"Base Jump",            BASEJUMP,  0},
    {"Surf",                 SURF,      1},
    {"Plongee sous marine",  DIVING,    1},
    {"Velo BMX",             BMX,       1},
    {"Velo de montagne",     CYCLING,   1},
    {"Tennis",               TENNIS,    1},
    {"Golf",                 GOLF,      1},
    {"Flechettes",           DARTS,     1},
    {"Bras de fer",          ARMWREST,  1},
    {"Yoga",                 YOGA,      1},
    {"Triathlon",            TRIATHLON, 0},
};

// =============================
// ACTIVITES SPECIALES
// =============================
SpecialActivity activities[] = {
    {"Strip Club",           STRIPCLUB, 1},
    {"Tatouage",             TATTOO,    1},
    {"Coiffeur",             BARBER,    1},
    {"Boutique vetements",   CLOTHING,  1},
    {"Salle de sport",       GYM,       1},
    {"Cinema",               CINEMA,    1},
    {"Bar",                  BAR,       1},
    {"Restaurant",           RESTAURANT,1},
    {"Casino",               CASINO,    1},
    {"Bowling",              BOWLING,   1},
    {"Shooting Range",       SHOOTING,  1},
    {"Courses hippiques",    RACING,    1},
};

// =============================
// PERSONNALISATION PERSONNAGE
// =============================
CustomOption hair_styles[] = {
    {"Afro",          1}, {"Tresses",        1},
    {"Rasé",          1}, {"Dreadlocks",     1},
    {"Mohawk",        1}, {"Braids",         1},
    {"Buzz Cut",      1}, {"Cornrows",       1},
    {"Curly",         1}, {"Fade",           1},
    {"Locs",          1}, {"Natural",        1},
};

CustomOption beard_styles[] = {
    {"Sans barbe",    1}, {"Barbe courte",   1},
    {"Barbe longue",  1}, {"Moustache",      1},
    {"Bouc",          1}, {"Barbe pleine",   1},
    {"Sideburns",     1}, {"Stubble",        1},
};

CustomOption tattoo_styles[] = {
    {"Tribal bras",   1}, {"Dragon dos",     1},
    {"Rose epaule",   1}, {"Crane main",     1},
    {"Flammes jambe", 1}, {"Etoiles cou",    1},
    {"Lion poitrine", 1}, {"Croix bras",     1},
    {"Script visage", 1}, {"Tribal complet", 1},
};

// =============================
// VETEMENTS COMPLETS
// =============================
ClothingItem tops[] = {
    {"T-shirt blanc",     TOP, 200,   1},
    {"T-shirt noir",      TOP, 200,   1},
    {"Chemise casual",    TOP, 500,   1},
    {"Chemise luxe",      TOP, 2000,  1},
    {"Veste cuir",        TOP, 5000,  1},
    {"Veste costard",     TOP, 8000,  1},
    {"Hoodie",            TOP, 800,   1},
    {"Tank top",          TOP, 150,   1},
    {"Manteau hiver",     TOP, 3000,  1},
    {"Uniforme militaire",TOP, 0,     0},
    {"Tenue police",      TOP, 0,     0},
    {"Costume 3 pieces",  TOP, 15000, 1},
};

ClothingItem bottoms[] = {
    {"Jean bleu",         BOTTOM, 500,   1},
    {"Jean noir",         BOTTOM, 500,   1},
    {"Pantalon costard",  BOTTOM, 3000,  1},
    {"Short",             BOTTOM, 200,   1},
    {"Jogging",           BOTTOM, 300,   1},
    {"Pantalon cargo",    BOTTOM, 800,   1},
    {"Pantalon militaire",BOTTOM, 0,     0},
};

ClothingItem shoes[] = {
    {"Sneakers blancs",   SHOES, 500,   1},
    {"Sneakers Nike",     SHOES, 800,   1},
    {"Jordan",            SHOES, 2000,  1},
    {"Boots",             SHOES, 1500,  1},
    {"Chaussures luxe",   SHOES, 5000,  1},
    {"Tongs",             SHOES, 100,   1},
    {"Bottes militaires", SHOES, 0,     0},
};

ClothingItem accessories[] = {
    {"Lunettes soleil",   ACCESSORY, 300,  1},
    {"Montre luxe",       ACCESSORY, 50000,1},
    {"Chapeau",           ACCESSORY, 200,  1},
    {"Casquette",         ACCESSORY, 150,  1},
    {"Chaine or",         ACCESSORY, 10000,1},
    {"Bracelet",          ACCESSORY, 5000, 1},
    {"Bague",             ACCESSORY, 8000, 1},
    {"Masque",            ACCESSORY, 500,  1},
    {"Sac a dos",         ACCESSORY, 1000, 1},
    {"Gilet pare balles", ACCESSORY, 0,    0},
};

// =============================
// BRAQUAGES COMPLETS
// =============================
Heist heists[] = {
    {
        .name = "Braquage Banque Centrale",
        .players_needed = 4,
        .reward = 500000,
        .difficulty = HARD,
        .completed = 0,
        .setup_missions = 3
    },
    {
        .name = "Vol du Train Blinde",
        .players_needed = 2,
        .reward = 200000,
        .difficulty = MEDIUM,
        .completed = 0,
        .setup_missions = 2
    },
    {
        .name = "Cambriolage du Musee",
        .players_needed = 3,
        .reward = 300000,
        .difficulty = MEDIUM,
        .completed = 0,
        .setup_missions = 2
    },
    {
        .name = "Le Braquage du Siecle",
        .players_needed = 4,
        .reward = 2000000,
        .difficulty = VERY_HARD,
        .completed = 0,
        .setup_missions = 5
    },
    {
        .name = "Arsenal National",
        .players_needed = 4,
        .reward = 1000000,
        .difficulty = VERY_HARD,
        .completed = 0,
        .setup_missions = 4
    },
    {
        .name = "Coup d Etat",
        .players_needed = 4,
        .reward = 5000000,
        .difficulty = EXTREME,
        .completed = 0,
        .setup_missions = 6
    },
};

int total_heists = 6;
int total_extreme_sports = 12;
int total_activities = 12;

// Demarrer braquage
void start_heist(int index) {
    heists[index].completed = 0;
}

// Terminer braquage
void complete_heist(int index) {
    heists[index].completed = 1;
}

// Acheter vetement
void buy_clothing(ClothingItem* item) {
    item->is_available = 1;
}

// Changer coiffure
void change_hairstyle(int index) {
    hair_styles[index].is_unlocked = 1;
}

// Ajouter tatouage
void add_tattoo(int index) {
    tattoo_styles[index].is_unlocked = 1;
}

// Jouer activite
void play_activity(int index) {
    activities[index].is_available = 1;
}
