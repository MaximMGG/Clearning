#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main() {

    char str[100];
    snprintf(str, 100, "%s", "asassa");


    char *str2;
    str2 = malloc(10);
    sprintf(str2, "%s", "123123");

    int len = strlen(str) + strlen(str2) + 1;
    str2 = realloc(str2, sizeof(char) * len);
    snprintf(str2, len, "%s%s", str2, str);

    printf("%s\n", str2);

    return 0;
}

