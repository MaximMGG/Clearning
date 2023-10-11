#include "core.h"






int task1(int const a, int const * b) {
    printf("%d %d", a, *b);


}


int main() {

    int a = 12;
    int b = 14;

    task1(a, &b);

    return 0;
}
