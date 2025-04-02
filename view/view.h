#include "functions.h"

#ifndef VIEWS_H
#define VIEWS_H

void menu();
void gameStart(Snake *ptrSnake, Food *ptrFood, char (*ptrBufferScreen)[WIDTH]);
void drawScreen(Snake *ptrSnake, Food *ptrFood, char (*ptrBufferScreen)[WIDTH], int *score);


#endif