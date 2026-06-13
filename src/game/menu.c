// ELYRIA STORIES - Menu principal

#include "menu.h"

// Etat du menu
MenuState menu = {
    .current = MAIN_MENU,
    .selected_option = 0,
    .is_open = 1
};

// Options menu principal
char* main_options[] = {
    "NOUVELLE PARTIE",
    "CONTINUER",
    "CHARGER PARTIE",
    "OPTIONS",
    "QUITTER"
};

// Options pause
char* pause_options[] = {
    "CONTINUER",
    "CARTE",
    "STATISTIQUES",
    "SAUVEGARDER",
    "OPTIONS",
    "QUITTER"
};

int total_main_options = 5;
int total_pause_options = 6;

// Naviguer menu
void menu_up() {
    if (menu.selected_option > 0)
        menu.selected_option--;
}

void menu_down() {
    if (menu.selected_option < total_main_options - 1)
        menu.selected_option++;
}

// Selectionner option
void menu_select() {
    switch(menu.current) {
        case MAIN_MENU:
            if (menu.selected_option == 0) new_game();
            if (menu.selected_option == 1) load_game(1);
            if (menu.selected_option == 4) sceKernelExitGame();
            break;
        case PAUSE_MENU:
            if (menu.selected_option == 0) menu.is_open = 0;
            if (menu.selected_option == 3) save_game(1);
            break;
        default:
            break;
    }
}

// Ouvrir pause
void open_pause() {
    menu.current = PAUSE_MENU;
    menu.is_open = 1;
    menu.selected_option = 0;
}

// Fermer menu
void close_menu() {
    menu.is_open = 0;
}
