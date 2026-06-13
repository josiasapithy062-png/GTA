// ELYRIA STORIES - Voitures classiques et anciennes

#include "classic_cars.h"

ClassicCar classic_cars[] = {

    // FORD CLASSIQUES
    {"Ford Mustang 1965",      FORD,       200.0f, 10.0f, 5.0f, 150000,  0},
    {"Ford Mustang 1969",      FORD,       210.0f, 10.5f, 4.8f, 180000,  0},
    {"Ford Thunderbird 1955",  FORD,       180.0f, 9.0f,  5.5f, 120000,  0},
    {"Ford Falcon 1963",       FORD,       170.0f, 8.5f,  6.0f, 100000,  0},
    {"Ford Model T 1920",      FORD,       60.0f,  3.0f,  8.0f, 80000,   0},
    {"Ford Fairlane 1966",     FORD,       190.0f, 9.5f,  5.2f, 130000,  0},
    {"Ford GT40 1968",         FORD,       330.0f, 14.0f, 3.5f, 500000,  0},

    // CHEVROLET CLASSIQUES
    {"Chevrolet Camaro 1969",  CHEVROLET,  220.0f, 11.0f, 4.5f, 200000,  0},
    {"Chevrolet Corvette 1963",CHEVROLET,  230.0f, 11.5f, 4.2f, 250000,  0},
    {"Chevrolet Impala 1967",  CHEVROLET,  180.0f, 9.0f,  5.5f, 150000,  0},
    {"Chevrolet Bel Air 1957", CHEVROLET,  160.0f, 8.0f,  6.0f, 120000,  0},
    {"Chevrolet Nova 1970",    CHEVROLET,  200.0f, 10.0f, 5.0f, 140000,  0},
    {"Chevrolet El Camino",    CHEVROLET,  190.0f, 9.5f,  5.2f, 130000,  0},

    // DODGE CLASSIQUES
    {"Dodge Charger 1969",     DODGE,      240.0f, 12.0f, 4.0f, 300000,  0},
    {"Dodge Challenger 1970",  DODGE,      230.0f, 11.5f, 4.2f, 280000,  0},
    {"Dodge Viper 1992",       DODGE,      290.0f, 13.0f, 3.8f, 400000,  0},
    {"Dodge Coronet 1968",     DODGE,      200.0f, 10.0f, 5.0f, 160000,  0},
    {"Dodge Dart 1968",        DODGE,      180.0f, 9.0f,  5.5f, 130000,  0},

    // PONTIAC CLASSIQUES
    {"Pontiac GTO 1969",       PONTIAC,    220.0f, 11.0f, 4.5f, 220000,  0},
    {"Pontiac Firebird 1977",  PONTIAC,    210.0f, 10.5f, 4.8f, 200000,  0},
    {"Pontiac Trans Am 1979",  PONTIAC,    215.0f, 10.8f, 4.6f, 210000,  0},
    {"Pontiac Bonneville 1962",PONTIAC,    170.0f, 8.5f,  6.0f, 120000,  0},

    // CADILLAC CLASSIQUES
    {"Cadillac DeVille 1959",  CADILLAC_C, 160.0f, 7.0f,  6.5f, 200000,  0},
    {"Cadillac Eldorado 1967", CADILLAC_C, 170.0f, 7.5f,  6.2f, 220000,  0},
    {"Cadillac Fleetwood 1970",CADILLAC_C, 165.0f, 7.2f,  6.4f, 210000,  0},

    // BUICK CLASSIQUES
    {"Buick Riviera 1963",     BUICK,      175.0f, 8.5f,  5.8f, 130000,  0},
    {"Buick Skylark 1964",     BUICK,      170.0f, 8.0f,  6.0f, 120000,  0},
    {"Buick GSX 1970",         BUICK,      210.0f, 10.5f, 4.8f, 180000,  0},

    // MERCURY CLASSIQUES
    {"Mercury Cougar 1968",    MERCURY,    190.0f, 9.5f,  5.2f, 140000,  0},
    {"Mercury Montego 1970",   MERCURY,    180.0f, 9.0f,  5.5f, 130000,  0},

    // PLYMOUTH CLASSIQUES
    {"Plymouth Barracuda 1970",PLYMOUTH,   220.0f, 11.0f, 4.5f, 250000,  0},
    {"Plymouth Road Runner",   PLYMOUTH,   230.0f, 11.5f, 4.2f, 260000,  0},
    {"Plymouth Superbird 1970",PLYMOUTH,   240.0f, 12.0f, 4.0f, 300000,  0},

    // OLDSMOBILE CLASSIQUES
    {"Oldsmobile 442 1970",    OLDSMOBILE, 215.0f, 10.8f, 4.6f, 200000,  0},
    {"Oldsmobile Cutlass 1972",OLDSMOBILE, 190.0f, 9.5f,  5.2f, 150000,  0},

    // VOLKSWAGEN CLASSIQUES
    {"VW Beetle 1967",         VW,         130.0f, 6.0f,  7.0f, 80000,   0},
    {"VW Bus 1972",            VW,         120.0f, 5.5f,  7.5f, 90000,   0},
    {"VW Karmann Ghia 1970",   VW,         150.0f, 7.0f,  6.5f, 100000,  0},

    // MERCEDES CLASSIQUES
    {"Mercedes 300SL 1955",    MERCEDES_C, 260.0f, 12.0f, 4.0f, 800000,  0},
    {"Mercedes 190E 1984",     MERCEDES_C, 200.0f, 9.0f,  5.5f, 200000,  0},
    {"Mercedes W123 1976",     MERCEDES_C, 170.0f, 7.5f,  6.2f, 150000,  0},

    // BMW CLASSIQUES
    {"BMW 2002 1968",          BMW_C,      170.0f, 8.0f,  6.0f, 120000,  0},
    {"BMW M1 1978",            BMW_C,      260.0f, 12.0f, 4.0f, 400000,  0},
    {"BMW 507 1957",           BMW_C,      220.0f, 10.5f, 4.5f, 300000,  0},

    // JAGUAR CLASSIQUES
    {"Jaguar E-Type 1961",     JAGUAR,     240.0f, 11.5f, 4.2f, 350000,  0},
    {"Jaguar XK120 1949",      JAGUAR,     200.0f, 9.5f,  5.0f, 280000,  0},
    {"Jaguar Mark 2 1959",     JAGUAR,     180.0f, 8.5f,  5.5f, 200000,  0},

    // ASTON MARTIN CLASSIQUES
    {"Aston Martin DB5 1964",  ASTON_C,    230.0f, 11.0f, 4.5f, 500000,  0},
    {"Aston Martin DB4 1958",  ASTON_C,    220.0f, 10.5f, 4.8f, 450000,  0},

    // ALFA ROMEO CLASSIQUES
    {"Alfa Romeo Spider 1966", ALFA,       190.0f, 9.5f,  5.2f, 150000,  0},
    {"Alfa Romeo GTV 1974",    ALFA,       195.0f, 9.8f,  5.0f, 160000,  0},

    // FIAT CLASSIQUES
    {"Fiat 500 1957",          FIAT,       100.0f, 5.0f,  7.5f, 60000,   0},
    {"Fiat 124 Spider 1966",   FIAT,       160.0f, 8.0f,  6.0f, 100000,  0},

    // PORSCHE CLASSIQUES
    {"Porsche 356 1954",       PORSCHE_C,  180.0f, 9.0f,  5.5f, 300000,  0},
    {"Porsche 911 1973",       PORSCHE_C,  220.0f, 11.0f, 4.5f, 400000,  0},
    {"Porsche 914 1969",       PORSCHE_C,  190.0f, 9.5f,  5.2f, 250000,  0},

    // VOITURES SOVIETIQUES
    {"Lada 2101 1970",         LADA,       130.0f, 6.0f,  7.0f, 30000,   0},
    {"Lada Niva 1977",         LADA,       120.0f, 5.5f,  7.5f, 40000,   0},
    {"Volga GAZ 1956",         LADA,       140.0f, 6.5f,  7.2f, 50000,   0},

    // VOITURES AFRICAINES ET EXOTIQUES
    {"Peugeot 504 1968",       PEUGEOT,    150.0f, 7.0f,  6.5f, 50000,   0},
    {"Peugeot 403 1955",       PEUGEOT,    130.0f, 6.0f,  7.0f, 40000,   0},
    {"Renault 4L 1961",        RENAULT,    100.0f, 4.5f,  8.0f, 30000,   0},
    {"Citroen DS 1955",        CITROEN,    160.0f, 7.5f,  6.2f, 80000,   0},
    {"Citroen 2CV 1948",       CITROEN,    80.0f,  3.5f,  8.5f, 25000,   0},
};

int total_classic_cars = 65;

// Acheter voiture classique
int buy_classic_car(int index) {
    classic_cars[index].is_owned = 1;
    return 1;
}

// Restaurer voiture classique
void restore_classic_car(int index) {
    classic_cars[index].condition = 100;
}

// Stocker dans garage
void store_classic_in_garage(int index) {
    classic_cars[index].is_owned = 1;
}
