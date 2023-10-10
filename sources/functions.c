#include "core.h"
#include <stdarg.h>


void pfunc(int *a, int *b, int *c) {
    printf("copy of P -> %d, %d, %d\n", a, b, c);

    int *ptr = a;

    for(int i = 0; i < 3; i++){
        printf("a -- %d\n", *ptr);
        ptr -= 1;
    }

}


void ppfunc() {
    
    int *arr;
    int len = 10;

    arr = malloc(sizeof(int) * 10);

    arr[0] = 100;
    
    int *begin = &arr[0];
    int *end = begin + 10;
    arr[1] = 2;

    arr[8] = 123; 

    for(begin; begin < end ; begin++){
        printf("%d\n", *begin);
    }

    free(arr);
}


void magic() {
    int *arr;
    int len = 10;
    arr = malloc(sizeof(int) * len);
    int *p = &arr[0];
    for(int i = 0; i < len; i++){
        arr[i] = p - (p - i);
        printf("%d\n", *p);
        p++;
    }
    free(arr);
}



void func(int a, int b, int c) {
    printf("%d %d %d\n", &a, &b, &c);
    int *ptr = &a;

    printf ("%d\n", *ptr);
    
    for(int i = 0; i < 3; i++){
        printf("a -- %d\n", *ptr);
        if (ptr < 0) {
            ptr -= 2;
        } else {
            ptr += 2;
        }
    }
}

double sumWithMacro(int cnd, ...);
double sum(int cnd, ...);
int sumInt(int cnd, ...);
void myPrint(char *param, ...);
int avarageInt(int cnt, ...);

int main() {

    // int index = 5;
    //
    // int *pI = &index;
    // int *pI2 = pI + 1;
    // *pI2 = 7;

    // printf("%d, %d\n -> %d", *pI, *(pI + 1), *pI2);

    // int a[5] = {1, 2, 3, 4, 5};
    //
    // int *pa = &a[0];
    //
    // for(int i = 0; i < 5; i++){
    //     printf("%d\n", *pa);
    //     pa++;
    // }


    // int a = 2;
    // int b = 3;
    // int c = 4;

    // printf("original p ->%d %d %d\n", &a, &b, &c);

    // func(a, b, c);
    // pfunc(&a, &b, &c);
    // ppfunc();
    // magic();

    int pp = 3;
    double a = 2.1;
    double b = 2.1;
    double c = 3.1;

    printf("%d %d %d %d\n",&pp, &a, &b, &c);

    printf("%f\n", sum(3, a, b, c));
    printf("%d\n", sumInt(3, 2, 3, 4));
    printf("%lf\n", sumWithMacro(5, 4.1, 5.67, 123414.11231414, 1.0));
    myPrint("isdc", 23, "hello", 234.111, 'w');
    printf("%d\n", avarageInt(5, 1, 2, 3, 4, 5));

    return 0;
}



 double sum(int cnt, ...){
   
    double res = 0;
    double *p = &cnt + 2;
    for (int i = 0; cnt > 0; cnt--) {
        res += *p;
        p++;
    }

    //  va_list ap;
    //  va_start(ap, cnt);
    //  for(int i = 0; i < cnt; i++){
    //     res += va_arg(ap, double);
    //  }
    //  va_end(ap);
     return res;
}


int  sumInt(int cnt, ...) {
    int res = 0;
    int *p = &cnt + 2;
    
    for(int i = 0; cnt > 0; cnt--){
        res += *p;
        p += 2;
    }
    // va_list ap;

    // va_start(ap, cnt); 

    // for(int i = 0; i < cnt; i++){
    //     res += va_arg(ap, int);
    // }
    // va_end(ap);
    return res;
}

double sumWithMacro(int cnt, ...) {
    double res = 0; 
    va_list ap;

    va_start(ap, cnt);

    for(int i = 0; i < cnt; i++){
        res += va_arg(ap, double);
    }

    va_end(ap);

    return res;
}

void myPrint(char *param, ...) {
    
    va_list ptr;
    va_start(ptr, param);

    while (*param) {
        if (*param == 'i') {
            printf("--%d--\n", va_arg(ptr, int));
        } else if (*param == 'd') {
            printf("--%f--\n", va_arg(ptr, double));
        } else if (*param == 'c') {
            printf("--%c--\n", va_arg(ptr, int));
        } else if (*param == 's') {
            printf("--%s--\n", va_arg(ptr, char*));
        }
        param++;
    }
    va_end(ptr);
}

int avarageInt(int cnt, ...) {
    int buf = 0;

    va_list pp;

    va_start(pp, cnt);

    for(int i = 0; i < cnt; i++){
       buf += va_arg(pp, int); 
    }
    va_end(pp);

    return buf / cnt;
}










