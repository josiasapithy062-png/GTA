// ELYRIA STORIES - Header voitures classiques
#ifndef CLASSIC_CARS_H
#define CLASSIC_CARS_H

typedef enum {
    FORD,
    CHEVROLET,
    DODGE,
    PONTIAC,
    CADILLAC_C,
    BUICK,
    MERCURY,
    PLYMOUTH,
    OLDSMOBILE,
    VW,
    MERCEDES_C,
    BMW_C,
    JAGUAR,
    ASTON_C,
    ALFA,
    FIAT,
    PORSCHE_C,
    LADA,
    PEUGEOT,
    RENAULT,
    CITROEN
} ClassicBrand;

typedef struct {
    char name[32];
    ClassicBrand brand;
    float max_speed;
    float acceleration;
    float handling;
    int price;
    int is_owned;
    int condition;
} ClassicCar;

extern ClassicCar classic_cars[];
extern int total_classic_cars;

int buy_classic_car(int index);
void restore_classic_car(int index);
void store_classic_in_garage(int index);

#endif
