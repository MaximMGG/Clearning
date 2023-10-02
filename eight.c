#include <stdio.h>
#include <stdlib.h>


void foo(int *p) {

    *p = 234;

}

void CreateInt(int **p) {
    *p = malloc(sizeof(int));
}


void FreeMemory(int **p) {
    free(*p);
    *p = NULL;

}

int main() {

    int i = 123;
    int *a = &i;

    foo(a);

    printf("%d\n", *a);
    printf("%d\n", a);


    return 0;
}