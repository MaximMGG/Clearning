#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define cnt 5
#define number int
#define anyword int i = cnt
#define printI printf("%d", i)
#define con 10


int main() {
    printf("%d\n", con);

    int arr[con];

    for (int i = 0; i < con; i++)
    {
        arr[i] = i + 1;
        printf("%d\n", arr[i]);
    }
    srand(time(NULL));
    int a = rand() % 10 + 10;

    printf("%d\n", a);

    for (int i = 0; i < con; i++) {
        arr[i] = rand() % 40;
        printf("%d\n", arr[i]);
    }
    
    return 0;
}