#include "functions.h"

void snakeMove(Snake *ptrSnake, bool *gameOver){

    int input = getch();

    switch(input){
    
        case KEY_UP:
            if(ptrSnake->directionY == 0){
                ptrSnake->directionY = -1;
                ptrSnake->directionX = 0;
            }
            break;

        case KEY_DOWN:
            if(ptrSnake->directionY == 0){
                ptrSnake->directionY = 1;
                ptrSnake->directionX = 0;
            }
            break;
        case KEY_LEFT:
            if(ptrSnake->directionX == 0){
                ptrSnake->directionX = -1;
                ptrSnake->directionY = 0;
            }
            break;
        case KEY_RIGHT:
            if(ptrSnake->directionX == 0){
                ptrSnake->directionX = 1;
                ptrSnake->directionY = 0;
            }
            break;
        case 'q':
            *gameOver = TRUE;
            break;
    }

}
