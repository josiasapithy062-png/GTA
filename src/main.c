#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspgu.h>

PSP_MODULE_INFO("ELYRIA STORIES", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_KB(-1024);

static int exitCallback(int arg1, int arg2, void *common) {
    sceKernelExitGame();
    return 0;
}

int main(void) {
    // Point d'entree du jeu ELYRIA STORIES
    return 0;
}
