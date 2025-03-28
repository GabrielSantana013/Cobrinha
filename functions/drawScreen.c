#include "functions.h"

void drawScreen(Snake *ptrSnake, Food *ptrFood, char (*ptrBufferScreen)[WIDTH], int *score){


    for(int i = 1; i < HEIGHT-1; i++){
        for(int j =1; j < WIDTH-1; j++){
            ptrBufferScreen[i][j] = ' ';
        }
    }
    
    ptrBufferScreen[ptrFood->y][ptrFood->x] = FOOD; 

    for(int i = 0; i < ptrSnake->length; i++){
            int x = ptrSnake->x[i];
            int y = ptrSnake->y[i];
            ptrBufferScreen[y][x] = SNAKE;
    }

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(ptrBufferScreen[i][j] == WALL){                
                attron(COLOR_PAIR(WALL_COLOR));                    
                mvaddch(i,j,ptrBufferScreen[i][j]);
                attroff(COLOR_PAIR(WALL_COLOR));
            }
            else if(ptrBufferScreen[i][j] == SNAKE){            
                attron(COLOR_PAIR(SNAKE_COLOR));                    
                mvaddch(i,j,ptrBufferScreen[i][j]);
                attroff(COLOR_PAIR(SNAKE_COLOR));           
            }
            else if(ptrBufferScreen[i][j] == FOOD){            
                attron(COLOR_PAIR(FOOD_COLOR));                    
                mvaddch(i,j,ptrBufferScreen[i][j]);
                attroff(COLOR_PAIR(FOOD_COLOR));            
            }
            else{
                mvaddch(i,j,ptrBufferScreen[i][j]);            
            }
            
        }
    }


    mvprintw(HEIGHT, 0, "Score: %d", *score);
    refresh();

}