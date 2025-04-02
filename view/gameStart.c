#include "functions.h"

void gameStart(Snake *ptrSnake,Food *ptrFood, char (*ptrBufferScreen)[WIDTH]){

    initscr();
    cbreak(); //n aguarda o enter p ler
    noecho(); //n escreve na tela oq eu apertei
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();

    init_pair(SNAKE_COLOR, COLOR_GREEN, COLOR_BLACK);
    init_pair(FOOD_COLOR, COLOR_RED, COLOR_BLACK);
    init_pair(WALL_COLOR, COLOR_YELLOW, COLOR_BLACK);


    spawnFood(ptrFood);
    ptrSnake->length = 1;
    ptrSnake->x[0] = WIDTH/2;
    ptrSnake->y[0] = HEIGHT/2;
    ptrSnake->directionX = 1;
    ptrSnake->directionY = 0;

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(i == 0 || i == HEIGHT - 1 || j==0 || j == WIDTH -1){
                ptrBufferScreen[i][j] = WALL;
            }
            else{
                ptrBufferScreen[i][j] = ' ';
            }           
        }     
    }

}

