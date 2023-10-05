#include <stdio.h>


void changeInt(int *a) {


    *a += 3;

    printf("%d\n", *a);
}


int main() {


    int a = 14;

    changeInt(&a);

    return 0;
}
