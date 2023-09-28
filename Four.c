#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void randomizer() {
    srand(time(NULL));
    char buf[20];
    for (int i = 0; i < 20; i++)
    {
        buf[i] = rand() % 256;
        printf("%c\n", buf[i]);
    }
}

void fromAtoZ() {
    srand(time(NULL));
    char alphabet[26];
    alphabet[0] = 'a';
    for (int i = 1; i < 26; i++)
    {
        alphabet[i] = alphabet[0] + i;
    }

    for (int i = 0; i < 26; i++)
    {
        printf("%c\n", alphabet[i]);
    }
    
    
}





int main() {
    // int i = 123;
    // char c[50];
    // sprintf(c,"%d", i);
    // int i;
    // char c[50] = "456";
    // // itoa(i, c, 10);
    // i = atoi(c);


    // float f;
    // char c[50] = "3.44";
    // f = atof(c);


    // char c = 35;
    // printf("%c\n", c);

    randomizer();
    puts("----------");
    fromAtoZ();

    return 0;
}