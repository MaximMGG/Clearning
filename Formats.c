#include <stdio.h>
#include <string.h>

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

int main() {

    arithmeticOperator();
    inputDate();

    return 0;
}

