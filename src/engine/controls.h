// ELYRIA STORIES - Header controles PSP
#ifndef CONTROLS_H
#define CONTROLS_H

#include <pspctrl.h>
#include "physics.h"

typedef struct {
    int cross;
    int circle;
    int square;
    int triangle;
    int l1;
    int r1;
    int start;
    int select;
    int up;
    int down;
    int left;
    int right;
    int analog_x;
    int analog_y;
} ControlState;

extern ControlState controls;

void controls_update();
void handle_on_foot_controls();
void handle_vehicle_controls();
void handle_plane_controls();
void handle_boat_controls();

#endif
