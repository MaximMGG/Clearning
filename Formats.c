#include <stdio.h>
#include <string.h>
#include <math.h>

void arithmeticOperator() {
    int x = 5;
    int y = 2;

    // float z = x / (float) y;
    // printf("%f", z);

    int z = x % y;
    printf("%d\n", z);

}

void inputDate() {

    char name[25];
    int age;

    printf("What's your name?\n");

    // scanf("%s", &name); // can read any character unexepted whitespaces
    fgets(name, 25, stdin); //we need this function in needs that user can write something with whitespaces
    name[strlen(name)-1] = '\0';

    printf("Hello diar %s\n", name);

    printf("How old are you?\n");

    scanf("%d", &age);

    printf("You are %d years old\n", age);

}



void mathFunctions() {
    double A = sqrt(9);
    double B = pow(2, 4);
    int C = round(3.14);
    int D = ceil(3.14);
    int E = floor(3.99);
    double F = fabs(-100);
    double G = log(3);
    double H = sin(45);
    double I = cos(45);
    double J = tan(45);

    printf("\n%lf\n", A);
    printf("\n%lf\n", B);
    printf("\n%d\n", C);
    printf("\n%d\n", D);
    printf("\n%d\n", E);
    printf("\n%lf\n", F);
    printf("\n%lf\n", G);
    printf("\n%lf\n", H);
    printf("\n%lf\n", I);
    printf("\n%lf\n", J);
}

void doubleCount() {
    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nEnter radius of a circle: ");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * pow(radius, 2);

    printf("circumference: %lf\n", circumference);
    printf("area: %lf\n", area);



}


int main() {

    // arithmeticOperator();
    // inputDate();
    // mathFunctions();
    doubleCount();

    return 0;
}

