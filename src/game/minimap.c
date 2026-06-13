// ELYRIA STORIES - Minimap et GPS
#include "minimap.h"
GPSRoute current_route = {0};
MapMarker markers[] = {
    {"Objectif Mission",  MISSION_MARKER,  0.0f,    0.0f,    0xFF00FF00, 1},
    {"Planque",           SAFEHOUSE_MARKER,0.0f,    0.0f,    0xFF0000FF, 1},
    {"Armurerie",         WEAPON_MARKER,   500.0f,  300.0f,  0xFFFF0000, 1},
    {"Hopital",           HOSPITAL_MARKER, 300.0f,  200.0f,  0xFF00FFFF, 1},
    {"Police",            POLICE_MARKER,   100.0f,  100.0f,  0xFF0000FF, 1},
    {"Aeroport USA",      AIRPORT_MARKER,  1200.0f,-1300.0f, 0xFFFFFF00, 1},
    {"Port USA",          PORT_MARKER,     800.0f, -1200.0f, 0xFF00FFFF, 1},
    {"Frontiere",         BORDER_MARKER,   4800.0f, 0.0f,    0xFFFF8800, 1},
    {"Aeroport Elyria",   AIRPORT_MARKER,  6800.0f,-1300.0f, 0xFFFFFF00, 1},
    {"Arsenal",           MILITARY_MARKER, 7000.0f, 2000.0f, 0xFFFF0000, 1},
    {"Palais",            MISSION_MARKER,  6200.0f, 1500.0f, 0xFF8800FF, 1},
};
int total_markers = 11;
void set_gps_destination(float x, float y) {
    current_route.dest_x = x;
    current_route.dest_y = y;
    current_route.is_active = 1;
}
void clear_gps() { current_route.is_active = 0; }
void add_marker(char* name, float x, float y) { }
void remove_marker(int index) { markers[index].is_visible = 0; }
