#include <stdio.h>
#include <stdlib.h>


#define mapWidth 80
#define mapHeight 25


typedef struct SObject {
    float x, y;
} TObject;

char map[mapHeight][mapWidth + 1];

void ClearMap() {
    for (int i = 0; i < mapWidth; i++) {
        map[0][i] = '.';
    }
    map[0][mapWidth] = '\0';
    for (int j = 0; j < mapWidth; j++) {
        sprintf(map[j], map[0]);
    }
}

void ShowMap() {
    map[mapHeight - 1][mapWidth - 1] = '\0';
    for (int i = 0; i < mapHeight; i++) {
        printf("%s", map[i]);
    }
}


void SetObjectPos(TObject *obj, float xPos, float yPos) {

    (*obj).x = xPos;

}


int main() {

    return 0;
}
