#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../functions/functions.h"


int main(){

    Snake snake, *ptrSnake;
    Food food, *ptrFood;


    bool gameOver = FALSE, *ptrGameOver;
    int score = 0, *ptrScore;
    char bufferScreen [HEIGHT][WIDTH], (*ptrBufferScreen)[WIDTH];

    ptrSnake = &snake;
    ptrFood = &food;
    ptrScore = &score;
    ptrGameOver = &gameOver;
    ptrBufferScreen = bufferScreen;

    
    gameStart(ptrSnake, ptrFood, ptrBufferScreen);
    drawScreen(ptrSnake, ptrFood, ptrBufferScreen, ptrScore);
    while(!gameOver){
        drawScreen(ptrSnake, ptrFood, ptrBufferScreen, ptrScore);
        updateSnake(ptrSnake, ptrFood, ptrGameOver, ptrScore);
        snakeMove(ptrSnake, ptrGameOver);
        napms(DELAYMS); //delay    
    }
    endwin();

    return 0;
}
