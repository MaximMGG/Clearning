#include <stdio.h> 
#include <stdlib.h> 

typedef int (*TFuncAB) (int, int);


int max(int a, int b) {
    return a > b ? a : b;
}


int Get5() {
    return 5;
}

int min(int a, int b) {
    return a > b ? b : a;
}

int plus(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int GetOne(int mas[], TFuncAB fn) {
    int val = mas[0];
    if (fn != NULL) 
        for (int i = 0; i < 10; i++) {
            val = fn(val, mas[i]);
        }
    return val;
}

int main() {
    
    int length = 4;
    TFuncAB *func;

    func = malloc(sizeof(*func) * length);

    func[0] = min;
    func[1] = max;
    func[2] = plus;
    func[3] = multiply;

    int mas[10] = {22, 14, 155, 535, 2, 132, 76, 44, 11, 22};

    for(int i = 0; i < 4; i++) {
        printf("%d\n", func[i](23, 22));
    }
    free(func);
    return 0;
}
