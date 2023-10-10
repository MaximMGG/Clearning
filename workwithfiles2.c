#include <stdio.h>
#include <stdlib.h>



typedef struct T {
    int x, y;
    float f;
    char c[10];
} T;


void readStucture();

int main() {





    T i = {50, 22, 3.111, "HellO!"};




    FILE *f;


    f = fopen("test2.txt", "w");

    fwrite(&i, 1, sizeof(i), f);

    fclose(f);

    T buf;
    f = fopen("test2.txt", "r");
   
    fread(&buf, 1, sizeof(buf), f);

    fclose(f);

    // printf("%d %d %f %s", buf.x, buf.y, buf.f, buf.c);

    int *a =  malloc(sizeof(*a));

    f = fopen("test3.txt", "w");
    fwrite(a, 1, sizeof(*a), f);
    fclose(f);

    f = fopen("test3.txt", "r");

    int *b = malloc(sizeof(*b));
    fread(b, 1, sizeof(*b), f);
    fclose(f);


    // printf("%d", *b);



    FILE *c = fopen("test3.txt", "w");

    int con = 5;
    int *arr = malloc(sizeof(*arr) * con);

    for(int i = 0; i < con; i++){
        arr[i] = 10 + i;
    }

    fwrite(arr, con, sizeof(*arr), c);
    fclose(c);

    c = fopen("test3.txt", "r");

    int *arrRead = malloc(sizeof(*arrRead) * con);

    fread(arrRead, con, sizeof(*arrRead), c);

    fclose(c);

    for(int i = 0; i < con; i++){
        // printf("%d\n", arrRead[i]);
    }

    readStucture();

    return 0;
}

typedef struct{
    int a, b;
} A;

typedef struct {
    int a, b;
    char s[15];
    A aa;
} D;


void readStucture() {

    D d = {1, 2, "Hello!", {1, 2}};

    FILE *f; 
    f = fopen("test4.txt", "w");

    fwrite(&d, 1, sizeof(d), f);

    fclose(f);

    f = fopen("test4.txt", "r");

    D dplus;

    fread(&dplus, 1, sizeof(dplus), f);

    fclose(f);

    printf("%d, %d, %s, {%d, %d}", dplus.a, dplus.b, dplus.s, dplus.aa.a, dplus.aa.b);

}
