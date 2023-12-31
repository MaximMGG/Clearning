#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>


#define width 66
#define height 26


typedef struct {
    int x, y;
    int w;

} TRocket;

typedef struct {
    float x, y;
    int xi, yi;
    float alpha;
    float speed;
} TBall;

char mas[height][width];
TRocket rocket;
TBall ball;

int hitCount;
int maxHitCount;

void moveBall(float x, float y) {
    ball.x = x;
    ball.y = y;
    ball.xi = (int) round(ball.x);
    ball.yi = (int) round(ball.y);
}

void initBall() {
    moveBall(2, 2);
    ball.alpha = -1;
    ball.speed = 0.5;
}

void moveRocket(int x) {
    if (!x < 1)
        rocket.x = x;
    if ((x + rocket.w) > (width - 2)) {
        rocket.x = width - 2 - rocket.w;
    }
}



void initRocket() {
    rocket.w = 7;
    rocket.x = (width - rocket.w) / 2;
    rocket.y = height - 3;
}


void putBall() {
    mas[ball.yi][ball.xi] = '*';
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
        if (i == 3) {
            printf("    hit %i    ", hitCount);
        }
        if (i == 4) {
            printf("    max %i    ", maxHitCount);
        }
        if (i < height - 2)
            printf("\n");
    }
}

void autoMoveBall() {
    if (ball.alpha < 0) {
        ball.alpha += M_PI * 2;
    }
    if (ball.alpha > M_PI * 2) {
        ball.alpha -= M_PI * 2;
    }
    TBall bl = ball;

    moveBall(ball.x + cos(ball.alpha) * ball.speed,
            ball.y + sin(ball.alpha) * ball.speed);
    
    if ((mas[ball.yi][ball.xi] == '#') || (mas[ball.yi][ball.xi] == '@')) {
        if (mas[ball.yi][ball.xi] == '@') {
            hitCount++;
        }
        if ((ball.xi != bl.xi) && (ball.yi != bl.yi)) {
            if (mas[bl.yi][ball.xi] == mas[ball.yi][bl.xi]) {
                bl.alpha = bl.alpha + M_PI;
            } else {
                if (mas[bl.yi][ball.xi] == '#')
                    bl.alpha = (2 * M_PI - bl.alpha) + M_PI;
                else
                    bl.alpha = (2 * M_PI - bl.alpha);
            }
        } else if (ball.yi == bl.yi){
            bl.alpha = (2 * M_PI - bl.alpha) + M_PI;
        } else {
            bl.alpha = (2 * M_PI - bl.alpha);
        }
        ball = bl;
        autoMoveBall();
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

    bool run = false;


    do
    {

        if (run)
            autoMoveBall();

        if (ball.yi > height - 4) {
            run = false;
            maxHitCount = hitCount > maxHitCount ? hitCount : maxHitCount;
            hitCount = 0;
        }


        setCur(0, 0);
        init();
        putRocket();
        putBall();
        show();
        if (GetKeyState('A') < 0)
            moveRocket(rocket.x - 1);
        if (GetKeyState('D') < 0)
            moveRocket(rocket.x + 1);
        if (GetKeyState('W') < 0)
            run = true;
        if (!run)
            moveBall(rocket.x + rocket.w / 2, rocket.y -1);
        Sleep(10);

    } while (GetKeyState(VK_ESCAPE) >= 0);

   return 0;
}