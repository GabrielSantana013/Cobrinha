#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <stdbool.h>

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


typedef struct{

    int x[MAX_SIZE];
    int y[MAX_SIZE];
    int length;
    int directionX;
    int directionY;
    

}Snake;

typedef struct{

    int x;
    int y;

}Food;

Snake snake;
Food food;
bool gameOver = FALSE;
int score = 0;

char bufferScreen[HEIGHT][WIDTH];


void spawnFood(){

    food.x = rand() % (WIDTH -2) + 1;
    food.y = rand() % (HEIGHT -2) + 1;

}


void gameStart(){

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


    spawnFood();
    snake.length = 1;
    snake.x[0] = WIDTH/2;
    snake.y[0] = HEIGHT/2;
    snake.directionX = 1;
    snake.directionY = 0;

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(i == 0 || i == HEIGHT - 1 || j==0 || j == WIDTH -1){
                bufferScreen[i][j] = WALL;
            }
            else{
                bufferScreen[i][j] = ' ';
            }           
        }     
    }

}




void drawScreen(){


    for(int i = 1; i < HEIGHT-1; i++){
        for(int j =1; j < WIDTH-1; j++){
            bufferScreen[i][j] = ' ';
        }
    }
    
    bufferScreen[food.y][food.x] = FOOD; 

    for(int i = 0; i < snake.length; i++){
            int x = snake.x[i];
            int y = snake.y[i];
            bufferScreen[y][x] = SNAKE;
    }

    for(int i = 0; i < HEIGHT; i++){
        for(int j = 0; j < WIDTH; j++){
            if(bufferScreen[i][j] == WALL){                
                attron(COLOR_PAIR(WALL_COLOR));                    
                mvaddch(i,j,bufferScreen[i][j]);
                attroff(COLOR_PAIR(WALL_COLOR));
            }
            else if(bufferScreen[i][j] == SNAKE){            
                attron(COLOR_PAIR(SNAKE_COLOR));                    
                mvaddch(i,j,bufferScreen[i][j]);
                attroff(COLOR_PAIR(SNAKE_COLOR));           
            }
            else if(bufferScreen[i][j] == FOOD){            
                attron(COLOR_PAIR(FOOD_COLOR));                    
                mvaddch(i,j,bufferScreen[i][j]);
                attroff(COLOR_PAIR(FOOD_COLOR));            
            }
            else{
                mvaddch(i,j,bufferScreen[i][j]);            
            }
            
        }
    }


    mvprintw(HEIGHT, 0, "Score: %d", score);
    refresh();

}

void updateSnake(){
    int newX = snake.x[0] + snake.directionX;
    int newY = snake.y[0] + snake.directionY;

    if(newX <=0 || newX >= WIDTH-1 || newY <=0 || newY >= HEIGHT-1){
    
        gameOver = TRUE;
    
    }
    
    if(newX == food.x && newY == food.y){
        snake.length++;
        score += 10;
        spawnFood();        
    }

    for(int i = snake.length-1; i > 0; i--){
        snake.x[i] = snake.x[i-1];
        snake.y[i] = snake.y[i-1];        
    }

    snake.x[0] = newX;
    snake.y[0] = newY;
}

void snakeMove(){

    int input = getch();

    switch(input){
    
        case KEY_UP:
            if(snake.directionY == 0){
                snake.directionY = -1;
                snake.directionX = 0;
            }
            break;

        case KEY_DOWN:
            if(snake.directionY == 0){
                snake.directionY = 1;
                snake.directionX = 0;
            }
            break;
        case KEY_LEFT:
            if(snake.directionX == 0){
                snake.directionX = -1;
                snake.directionY = 0;
            }
            break;
        case KEY_RIGHT:
            if(snake.directionX == 0){
                snake.directionX = 1;
                snake.directionY = 0;
            }
            break;
        case 'q':
            gameOver = TRUE;
            break;
    }

}


int main(){

    gameStart();
    drawScreen();
    while(!gameOver){
        drawScreen();
        updateSnake();
        snakeMove();
        napms(DELAYMS); //delay

    
    }
    endwin();

    return 0;
}
