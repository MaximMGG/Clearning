#include <stdio.h>


int main() {

    int nums[100];
    int buf = 1001;
    nums[0] = 1000;

    for(int i = 1; i < 100; i++) {
        nums[i] = nums[i - 1] + buf;
    }

    FILE *f = fopen("testd.txt", "w");

    for(int i = 0; i < 100; i++) {

        fprintf(f, "%d", nums[i]);
    }

    fclose(f);


    FILE *ff = fopen("testb.bin", "wb");

    for(int i = 0; i < 100; i++) {
        fwrite(&(nums[i]), 1, sizeof(int), ff);
    }

    fclose(ff);


    return 0;
}
