#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <winnt.h>



#define width 80
#define height 25


typedef struct {
    char map[height][width + 1];

} loc;


loc l;


void loc_LoadFromFile(char *fileName) {
    memset(&l.map, ' ', sizeof(l));
    for(int i = 0; i < height; i++){
        l.map[i][width] = '\0';
    }

    FILE *f = fopen(fileName, "r");
    char c[80];
    int line = 0;
    while(!feof(f)) {
        fgets(c, width, f);
        int cnt = strlen(c);
        if (c[cnt - 1] == '\n') cnt--;
        strncpy(l.map[line], c, cnt);
        line++;
    }
    fclose(f);

    l.map[height - 1][width - 1] = '\0';
}

int main() {

    loc_LoadFromFile("MapForGameQuest.txt");
    for(int i = 0; i < height; i++){
        printf("%s\n", l.map[i]);
    }

    return 0;
}
