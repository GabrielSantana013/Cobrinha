#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"
#include "logo.h"

#define WIDTH 60
#define HEIGHT 30
#define MENU_COLOR 1
#define MENU_ITEM_COLOR 2

typedef enum{

    JOGAR = 1,
    SCOREBOARD,
    INSTRUCOES,
    SAIR
}opcaoMenu;


int menu(){
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


    opcaoMenu opcoes[4] = {JOGAR, SCOREBOARD, INSTRUCOES, SAIR};
    int indice = 0;

    //posiciona a seta no lado esquerdo do menu
    do{
        mvprintw(start_menu_y + 8, start_menu_x - 2, "->");
        int choice = getch();
        switch (choice) {
            case KEY_UP:
                if (start_menu_y > 8) {
                    mvprintw(start_menu_y + 8, start_menu_x - 2, "  ");
                    start_menu_y--;
                }
                if(indice > 0){
                    indice--;
                }
                break;
            case KEY_DOWN:
                if (start_menu_y < 11) {
                    mvprintw(start_menu_y + 8, start_menu_x - 2, "  ");
                    start_menu_y++;
                }
                if(indice < 3){
                    indice++;
                }
                break;
            case '\n':
            if (opcoes[indice] == SAIR) {
                endwin();
                exit(0);
            } else {
                endwin();
                return opcoes[indice];
            }
                break;
        }

    }while(true);

    wrefresh(menuWin);
    getch();    

    endwin(); // Encerra ncurses
}
