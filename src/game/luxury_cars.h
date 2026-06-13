#ifndef LUXURY_CARS_H
#define LUXURY_CARS_H
typedef enum {
    LAMBORGHINI, FERRARI, BUGATTI, ROLLS_ROYCE,
    BENTLEY, MERCEDES, BMW, PORSCHE, ASTON_MARTIN,
    MCLAREN, MASERATI, KOENIGSEGG, PAGANI, TESLA, CADILLAC
} LuxuryBrand;
typedef struct {
    char name[32];
    LuxuryBrand brand;
    float max_speed;
    float acceleration;
    float handling;
    int price;
    int is_owned;
} LuxuryCar;
extern LuxuryCar luxury_cars[];
extern int total_luxury_cars;
int buy_luxury_car(int index);
void steal_luxury_car(int index);
void store_in_garage(int car_index);
#endif
