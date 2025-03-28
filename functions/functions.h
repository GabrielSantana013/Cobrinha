#include <ncurses.h>


#define WIDTH 40
#define HEIGHT 20
#define MAX_SIZE 100
#define DELAYMS 100
#define WALL '#'
#define SNAKE '@'
#define FOOD 'o'
#define SNAKE_COLOR 1
#define FOOD_COLOR 2
#define WALL_COLOR 3

#ifndef SNAKE_H
#define SNAKE_H

typedef struct{

    int x[MAX_SIZE];
    int y[MAX_SIZE];
    int length;
    int directionX;
    int directionY;
    

}Snake;

#endif


#ifndef FOOD_H
#define FOOD_H
typedef struct{

    int x;
    int y;

}Food;

#endif

void gameStart(Snake *ptrSnake, Food *ptrFood, char (*ptrBufferScreen)[WIDTH]);
void drawScreen(Snake *ptrSnake, Food *ptrFood,  char (*ptrBufferScreen)[WIDTH], int *score);
void updateSnake(Snake *ptrSnake, Food *ptrFood, bool *gameOver, int *score);
void snakeMove(Snake *ptrSnake, bool *gameOver);
void spawnFood(Food *ptrFood);

