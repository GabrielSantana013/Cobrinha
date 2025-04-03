#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"
#include "logo.h"

#define WIDTH 60
#define HEIGHT 30
#define MENU_COLOR 1
#define MENU_ITEM_COLOR 2

void menu(){
    initscr();
    cbreak(); 
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    
    init_pair(MENU_COLOR, COLOR_CYAN, COLOR_BLACK);
    init_pair(MENU_ITEM_COLOR, COLOR_WHITE, COLOR_BLACK);

    refresh();

    // Cria uma nova janela para o menu
    WINDOW *menuWin = newwin(HEIGHT, WIDTH, 0, 0);
    box(menuWin, 0, 0); 
    wrefresh(menuWin);
    refresh();
    
    // Posicionamento do logo
    int start_logo_x = 12;  
    int start_logo_y = 1;   

    for (int i = 0; i < 7; i++) {
        mvprintw(start_logo_y + i, start_logo_x, "%s", menuLogo[i]);
    }

    int start_menu_x = 22;
    int start_menu_y = 8;

    mvprintw(start_menu_y + 8, start_menu_x + 1, "Jogar");
    mvprintw(start_menu_y + 9, start_menu_x + 1, "Scoreboard");
    mvprintw(start_menu_y + 10, start_menu_x + 1, "Instruções");
    mvprintw(start_menu_y + 11, start_menu_x + 1, "Sair");
    
    wrefresh(menuWin);
    getch();    

    endwin(); // Encerra ncurses
}
