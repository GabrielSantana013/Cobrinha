#include "functions.h"

#ifndef VIEWS_H
#define VIEWS_H

#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define BOTTOM_LEFT_WALL '\\'
#define BOTTOM_RIGHT_WALL '/'
#define TOP_LEFT_WALL '/'
#define TOP_RIGHT_WALL '\\'
#define WIDTH 40
#define HEIGHT 20


void menu(char (*ptrBufferScreen)[WIDTH]);
void gameStart(Snake *ptrSnake, Food *ptrFood, char (*ptrBufferScreen)[WIDTH]);
void drawScreen(Snake *ptrSnake, Food *ptrFood, char (*ptrBufferScreen)[WIDTH], int *score);


#endif