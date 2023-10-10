#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>

void task();

int main() {
    FILE *f;

    // printf("%s\n", _fmode == _O_TEXT ? "TEXT" : "BINARY");
    _fmode = _O_BINARY;

    f = fopen("test5.txt", "w");

    char c[3] = "AB";
    c[1] = 26;
    fprintf(f, "%s", c); 
    fclose(f);

    f = fopen("test5.txt", "r");

    char buf[10] = "";
    fread(buf, 1, sizeof(buf), f);
    fclose(f);

    for(int i = 0; i < 10; i++){
        // printf("%d\n", buf[i]);
    }

    task();

}


void task() {
    _fmode = _O_TEXT;
    FILE *file = fopen("test5task.txt", "w");

    int arr[5] = {1, 2, 3, 4, 5};

    fwrite(&arr, 1, sizeof(arr), file);
    fclose(file);

    int arrcopy[5];
    fopen("test5task.txt", "r");
    fread(&arrcopy, 1, sizeof(arrcopy), file);
    for(int i = 0; i < 5; i++){
        printf("%d\n", arrcopy[i]);
    }
    fclose(file);

    _fmode = _O_BINARY;

    file = fopen("test5task.txt", "w");

    int arr2[5] = {1, 2, 26, 4, 5};

    fwrite(&arr2, 1, sizeof(arr2), file);
    fclose(file);

    int arrcopy2[5];
    fopen("test5task.txt", "r");
    fread(&arrcopy2, 1, sizeof(arrcopy2), file);
    for(int i = 0; i < 5; i++){
        printf("%d\n", arrcopy2[i]);
    }
    fclose(file);

}
