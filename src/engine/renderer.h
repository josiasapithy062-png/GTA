#ifndef RENDERER_H
#define RENDERER_H
#include <pspgu.h>
#include <pspgum.h>
#include <math.h>
#include "graphics.h"
#include "models.h"
#include "textures.h"
typedef struct { float x,y,z,angle_x,angle_y,fov,near,far; } Camera;
typedef struct { float player_x,player_y,player_z; int hour; } GameState;
extern Camera camera;
extern unsigned int disp_list[];
void update_camera(float px, float py, float pz, float angle);
void apply_camera();
void render_frame(GameState* state);
#endif
