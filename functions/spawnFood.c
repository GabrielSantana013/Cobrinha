#include "functions.h"
#include <stdlib.h>

void spawnFood(Food *ptrFood){

    ptrFood->x = rand() % (WIDTH -2) + 1;
    ptrFood->y = rand() % (HEIGHT -2) + 1;

}