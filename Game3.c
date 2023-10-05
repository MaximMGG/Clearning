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
    BOOL IsFly;
    char cType;
    float horizSpeed;
} TObject;

TObject mario;
TObject *brick = NULL;
int brickLength;

TObject *moving = NULL;
int movingLength;

char map[mapHeight][mapWidth + 1];


void CleanMap() {
    for(int i = 0; i < mapWidth; i++) {
        map[0][i] = ' ';
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

void HorizontalMoveObject(TObject *obj) {
    obj[0].x += obj[0].horizSpeed;
}

void SetObjectPos(TObject *obj, float xPos, float yPos) {
    (*obj).x = xPos;
    (*obj).y = yPos;
}

void InitObject(TObject *obj, float xPos, float yPos, float oWidth, float oHeight, char inType) {
    SetObjectPos(obj, xPos, yPos);
    (*obj).width = oWidth;
    (*obj).height = oHeight;
    (*obj).vSpeed = 0;
    (*obj).cType = inType;
    (*obj).horizSpeed = 0.2;
}

BOOL IsCollision(TObject o1, TObject o2);

void CreateLevel(int lvl);

void VMoveObject(TObject *obj){


    (*obj).IsFly = TRUE;
    (*obj).vSpeed += 0.05;
    SetObjectPos(obj, (*obj).x, (*obj).y + (*obj).vSpeed);
    for (int i = 0; i < brickLength; i++) {
        if (IsCollision(*obj, brick[i])) {
            (*obj).y -= (*obj).vSpeed;
            (*obj).vSpeed = 0;
            (*obj).IsFly = FALSE;
            if (brick[i].cType == '+') {
                CreateLevel(2);
                Sleep(1000);
            }
            break;
        }
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
                map[j][i] = obj.cType;
        }
    }
}


void SetCurs(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void HorizontalMoveMap(float dx) {
    mario.x -= dx;
    for (int i = 0; i < brickLength; i++) 
        if (IsCollision(mario, brick[i])) {
            mario.x += dx;
            return;
        }
    mario.x += dx;


    for (int i = 0; i < brickLength; i++) {
        brick[i].x += dx;
    }

    for(int i = 0; i < movingLength; i++){
        moving[i].x += dx;
    }
}

BOOL IsCollision(TObject o1, TObject o2) {
    return ((o1.x + o1.width) > o2.x) && (o1.x < (o2.x + o2.width)) &&
          ((o1.y + o1.height) > o2.y) && (o1.y < (o2.y + o2.height));
}

void CreateLevel(int lvl) {

    InitObject(&mario, 39, 10, 3, 3, '@');

    if (lvl == 1) {
        brickLength = 6;
        brick = realloc(brick, sizeof(*brick) * brickLength);

        InitObject(brick+0, 20, 20, 40, 5, '#');
        InitObject(brick+1, 60, 15, 10, 10, '#');
        InitObject(brick+2, 80, 20, 20, 5, '#');
        InitObject(brick+3, 120, 15, 10, 10, '#');
        InitObject(brick+4, 150, 20, 40, 5, '#');
        InitObject(brick+5, 210, 15, 10, 10, '+');
        movingLength = 1;
        moving = realloc(moving, sizeof(*moving) * movingLength);
        InitObject(moving + 0, 25, 10, 3, 2, 'o');
    }
    if (lvl == 2) {
        brickLength = 12;
        brick = realloc(brick, sizeof(*brick) * brickLength);

        InitObject(brick+0, 20, 20, 40, 5, '#');
        InitObject(brick+1, 60, 15, 10, 10, '#');
        InitObject(brick+2, 80, 20, 20, 5, '#');
        InitObject(brick+3, 120, 15, 10, 10, '#');
        InitObject(brick+4, 150, 20, 40, 5, '#');
        InitObject(brick+5, 200, 15, 10, 10, '#');
        InitObject(brick+6, 240, 20, 8, 12, '#');
        InitObject(brick+7, 280, 20, 10, 15, '#');
        InitObject(brick+8, 310, 15, 10, 10, '#');
        InitObject(brick+9, 350, 17, 7, 12, '#');
        InitObject(brick+10, 370, 10, 10, 20, '#');
        InitObject(brick+11, 411, 20, 5, 5, '+');

    }
}


int main() {

    CreateLevel(1);


    do {

        CleanMap();


        if ((mario.IsFly == FALSE) && (GetKeyState(VK_SPACE) < 0)) mario.vSpeed = -1;
        if (GetKeyState('A') < 0) HorizontalMoveMap(1);
        if (GetKeyState('D') < 0) HorizontalMoveMap(-1);

        if (mario.y > mapHeight) CreateLevel(1);


        VMoveObject(&mario);
        for(int i = 0; i < brickLength; i++) {
            PutObjectOnMap(brick[i]);
        }

        for(int i = 0; i < movingLength; i++) {
            VMoveObject(moving + i);
            HorizontalMoveObject(moving + i);
            PutObjectOnMap(moving[i]);
        }
        PutObjectOnMap(mario);
        SetCurs(0, 0);
        ShowMap();

        Sleep(10);
    }
    while (GetKeyState(VK_ESCAPE) >= 0);



    return 0;
}
