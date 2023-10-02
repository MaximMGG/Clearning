#include <stdio.h>
#include <math.h>

#define mapWidth 80
#define mapHeight 25

typedef struct SOjbect {
    float x,y;
    float width, height;
} TObject;
TObject mario;

char map[mapHeight][mapWidth + 1];


void CleanMap() {
    for(int i = 0; i < mapWidth; i++) {
        map[0][i] = '.';
    }

    for (int j = 0; j < mapHeight; j++) {
        sprintf(map[j], "%s", map[0]);
    }
}

void ShowMap() {
    map[mapHeight - 1][mapWidth - 1] = '\0';
    for(int i = 0; i < mapHeight; i++) {
        printf("%s", map[i]);
    }
}

void SetObjectPos(TObject *obj, float xPos, float yPos) {
    (*obj).x = xPos;
    (*obj).y = yPos;
}

void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight) {
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
}

void PutObjectOnMap(TObject obj) {
    int ix = (int) round(obj.x);
    int iy = (int) round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);


    for (int i = ix; i < (ix + iWidth); i++) {
        for (int j = iy; j < (iy + iHeight); j++) {
            map[iy][ix] = '@';
        }
    }


}

int main() {

    // printf("%s", "Hello");
    InitObject(&mario, 20, 10, 3, 3);
    CleanMap();
    PutObjectOnMap(mario);
    ShowMap();



    return 0;
}
