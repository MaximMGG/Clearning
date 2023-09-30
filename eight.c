#include <stdio.h>
#include <stdlib.h>


void CreateInt(int **p) {
    *p = malloc(sizeof(int));
}


void FreeMemory(int **p) {
    free(*p);
    *p = NULL;

}

int main() {

    int *a = NULL;

    CreateInt(&a);

    if (a != NULL) {
        *a = 777;
        printf("%d\n", *a);
    }

    FreeMemory(&a);

    printf("%d\n", a);

    return 0;
}