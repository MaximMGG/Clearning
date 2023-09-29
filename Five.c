#include <stdio.h>
#include <windows.h>
#include <string.h>


#define h 25
#define w 80

char mas[h][w + 1];

void init() {
    for (int i = 0; i < w; i++) {
        mas[0][i] = ' ';
    }
    mas[0][w] = '\0';

    for (int i = 0; i < h; i++)
    {
        sprintf(mas[i], mas[0]);
    }
}
void show() {
    mas[h - 1][w - 1] = '\0';
    for (int i = 0; i < h; i++)
    {
        printf(mas[i]);
    }
}

void newSnow() {
    for (int  i = 0; i < w; i++)
    {
        if (rand() % 12 == 1) {
            mas[0][i] = '*';
        }
    }
    
}

void moveSnow() {
    int dx;
    for (int j = h - 1; j >= 0; j--)
    {
        for (int i = 0; i < w; i++)
        {
            if (mas[j][i] == '*') {
                mas[j][i] = ' ';
                dx = 0;
                if (rand() % 10 < 1) dx++;
                if (rand() % 10 < 1) dx--;
                dx = dx + i;
                if ((dx >= 0) && (dx < w) && (j + 1 < h)) {
                    mas[j + 1][dx] = '*';
                }
            }
        }
        
    }
    
}

void setCur(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {

    init();
    do
    {
        setCur(0, 0);
        moveSnow();
        newSnow();
        show();
        Sleep(100);
    } while (GetKeyState(VK_ESCAPE) >= 0);

    return 0;
}