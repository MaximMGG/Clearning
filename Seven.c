#include <stdio.h>
#include <stdlib.h>



int main() {

    char *mas = NULL;

    mas = malloc(1);

    printf("%d\n", mas);

    mas[0] = 2;
    mas[1] = 4;
    mas[2] = 111;
    mas[4] = 111;

    printf("%d\n", mas[0]);
    printf("%d\n", mas[1]);
    printf("%d\n", mas[2]);
    printf("%d\n", mas[3]);
    printf("%d\n", mas[4]);

    mas = realloc(mas, 8);
    printf("%d\n", mas);

    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", mas + i);
        printf("%d\n", mas[i]);
    }
    




    return 0;
}
