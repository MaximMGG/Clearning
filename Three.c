#include <stdio.h>
#include <stdlib.h>




struct sPoint {
    int x, y;
} p;

struct table {
    int x, y, z;
    char *name;
    struct Color color;
    
} tab;

struct Color {
    char *code;
    char *name;
} color;


typedef int cel;
typedef struct sPoint T;

void printTable(struct table t) {
    printf("x -> %d\t, y -> %d\t, z -> %d\t", t.x, t.y, t.z);
    prtntf("name of table is: %s\n", t.name);
    printf("And color and code are : %s, %s", t.color.name, t.color.code);
}

struct table getTable() {

    struct Color red;
    red.name = "Red";
    red.code = "0124x1";

    struct table t;
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

    struct table b = (tab)getTable();
    printTable(b);
    

    return 0;
}