#include <stdio.h>

void arithmeticOperator() {
    int x = 5;
    int y = 2;

    // float z = x / (float) y;
    // printf("%f", z);

    int z = x % y;
    printf("%d", z);

}

int main() {

    arithmeticOperator();

    return 0;
}

