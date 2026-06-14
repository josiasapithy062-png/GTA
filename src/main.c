#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspctrl.h>
#include <pspdebug.h>
#include <psprtc.h>
#include <math.h>
#include <stdlib.h>

PSP_MODULE_INFO("ELYRIA STORIES", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

static unsigned int __attribute__((aligned(16))) list[262144];
typedef struct{float x,y,z;unsigned int color;}Vertex;

// Stats joueur
int current_char=0,health=100,armor=50,money=5000;
int wanted=0,current_mission=0,mission_complete=0;
int in_vehicle=0,current_country=0,game_hour=12;
int total_kills=0,total_missions=0,properties=0;
int has_weapon=1,ammo=50,is_running=0,is_dead=0;
int coup_phase=0,heist_phase=0,coup_done=0,heist_done=0;
float px=0,py=0,pz=0,angle=0,vx=0,vz=0;
float plane_alt=0,plane_spd=0,is_flying=0;
int prev_buttons=0,frame=0,cheat_timer=0;
int npc_count=5,animal_count=3;
float npc_x[]={20,40,-20,-40,60};
float npc_z[]={20,-20,30,-30,50};
float animal_x[]={100,-100,150};
float animal_z[]={100,50,-80};

// Donnees
char* char_names[]={"JOSIAS","FRANCK","MIKAEL","TREV"};
unsigned int char_colors[]={0xFF4444FF,0xFF44FF44,0xFFFFFF44,0xFFFF4444};
char* char_special[]={"Leadership","Pilotage","Precision","Berserk"};
char* missions[]={"Bienvenue Elyria","Vol de Voiture","Frontiere",
    "Braquage Banque","Arsenal National","Coup d Etat Pt1",
    "Coup d Etat Pt2","Coup d Etat Pt3","Braquage Siecle Pt1",
    "Braquage Siecle Pt2","Braquage Siecle Final","Liberation Elyria"};
int mission_rewards[]={1000,5000,10000,50000,75000,30000,
    40000,100000,60000,80000,200000,500000};
char* countries[]={"USA - Liberty City","ELYRIA - Elyria City"};
char* weapons[]={"Poings","Pistolet","AK47","Sniper","RPG","Minigun"};
int weapon_damage[]={10,25,45,99,200,50};
int current_weapon=0;

// Proprietes
char* properties_list[]={"Garage USA","Planque Elyria","Club Nightlife",
    "Arsenal Prive","Manoir Elyria"};
int property_prices[]={50000,75000,200000,500000,1000000};
int property_owned[]={0,0,0,0,0};

// Vehicules
char* vehicles[]={"Sultan","Infernus","Moto Sport","Speedboat",
    "Hydra","Maverick","Tank Abrams"};
int vehicle_speeds[]={150,200,220,180,400,200,80};
int current_vehicle_type=0;

// Codes triche
int cheat_money=0,cheat_health=0,cheat_wanted=0,cheat_weapons=0;

// Vertices 3D
static Vertex __attribute__((aligned(16))) ground[4]={
    {-2000,0,-2000,0xFF228B22},{2000,0,-2000,0xFF228B22},
    {-2000,0,2000,0xFF228B22},{2000,0,2000,0xFF228B22}};
static Vertex __attribute__((aligned(16))) sea[4]={
    {-2000,0,-2000,0xFF006994},{2000,0,-2000,0xFF006994},
    {-2000,0,2000,0xFF006994},{2000,0,2000,0xFF006994}};
static Vertex __attribute__((aligned(16))) road[4]={
    {-8,0.1f,-2000,0xFF333333},{8,0.1f,-2000,0xFF333333},
    {-8,0.1f,2000,0xFF333333},{8,0.1f,2000,0xFF333333}};
static Vertex __attribute__((aligned(16))) pv[4]={
    {-1,0,-1,0xFF0000FF},{1,0,-1,0xFF0000FF},
    {-1,2,-1,0xFF0000FF},{1,2,-1,0xFF0000FF}};
static Vertex __attribute__((aligned(16))) bv[4]={
    {-5,0,-3,0xFF888888},{5,0,-3,0xFF888888},
    {-5,15,-3,0xFF666666},{5,15,-3,0xFF666666}};
static Vertex __attribute__((aligned(16))) cv[4]={
    {-2,0,-1,0xFFFF4400},{2,0,-1,0xFFFF4400},
    {-2,1.5f,-1,0xFFCC3300},{2,1.5f,-1,0xFFCC3300}};
static Vertex __attribute__((aligned(16))) npc_v[4]={
    {-0.5f,0,-0.5f,0xFFFFBF00},{0.5f,0,-0.5f,0xFFFFBF00},
    {-0.5f,2,-0.5f,0xFFFFBF00},{0.5f,2,-0.5f,0xFFFFBF00}};
static Vertex __attribute__((aligned(16))) animal_v[4]={
    {-0.5f,0,-0.5f,0xFF8B4513},{0.5f,0,-0.5f,0xFF8B4513},
    {-0.5f,1,-0.5f,0xFF8B4513},{0.5f,1,-0.5f,0xFF8B4513}};
static Vertex __attribute__((aligned(16))) tree_v[4]={
    {-1,0,-1,0xFF228B22},{1,0,-1,0xFF228B22},
    {-1,5,-1,0xFF32CD32},{1,5,-1,0xFF32CD32}};
static Vertex __attribute__((aligned(16))) border_v[4]={
    {-3,0,-1,0xFFFFFF00},{3,0,-1,0xFFFFFF00},
    {-3,5,-1,0xFFFF8800},{3,5,-1,0xFFFF8800}};
static Vertex __attribute__((aligned(16))) plane_v[4]={
    {-3,0,-1,0xFF888888},{3,0,-1,0xFF888888},
    {-3,1,-1,0xFF666666},{3,1,-1,0xFF666666}};

static int exitCB(int a,int b,void*c){sceKernelExitGame();return 0;}
static int cbThread(SceSize a,void*b){
    int id=sceKernelCreateCallback("Exit",exitCB,NULL);
    sceKernelRegisterExitCallback(id);
    sceKernelSleepThreadCB();return 0;
}

void draw_quad(Vertex* v,float x,float y,float z){
    sceGumPushMatrix();
    ScePspFVector3 pos={x,y,z};
    sceGumTranslate(&pos);
    sceGuDisable(GU_TEXTURE_2D);
    sceGumDrawArray(GU_TRIANGLE_STRIP,
        GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,4,0,v);
    sceGumPopMatrix();
}

void update_npcs(){
    int i;
    for(i=0;i<npc_count;i++){
        npc_x[i]+=sinf(frame*0.01f+i)*0.05f;
        npc_z[i]+=cosf(frame*0.01f+i)*0.05f;
    }
    for(i=0;i<animal_count;i++){
        animal_x[i]+=sinf(frame*0.02f+i)*0.08f;
        animal_z[i]+=cosf(frame*0.02f+i)*0.08f;
    }
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
    pspDebugScreenInit();

    while(1){
        frame++;
        if(frame%600==0){game_hour=(game_hour+1)%24;}

        SceCtrlData pad;
        sceCtrlReadBufferPositive(&pad,1);
        int btn=pad.Buttons;
        int new_btn=btn&~prev_buttons;
        int ax=pad.Lx-128,ay=pad.Ly-128;

        if(is_dead){
            if(new_btn&PSP_CTRL_CROSS){
                is_dead=0;health=100;
                money-=500;wanted=0;
                px=0;py=0;pz=0;
            }
            prev_buttons=btn;
            goto render;
        }

        // Rotation
        if(ax<-20)angle-=0.05f;
        if(ax>20)angle+=0.05f;

        // Mouvement
        float spd=(btn&PSP_CTRL_RTRIGGER)?0.6f:0.2f;
        is_running=(btn&PSP_CTRL_RTRIGGER)?1:0;

        if(!in_vehicle&&!is_flying){
            if(ay<-20){px+=spd*sinf(angle);pz+=spd*cosf(angle);}
            if(ay>20){px-=spd*sinf(angle);pz-=spd*cosf(angle);}
            if(new_btn&PSP_CTRL_CROSS)py=4.0f;
        } else if(in_vehicle&&!is_flying){
            if(btn&PSP_CTRL_CROSS){
                vx+=0.2f*sinf(angle);
                vz+=0.2f*cosf(angle);
            }
            if(btn&PSP_CTRL_SQUARE){vx*=0.8f;vz*=0.8f;}
            px+=vx;pz+=vz;
            vx*=0.96f;vz*=0.96f;
        } else if(is_flying){
            if(btn&PSP_CTRL_CROSS)plane_spd+=0.1f;
            if(btn&PSP_CTRL_SQUARE)plane_spd-=0.1f;
            if(plane_spd<0)plane_spd=0;
            if(btn&PSP_CTRL_UP)plane_alt+=0.5f;
            if(btn&PSP_CTRL_DOWN)plane_alt-=0.5f;
            if(plane_alt<0){plane_alt=0;is_flying=0;}
            px+=plane_spd*sinf(angle);
            pz+=plane_spd*cosf(angle);
            py=plane_alt;
        }

        if(py>0&&!is_flying)py-=0.2f;else if(!is_flying)py=0;

        // Boutons
        if(new_btn&PSP_CTRL_CIRCLE){
            if(is_flying){is_flying=0;plane_alt=0;}
            else in_vehicle=!in_vehicle;
            vx=0;vz=0;
        }
        if(new_btn&PSP_CTRL_LTRIGGER)
            current_char=(current_char+1)%4;
        if(new_btn&PSP_CTRL_TRIANGLE){
            if(!mission_complete){
                money+=mission_rewards[current_mission];
                mission_complete=1;
                total_missions++;
            } else {
                current_mission=(current_mission+1)%12;
                mission_complete=0;
            }
        }
        // Select = voler arme
        if(new_btn&PSP_CTRL_SELECT)
            current_weapon=(current_weapon+1)%6;
        // Start = avion
        if(new_btn&PSP_CTRL_START&&in_vehicle){
            is_flying=1;plane_alt=0;plane_spd=0;
        }
        // Changer pays
        if(new_btn&PSP_CTRL_RIGHT){
            current_country=!current_country;
            px=current_country?500:0;pz=0;
        }
        // Changer vehicule
        if(new_btn&PSP_CTRL_LEFT)
            current_vehicle_type=(current_vehicle_type+1)%7;

        // Wanted
        if(frame%120==0&&wanted>0)health-=wanted*2;
        if(new_btn&(PSP_CTRL_UP))if(wanted<5)wanted++;
        if(new_btn&(PSP_CTRL_DOWN))if(wanted>0)wanted--;

        // Mort
        if(health<=0){
            is_dead=1;total_kills++;
        }

        // Acheter propriete
        if(frame%1==0&&money>property_prices[0]&&!property_owned[0]){
            // Auto achat desactive
        }

        // NPC IA
        update_npcs();

        // Heure du jour
        if(game_hour>=22||game_hour<6)
            cheat_wanted=1;
        else cheat_wanted=0;

        prev_buttons=btn;

        render:;

        // CIEL selon heure
        unsigned int sky;
        if(game_hour>=6&&game_hour<9) sky=0xFFFFB347;
        else if(game_hour>=9&&game_hour<18) sky=current_country?0xFFE8B4A0:0xFF87CEEB;
        else if(game_hour>=18&&game_hour<21) sky=0xFFFF6B35;
        else sky=0xFF0A0A2A;

        sceGuStart(GU_DIRECT,list);
        sceGuClearColor(sky);
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);

        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(75.0f,16.0f/9.0f,0.1f,800.0f);
        sceGumMatrixMode(GU_VIEW);
        sceGumLoadIdentity();
        float cam_y=is_flying?-(py+20):-(py+5);
        ScePspFVector3 cam={
            -(px-10*sinf(angle)),cam_y,-(pz-10*cosf(angle))};
        sceGumTranslate(&cam);
        sceGumRotateY(-angle);
        sceGumMatrixMode(GU_MODEL);
        sceGumLoadIdentity();

        // Sol ou mer
        if(pz>300)draw_quad(sea,0,-0.1f,0);
        else draw_quad(ground,0,0,0);

        // Routes
        draw_quad(road,0,0,0);

        // Batiments
        int i;
        for(i=0;i<10;i++)draw_quad(bv,i*30-150,0,50);
        for(i=0;i<10;i++)draw_quad(bv,i*30-150,0,-50);
        for(i=0;i<5;i++)draw_quad(bv,i*40-100,0,100);

        // Arbres
        for(i=0;i<8;i++)draw_quad(tree_v,i*20-80,0,25);
        for(i=0;i<8;i++)draw_quad(tree_v,i*20-80,0,-25);

        // Frontiere USA/ELYRIA
        draw_quad(border_v,0,0,200);
        draw_quad(border_v,20,0,200);
        draw_quad(border_v,-20,0,200);

        // NPC
        for(i=0;i<npc_count;i++)
            draw_quad(npc_v,npc_x[i],0,npc_z[i]);

        // Animaux
        for(i=0;i<animal_count;i++)
            draw_quad(animal_v,animal_x[i],0,animal_z[i]);

        // Vehicules stationnes
        for(i=0;i<4;i++)draw_quad(cv,i*15-30,0,10);

        // Joueur
        pv[0].color=pv[1].color=pv[2].color=pv[3].color=
            char_colors[current_char];
        if(!is_dead)draw_quad(pv,px,py,pz);

        // Vehicule/Avion
        if(in_vehicle&&!is_flying)draw_quad(cv,px,py,pz);
        if(is_flying)draw_quad(plane_v,px,py,pz);

        sceGuFinish();
        sceGuSync(0,0);

        // HUD
        pspDebugScreenSetOffset(0);
        pspDebugScreenSetXY(0,0);
        pspDebugScreenSetTextColor(0xFFFFFF00);
        pspDebugScreenPrintf("=== ELYRIA STORIES ===");

        pspDebugScreenSetXY(0,1);
        pspDebugScreenSetTextColor(0xFF00FF00);
        pspDebugScreenPrintf("%s | %s | %s",
            char_names[current_char],
            is_running?"COURSE":"MARCHE",
            countries[current_country]);

        pspDebugScreenSetXY(0,2);
        pspDebugScreenSetTextColor(0xFFFF4444);
        pspDebugScreenPrintf("HP:%d  ARM:%d  $%d  KILLS:%d",
            health,armor,money,total_kills);

        pspDebugScreenSetXY(0,3);
        pspDebugScreenSetTextColor(0xFFFFFFFF);
        pspDebugScreenPrintf("ARME:%s(%d)  WANTED:%d*  H:%dh",
            weapons[current_weapon],ammo,wanted,game_hour);

        pspDebugScreenSetXY(0,4);
        pspDebugScreenSetTextColor(0xFFFFAA00);
        if(in_vehicle)
            pspDebugScreenPrintf("VEH:%s(Start=Avion)",
                vehicles[current_vehicle_type]);
        else if(is_flying)
            pspDebugScreenPrintf("AVION ALT:%.0f SPD:%.0f",
                plane_alt,plane_spd);

        pspDebugScreenSetXY(0,5);
        pspDebugScreenSetTextColor(0xFF44FFFF);
        if(!mission_complete)
            pspDebugScreenPrintf("MISSION %d: %s",
                current_mission+1,missions[current_mission]);
        else
            pspDebugScreenPrintf("MISSION OK! +$%d [Tri=Suite]",
                mission_rewards[current_mission]);

        if(coup_done)pspDebugScreenPrintf(" [COUP ETAT OK!]");
        if(heist_done)pspDebugScreenPrintf(" [BRAQUAGE OK!]");

        if(is_dead){
            pspDebugScreenSetXY(5,15);
            pspDebugScreenSetTextColor(0xFFFF0000);
            pspDebugScreenPrintf("=== VOUS ETES MORT ===");
            pspDebugScreenSetXY(3,16);
            pspDebugScreenPrintf("Croix=Respawn(-$500)");
        }

        pspDebugScreenSetXY(0,31);
        pspDebugScreenSetTextColor(0xFF888888);
        pspDebugScreenPrintf("L1=Perso O=Veh R1=Run Tri=Mission Sel=Arme Dr=Pays");

        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
    }
    sceGuTerm();
    return 0;
}
