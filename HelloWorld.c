#include <stdio.h>
#include <stdlib.h>

int main() {

    // printf("\"I like poppys\"  - One grate man");

    int x;
    x = 1234;

    int age = 21;
    float gpa = 2.05983001;
    char grade = 'C';//ingle character
    char name[] = "Boby";// array of characters (String)

    printf("You name is %s and you are %d years old\n", name, age); // %s - array of characters, %d - int
    printf("Your avarage is %c\n", grade); // %c - single character
    printf("Your gpa is %.2f", gpa);// %f - float (if %.2f) count of number ofter point.

    return 0;
}

/*



*/