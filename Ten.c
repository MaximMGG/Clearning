#include <stdio.h>
#include <stdlib.h>
#include <math.h>




void MePrint(int count) {

    printf("text: %d\n", count);
    count--;
    if (count <= 0) return;
    MePrint(count);
}

int MyFacorial(int x) {
    if (x > 1) 
        return x * MyFacorial(x - 1);
    else 
        return 1;

}

int ter(int i) {
    return i > 10 ? 10 : i > 100 ? 100 : 1000;
}


int main() {

    int b = (int)round(pow(3, 5));


    printf("%d\n", b);

    // int a = MyFacorial(3);
    // printf("%d", a);
    // MePrint(15);



    // int i;
    // scanf("%d", &i);
    //
    // i = 50 + (i < 10 ? 10 : i * 2);
    //
    // printf("%d\n", i);
    
    return 0;
}

