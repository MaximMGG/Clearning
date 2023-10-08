#include <stdio.h>
#include <stdlib.h>



typedef struct T {
    int x, y;
    float f;
} T;

int main() {





    T i = {50, 22, 3.111};




    FILE *f;


    f = fopen("test2.txt", "w");

    fwrite(&i, 1, sizeof(i), f);

    fclose(f);

    T buf;
    f = fopen("test2.txt", "r");
   
    fread(&buf, 1, sizeof(buf), f);

    fclose(f);

    printf("%d %d %.2f\n", buf.x, buf.y, buf.f);

    return 0;
}
