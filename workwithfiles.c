#include <stdio.h>
#include <stdlib.h>



char* getString(FILE *f) {
    char *arr;

    for(int i; arr[i-1] != '\n'; i++) {
        fscanf(f, "%c", &arr[i]);
    }

    return arr;
}




int main() {
    //
    // FILE *f;
    // char c[1000];
    // char *s;
    //
    // f = fopen("test.txt", "w");
    //     fprintf(f, "%s", "Hello from File!\n");
    //     fprintf(f, "%s", "Hello one more time from File!\n");
    //
    // fclose(f);
    //
    //
    // f = fopen("test.txt", "r");
    //
    // // fscanf(f, "%s", c);
    // // printf("%s", c);
    // while(!feof(f)) {
    //     if (fgets(c, 1000, f) != NULL) 
    //         printf("%s", c);
    // }
    // fclose(f);

    FILE *b; 
    b = fopen("test.txt", "r");

    // char *arr = getString(b);
    char ww[1000];

    // printf("%s", arr);

    // fgets(arr, 1000, b);
    // printf("%s from fgets" ,arr);

    fgets(ww, 1000, b);

    printf("%s from fgets ww", ww);

    fclose(b);

    return 0;
}
