#include <stdlib.h>
#include <stdio.h>



typedef int i32, *pi32;

typedef struct Sint {
    int x;
    char c;
} T, *pT;


int main() {

    T *t;

    t = malloc(8);

    t[0].x = 12; 
    t[0].c = 'A';
    t[1].x = 13; 
    t[1].c = 'P';
    for(int i = 0; i < 2; i++){
        printf("%d   %c", t[i].x, t[i].c);
    }

    return 0;
}

