#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>


#define width 66
#define height 26


typedef struct {
    int x, y;
    int w;

} TRocket;

typedef struct {
    float x, y;
    int xi, yi;
} TBall;

char mas[height][width];
TRocket rocket;
TBall ball;

void initBall() {
    moveBall(2, 2);
}

void moveRocket(int x) {
    if (!x < 1)
        rocket.x = x;
    if ((x + rocket.w) > (width - 2)) {
        rocket.x = width - 2 - rocket.w;
    }
}


void moveBall(int x, int y) {
    ball.x = x;
    ball.y = y;
    ball.xi = (int) round(ball.x);
    ball.yi = (int) round(ball.y);
}

void initRocket() {
    rocket.w = 7;
    rocket.x = (width - rocket.w) / 2;
    rocket.y = height - 3;
}


void putBall() {
    mas[ball.xi][ball.yi] = '*';
}




void putRocket() {
    for (int i = rocket.x; i < rocket.x + rocket.w; i++)
    {
        mas[rocket.y][i] = '@';
    }
    
}




void init() {
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < width - 1; j++) {
            if (i == 0 || i == height - 2) {
                mas[i][j] = '#';
            } else {
               mas[i][j] = j == 0 || j == width - 2 ? '#' : ' ';
            }
        }
    }
}

void show() {
    for (int i = 0; i < height - 1; i++) {
        printf("%s", mas[i]);
        if (i < height - 2)
            printf("\n");
    }
}




void setCur(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {

    initRocket();
    initBall();

    do
    {
        setCur(0, 0);
        init();
        putRocket();
        putBall();
        show();
        if (GetKeyState('A') < 0)
            moveRocket(rocket.x - 1);
        if (GetKeyState('D') < 0)
            moveRocket(rocket.x + 1);
        Sleep(10);
        moveBall(rocket.x + rocket.w / 2, rocket.y - 1);

    } while (GetKeyState(VK_ESCAPE) >= 0);

   return 0;
}