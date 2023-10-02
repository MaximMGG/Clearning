#include <processenv.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

#define mapWidth 80
#define mapHeight 25

typedef struct SOjbect {
    float x,y;
    float vSpeed;
    float width, height;
} TObject;
TObject mario;
TObject brick[1];

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
        printf("%s\n", map[i]);
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
    (*obj).vSpeed = 0;
}

BOOL IsCollision(TObject o1, TObject o2);

void VMoveObject(TObject *obj){
    (*obj).vSpeed += 0.05;
    SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vSpeed);
    if (IsCollision(*obj, brick[0])) {
        (*obj).y -= (*obj).vSpeed;
        (*obj).vSpeed = 0;
    }
}


BOOL IsPosInMap(int x, int y) {
    return (x >= 0) && (x < mapWidth) && (y >= 0) && (y < mapHeight);
}

void PutObjectOnMap(TObject obj) {
    int ix = (int) round(obj.x);
    int iy = (int) round(obj.y);
    int iWidth = (int)round(obj.width);
    int iHeight = (int)round(obj.height);


    for (int i = ix; i < (ix + iWidth); i++) {
        for (int j = iy; j < (iy + iHeight); j++) {
            if (IsPosInMap(i, j))
                map[j][i] = '@';
        }
    }
}


void SetCurs(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

BOOL IsCollision(TObject o1, TObject o2) {
    return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
          ((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}


int main() {

    // printf("%s", "Hello");
    InitObject(&mario, 39, 10, 3, 3);
    InitObject(brick, 20, 20, 40, 5);


    do {

        CleanMap();


        if (GetKeyState(VK_SPACE) < 0) mario.vSpeed = -0.7;



        VMoveObject(&mario);
        PutObjectOnMap(brick[0]);
        PutObjectOnMap(mario);
        SetCurs(0, 0);
        ShowMap();

        Sleep(10);
    }
    while (GetKeyState(VK_ESCAPE) >= 0);



    return 0;
}
