#include "my_string.h"

void getInt(int b, ...) {

    int *bb = &b;
    printf("%d\n", *bb);
    bb += 7;

    // for(int i = 0; i < 20; i++) {
    //     printf("%c\n", *(bb + i));
    // }

    printf("%c\n", *bb);
    bb += 2;
    printf("%c\n", *bb);
    bb += 2;
    printf("%c\n", *bb);
    bb += 2;
}

int main() {

    char *a = "Johnson";
    char *b = "Plasa hotel";
    char *c = "wife";

    str *mystring = cr_str(str_format("Hello %s, heppy to see you in aur %s, are with your %s?", a, b));

    printf("String is -> %s\n", mystring->str);
    printf("Length is -> %d\n", mystring->length);

    puts("-------------------");
   
    getInt(3, 'g', 'b', 'q');

    return 0;
}

