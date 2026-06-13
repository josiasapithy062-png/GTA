#ifndef STREETLIFE_H
#define STREETLIFE_H
typedef enum { FIGHT,ACCIDENT,ROBBERY,PROTEST,MARKET,RACE,SHOOTING,ARREST,PARTY,FIRE,DEAL,ESCORT,MUSIC,SPORT,BURGLARY } EventType;
typedef struct { char name[32]; EventType type; int country; float x,y; int is_active; } StreetEvent;
extern StreetEvent events[];
extern int total_events;
void trigger_event(int index);
void end_event(int index);
void intervene_event(int index);
#endif
