#ifndef WANTED_H
#define WANTED_H
typedef enum { COP_FOOT, COP_CAR, COP_MOTO, SWAT, COP_HELI, FBI, FBI_CAR, ARMY, ARMY_TANK, ARMY_PLANE } UnitType;
typedef struct { UnitType type; int min_stars; int health; int is_deployed; } PoliceUnit;
typedef struct { int level; int is_being_chased; int bribe_cost; } WantedSystem;
extern WantedSystem wanted;
extern PoliceUnit units[];
extern int total_units;
void update_wanted(int stars);
void escape_wanted();
void bribe_police();
void call_lawyer();
#endif
