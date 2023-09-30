#include <stdio.h>
#include <stdlib.h>



int main() {

    void *p;

    int *x = NULL;

    x = malloc(sizeof(int));

    *x = 333;

    printf("%d\n", *x);
    printf("%d\n", x);

    free(x);

    x = NULL;


    return 0;
}
