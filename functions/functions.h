#include <ncurses.h>


#define WIDTH 60
#define HEIGHT 30
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


void updateSnake(Snake *ptrSnake, Food *ptrFood, bool *gameOver, int *score);
void snakeMove(Snake *ptrSnake, bool *gameOver);
void spawnFood(Food *ptrFood);
