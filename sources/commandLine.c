#include "core.h"


int main(int argc, char *argv[]) {

    char *c;

    int a = strtol(argv[1], &c, 10);
    int b = strtol(argv[3], &c, 10);

    if (*argv[2] == '+') {
        printf("sum of %d and %d is : %d", a, b, a + b);
    } else if (*argv[2] == '-') {
        printf("%d menul %d is : %d", a, b, a - b);
    } else if (*argv[2] == '*') {
        printf("%d multiply %b is : %d", a, b, a * b);
    }

    return 0;
}
