#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void errFund(int a) {
    int i[10] = {};
    assert(a >= 0 && a < 10);
    printf("%d\n", i[a]);
}

int main() {




    errFund(15);



    return 0;
}
