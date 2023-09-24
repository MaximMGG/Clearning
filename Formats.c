#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <winuser.h>



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

double hypotenuse() {

    double a;
    double b;
    
    printf("Please write a\n");
    scanf("%lf", &a);

    printf("Please write b\n");
    scanf("%lf", &b);

    return sqrt(pow(a, 2) + pow(b, 2));
}


void ifStatements() {
    int age;

    printf("Enter you age: ");
    scanf("%d", &age);

    if (age == 18) {
        printf("You are now signed up!");

    }


}

void switches() {

    char grade;

    printf("\nEnter a letter grade: ");

    scanf("%c", &grade);

    switch (grade) {
        case 'A':
            printf("perfect!\n");
            break;
        case 'B':
            printf("You did good!\n");
            break;
        case 'C':
            printf("You did ok!\n");
            break;
        case 'R':
            printf("At least it's not an F!\n");
            break;
        case 'F':
            printf("You failed!\n");
            break;
        default:
            printf("Please write valid letter");
    }

}


void operators() {

    int t;
    t = 5;

    if (t > 10) {
        printf("www");
        printf("123123k");
    }

    else printf("gr");

}

void calculatie() {

    int one;
    int two;
    char operator[] = "o";

    printf("Here is calculator!\nEnter first number: ");
    scanf("%d", &one);

    printf("Enter second number: ");
    scanf("%d", &two);

    printf("Enter symbol: ");
    scanf("%s", &operator);


    switch (operator[0]) {
        case '*': {printf("%d", one * two); break;}
        case '/' : {printf("%d", one / two); break;}
        case '+' : {printf("%d", one + two); break;}
        case '-' : {printf("%d", one - two); break;}
        default : {printf("You didn't enter operator");}
    }
    printf("%s", operator);
}

void printArray(int buf[], int length) {
    int data_type;
    // data_type = sizeof(buf) / sizeof(buf[0]); //do not work for arguments

    // printf("%d", data_type);
    // printf("%d\n", (*(&buf + 1) - buf)); // do not work for arguments
    int temp[] = {12341234, 2, 3, 4, 5};

    int le = sizeof(temp) / sizeof(temp[0]); // do not work for arguments

    printf("%d\n", le);

    data_type = *(&temp + 1) - temp;
    // printf("%d\n", data_type);
    
    for (int i = 0; i < length; i++) {
        printf("%d\n",buf[i]);
    }

    printf("\n");

    // not work :(
    // for (int i = 0; buf[i] != '\0'; i++) { // do not work for arguments
    
    //     printf("%d\n", buf[i]);
    // }

    printf("\n");

    for (int i = 0; temp[i] != '\0'; i++)
    {
        printf("%d\n", temp[i]);
    }
    

}

void proc1(int a)
{
    if (a < 10) {
        printf("%d\n", a);
    } else {
        printf("Error...\n");
    }
}

int proc2(int a, int b)
{
    return a > b ? 1 : 0;
}

void fuc() {
    proc1(proc2(5, 15));
    proc1(5);
    proc1(15);
}

void easyFunc() {
    int length = 10;

    int buf[length];


    for (int i = 0; i < length; i++) {
        if(i < 5) {
            buf[i] = 7;
        } else {
            buf[i] = pow(i, 2);
        }
    }
    printArray(buf, length);
}

void symbols() {

    setlocale(LC_ALL, "Russian");
    char ch = 'W';

    printf("%c\n", ch);

    // scanf("%c", ch);

    // ch = getch();
    // ch = getche();
    putch('W');
    printf("\n");
    // *_cgets();

    // printf("ch = %c", ch);

    char s[10] = "Превет";

    printf("%s\n", s);

    sprintf(s, "12aaaasd");
    s[4] = '\0';
    printf("%s", s);

    // scanf("%s", s);
    gets(s);

    // OemToChar(s, s);

    printf("%s", s);

}



int main() {



    // arithmeticOperator();
    // inputDate();
    // mathFunctions();
    // doubleCount();
    // printf("Here is hypotenuse %lf\n", hypotenuse());
    // ifStatements();
    // switches();
    // operators();
    // calculatie();
    // fuc();
    // easyFunc();
    symbols();

    return 0;
}

