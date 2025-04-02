#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"

#define WIDTH 40
#define HEIGHT 20
#define MENU_COLOR 1
#define MENU_ITEM_COLOR 2
#define CURSOR_COLOR 3



void menu(char (*ptrBufferScreen)[WIDTH]){

    initscr();
    cbreak(); 
    noecho();
    nodelay(stdscr, FALSE);
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    init_pair(MENU_COLOR, COLOR_CYAN, COLOR_BLACK);
    init_pair(MENU_ITEM_COLOR, COLOR_WHITE, COLOR_BLACK);

    int choice = 0;

    char *menu_items[] = {
        "Start Game",
        "Scoreboard",
        "Instructions",
        "Exit"
    };

    char *cursor = "-->";


    int num_items = sizeof(menu_items) / sizeof(menu_items[0]);


    //printar as bordas
    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(i == 0 || i == HEIGHT - 1 || j==0 || j == WIDTH -1){
                if(i == 0 && j == 0){
                    ptrBufferScreen[i][j] = TOP_LEFT_WALL;
                } else if(i == 0 && j == WIDTH - 1){
                    ptrBufferScreen[i][j] = TOP_RIGHT_WALL;
                } else if(i == HEIGHT - 1 && j == 0){
                    ptrBufferScreen[i][j] = BOTTOM_LEFT_WALL;
                } else if(i == HEIGHT - 1 && j == WIDTH - 1){
                    ptrBufferScreen[i][j] = BOTTOM_RIGHT_WALL;
                } else if(i == 0 || i == HEIGHT - 1){
                    ptrBufferScreen[i][j] = HORIZONTAL_WALL;
                } else {
                    ptrBufferScreen[i][j] = VERTICAL_WALL;
                }
                
            } else {
                mvaddch(i,j,' ');
            }
        }

    }

/*     while(1){
        clear();
        for(int i = 0; i < num_items; i++){
            if(i == choice){
                attron(COLOR_PAIR(MENU_ITEM_COLOR));
            } else {
                attroff(COLOR_PAIR(MENU_ITEM_COLOR));
            }
            mvprintw(HEIGHT/2 + i, (WIDTH - strlen(menu_items[i])) / 2, "%s", menu_items[i]);
        }
        refresh();

        int ch = getch();
        switch(ch){
            case KEY_UP:
                choice--;
                if(choice < 0) choice = num_items - 1;
                break;
            case KEY_DOWN:
                choice++;
                if(choice >= num_items) choice = 0;
                break;
            case '\n':
                if(choice == 0){
                    // Start game
                    return;
                } else if(choice == 1){
                    // Show instructions
                    mvprintw(HEIGHT/2 + num_items + 1, (WIDTH - 20) / 2, "Instructions go here...");
                    refresh();
                    getch();
                } else if(choice == 2){
                    // Exit
                    endwin();
                    exit(0);
                }
                break;
        }


    }
 */
    endwin();
    // Cleanup and exit
}