#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "../functions/functions.h"
#include "../view/view.h"


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

    switch(menu()){
        case 1:
        gameStart(ptrSnake, ptrFood, ptrBufferScreen);
        drawScreen(ptrSnake, ptrFood, ptrBufferScreen, ptrScore);
        while(!gameOver){
            drawScreen(ptrSnake, ptrFood, ptrBufferScreen, ptrScore);
            updateSnake(ptrSnake, ptrFood, ptrGameOver, ptrScore);
            snakeMove(ptrSnake, ptrGameOver);
            napms(DELAYMS); //delay
        }
        endwin();
        case 2:
            //scoreboard
            break;
        case 3:
            //instruções
            break;
        case 4:
            exit(0);
            break;
    }

    
    

    return 0;
}
