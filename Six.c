#include <stdio.h>



int Inc(int a) {
    return a + 3;
}

void Inc2(int *x) {
    if (x != NULL)
        *x += 5;
}

void doJob(int *x, int *y) {
    // *x += 1;
    // *y *= 2;
    int buf = *x;
    *x = *y;
    *y = buf;
}

struct sPoint {
    int x;
    int y;
};


typedef struct sPoint tPoint;

void poitWiev2(tPoint *t, int x, int y) {
    if (t != NULL)
    {
        (*t).x = x;
        (*t).y = y;
    }
}


void poitWiev(tPoint t) {
    printf("x ->%d\t y->%d", t.x, t.y);
}

int main() {


    tPoint p;
    tPoint *pPtr;
    pPtr = &p;

    p.x = 3;
    p.y = 5;
    if (pPtr != NULL) {
        (*pPtr).x = 234;
        (*pPtr).y = 34;
    }
    poitWiev2(pPtr, 22, 33);

    poitWiev(*pPtr);

    // printf("x -> %d\t y -> %d", p.x, p.y);

    return 0;
}