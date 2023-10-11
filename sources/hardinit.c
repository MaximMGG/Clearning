#include "core.h"

// int func(int x);
// int (*var1)(int);
// int (*func2())(int) {return func;}
// int (**func3())(int) {return &var1;}
//


typedef int Tfunc1 (int);

int func(int x);
Tfunc1 *var1;
Tfunc1 *func2() {return func;}
Tfunc1 **func3() {return &var1;}



int m[5] = {0, 1, 2, 3, 4};
int (*fumas())[] {return &m;}
int (*(*varm1)())[] = fumas;

int f1() {return 20;}
int f2() {return 50;}
int (*arrfu2[2])() = {f1, f2};


int (*(*fuarrfu3())[2])() {return &arrfu2;}

int main2() {


    printf("%d\n", (*fumas())[2]);
    printf("%d\n", (*varm1())[4]);

    printf("%d\n", arrfu2[0]());

    printf("%d\n", (*fuarrfu3())[1]());

    return 0;
}

int main() {

    int arr[5];
    arr[3] = 7;
    printf("%d\n", arr[3]);


    int a = 33;
    int *arr2[5];

    arr2[2] = &a;

    printf("%d\n", *arr2[2]);

    typedef int Parr[5];
    Parr *parr;
    parr = &arr;
    printf("%d\n", (*parr)[3]);


    typedef int *Tarr3[5];
    Tarr3 *Parr3;
    Parr3 = &arr2;
    printf("%d\n", *(*Parr3)[2]);


    int arr22[5][5];
    arr22[1][3] = 22;

    int (*Parr4)[5][5];
    Parr4 = &arr22;
    printf("%d\n", (*Parr4)[1][3]);


    int (*arr7[5])[5];
    arr7[1] = &arr;
    printf("%d\n", (*arr7[1])[3]);


    int (*(*Parr5)[5])[5];
    Parr5 = &arr7;
    (*Parr5)[2] = &arr;
    printf("%d\n", (*(*Parr5)[1])[3]);
    printf("%d\n", (*(*Parr5)[2])[3]);

    var1 = func;
    printf("%d\n", var1(5));
    printf("%d\n", func2()(6));
    printf("%d\n", (*func3())(7));

    puts("========");
    main2();

    return 0;
}



int func(int x) {

    return x;
}
