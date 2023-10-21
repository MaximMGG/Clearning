#include "core.h"


int main() {
    
    int len = 5;
    int *arr;

    arr = malloc(sizeof(int) * len);
    int *arr2 = arr;

    for(int i = 0; i < len; i++){
        *arr = 10 + i;
        printf("%d\n", arr2[i]);
        arr = arr + 1;
    }

    free(arr);
    return 0;
}
