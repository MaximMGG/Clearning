#include <stdio.h>
#include <stdlib.h>



void task();

int main() {
    
    FILE *file = fopen("test6.txt", "a+");

    fprintf(file, "ASDF123");

    char c[100];

    fseek(file, 0, SEEK_SET);

    if (fgets(c, 100, file) != NULL) {
        // printf(c);
    }
    fclose(file);

    task();

    return 0;

}



void task() {

    FILE *file = fopen("test6task.txt", "w+");

    fprintf(file, "asdfg");

    fseek(file, 2, SEEK_SET);
    char c[10];
    if (fgets(c, 10, file) != NULL) {
        puts(c);
    }
    fclose(file);


    file = fopen("test6task.txt", "a+");


    fprintf(file, "qqq");


    fseek(file, -4, SEEK_CUR);


    char aa[20];

    if(fgets(aa, 20, file) != NULL) {
        puts(aa);
    }

    fclose(file);
}
