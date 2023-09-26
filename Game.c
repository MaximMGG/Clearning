#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


int main() {

    char mas[10][21];
    int x = 10, y = 5;
    char key;
    int ox, oy;
    int ax = 5, ay = 3;
    int count = 0;

    srand(time(NULL));

    do
    {
        printf("Good one you peeked %d apples\n", count);
        sprintf(mas[0], "####################");
        for (int i = 1; i < 9; i++)
        {
            sprintf(mas[i], "#                  #");
        }
        mas[y][x] = '@';
        mas[ay][ax] = '*';

        sprintf(mas[9], "####################");

        for (int i = 0; i < 10; i++)
        {
            printf("%s\n", mas[i]);
        }

        key = getch();

        ox = x;
        oy = y;

        switch (key)
        {
        case 'w':
        {
            y--;
            break;
        }
        case 's':
        {
            y++;
            break;
        }
        case 'd':
        {
            x++;
            break;
        }
        case 'a':
        {
            x--;
            break;
        }
        }

        if (mas[y][x] == '#') {
            x = ox;
            y = oy;
        }

        if (x == ax && y == ay) {
            ax = rand() * 1.0 / RAND_MAX * 18 + 1;
            ay = rand() * 1.0 / RAND_MAX * 8 + 1;
            count++;
        }
        system("cls");

    } while (key != 'e');

    return 0;
}