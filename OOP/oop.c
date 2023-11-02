#include "my_string.h"


int main() {

    // char *a = "Johnson";
    // char *b = "Plasa hotel";
    // char *c = "wife";
    //
    // str *mystring = cr_str(str_format("Hello %s, heppy to see you in aur %s, are with your %s?", a, b, c));
    //
    // printf("String is -> %s\n", mystring->str);
    // printf("Length is -> %d\n", mystring->length);
    //
    // str_distroy(mystring);

    str *s_i = cr_str(str_format("I am %s, and i have %d, bolls", "Jimmy", 4123));

    printf("String is %s\n", s_i->str);
    printf("Length is -> %d\n", s_i->length);

    str_distroy(s_i);
   

    return 0;
}

