// ELYRIA STORIES - 70 Missions completes

#include "missions.h"

Mission missions[70] = {

// =============================
// MISSIONS SOLO - 20 missions
// =============================

// JOSIAS SOLO (6)
{1,  "Bienvenue a Elyria",        "Josias", SOLO,  ELYRIA, 1000,   0, "Decouvre Elyria City"},
{2,  "Premiere voiture",          "Josias", SOLO,  ELYRIA, 2000,   0, "Vole ta premiere voiture"},
{3,  "Le coiffeur",               "Josias", SOLO,  ELYRIA, 500,    0, "Change de look"},
{4,  "Nouvelle fringue",          "Josias", SOLO,  ELYRIA, 1500,   0, "Achete des vetements"},
{5,  "Premier garage",            "Josias", SOLO,  ELYRIA, 5000,   0, "Achete ton premier garage"},
{6,  "Regle de compte",           "Josias", SOLO,  ELYRIA, 8000,   0, "Elimine un ennemi solo"},

// FRANCK SOLO (5)
{7,  "Course de rue",             "Franck", SOLO,  USA,    3000,   0, "Gagne une course illegale"},
{8,  "Livraison express",         "Franck", SOLO,  USA,    4000,   0, "Livre un colis suspect"},
{9,  "Vol de voiture de luxe",    "Franck", SOLO,  USA,    6000,   0, "Vole une voiture de luxe"},
{10, "Fuite de la police",        "Franck", SOLO,  USA,    5000,   0, "Echappe a 3 etoiles"},
{11, "Infiltration",              "Franck", SOLO,  USA,    7000,   0, "Entre dans une base secrete"},

// MIKAEL SOLO (5)
{12, "Achat de propriete",        "Mikael", SOLO,  USA,    10000,  0, "Achete ta premiere planque"},
{13, "Negociation tendue",        "Mikael", SOLO,  ELYRIA, 8000,   0, "Negocie avec un chef de gang"},
{14, "Escorte VIP",               "Mikael", SOLO,  ELYRIA, 9000,   0, "Protege un politicien"},
{15, "Sabotage",                  "Mikael", SOLO,  USA,    11000,  0, "Sabote une usine ennemie"},
{16, "L informateur",             "Mikael", SOLO,  USA,    7500,   0, "Trouve un informateur"},

// TREV SOLO (4)
{17, "Explosion controlee",       "Trev",   SOLO,  ELYRIA, 12000,  0, "Fais exploser un batiment"},
{18, "Attaque de convoi",         "Trev",   SOLO,  ELYRIA, 15000,  0, "Attaque un convoi militaire"},
{19, "Le sniper",                 "Trev",   SOLO,  USA,    13000,  0, "Elimine une cible a distance"},
{20, "Chaos total",               "Trev",   SOLO,  ELYRIA, 20000,  0, "Cree le chaos dans la ville"},

// =============================
// MISSIONS GROUPE - 50 missions
// =============================

// JOSIAS GROUPE (15)
{21, "Premier braquage",          "Josias", GROUP, ELYRIA, 25000,  0, "Braquer une petite banque"},
{22, "Le coup d Etat - Partie 1", "Josias", GROUP, ELYRIA, 30000,  0, "Recrute des allies politiques"},
{23, "Le coup d Etat - Partie 2", "Josias", GROUP, ELYRIA, 40000,  0, "Prends le controle des medias"},
{24, "Le coup d Etat - Partie 3", "Josias", GROUP, ELYRIA, 50000,  0, "Neutralise le gouvernement"},
{25, "Le coup d Etat - Final",    "Josias", GROUP, ELYRIA, 100000, 0, "Installe notre homme au pouvoir"},
{26, "Prise d otages",            "Josias", GROUP, ELYRIA, 35000,  0, "Prends en otage un ministre"},
{27, "Attaque de la prison",      "Josias", GROUP, ELYRIA, 45000,  0, "Libere un prisonnier important"},
{28, "Guerre de gangs",           "Josias", GROUP, ELYRIA, 28000,  0, "Elimine le gang adverse"},
{29, "Trafic d armes",            "Josias", GROUP, ELYRIA, 55000,  0, "Livre des armes aux allies"},
{30, "Blanchiment",               "Josias", GROUP, ELYRIA, 60000,  0, "Blanchis l argent du gang"},
{31, "Double trahison",           "Josias", GROUP, ELYRIA, 70000,  0, "Elimine le traitre"},
{32, "Siege de la banque",        "Josias", GROUP, USA,    80000,  0, "Siege de 3 heures a la banque"},
{33, "Evacuation d urgence",      "Josias", GROUP, ELYRIA, 40000,  0, "Evacue le groupe sous les balles"},
{34, "Mission diplomatique",      "Josias", GROUP, ELYRIA, 35000,  0, "Negocie un accord secret"},
{35, "La grande evasion",         "Josias", GROUP, USA,    90000,  0, "Evade toute l equipe de prison"},

// FRANCK GROUPE (10)
{36, "Course poursuite",          "Franck", GROUP, USA,    20000,  0, "Echappe a la police en groupe"},
{37, "Vol de camion blinde",      "Franck", GROUP, USA,    35000,  0, "Vole un camion blinde"},
{38, "Frontiere clandestine",     "Franck", GROUP, USA,    40000,  0, "Passe la frontiere illegalement"},
{39, "Livraison de drogue",       "Franck", GROUP, USA,    30000,  0, "Livre une cargaison dangereuse"},
{40, "Attaque du port",           "Franck", GROUP, USA,    45000,  0, "Prends le controle du port"},
{41, "Guerre de territoire",      "Franck", GROUP, USA,    38000,  0, "Conquiert un nouveau territoire"},
{42, "Vol d helicoptere",         "Franck", GROUP, USA,    42000,  0, "Vole un helicoptere militaire"},
{43, "Escorte de drogue",         "Franck", GROUP, ELYRIA, 50000,  0, "Escorte un chargement precieux"},
{44, "Embuscade",                 "Franck", GROUP, USA,    33000,  0, "Tends une embuscade au convoi"},
{45, "Prise de controle",         "Franck", GROUP, USA,    60000,  0, "Prends le controle du marche noir"},

// MIKAEL GROUPE (10)
{46, "Le Grand Braquage - Prep",  "Mikael", GROUP, USA,    15000,  0, "Prepare le braquage du siecle"},
{47, "Le Grand Braquage - Recup", "Mikael", GROUP, USA,    20000,  0, "Recupere le materiel necessaire"},
{48, "Le Braquage du Siecle",     "Mikael", GROUP, USA,    200000, 0, "Execute le plus grand braquage"},
{49, "Achat de l arsenal",        "Mikael", GROUP, ELYRIA, 80000,  0, "Achete des armes lourdes"},
{50, "Corruption",                "Mikael", GROUP, ELYRIA, 70000,  0, "Corromps des officiels"},
{51, "Fuite internationale",      "Mikael", GROUP, USA,    90000,  0, "Fuis vers Elyria avec le butin"},
{52, "Negociation armees",        "Mikael", GROUP, ELYRIA, 65000,  0, "Negocie sous la menace"},
{53, "Infiltration gouvernement", "Mikael", GROUP, ELYRIA, 75000,  0, "Place un espion au gouvernement"},
{54, "Liquidation de temoins",    "Mikael", GROUP, USA,    55000,  0, "Elimine les temoins dangereux"},
{55, "Le dernier contrat",        "Mikael", GROUP, USA,    150000, 0, "Dernier contrat avant la retraite"},

// TREV GROUPE (15)
{56, "Assaut de l arsenal",       "Trev",   GROUP, ELYRIA, 80000,  0, "Assaut sur l arsenal national"},
{57, "Vol de minigun",            "Trev",   GROUP, ELYRIA, 90000,  0, "Vole les miniguns de l arsenal"},
{58, "Destruction de base",       "Trev",   GROUP, ELYRIA, 100000, 0, "Detruit une base militaire"},
{59, "Attentat rate",             "Trev",   GROUP, USA,    70000,  0, "Sabote un attentat ennemi"},
{60, "Guerre totale",             "Trev",   GROUP, ELYRIA, 85000,  0, "Declare la guerre a l armee"},
{61, "Prise de l aeroport",       "Trev",   GROUP, USA,    95000,  0, "Prends le controle de l aeroport"},
{62, "Destruction du pont",       "Trev",   GROUP, ELYRIA, 110000, 0, "Detruit le pont frontiere"},
{63, "Assaut naval",              "Trev",   GROUP, USA,    88000,  0, "Attaque depuis la mer"},
{64, "Vol de tank",               "Trev",   GROUP, ELYRIA, 120000, 0, "Vole un tank de l armee"},
{65, "Bombardement",              "Trev",   GROUP, ELYRIA, 130000, 0, "Bombarde un quartier ennemi"},
{66, "Siege du palais",           "Trev",   GROUP, ELYRIA, 140000, 0, "Assieges le palais presidentiel"},
{67, "Derniere bataille",         "Trev",   GROUP, ELYRIA, 160000, 0, "Bataille finale pour Elyria"},
{68, "Mission suicide",           "Trev",   GROUP, USA,    175000, 0, "Mission extreme haute risque"},
{69, "Liberation d Elyria",       "Trev",   GROUP, ELYRIA, 190000, 0, "Libere Elyria du gouvernement"},
{70, "Le Nouveau Pouvoir",        "Josias", GROUP, ELYRIA, 250000, 0, "Instaure le nouveau gouvernement"},

};

int total_missions = 70;
int current_mission = -1;

void start_mission(int id) {
    current_mission = id;
}

void complete_mission(int id) {
    missions[id-1].completed = 1;
    current_mission = -1;
}

int get_mission_reward(int id) {
    return missions[id-1].reward;
}
