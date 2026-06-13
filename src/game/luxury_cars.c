// ELYRIA STORIES - Toutes les voitures de luxe

#include "luxury_cars.h"

LuxuryCar luxury_cars[] = {

    // LAMBORGHINI
    {"Lamborghini Aventador",  LAMBORGHINI, 350.0f, 15.0f, 3.5f, 5000000, 0},
    {"Lamborghini Huracan",    LAMBORGHINI, 330.0f, 14.0f, 4.0f, 4000000, 0},
    {"Lamborghini Urus",       LAMBORGHINI, 280.0f, 12.0f, 5.0f, 3000000, 0},
    {"Lamborghini Murcielago", LAMBORGHINI, 340.0f, 14.5f, 3.8f, 4500000, 0},
    {"Lamborghini Gallardo",   LAMBORGHINI, 320.0f, 13.5f, 4.2f, 3500000, 0},

    // FERRARI
    {"Ferrari SF90",           FERRARI,     340.0f, 14.0f, 3.8f, 4500000, 0},
    {"Ferrari 488",            FERRARI,     330.0f, 13.5f, 4.0f, 3800000, 0},
    {"Ferrari Roma",           FERRARI,     310.0f, 13.0f, 4.5f, 3000000, 0},
    {"Ferrari Portofino",      FERRARI,     300.0f, 12.5f, 5.0f, 2500000, 0},
    {"Ferrari F40",            FERRARI,     320.0f, 13.8f, 3.9f, 4000000, 0},
    {"Ferrari LaFerrari",      FERRARI,     350.0f, 15.0f, 3.5f, 5500000, 0},

    // BUGATTI
    {"Bugatti Chiron",         BUGATTI,     420.0f, 18.0f, 3.0f, 8000000, 0},
    {"Bugatti Veyron",         BUGATTI,     400.0f, 17.0f, 3.2f, 7000000, 0},
    {"Bugatti Divo",           BUGATTI,     380.0f, 16.0f, 3.4f, 7500000, 0},
    {"Bugatti Bolide",         BUGATTI,     500.0f, 20.0f, 2.5f, 9000000, 0},

    // ROLLS ROYCE
    {"Rolls Royce Phantom",    ROLLS_ROYCE, 250.0f, 8.0f,  6.0f, 6000000, 0},
    {"Rolls Royce Ghost",      ROLLS_ROYCE, 240.0f, 7.5f,  6.5f, 5000000, 0},
    {"Rolls Royce Cullinan",   ROLLS_ROYCE, 230.0f, 7.0f,  7.0f, 4500000, 0},
    {"Rolls Royce Wraith",     ROLLS_ROYCE, 260.0f, 8.5f,  5.5f, 5500000, 0},
    {"Rolls Royce Dawn",       ROLLS_ROYCE, 250.0f, 8.0f,  6.0f, 5200000, 0},

    // BENTLEY
    {"Bentley Continental GT", BENTLEY,     330.0f, 12.0f, 4.5f, 3500000, 0},
    {"Bentley Mulsanne",       BENTLEY,     270.0f, 9.0f,  6.0f, 4000000, 0},
    {"Bentley Bentayga",       BENTLEY,     290.0f, 10.0f, 5.5f, 3000000, 0},
    {"Bentley Flying Spur",    BENTLEY,     320.0f, 11.0f, 5.0f, 3800000, 0},

    // MERCEDES
    {"Mercedes AMG GT",        MERCEDES,    320.0f, 13.0f, 4.0f, 2000000, 0},
    {"Mercedes S Class",       MERCEDES,    250.0f, 9.0f,  6.0f, 1500000, 0},
    {"Mercedes G Wagon",       MERCEDES,    220.0f, 8.0f,  7.0f, 1800000, 0},
    {"Mercedes Maybach",       MERCEDES,    260.0f, 9.5f,  5.5f, 2500000, 0},
    {"Mercedes SLS AMG",       MERCEDES,    310.0f, 12.5f, 4.2f, 2200000, 0},

    // BMW
    {"BMW M8",                 BMW,         310.0f, 12.0f, 4.5f, 1500000, 0},
    {"BMW M5",                 BMW,         305.0f, 11.5f, 4.8f, 1200000, 0},
    {"BMW 7 Series",           BMW,         250.0f, 9.0f,  6.0f, 1000000, 0},
    {"BMW i8",                 BMW,         280.0f, 11.0f, 5.0f, 1300000, 0},
    {"BMW X7",                 BMW,         240.0f, 8.5f,  6.5f, 900000,  0},

    // PORSCHE
    {"Porsche 911 GT3",        PORSCHE,     320.0f, 13.0f, 3.8f, 2500000, 0},
    {"Porsche Cayenne",        PORSCHE,     270.0f, 10.0f, 5.5f, 1500000, 0},
    {"Porsche Panamera",       PORSCHE,     290.0f, 11.0f, 5.0f, 1800000, 0},
    {"Porsche Taycan",         PORSCHE,     260.0f, 12.0f, 4.5f, 2000000, 0},
    {"Porsche Boxster",        PORSCHE,     280.0f, 11.5f, 4.2f, 1600000, 0},

    // ASTON MARTIN
    {"Aston Martin DB11",      ASTON_MARTIN,300.0f, 12.0f, 4.0f, 3000000, 0},
    {"Aston Martin Vantage",   ASTON_MARTIN,315.0f, 13.0f, 3.8f, 2800000, 0},
    {"Aston Martin DBS",       ASTON_MARTIN,340.0f, 14.0f, 3.5f, 3500000, 0},
    {"Aston Martin Valkyrie",  ASTON_MARTIN,400.0f, 17.0f, 3.0f, 6000000, 0},

    // MCLAREN
    {"McLaren 720S",           MCLAREN,     341.0f, 14.5f, 3.6f, 4000000, 0},
    {"McLaren P1",             MCLAREN,     350.0f, 15.0f, 3.4f, 5000000, 0},
    {"McLaren Senna",          MCLAREN,     340.0f, 14.8f, 3.5f, 4500000, 0},
    {"McLaren Artura",         MCLAREN,     330.0f, 14.0f, 3.7f, 3500000, 0},

    // MASERATI
    {"Maserati GranTurismo",   MASERATI,    300.0f, 11.0f, 4.5f, 2000000, 0},
    {"Maserati Quattroporte",  MASERATI,    270.0f, 10.0f, 5.5f, 1800000, 0},
    {"Maserati Levante",       MASERATI,    265.0f, 9.5f,  6.0f, 1500000, 0},

    // KOENIGSEGG
    {"Koenigsegg Agera",       KOENIGSEGG,  440.0f, 19.0f, 2.8f, 9500000, 0},
    {"Koenigsegg Jesko",       KOENIGSEGG,  480.0f, 20.0f, 2.5f, 10000000,0},
    {"Koenigsegg Regera",      KOENIGSEGG,  410.0f, 18.0f, 3.0f, 8500000, 0},

    // PAGANI
    {"Pagani Zonda",           PAGANI,      380.0f, 16.0f, 3.2f, 7000000, 0},
    {"Pagani Huayra",          PAGANI,      390.0f, 17.0f, 3.0f, 8000000, 0},

    // TESLA
    {"Tesla Model S Plaid",    TESLA,       320.0f, 16.0f, 4.0f, 500000,  0},
    {"Tesla Roadster",         TESLA,       400.0f, 18.0f, 3.5f, 800000,  0},

    // CADILLAC
    {"Cadillac Escalade",      CADILLAC,    230.0f, 8.0f,  7.0f, 600000,  0},
    {"Cadillac CT5",           CADILLAC,    260.0f, 10.0f, 5.5f, 500000,  0},
};

int total_luxury_cars = 62;

// Acheter voiture de luxe
int buy_luxury_car(int index) {
    return 1;
}

// Voler voiture de luxe
void steal_luxury_car(int index) {
    luxury_cars[index].is_owned = 1;
}

// Stocker dans garage
void store_in_garage(int car_index) {
    luxury_cars[car_index].is_owned = 1;
}
