#ifndef MINIMAP_H
#define MINIMAP_H
typedef enum { MISSION_MARKER, SAFEHOUSE_MARKER, WEAPON_MARKER, HOSPITAL_MARKER, POLICE_MARKER, AIRPORT_MARKER, PORT_MARKER, BORDER_MARKER, MILITARY_MARKER } MarkerType;
typedef struct { char name[32]; MarkerType type; float x; float y; unsigned int color; int is_visible; } MapMarker;
typedef struct { float dest_x; float dest_y; int is_active; } GPSRoute;
extern MapMarker markers[];
extern GPSRoute current_route;
extern int total_markers;
void set_gps_destination(float x, float y);
void clear_gps();
void add_marker(char* name, float x, float y);
void remove_marker(int index);
#endif
