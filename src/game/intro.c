#include "intro.h"
int intro_complete=0,current_scene=0;
void play_intro(){intro_complete=0;current_scene=0;}
void skip_intro(){intro_complete=1;}
void next_scene(){current_scene++;if(current_scene>=9)intro_complete=1;}
