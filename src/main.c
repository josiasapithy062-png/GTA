#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspctrl.h>
#include <pspdebug.h>
#include <pspaudio.h>
#include <psprtc.h>
#include <psppower.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

PSP_MODULE_INFO("ELYRIA STORIES", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER|THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

static unsigned int __attribute__((aligned(16))) list[262144];
typedef struct{float x,y,z;unsigned int color;}Vertex;

// =============================
// ETAT COMPLET DU JEU
// =============================
int current_char=0,health=100,armor=100,money=5000;
int wanted=0,current_mission=0,mission_complete=0;
int in_vehicle=0,current_country=0,game_hour=12;
int total_kills=0,total_missions_done=0;
int is_dead=0,is_running=0,is_swimming=0;
int is_flying=0,is_in_boat=0;
int has_parachute=0,parachute_open=0;
int current_weapon=0,ammo[]={999,50,120,10,5,999};
int frame=0,prev_buttons=0;
int coup_phase=0,heist_phase=0;
int coup_done=0,heist_done=0;
int show_map=0,show_phone=0,game_paused=0;
int properties_owned[]={0,0,0,0,0};
int vehicles_owned[]={0,0,0,0,0,0,0};
int current_vehicle_type=0;
int reputation=0,street_cred=0;
int casino_chips=0,in_casino=0;
int total_money_earned=0,cars_stolen=0;
int border_crossed=0,at_border=0;
int weather=0,rain_intensity=0;
int game_day=1;

float px=0,py=0,pz=0,angle=0;
float vx=0,vz=0,vy=0;
float plane_alt=0,plane_spd=0;
float boat_spd=0;
float cam_dist=10.0f;

// NPC et animaux
#define MAX_NPC 10
#define MAX_ANIMAL 5
float npc_x[MAX_NPC],npc_z[MAX_NPC];
int npc_alive[MAX_NPC],npc_hostile[MAX_NPC];
float animal_x[MAX_ANIMAL],animal_z[MAX_ANIMAL];
int npc_type[MAX_NPC]; // 0=civil 1=police 2=militaire

// =============================
// DONNEES DU JEU
// =============================
char* char_names[]={"JOSIAS","FRANCK","MIKAEL","TREV"};
char* char_special[]={"Leadership +30%","Pilotage +50%","Precision +40%","Berserk +100%"};
unsigned int char_colors[]={0xFF4488FF,0xFF44FF88,0xFFFFFF44,0xFFFF4444};
int char_health_max[]={100,100,100,150};

char* missions[]={
    "1.Bienvenue a Elyria - Explore la ville",
    "2.Vol de Voiture - Vole une Infernus",
    "3.La Frontiere - Passe en clandestin",
    "4.Braquage Banque - Vole 500k",
    "5.Arsenal Pt1 - Infiltre l arsenal",
    "6.Arsenal Pt2 - Vole les miniguns",
    "7.Coup Etat Pt1 - Recrute des allies",
    "8.Coup Etat Pt2 - Prends les medias",
    "9.Coup Etat Pt3 - Siege parlement",
    "10.Coup Etat FINAL - Installe le pouvoir",
    "11.Braquage Siecle Prep - Planifie",
    "12.Braquage Siecle FINAL - Execute"
};
int mission_rewards[]={
    1000,5000,10000,50000,
    30000,75000,40000,50000,
    80000,200000,100000,500000
};
char* mission_chars[]={
    "JOSIAS","FRANCK","FRANCK","MIKAEL",
    "TREV","TREV","JOSIAS","MIKAEL",
    "JOSIAS","JOSIAS","MIKAEL","TOUS"
};

char* countries[]={"USA - Liberty City","ELYRIA - Elyria City"};
char* weapons_list[]={"Poings","Pistolet","AK47","Sniper","RPG","Minigun"};
int weapon_dmg[]={10,30,50,99,200,75};

char* vehicles_list[]={"Sultan","Infernus","Moto","Speedboat","Hydra","Maverick","Tank"};
int vehicle_spd[]={150,200,220,180,400,200,80};
unsigned int vehicle_colors[]={
    0xFFFF4400,0xFF0044FF,0xFF44FF00,
    0xFF0088FF,0xFF888888,0xFF444444,0xFF226600};

char* props[]={"Garage USA $50k","Planque Elyria $75k",
    "Club $200k","Arsenal $500k","Manoir $1M"};
int prop_prices[]={50000,75000,200000,500000,1000000};

char* weather_names[]={"Ensoleille","Nuageux","Pluie","Orage","Brouillard"};
unsigned int weather_sky[]={0xFF87CEEB,0xFF778899,0xFF556677,0xFF334455,0xFF99AABB};

char* wanted_txt[]={"","[*]","[**]","[***]","[****]","[*****]"};

// =============================
// VERTICES 3D
// =============================
static Vertex __attribute__((aligned(16))) ground[4]={
    {-3000,0,-3000,0xFF228B22},{3000,0,-3000,0xFF228B22},
    {-3000,0,3000,0xFF228B22},{3000,0,3000,0xFF228B22}};
static Vertex __attribute__((aligned(16))) elyria_ground[4]={
    {-3000,0,-3000,0xFF8B7355},{3000,0,-3000,0xFF8B7355},
    {-3000,0,3000,0xFF8B7355},{3000,0,3000,0xFF8B7355}};
static Vertex __attribute__((aligned(16))) sea[4]={
    {-3000,-0.5f,-3000,0xFF006994},{3000,-0.5f,-3000,0xFF006994},
    {-3000,-0.5f,3000,0xFF006994},{3000,-0.5f,3000,0xFF006994}};
static Vertex __attribute__((aligned(16))) road[4]={
    {-8,0.1f,-3000,0xFF333333},{8,0.1f,-3000,0xFF333333},
    {-8,0.1f,3000,0xFF333333},{8,0.1f,3000,0xFF333333}};
static Vertex __attribute__((aligned(16))) road2[4]={
    {-3000,0.1f,-8,0xFF333333},{3000,0.1f,-8,0xFF333333},
    {-3000,0.1f,8,0xFF333333},{3000,0.1f,8,0xFF333333}};
static Vertex __attribute__((aligned(16))) pv[4]={
    {-0.8f,0,-0.8f,0xFF4488FF},{0.8f,0,-0.8f,0xFF4488FF},
    {-0.8f,2,-0.8f,0xFF4488FF},{0.8f,2,-0.8f,0xFF4488FF}};
static Vertex __attribute__((aligned(16))) bv_small[4]={
    {-4,0,-3,0xFF888888},{4,0,-3,0xFF888888},
    {-4,8,-3,0xFF666666},{4,8,-3,0xFF666666}};
static Vertex __attribute__((aligned(16))) bv_big[4]={
    {-6,0,-4,0xFF777799},{6,0,-4,0xFF777799},
    {-6,20,-4,0xFF555577},{6,20,-4,0xFF555577}};
static Vertex __attribute__((aligned(16))) bv_palace[4]={
    {-10,0,-6,0xFFDDCC99},{10,0,-6,0xFFDDCC99},
    {-10,25,-6,0xFFBBAA77},{10,25,-6,0xFFBBAA77}};
static Vertex __attribute__((aligned(16))) cv[4]={
    {-2,0,-1,0xFFFF4400},{2,0,-1,0xFFFF4400},
    {-2,1.5f,-1,0xFFCC3300},{2,1.5f,-1,0xFFCC3300}};
static Vertex __attribute__((aligned(16))) boat_v[4]={
    {-3,0,-1,0xFF004488},{3,0,-1,0xFF004488},
    {-3,1,-1,0xFF003366},{3,1,-1,0xFF003366}};
static Vertex __attribute__((aligned(16))) plane_v[4]={
    {-4,0,-1,0xFF888888},{4,0,-1,0xFF888888},
    {-4,1,-1,0xFF666666},{4,1,-1,0xFF666666}};
static Vertex __attribute__((aligned(16))) heli_v[4]={
    {-2,0,-2,0xFF444444},{2,0,-2,0xFF444444},
    {-2,2,-2,0xFF333333},{2,2,-2,0xFF333333}};
static Vertex __attribute__((aligned(16))) npc_civil[4]={
    {-0.5f,0,-0.5f,0xFFFFBF00},{0.5f,0,-0.5f,0xFFFFBF00},
    {-0.5f,1.8f,-0.5f,0xFFFFBF00},{0.5f,1.8f,-0.5f,0xFFFFBF00}};
static Vertex __attribute__((aligned(16))) npc_police[4]={
    {-0.5f,0,-0.5f,0xFF0000FF},{0.5f,0,-0.5f,0xFF0000FF},
    {-0.5f,1.8f,-0.5f,0xFF0000FF},{0.5f,1.8f,-0.5f,0xFF0000FF}};
static Vertex __attribute__((aligned(16))) npc_military[4]={
    {-0.5f,0,-0.5f,0xFF226600},{0.5f,0,-0.5f,0xFF226600},
    {-0.5f,1.8f,-0.5f,0xFF226600},{0.5f,1.8f,-0.5f,0xFF226600}};
static Vertex __attribute__((aligned(16))) animal_dog[4]={
    {-0.6f,0,-0.3f,0xFF8B4513},{0.6f,0,-0.3f,0xFF8B4513},
    {-0.6f,0.8f,-0.3f,0xFF8B4513},{0.6f,0.8f,-0.3f,0xFF8B4513}};
static Vertex __attribute__((aligned(16))) tree_v[4]={
    {-1.5f,0,-1.5f,0xFF228B22},{1.5f,0,-1.5f,0xFF228B22},
    {-1.5f,6,-1.5f,0xFF32CD32},{1.5f,6,-1.5f,0xFF32CD32}};
static Vertex __attribute__((aligned(16))) palm_v[4]={
    {-1,0,-1,0xFF228B22},{1,0,-1,0xFF228B22},
    {-1,8,-1,0xFF44AA44},{1,8,-1,0xFF44AA44}};
static Vertex __attribute__((aligned(16))) border_post[4]={
    {-2,0,-1,0xFFFFFF00},{2,0,-1,0xFFFFFF00},
    {-2,6,-1,0xFFFF8800},{2,6,-1,0xFFFF8800}};
static Vertex __attribute__((aligned(16))) water_v[4]={
    {-3000,-0.2f,-3000,0xFF1166AA},{3000,-0.2f,-3000,0xFF1166AA},
    {-3000,-0.2f,3000,0xFF1166AA},{3000,-0.2f,3000,0xFF1166AA}};

// =============================
// CALLBACKS
// =============================
static int exitCB(int a,int b,void*c){sceKernelExitGame();return 0;}
static int cbThread(SceSize a,void*b){
    int id=sceKernelCreateCallback("Exit",exitCB,NULL);
    sceKernelRegisterExitCallback(id);
    sceKernelSleepThreadCB();return 0;
}

// =============================
// FONCTIONS RENDU
// =============================
void draw_quad(Vertex* v,float x,float y,float z){
    sceGumPushMatrix();
    ScePspFVector3 pos={x,y,z};
    sceGumTranslate(&pos);
    sceGuDisable(GU_TEXTURE_2D);
    sceGumDrawArray(GU_TRIANGLE_STRIP,
        GU_COLOR_8888|GU_VERTEX_32BITF|GU_TRANSFORM_3D,4,0,v);
    sceGumPopMatrix();
}

void draw_vehicle(float x,float y,float z,int type){
    int i;unsigned int c=vehicle_colors[type];
    cv[0].color=cv[1].color=cv[2].color=cv[3].color=c;
    switch(type){
        case 3:draw_quad(boat_v,x,y,z);break;
        case 4:case 5:
            if(is_flying)draw_quad(plane_v,x,y,z);
            else draw_quad(heli_v,x,y,z);
            break;
        default:draw_quad(cv,x,y,z);break;
    }
}

void init_npcs(){
    int i;
    for(i=0;i<MAX_NPC;i++){
        npc_x[i]=(float)((i*37+15)%80-40);
        npc_z[i]=(float)((i*53+20)%80-40);
        npc_alive[i]=1;npc_hostile[i]=0;
        npc_type[i]=i%3;
    }
    for(i=0;i<MAX_ANIMAL;i++){
        animal_x[i]=(float)((i*41+60)%120-60);
        animal_z[i]=(float)((i*67+30)%120-60);
    }
}

void update_npcs(){
    int i;
    for(i=0;i<MAX_NPC;i++){
        if(!npc_alive[i])continue;
        float dx=px-npc_x[i],dz=pz-npc_z[i];
        float dist=dx*dx+dz*dz;
        if(npc_hostile[i]&&dist<400){
            npc_x[i]+=dx*0.01f;npc_z[i]+=dz*0.01f;
            if(dist<4&&health>0)health-=1;
        } else {
            npc_x[i]+=sinf(frame*0.01f+i)*0.05f;
            npc_z[i]+=cosf(frame*0.013f+i)*0.05f;
        }
        if(wanted>=3)npc_hostile[i]=(npc_type[i]==1||npc_type[i]==2);
        else if(wanted>=1)npc_hostile[i]=(npc_type[i]==1);
        else npc_hostile[i]=0;
    }
    for(i=0;i<MAX_ANIMAL;i++){
        animal_x[i]+=sinf(frame*0.02f+i*1.5f)*0.08f;
        animal_z[i]+=cosf(frame*0.017f+i*1.5f)*0.08f;
    }
}

void update_weather(){
    if(frame%3600==0)weather=(weather+1)%5;
    rain_intensity=(weather>=2)?1:0;
}

// =============================
// MAIN
// =============================
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
    sceGuEnable(GU_BLEND);
    sceGuBlendFunc(GU_ADD,GU_SRC_ALPHA,GU_ONE_MINUS_SRC_ALPHA,0,0);
    sceGuFinish();sceGuSync(0,0);
    sceDisplayWaitVblankStart();
    sceGuDisplay(GU_TRUE);
    pspDebugScreenInit();
    init_npcs();

    while(1){
        frame++;
        if(frame%600==0)game_hour=(game_hour+1)%24;
        if(frame%14400==0)game_day++;
        update_weather();
        update_npcs();

        SceCtrlData pad;
        sceCtrlReadBufferPositive(&pad,1);
        int btn=pad.Buttons;
        int new_btn=btn&~prev_buttons;
        int ax=pad.Lx-128,ay=pad.Ly-128;

        if(game_paused){
            if(new_btn&PSP_CTRL_START)game_paused=0;
            goto render;
        }

        if(is_dead){
            if(new_btn&PSP_CTRL_CROSS){
                is_dead=0;health=100;armor=50;
                money-=1000;if(money<0)money=0;
                wanted=0;px=0;py=0;pz=0;
            }
            goto render;
        }

        // ROTATION
        if(ax<-20)angle-=0.05f;
        if(ax>20) angle+=0.05f;

        // DEPLACEMENT
        float spd=(btn&PSP_CTRL_RTRIGGER)?0.6f:0.2f;
        is_running=(btn&PSP_CTRL_RTRIGGER)?1:0;
        if(rain_intensity)spd*=0.8f;

        if(!in_vehicle&&!is_flying&&!is_in_boat){
            if(ay<-20){px+=spd*sinf(angle);pz+=spd*cosf(angle);}
            if(ay>20) {px-=spd*sinf(angle);pz-=spd*cosf(angle);}
            if(new_btn&PSP_CTRL_CROSS){py=4.0f;
                if(has_parachute&&py>10)parachute_open=1;}
        } else if(in_vehicle&&!is_flying){
            if(btn&PSP_CTRL_CROSS){
                vx+=0.2f*sinf(angle);vz+=0.2f*cosf(angle);}
            if(btn&PSP_CTRL_SQUARE){vx*=0.75f;vz*=0.75f;}
            if(rain_intensity){vx*=0.95f;vz*=0.95f;}
            px+=vx;pz+=vz;vx*=0.96f;vz*=0.96f;
        } else if(is_flying){
            if(btn&PSP_CTRL_CROSS)plane_spd+=0.15f;
            if(btn&PSP_CTRL_SQUARE){plane_spd-=0.1f;if(plane_spd<0)plane_spd=0;}
            if(btn&PSP_CTRL_UP)plane_alt+=0.8f;
            if(btn&PSP_CTRL_DOWN){plane_alt-=0.8f;if(plane_alt<0){plane_alt=0;is_flying=0;in_vehicle=1;}}
            px+=plane_spd*sinf(angle);pz+=plane_spd*cosf(angle);py=plane_alt;
        } else if(is_in_boat){
            if(btn&PSP_CTRL_CROSS){boat_spd+=0.15f;if(boat_spd>8)boat_spd=8;}
            if(btn&PSP_CTRL_SQUARE){boat_spd-=0.2f;if(boat_spd<0)boat_spd=0;}
            px+=boat_spd*sinf(angle);pz+=boat_spd*cosf(angle);
            boat_spd*=0.98f;
        }

        if(py>0&&!is_flying){
            if(parachute_open)py-=0.05f;
            else py-=0.2f;
        } else if(!is_flying)py=0;
        if(py<=0)parachute_open=0;

        // BOUTONS ACTIONS
        if(new_btn&PSP_CTRL_CIRCLE){
            if(is_flying){is_flying=0;plane_alt=0;in_vehicle=1;}
            else if(is_in_boat){is_in_boat=0;}
            else{
                in_vehicle=!in_vehicle;
                if(in_vehicle){vx=0;vz=0;cars_stolen++;}
            }
        }

        // L1 = changer personnage
        if(new_btn&PSP_CTRL_LTRIGGER){
            current_char=(current_char+1)%4;
            health=char_health_max[current_char];
        }

        // Triangle = mission
        if(new_btn&PSP_CTRL_TRIANGLE){
            if(!mission_complete){
                money+=mission_rewards[current_mission];
                total_money_earned+=mission_rewards[current_mission];
                mission_complete=1;
                total_missions_done++;
                reputation+=10;street_cred+=15;
                if(current_mission==9)coup_done=1;
                if(current_mission==11)heist_done=1;
            } else {
                current_mission=(current_mission+1)%12;
                mission_complete=0;
            }
        }

        // Select = changer arme
        if(new_btn&PSP_CTRL_SELECT)
            current_weapon=(current_weapon+1)%6;

        // Start = pause / avion
        if(new_btn&PSP_CTRL_START){
            if(in_vehicle&&!is_flying&&!is_in_boat){
                if(current_vehicle_type==3)is_in_boat=1;
                else if(current_vehicle_type>=4)is_flying=1;
                else game_paused=!game_paused;
            } else game_paused=!game_paused;
        }

        // Droite = changer pays
        if(new_btn&PSP_CTRL_RIGHT){
            current_country=!current_country;
            px=current_country?300:0;pz=0;py=0;
            border_crossed++;
        }

        // Gauche = changer vehicule
        if(new_btn&PSP_CTRL_LEFT)
            current_vehicle_type=(current_vehicle_type+1)%7;

        // Haut = wanted+
        if(new_btn&PSP_CTRL_UP)if(wanted<5)wanted++;
        // Bas = wanted-
        if(new_btn&PSP_CTRL_DOWN)if(wanted>0)wanted--;

        // WANTED degats
        if(frame%90==0&&wanted>0&&health>0)
            health-=wanted*3;

        // Frontiere
        if(pz>190&&pz<210)at_border=1;
        else at_border=0;

        // Mer
        if(pz>250||pz<-250)is_swimming=1;
        else is_swimming=0;

        // Mort
        if(health<=0)is_dead=1;

        prev_buttons=btn;

        render:;

        // COULEUR CIEL
        unsigned int sky;
        if(game_paused||is_dead){
            sky=0xFF222222;
        } else {
            sky=weather_sky[weather];
            if(game_hour>=6&&game_hour<9)  sky=0xFFFFB347;
            else if(game_hour>=18&&game_hour<21)sky=0xFFFF6B35;
            else if(game_hour>=21||game_hour<6) sky=0xFF0A0A2A;
            else sky=weather_sky[weather];
            if(current_country==1)sky=(sky&0x00FFFFFF)|0x55000000;
        }

        sceGuStart(GU_DIRECT,list);
        sceGuClearColor(sky);
        sceGuClearDepth(0);
        sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);

        // CAMERA
        sceGumMatrixMode(GU_PROJECTION);
        sceGumLoadIdentity();
        sceGumPerspective(75.0f,16.0f/9.0f,0.1f,800.0f);
        sceGumMatrixMode(GU_VIEW);
        sceGumLoadIdentity();
        float cy=is_flying?-(py+20):-(py+6);
        ScePspFVector3 cam={
            -(px-cam_dist*sinf(angle)),cy,
            -(pz-cam_dist*cosf(angle))};
        sceGumTranslate(&cam);
        sceGumRotateY(-angle);
        sceGumMatrixMode(GU_MODEL);
        sceGumLoadIdentity();

        // SOL
        if(current_country==0)draw_quad(ground,0,0,0);
        else draw_quad(elyria_ground,0,0,0);

        // MER
        draw_quad(water_v,0,0,300);

        // ROUTES
        draw_quad(road,0,0,0);
        draw_quad(road2,0,0,0);

        // BATIMENTS USA
        int i;
        for(i=0;i<12;i++)draw_quad(bv_small,i*25-150,0,60);
        for(i=0;i<12;i++)draw_quad(bv_small,i*25-150,0,-60);
        for(i=0;i<6;i++) draw_quad(bv_big,i*40-100,0,100);
        for(i=0;i<6;i++) draw_quad(bv_big,i*40-100,0,-100);

        // PALAIS ELYRIA
        if(current_country==1){
            draw_quad(bv_palace,0,0,50);
            draw_quad(bv_palace,-50,0,50);
            draw_quad(bv_palace,50,0,50);
        }

        // ARBRES
        for(i=0;i<10;i++)draw_quad(tree_v,i*20-100,0,30);
        for(i=0;i<10;i++)draw_quad(tree_v,i*20-100,0,-30);
        for(i=0;i<5;i++) draw_quad(palm_v,i*25-50,0,200);

        // FRONTIERE
        for(i=0;i<8;i++)draw_quad(border_post,i*15-60,0,195);

        // VEHICULES STATIONNES
        for(i=0;i<6;i++){
            cv[0].color=cv[1].color=cv[2].color=cv[3].color=vehicle_colors[i%7];
            draw_quad(cv,i*18-45,0,12);
        }

        // NPC
        for(i=0;i<MAX_NPC;i++){
            if(!npc_alive[i])continue;
            Vertex* nv=npc_hostile[i]?npc_police:
                (npc_type[i]==2?npc_military:npc_civil);
            draw_quad(nv,npc_x[i],0,npc_z[i]);
        }

        // ANIMAUX
        for(i=0;i<MAX_ANIMAL;i++)
            draw_quad(animal_dog,animal_x[i],0,animal_z[i]);

        // JOUEUR
        if(!is_dead){
            pv[0].color=pv[1].color=pv[2].color=pv[3].color=
                char_colors[current_char];
            draw_quad(pv,px,py,pz);
        }

        // VEHICULE
        if(in_vehicle||is_flying||is_in_boat)
            draw_vehicle(px,py,pz,current_vehicle_type);

        sceGuFinish();
        sceGuSync(0,0);

        // =============================
        // HUD COMPLET
        // =============================
        pspDebugScreenSetOffset(0);

        if(game_paused){
            pspDebugScreenSetXY(8,12);
            pspDebugScreenSetTextColor(0xFFFFFFFF);
            pspDebugScreenPrintf("=== PAUSE ===");
            pspDebugScreenSetXY(5,13);
            pspDebugScreenPrintf("Start=Reprendre");
            pspDebugScreenSetXY(3,14);
            pspDebugScreenPrintf("Missions:%d  $%d",
                total_missions_done,money);
            pspDebugScreenSetXY(3,15);
            pspDebugScreenPrintf("Rep:%d  Cred:%d  Kills:%d",
                reputation,street_cred,total_kills);
            pspDebugScreenSetXY(3,16);
            pspDebugScreenPrintf("Jour:%d  Heure:%dh",game_day,game_hour);
            goto end_frame;
        }

        if(is_dead){
            pspDebugScreenSetXY(5,13);
            pspDebugScreenSetTextColor(0xFFFF0000);
            pspDebugScreenPrintf("*** VOUS ETES MORT ***");
            pspDebugScreenSetXY(4,14);
            pspDebugScreenSetTextColor(0xFFFFFFFF);
            pspDebugScreenPrintf("Croix=Respawn(-$1000)");
            goto end_frame;
        }

        // Ligne 0 - Titre
        pspDebugScreenSetXY(0,0);
        pspDebugScreenSetTextColor(0xFFFFDD00);
        pspDebugScreenPrintf("ELYRIA STORIES v1.0");

        // Ligne 1 - Perso
        pspDebugScreenSetXY(0,1);
        pspDebugScreenSetTextColor(char_colors[current_char]);
        pspDebugScreenPrintf("%s[%s]%s",
            char_names[current_char],
            is_running?"COURSE":"MARCHE",
            in_vehicle?vehicles_list[current_vehicle_type]:
            is_flying?"AVION":is_in_boat?"BATEAU":"");

        // Ligne 2 - Stats
        pspDebugScreenSetXY(0,2);
        pspDebugScreenSetTextColor(0xFF44FF44);
        pspDebugScreenPrintf("HP:%d ARM:%d $%d REP:%d",
            health,armor,money,reputation);

        // Ligne 3 - Wanted/Arme/Heure
        pspDebugScreenSetXY(0,3);
        pspDebugScreenSetTextColor(0xFFFF4444);
        pspDebugScreenPrintf("%s %s(%d) %s %dh J%d",
            wanted_txt[wanted],
            weapons_list[current_weapon],ammo[current_weapon],
            weather_names[weather],game_hour,game_day);

        // Ligne 4 - Pays/Position
        pspDebugScreenSetXY(0,4);
        pspDebugScreenSetTextColor(0xFF44FFFF);
        pspDebugScreenPrintf("%s X:%.0f Z:%.0f %s",
            countries[current_country],px,pz,
            at_border?"[FRONTIERE]":
            is_swimming?"[MER]":"");

        // Ligne 5 - Mission
        pspDebugScreenSetXY(0,5);
        pspDebugScreenSetTextColor(0xFFFFAA00);
        if(!mission_complete)
            pspDebugScreenPrintf("M:%s[%s]",
                missions[current_mission],
                mission_chars[current_mission]);
        else
            pspDebugScreenPrintf("MISSION OK!+$%d [Tri=Suite]",
                mission_rewards[current_mission]);

        // Ligne 6 - Progression
        pspDebugScreenSetXY(0,6);
        pspDebugScreenSetTextColor(0xFF8888FF);
        pspDebugScreenPrintf("Missions:%d/12 %s%s",
            total_missions_done,
            coup_done?"[COUP OK]":"",
            heist_done?"[BRAQUAGE OK]":"");

        // Ligne 7 - Special
        if(is_flying){
            pspDebugScreenSetXY(0,7);
            pspDebugScreenSetTextColor(0xFFFFFFFF);
            pspDebugScreenPrintf("AVION Alt:%.0f Spd:%.1f Haut/Bas=Alt Carre=Ralentir",
                plane_alt,plane_spd);
        }

        // Bas - Controles
        pspDebugScreenSetXY(0,31);
        pspDebugScreenSetTextColor(0xFF666666);
        pspDebugScreenPrintf("L1=Perso O=Veh R1=Run Tri=Mission Sel=Arme Dr=Pays St=Pause");

        end_frame:;
        sceDisplayWaitVblankStart();
        sceGuSwapBuffers();
    }
    sceGuTerm();
    return 0;
}
