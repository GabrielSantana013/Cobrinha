#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"
#include "logo.h"

#define WIDTH 60
#define HEIGHT 30

void instructionsScreen() {
    initscr();
    cbreak(); 
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    
    refresh();

    // Cria uma nova janela para as instruções
    WINDOW *instructionScreen = newwin(HEIGHT, WIDTH+2, 0, 0);
    box(instructionScreen, 0, 0); 
    wrefresh(instructionScreen);
    refresh();
    
    // Posicionamento do logo
    int start_logo_x = 1;  
    int start_logo_y = 1;   

    for (int i = 0; i < 7; i++) {
        mvprintw(start_logo_y + i, start_logo_x, "%s", instructionsLogo[i]);
    }

    int start_instructions_x = 3;
    int start_instructions_y = 10;

    //printa as setas do teclado
    mvprintw(start_instructions_y+3, start_instructions_x, "Use as setas do teclado para mover a c@bra");
    mvprintw(start_instructions_y+4, start_instructions_x, "Pressione 'q' para sair do jogo");

    //printa as teclas de controle
    mvprintw(start_instructions_y+8, start_instructions_x, "Cima:     ^");
    mvprintw(start_instructions_y+9, start_instructions_x, "Baixo:    v");
    mvprintw(start_instructions_y+10, start_instructions_x, "Esquerda: <-");
    mvprintw(start_instructions_y+11, start_instructions_x, "Direita:  ->");
    mvprintw(start_instructions_y+14, start_instructions_x, "Pressione qualquer tecla para voltar ao menu");

    getch();

    // limpa a janela e deleta
    werase(instructionScreen);
    wrefresh(instructionScreen);
    delwin(instructionScreen);
    endwin();
    
}
