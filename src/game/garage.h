#ifndef GARAGE_H
#define GARAGE_H
typedef struct { char name[32]; int country; float pos_x; float pos_y; int capacity; int stored_vehicles; int is_owned; } Garage;
extern Garage garages[];
extern int total_garages;
void buy_garage(int index, int price);
void store_vehicle(int garage, int vehicle);
void retrieve_vehicle(int garage, int vehicle);
void repair_in_garage(int garage);
void customize_vehicle(int garage, int vehicle);
#endif
