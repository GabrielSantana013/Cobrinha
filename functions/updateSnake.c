#include "functions.h"

void updateSnake(Snake *ptrSnake, Food *ptrFood, bool *gameOver, int *score){
    int newX = ptrSnake->x[0] + ptrSnake->directionX;
    int newY = ptrSnake->y[0] + ptrSnake->directionY;

    if(newX <=0 || newX >= WIDTH-1 || newY <=0 || newY >= HEIGHT-1){
    
        *gameOver = TRUE;
    }
    
    if(newX == ptrFood->x && newY == ptrFood->y){
        ptrSnake->length++;
        *score += 10;
        spawnFood(ptrFood);        
    }

    for(int i = ptrSnake->length-1; i > 0; i--){
        ptrSnake->x[i] = ptrSnake->x[i-1];
        ptrSnake->y[i] = ptrSnake->y[i-1];        
    }

    ptrSnake->x[0] = newX;
    ptrSnake->y[0] = newY;
}
