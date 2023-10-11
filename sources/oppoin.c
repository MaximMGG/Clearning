#include "core.h"



int main() {

    int a = 123;
    long int b = 123l;
    long long w = 55LL;
    unsigned c = 33u;
    printf("%d %d\n", sizeof(123), sizeof(123000111000));


    long double o = 4.0l;
    double p = 2.;

    float e = 3.14f;

    printf("%d %d %d\n", sizeof(2.14l), sizeof(2.11f), sizeof(2.65));
    


    double aa = 1.33e2;
    double bb = 4E3;
    double cc = 314e-2L;

    printf("%g %g %lg", aa, bb, cc);

    return 0;
}

