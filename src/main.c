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

// Couleurs personnages
#define JOSIAS_COLOR  0xFF0000FF
#define FRANCK_COLOR  0xFF00FF00
#define MIKAEL_COLOR  0xFFFFFF00
#define TREV_COLOR    0xFFFF0000

// Etat du jeu
int current_char = 0; // 0=Josias 1=Franck 2=Mikael 3=Trev
int health = 100;
int armor = 50;
int money = 5000;
int wanted = 0;
int current_mission = 0;
int mission_complete = 0;
int in_vehicle = 0;
int current_country = 0; // 0=USA 1=ELYRIA
float px=0,py=0,pz=0,angle=0;
float vx=0,vz=0; // vitesse vehicule

// Personnages
char* char_names[] = {"JOSIAS","FRANCK","MIKAEL","TREV"};
unsigned int char_colors[] = {
    JOSIAS_COLOR, FRANCK_COLOR,
    MIKAEL_COLOR, TREV_COLOR
};

// Missions
char* missions[] = {
    "1. Bienvenue a Elyria",
    "2. Premier braquage",
    "3. Frontiere dangereuse",
    "4. L Arsenal National",
    "5. Le Coup d Etat",
    "6. Braquage du Siecle",
};
int mission_rewards[] = {1000,25000,10000,50000,100000,200000};

// Vertices
static Vertex __attribute__((aligned(16))) ground[4] = {
    {-1000,0,-1000,0xFF228B22},{1000,0,-1000,0xFF228B22},
    {-1000,0,1000,0xFF228B22},{1000,0,1000,0xFF228B22},
};
static Vertex __attribute__((aligned(16))) road[4] = {
    {-8,0.1f,-1000,0xFF333333},{8,0.1f,-1000,0xFF333333},
    {-8,0.1f,1000,0xFF333333},{8,0.1f,1000,0xFF333333},
};
static Vertex __attribute__((aligned(16))) pv[4] = {
    {-1,0,-1,0xFF000000},{1,0,-1,0xFF000000},
    {-1,2,-1,0xFF000000},{1,2,-1,0xFF000000},
};
static Vertex __attribute__((aligned(16))) bv[4] = {
    {-5,0,-3,0xFF888888},{5,0,-3,0xFF888888},
    {-5,10,-3,0xFF666666},{5,10,-3,0xFF666666},
};
static Vertex __attribute__((aligned(16))) car_v[4] = {
    {-2,0,-1,0xFFFF4400},{2,0,-1,0xFFFF4400},
    {-2,1.5f,-1,0xFFCC3300},{2,1.5f,-1,0xFFCC3300},
};

static int exitCB(int a,int b,void*c){sceKernelExitGame();return 0;}
static int cbThread(SceSize a,void*b){
    int id=sceKernelCreateCallback("Exit",exitCB,NULL);
    sceKernelRegisterExitCallback(id);
    sceKernelSleepThreadCB();return 0;
}

void draw_quad(Vertex* v, float x, float y, float z) {
    sceGumPushMatrix();
    ScePspFVector3 pos={x,y,z};
    sceGumTranslate(&pos);
    sceGuDisable(GU_TEXTURE_2D);
    sceGumDrawArray(GU_TRIANGLE_STRIP,
        GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,
        4,0,v);
    sceGumPopMatrix();
}

int prev_buttons = 0;

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
        int btn = pad.Buttons;
        int new_btn = btn & ~prev_buttons;

        // Joystick - mouvement
        int ax=pad.Lx-128, ay=pad.Ly-128;
        if(ax<-20) angle-=0.05f;
        if(ax>20)  angle+=0.05f;

        float spd = (btn&PSP_CTRL_RTRIGGER)?0.5f:0.2f;
        if(!in_vehicle) {
            if(ay<-20){px+=spd*sinf(angle);pz+=spd*cosf(angle);}
            if(ay>20) {px-=spd*sinf(angle);pz-=spd*cosf(angle);}
        } else {
            // Conduite vehicule
            if(btn&PSP_CTRL_CROSS){
                vx+=0.1f*sinf(angle);
                vz+=0.1f*cosf(angle);
            }
            if(btn&PSP_CTRL_SQUARE){
                vx*=0.9f; vz*=0.9f;
            }
            px+=vx; pz+=vz;
            vx*=0.98f; vz*=0.98f;
        }

        // Sauter (Croix a pied)
        if(!in_vehicle && (new_btn&PSP_CTRL_CROSS)) py=3.0f;
        if(py>0) py-=0.15f; else py=0;

        // Rond = entrer/sortir vehicule
        if(new_btn&PSP_CTRL_CIRCLE) {
            in_vehicle = !in_vehicle;
            if(in_vehicle) { vx=0; vz=0; }
        }

        // L1 = changer personnage
        if(new_btn&PSP_CTRL_LTRIGGER) {
            current_char=(current_char+1)%4;
        }

        // Triangle = accepter mission
        if(new_btn&PSP_CTRL_TRIANGLE) {
            if(!mission_complete) {
                money += mission_rewards[current_mission];
                mission_complete = 1;
            } else {
                current_mission=(current_mission+1)%6;
                mission_complete = 0;
            }
        }

        // Haut/Bas = wanted
        if(new_btn&PSP_CTRL_UP) if(wanted<5) wanted++;
        if(new_btn&PSP_CTRL_DOWN) if(wanted>0) wanted--;

        // Droite = changer pays
        if(new_btn&PSP_CTRL_RIGHT) {
            current_country = !current_country;
            px=current_country?500:0;
        }

        // Sante
        if(wanted>0 && health>0) health--;
        if(health<=0){health=100;money-=500;}

        prev_buttons = btn;

        // Couleur ciel selon pays
        unsigned int sky = current_country ? 0xFFE8B4A0 : 0xFF87CEEB;

        // RENDU
        sceGuStart(GU_DIRECT,list);
        sceGuClearColor(sky);
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);

        // Camera
        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(75.0f,16.0f/9.0f,0.1f,500.0f);
        sceGumMatrixMode(GU_VIEW);
        sceGumLoadIdentity();
        ScePspFVector3 cam={
            -(px-8*sinf(angle)),
            -(py+5),
            -(pz-8*cosf(angle))
        };
        sceGumTranslate(&cam);
        sceGumRotateY(-angle);
        sceGumMatrixMode(GU_MODEL);
        sceGumLoadIdentity();

        // Sol
        draw_quad(ground,0,0,0);

        // Route
        draw_quad(road,0,0,0);

        // Batiments USA
        int i;
        for(i=0;i<5;i++) draw_quad(bv,i*25-50,0,30);
        for(i=0;i<5;i++) draw_quad(bv,i*25-50,0,-30);

        // Personnage avec couleur
        pv[0].color=pv[1].color=pv[2].color=pv[3].color=
            char_colors[current_char];
        draw_quad(pv,px,py,pz);

        // Vehicule si dedans
        if(in_vehicle) draw_quad(car_v,px,py,pz);

        sceGuFinish();
        sceGuSync(0,0);
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
    }
    sceGuTerm();
    return 0;
}
