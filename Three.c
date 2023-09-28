#include <stdio.h>
#include <stdlib.h>


typedef int cel;
typedef struct table T;
typedef struct Color col;


struct sPoint {
    int x, y;
} p;
struct Color {
    char *code;
    char *name;
} c;

struct table {
    int x, y, z;
    char *name;
    col color;
} tab;


void printTable(T t) {
    printf("x -> %d\t, y -> %d\t, z -> %d\n", t.x, t.y, t.z);
    printf("name of table is: %s\n", t.name);
    printf("And color and code are : %s, %s", t.color.name, t.color.code);
}

T getTable() {

    col red;
    red.name = "Red";
    red.code = "0124x1";

    T t;
    t.x = 10;
    t.y = 11;
    t.z = 11;
    t.name = "Very butiful table";
    t.color = red;

    return t;
}

int main() {

    struct sPoint a;

    a.x = 12;
    printf("%d\n", a.x);

    p.x = 7;
    p.y = 3;
    printf("%d\n", p.x);

    cel i = 5;

    printf("%d\n", i);

    T b;

    b.x = 11;
    printf("%d\n", b.x);

    T arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i].x = 1;
        printf("Here number from structure array : %d\n", arr[i].x);
    
    }

    struct table tab = getTable();
    printTable(tab);

    return 0;
}