#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspctrl.h>
#include <math.h>
PSP_MODULE_INFO("ELYRIA STORIES", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);
static unsigned int __attribute__((aligned(16))) list[262144];
typedef struct { float x,y,z; unsigned int color; } Vertex;
static Vertex __attribute__((aligned(16))) ground[4] = {
    {-100,0,-100, 0xFF228B22},
    {100, 0,-100, 0xFF228B22},
    {-100,0, 100, 0xFF228B22},
    {100, 0, 100, 0xFF228B22},
};
float px=0,py=0,pz=0,angle=0;
static int exitCB(int a,int b,void*c){sceKernelExitGame();return 0;}
static int cbThread(SceSize a,void*b){
    int id=sceKernelCreateCallback("Exit",exitCB,NULL);
    sceKernelRegisterExitCallback(id);
    sceKernelSleepThreadCB();return 0;
}
int main(void){
    int thid=sceKernelCreateThread("cb",cbThread,0x11,0xFA0,0,0);
    if(thid>=0)sceKernelStartThread(thid,0,0);
    sceCtrlSetSamplingCycle(0);
    sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);
    sceGuInit();
    sceGuStart(GU_DIRECT,list);
    sceGuDrawBuffer(GU_PSM_8888,(void*)0,512);
    sceGuDispBuffer(480,272,(void*)0x88000,512);
    sceGuDepthBuffer((void*)0x110000,512);
    sceGuOffset(2048-240,2048-136);
    sceGuViewport(2048,2048,480,272);
    sceGuDepthRange(65535,0);
    sceGuScissor(0,0,480,272);
    sceGuEnable(GU_SCISSOR_TEST);
    sceGuEnable(GU_DEPTH_TEST);
    sceGuFinish();sceGuSync(0,0);
    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
    while(1){
        SceCtrlData pad;
        sceCtrlReadBufferPositive(&pad,1);
        int ax=pad.Lx-128,ay=pad.Ly-128;
        if(ax<-20)angle-=0.05f;
        if(ax>20)angle+=0.05f;
        float spd=0.2f;
        if(ay<-20){px+=spd*sinf(angle);pz+=spd*cosf(angle);}
        if(ay>20){px-=spd*sinf(angle);pz-=spd*cosf(angle);}
        sceGuStart(GU_DIRECT,list);
        sceGuClearColor(0xFF87CEEB);
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);
        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(75.0f,16.0f/9.0f,0.1f,500.0f);
        sceGumMatrixMode(GU_VIEW);
        sceGumLoadIdentity();
        ScePspFVector3 cam={-(px-8*sinf(angle)),-5,-(pz-8*cosf(angle))};
        sceGumTranslate(&cam);
        sceGumRotateY(-angle);
        sceGumMatrixMode(GU_MODEL);
        sceGumLoadIdentity();
        sceGuDisable(GU_TEXTURE_2D);
        sceGumDrawArray(GU_TRIANGLE_STRIP,
            GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,
            4,0,ground);
        sceGuFinish();sceGuSync(0,0);
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
    }
    sceGuTerm();return 0;
}
