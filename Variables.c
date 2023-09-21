#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {

    char a = 'C';
    char b[] = "Boby";

    float c = 3.123123; // 4 byte (32 bits of precision) 6-7 digits %f
    double d = 3.12341234134; // %lf double printing  --> 8 byte (64 bits of precision) 15-16 digints %lf
    printf("This is float %0.15f\n", c);
    printf("This is double %0.15lf\n", d);

    bool e = true;// 1 byte (true or false) %d
    printf("This is boolean value %d\n", e);

    char f = 100; // 1 byte (-128 to +127) %d or %c
    unsigned char g = 205; // 1 byte (0 to 255) %d or %c
    printf("This is charctrer %c\n", f);
    printf("This is unsigned charctrer %c\n", g);

    short int h = 32767; // 2 bytes (-32768 to +32767) %d we can declare like short h
    unsigned short int hu = 62767; // 2 bytes (+65535) %d we can declare like ubsigned short hu
    printf("This is short %d\n", h);
    printf("This is unsigned short %d\n", hu);

    int j = 2147483647; // 4 bytes (-2_147_483_648 to +2_147_483_647 ) %d
    unsigned int ju = 4294967295; // 4 bytes (+4_294_967_295) %u
    printf("This is int %d\n", j);
    printf("This is unsigned int %u\n", ju);

    long long int l = 9223372036854775807; // 8 bytes (-9 quintillion to +9quintillion) %lld
    unsigned long long int lu = 18446744073709551615U; // 8 bytes (+18quintillion) %llu
    printf("This is long %lld\n", l);
    printf("This is unsigned long %llu", lu);

    return 0;
}

/*



*/