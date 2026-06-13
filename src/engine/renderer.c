// ELYRIA STORIES - Renderer simplifie
#include <pspgu.h>
#include <pspgum.h>
#include <pspdisplay.h>
#include <math.h>

float cam_x=0,cam_y=5,cam_z=-10,cam_angle=0;

void update_camera(float px,float py,float pz,float angle){
    cam_x=px-8.0f*sinf(angle);
    cam_y=py+5.0f;
    cam_z=pz-8.0f*cosf(angle);
    cam_angle=angle;
}

void apply_camera(){
    sceGumMatrixMode(GU_PROJECTION);
    sceGumLoadIdentity();
    sceGumPerspective(75.0f,16.0f/9.0f,0.1f,1000.0f);
    sceGumMatrixMode(GU_VIEW);
    sceGumLoadIdentity();
    ScePspFVector3 pos={-cam_x,-cam_y,-cam_z};
    sceGumTranslate(&pos);
    sceGumRotateY(-cam_angle);
    sceGumMatrixMode(GU_MODEL);
    sceGumLoadIdentity();
}
