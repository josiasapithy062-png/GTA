#ifndef STREETLIFE_H
#define STREETLIFE_H
typedef enum {FIGHT,ACCIDENT,ROBBERY,SHOOTING,FIRE,DEAL,PARTY,MARKET} EventType;
typedef struct {char name[32];EventType type;int country;float x,y;int is_active;} StreetEvent;
extern StreetEvent events[];
extern int total_events;
void trigger_event(int i);
void end_event(int i);
#endif
